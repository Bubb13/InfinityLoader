
###############################################################################
# Generates the .h/.cpp files required to build the bindings DLL.             #
# This file has been hacked together under the principle of "It just works!". #
# Good luck - here be dragons.                                                #
###############################################################################

from enum import Enum
from io import TextIOWrapper
from itertools import islice
from typing import Callable, Match, Tuple, TypeVar
import builtins
import importlib
import re
import sys


T = TypeVar("T")

class UniqueWrapper:

	def __init__(self, object: T, pHash: Callable[[T], int], pEq: Callable[[T, T], bool]) -> None:
		self.object: T = object
		self.pHash: Callable[[T], int] = pHash
		self.pEq: Callable[[T, T], bool] = pEq

	def __hash__(self) -> int:
		return self.pHash(self.object)

	def __eq__(self, other: object) -> bool:
		return isinstance(other, UniqueWrapper) and self.pEq(self.object, other.object)


class UniqueList(list[T]):

	def defaultHash(object: T):
		return id(object)


	def defaultEq(a: T, b: T):
		return a is b


	def __init__(self, pHash: Callable[[T], int]=None, pEq: Callable[[T, T], bool]=None) -> None:
		super().__init__()
		self.pHash: Callable[[T], int] = pHash or UniqueList.defaultHash
		self.pEq: Callable[[T, T], bool] = pEq or UniqueList.defaultEq
		self.listIndexMapping: dict[UniqueWrapper[T], int] = {}


	def containsUnique(self, v: T):
		return UniqueWrapper(v, self.pHash, self.pEq) in self.listIndexMapping


	def addUnique(self, v: T):
		if (wrapper := UniqueWrapper(v, self.pHash, self.pEq)) not in self.listIndexMapping:
			self.listIndexMapping[wrapper] = len(self)
			self.append(v)


	def removeUnique(self, v: T):
		if index := self.listIndexMapping.get(wrapper := UniqueWrapper(v, self.pHash, self.pEq)):
			del self.listIndexMapping[wrapper]
			del self[index]
			for i in range(index, len(self)):
				self.listIndexMapping[UniqueWrapper(self[i], self.pHash, self.pEq)] = i


	def rebuildIndexMapping(self):
		newMapping: dict[UniqueWrapper[T], int] = {}
		for i, v in enumerate(self):
			if (wrapper := UniqueWrapper(v, self.pHash, self.pEq)) in self.listIndexMapping:
				newMapping[wrapper] = i
		self.listIndexMapping = newMapping



##################
# String Utility #
##################

def stripUnnecessaryTypeSpaces(typeStr: str):

	parts: list[str] = []
	nextStart = 0
	checkSpace = False

	def checkSub(i):
		nonlocal nextStart
		nonlocal checkSpace
		if i - nextStart > 0:
			parts.append(typeStr[nextStart:i])
			checkSpace = True

		nextStart = i + 1

	for i, char in enumerate(typeStr):
		if char == " ":
			checkSub(i)
		elif checkSpace:
			checkSpace = False
			if char != "*" and char != "&" and char != "<" and char != ">":
				parts.append(" ")

	checkSub(i + 1)
	return "".join(parts)


def stripTypeBrackets(stringIn):
	try:
		return stringIn[:stringIn.index("<")]
	except ValueError:
		return stringIn


def findTemplateBracketStarts(str):
	hits = []
	bracketLevel = 0
	for i in range(0, len(str)):
		char = str[i]
		if char == "<":
			if bracketLevel == 0 and (i > 0 and (i < 2 or str[i-2:i] != "::")): hits.append(i)
			bracketLevel += 1
		elif char == ">":
			bracketLevel -= 1
	return hits


def separateTemplateTypeParts(str, startI=0):
	bracketLevel = 0
	name = None
	for i in range(startI, len(str)):
		char = str[i]
		if char == "<":
			bracketLevel += 1
			startI = i + 1
			name = str[0:i]
			break

	assert bracketLevel != 0

	for i in range(startI, len(str)):
		char = str[i]
		if char == "<":
			bracketLevel += 1
		elif char == ">":
			bracketLevel -= 1
			if bracketLevel == 0: return name, str[startI:i]


def splitKeepBrackets(stringIn, toSplit, noSplit=[], includeToSplit=False):

	def inList(string, i, l):
		for v in l:
			vLen = len(v)
			endI = i + vLen
			if string[i:endI] == v: return vLen
		return -1

	results: list[str] = []
	level = 0
	lastSplitEnd = 0
	i = 0
	limit = len(stringIn)
	while i < limit:

		incAmount = 1

		char = stringIn[i]
		if char == "<":
			level += 1
		elif char == ">":
			level -= 1
		elif level == 0:
		
			noSplitLen = inList(stringIn, i, noSplit)
			if noSplitLen != -1:
				i += noSplitLen
				continue
		
			splitLen = inList(stringIn, i, toSplit)
			if splitLen != -1:

				slice = stringIn[lastSplitEnd:i]
				incAmount = splitLen
				if len(slice) > 0: results.append(slice)

				if includeToSplit:
					toSplitSlice = stringIn[i:i+incAmount]
					results.append(toSplitSlice)

				lastSplitEnd = i + incAmount

		i += incAmount

	if i > lastSplitEnd:
		lastSlice = stringIn[lastSplitEnd:i]
		if len(lastSlice) > 0: results.append(lastSlice)

	return results


def splitMulti(stringIn, toSplit, noSplit=[]):

	def inNoSplit(string, i):
		for v in noSplit:
			noSplitLen = len(v)
			if string[i:i+noSplitLen] == v: return noSplitLen
		return -1

	results: list[str] = []
	lastSplitEnd = 0
	i = 0
	limit = len(stringIn)
	while i < limit:

		noSplitLen = inNoSplit(stringIn, i)
		if noSplitLen != -1:
			i += noSplitLen
			continue

		char = stringIn[i]
		if char in toSplit:
			slice = stringIn[lastSplitEnd:i]
			if len(slice) > 0: results.append(slice)
			lastSplitEnd = i + 1

		i += 1

	if i > lastSplitEnd:
		lastSlice = stringIn[lastSplitEnd:i]
		if len(lastSlice) > 0: results.append(lastSlice)

	return results


def removeRegexCount(string: str, keyword: str):

	afterLastMatchI = 0
	parts: list[str] = []
	removeCount = 0

	for v in re.finditer(keyword, string):
		parts.append(string[afterLastMatchI:v.start()])
		removeCount += 1
		afterLastMatchI = v.end()

	if afterLastMatchI != len(string):
		parts.append(string[afterLastMatchI:])

	return "".join(parts), removeCount


def getPointerLevel(str: str, removeAmount=0):
	pointerLevel = 0
	removedStrParts = []
	splits = splitKeepBrackets(stripUnnecessaryTypeSpaces(str), ["*", "&"], includeToSplit=True)
	for split in splits:
		if split == "*" or split == "&":
			pointerLevel += 1
			if removeAmount > 0:
				removeAmount -= 1
			else:
				removedStrParts.append(split)
		else:
			removedStrParts.append(split)

	return pointerLevel, "".join(removedStrParts)


#########################
# Group / TypeReference #
#########################

class HeaderType(Enum):
	NORMAL = 1
	CLEANED = 2


# Foward declarations just to suppress warnings
class Group: pass
globalGroup: Group
class TypeReference: pass
class Field: pass


class MainState:

	groupsDict: dict[str,Group] = {}
	groups: list[Group] = []
	filteredGroups: UniqueList[Group] = UniqueList()
	noCustomTypes: bool = None

	def addGroup(self, group: Group):

		if existingGroup := self.groupsDict.get(group.name):

			if not existingGroup is group: 

				# Note: This merge can be a source of errors if Group is updated to include new variables

				group.listIndex = existingGroup.listIndex
				self.groups[group.listIndex] = group

				if superGroup := existingGroup.superGroup:
					superGroup.subGroups.removeUnique(existingGroup)

				group.isDirectlyWanted = group.isDirectlyWanted or existingGroup.isDirectlyWanted
				group.isSoftWanted = group.isSoftWanted or existingGroup.isSoftWanted
				
				for inRef in existingGroup.inwardTypeRefs:
					inRef.group = group
					group.inwardTypeRefs.addUnique(inRef)

				for k, v in existingGroup.uniqueUseRepresentations.items():
					group.uniqueUseRepresentations[k] = v
		else:
			group.listIndex = len(self.groups)
			self.groups.append(group)

		self.groupsDict[group.name] = group
		

	def getGroup(self, name: str):
		return self.groupsDict[name]


	def tryGetGroup(self, name: str):
		return self.groupsDict.get(name)


	def updateGroupNameMapping(self, group: Group, newName: str):
		oldName = group.name
		group.name = newName
		if group.listIndex:
			del self.groupsDict[oldName]
			# Handles merging of two identically-named structs
			self.addGroup(group)



class TemplateMappingTracker:

	def __init__(self) -> None:
		self.mappings: dict[str, list[tuple[TypeReference]]] = {}

	def registerMapping(self, groupName, templateMapping: tuple[TypeReference]):
		mappingStack = self.mappings.get(groupName)
		if mappingStack == None:
			mappingStack = []
			self.mappings[groupName] = mappingStack
		mappingStack.append(templateMapping)

	def deregisterMapping(self, groupName):
		mappingStack = self.mappings.get(groupName)
		if mappingStack == None: return
		stackSize = len(mappingStack)
		if stackSize >= 1:
			mappingStack.pop()
			if stackSize == 1:
				del self.mappings[groupName]

	def getMapping(self, groupName):
		mappingStack = self.mappings.get(groupName)
		if mappingStack == None: return
		return mappingStack[-1]

	def debugPrintMappings(self):
		for key in self.mappings:
			print(f"{key} =>")
			val = self.mappings[key]
			for i in range(len(val)):
				tup = val[i]
				print(f"\t[{i}]:")
				for j in range(len(tup)):
					print(f"\t\t[{j}]=\"{tup[j].toString()}\"")



class TemplateTypeMode(Enum):
	USER_TYPE = 1
	HEADER = 2



primitives = {"intptr_t", "size_t", "int", "__int8", "__int16", "__int32", "__int64", "long", "bool", "char", "float", "wchar_t", "double", "long double"}
primitiveNumbers = {"intptr_t", "size_t", "int", "__int8", "__int16", "__int32", "__int64", "long", "float", "double", "long double"}

class TypeReference:

	def __init__(self):

		self.sourceString: str = None

		self.group: Group = None
		self.sourceGroup: Group = None
		self.pointerLevel: int = 0
		self.reference: bool = False
		self.arrayParts: list = []
		self.bitFieldPart: str = None
		self.templateTypes: list[TypeReference] = []

		self.primitive: bool = False
		self.noconst: bool = False

		self.unsigned: bool = False
		self.const: bool = False
		self.volatile: bool = False
		self.long: bool = False

		self.superRef: TypeReference = None
		self.subRef: TypeReference = None


	def copyTrivialFields(self, other):
		self.const = other.const
		self.long = other.long
		self.noconst = other.noconst
		self.primitive = other.primitive
		self.sourceGroup = other.sourceGroup
		self.sourceString = other.sourceString
		self.unsigned = other.unsigned
		self.volatile = other.volatile


	def getModifierStr(self):
		parts: list[str] = []
		if self.const:    parts.append("const ")
		if self.unsigned: parts.append("unsigned ")
		if self.volatile: parts.append("volatile ")
		if self.long:     parts.append("long ")
		return "".join(parts)


	def removeFromGroupRefs(self):
		if self.group:
			self.group.inwardTypeRefs.removeUnique(self)


	def changeReferencedGroup(self, newGroup: Group):
		if not (self.group is newGroup):
			self.removeFromGroupRefs()
			self.group = newGroup
			if newGroup != None:
				self.group.inwardTypeRefs.addUnique(self)


	def shallowCopy(self, copyObj: TypeReference=None) -> TypeReference:

		copyObj = copyObj or TypeReference()
		copyObj.copyTrivialFields(self)
		copyObj.arrayParts = self.arrayParts
		copyObj.bitFieldPart = self.bitFieldPart
		copyObj.group = self.group
		copyObj.pointerLevel = self.pointerLevel
		copyObj.subRef = self.subRef
		copyObj.superRef = self.superRef

		copyTemplateTypes: list[TypeReference] = []
		for templateRef in self.templateTypes:
			copyTemplateTypes.append(templateRef.shallowCopy())

		copyObj.templateTypes = copyTemplateTypes
		return copyObj


	def isGroupUsed(self, mainState: MainState):
		return not self.group or self.group.isUsed(mainState)


	def getSuperRef(self):
		return self.superRef


	def getGroup(self):
		return self.group


	def getArrayParts(self):
		return self.arrayParts


	def getName(self):
		return self.group and self.group.name or self.sourceString


	def getSingleName(self):
		return self.group and self.group.singleName or self.sourceString


	def getTemplates(self, mainState: MainState, askingGroup: Group=None):
		return self.templateTypes


	def isVoid(self):
		return self.getUserTypePointerLevel() == 0 and self.getName() == "void"


	def getAllTypeReferences(self, mainState: MainState):

		parts = [self]

		superRef = self.superRef
		while superRef:
			parts.append(superRef)
			superRef = superRef.superRef

		for templateType in self.templateTypes:
			for v in templateType.getAllTypeReferences(mainState):
				parts.append(v)

		return parts


	def isGenericTemplate(self):
		return self.sourceGroup != None and self.sourceGroup.templateTypeNameMapping.get(self.getName()) != None


	def isUnparameterized(self):
		return self.group and ((len(self.group.templateTypeNames) > 0 and len(self.templateTypes) == 0) or (self.superRef and self.superRef.isUnparameterized()))


	def isPrimitive(self):
		return self.getName() in primitives


	def isPrimitiveNumber(self):
		return self.getName() in primitiveNumbers


	def setUserTypePointerLevel(self, mainState: MainState, newVal: int) -> None:
		assert newVal >= 0, "self.pointerLevel cannot be negative"
		self.pointerLevel = newVal


	def getUserTypePointerLevel(self):
		return self.pointerLevel


	def adjustUserTypePointerLevel(self, mainState: MainState, adjustAmount: int) -> None:
		self.setUserTypePointerLevel(mainState, self.getUserTypePointerLevel() + adjustAmount)


	def checkReplaceTemplateType(self, mainState: MainState, sourceGroup: Group, templateMappingTracker: TemplateMappingTracker) -> TypeReference:
		
		toReturn = self
		toReturnName = toReturn.getName()

		if sourceGroup and (v := sourceGroup.templateTypeNameMapping.get(toReturnName)) != None:

			index = v.templateTypeNames.index(toReturnName)
			toReturn: TypeReference = templateMappingTracker.getMapping(v.name)[index]

			# HACK HACK HACK HACK HACK HACK HACK HACK HACK HACK HACK HACK HACK HACK HACK HACK HACK
			# HACK PointerReferences store their internal TypeReference as their template     HACK
			# HACK parameter. These still need to be exposed as a PointerReference so they    HACK
			# HACK properly handle their pointer level being changed. Getting the header      HACK
			# HACK name of the internal reference and defining it again to transform it into  HACK
			# HACK a PointerReference.                                                        HACK
			# HACK HACK HACK HACK HACK HACK HACK HACK HACK HACK HACK HACK HACK HACK HACK HACK HACK
			if sourceGroup.name == "Pointer":
				toReturn = defineTypeRef(mainState, sourceGroup, toReturn.getHeaderName(pointerLevelAdjust=self.getUserTypePointerLevel()), TypeRefSourceType.VARIABLE)
			else:
				toReturn = toReturn.shallowCopy()
				toReturn.adjustUserTypePointerLevel(mainState, self.getUserTypePointerLevel())

			toReturn.primitive = toReturn.primitive or self.primitive
			toReturn.noconst = toReturn.noconst or self.noconst

		return toReturn


	def _getAppliedNameInternal(self, mainState: MainState, sourceGroup: Group, templateMappingTracker: TemplateMappingTracker, pointerLevelAdjust=0, useUsertypeOverride=False, noModifiers=False, templateTypeMode: TemplateTypeMode=None):

		"""
		Given a TypeRef in which the caller wants to express an arbritary series of template uses, returns a
		string representation of the current TypeRef's group name as if its template types were filled with the information
		held by templateMappingTracker.

		If the current TypeRef does not have an attached Group, simply returns the TypeRef's name.
		"""

		assert templateTypeMode, "templateTypeMode must be defined!"

		parts: list[str] = []

		if not noModifiers:
			parts.append(self.getModifierStr())

		if superRef := self.getSuperRef():
			parts.append(superRef._getAppliedNameInternal(mainState, sourceGroup, templateMappingTracker, useUsertypeOverride=useUsertypeOverride, templateTypeMode=templateTypeMode))
			parts.append("::")

		if len(self.templateTypes) > 0:

			parts.append(self.getSingleName())
			assert parts[-1] != None, "Using bad self.getSingleName()"

			parts.append("<")

			if templateTypeMode == TemplateTypeMode.USER_TYPE:
				for templateType in self.templateTypes:
					replaced = templateType.checkReplaceTemplateType(mainState, sourceGroup, templateMappingTracker)
					parts.append(replaced.getAppliedUserTypeName(mainState, sourceGroup, templateMappingTracker, useUsertypeOverride=useUsertypeOverride))
					assert parts[-1] != None, f"Using bad templateType.getAppliedUserTypeName() for (original: {type(templateType).__name__}, replaced: {type(replaced).__name__}) [TemplateTypeMode.USER_TYPE]"
					parts.append(",")
			elif templateTypeMode == TemplateTypeMode.HEADER:
				for templateType in self.templateTypes:
					replaced = templateType.checkReplaceTemplateType(mainState, sourceGroup, templateMappingTracker)
					parts.append(replaced.getAppliedHeaderName(mainState, sourceGroup, templateMappingTracker, useUsertypeOverride=useUsertypeOverride))
					assert parts[-1] != None, f"Using bad templateType.getAppliedUserTypeName() for (original: {type(templateType).__name__}, replaced: {type(replaced).__name__}) [TemplateTypeMode.HEADER]"
					parts.append(",")

			parts.pop()
			parts.append(">")

		elif self.group:
			parts.append(self.group.getAppliedName(mainState, templateMappingTracker, useUsertypeOverride=useUsertypeOverride, templateTypeMode=templateTypeMode, singleName=True))
			assert parts[-1] != None, "Using bad group.getAppliedName()"
		else:
			parts.append(self.sourceString)
			assert parts[-1] != None, "Using bad self.sourceString"

		for _ in range(self.getUserTypePointerLevel() + pointerLevelAdjust):
			parts.append("*")

		return "".join(parts)


	def getHeaderName(self, pointerLevelAdjust=0):
		return self.toString(pointerLevelAdjust=pointerLevelAdjust, templatesUseHeaderName=True, iKnowWhatIAmDoing=True)


	def getAppliedHeaderName(self, mainState: MainState, sourceGroup: Group, templateMappingTracker: TemplateMappingTracker, pointerLevelAdjust=0, useUsertypeOverride=False):
		return self._getAppliedNameInternal(mainState, sourceGroup, templateMappingTracker, pointerLevelAdjust=pointerLevelAdjust, useUsertypeOverride=useUsertypeOverride, templateTypeMode=TemplateTypeMode.HEADER)


	def getAppliedUserTypeName(self, mainState: MainState, sourceGroup: Group, templateMappingTracker: TemplateMappingTracker, useUsertypeOverride=False):
		return self._getAppliedNameInternal(mainState, sourceGroup, templateMappingTracker, useUsertypeOverride=useUsertypeOverride, noModifiers=True, templateTypeMode=TemplateTypeMode.HEADER)


	def toString(self, pointerLevelAdjust=0, useUsertypeOverride=False, templatesUseHeaderName=False, iKnowWhatIAmDoing=False) -> str:

		parts: list[str] = [self.getModifierStr()]

		if superRef := self.getSuperRef():
			parts.append(superRef.toString(useUsertypeOverride=useUsertypeOverride, templatesUseHeaderName=templatesUseHeaderName, iKnowWhatIAmDoing=iKnowWhatIAmDoing))
			parts.append("::")

		if useUsertypeOverride and self.group != None and self.group.overrideUsertypeSingleName != None:
			parts.append(self.group.overrideUsertypeSingleName)
		else:
			parts.append(self.getSingleName())

		if len(self.templateTypes) > 0:

			parts.append("<")

			if templatesUseHeaderName:
				for templateType in self.templateTypes:
					parts.append(templateType.getHeaderName())
					parts.append(",")
			else:
				for templateType in self.templateTypes:
					parts.append(templateType.toString(iKnowWhatIAmDoing=iKnowWhatIAmDoing))
					parts.append(",")

			parts.pop()
			parts.append(">")

		for _ in range(self.getUserTypePointerLevel() + (pointerLevelAdjust if not self.reference else pointerLevelAdjust - 1)):
			parts.append("*")

		if self.reference:
			parts.append("&")

		return "".join(parts)


	# TODO: This is a really bad way of doing this
	def sameTypeAs(self, other: TypeReference):
		return self.getHeaderName() == other.getHeaderName()



class PointerReference(TypeReference):

	def __init__(self):
		super().__init__()
		self.originalRef: TypeReference = None


	@staticmethod
	def create(mainState: MainState, originalRef: TypeReference):

		assert not isinstance(originalRef, PointerReference), "Wrapception: PointerReference"
		obj = PointerReference()
		obj.copyTrivialFields(originalRef)

		obj.originalRef = originalRef
		obj.changeReferencedGroup(mainState.getGroup("Pointer"))
		obj.setUserTypePointerLevel(mainState, originalRef.getUserTypePointerLevel())

		if originalRef.group:
			originalRef.group.inwardTypeRefs.addUnique(originalRef)

		return obj


	def shallowCopy(self, copyObj=None):
		copyObj = copyObj or PointerReference()
		super().shallowCopy(copyObj)
		copyObj.originalRef = len(copyObj.templateTypes) > 0 and copyObj.templateTypes[0] or self.originalRef.shallowCopy()
		return copyObj


	def getSuperRef(self):
		return self.originalRef.superRef


	def isGroupUsed(self, mainState: MainState):
		return self.originalRef.isGroupUsed(mainState)


	def isUnparameterized(self):
		return self.originalRef.isUnparameterized()


	def getGroup(self):
		return self.originalRef.group


	def getArrayParts(self):
		return self.originalRef.getArrayParts()


	def getName(self):
		return self.originalRef.getName()


	def setUserTypePointerLevel(self, mainState: MainState, newVal: int) -> None:
		super().setUserTypePointerLevel(mainState, newVal)
		if newVal == 0:
			self.originalRef.setUserTypePointerLevel(mainState, 0)
			if len(self.templateTypes) > 0:
				self.templateTypes.pop()
			if originalGroup := self.originalRef.group:
				self.changeReferencedGroup(originalGroup)
		else:
			self.originalRef.setUserTypePointerLevel(mainState, newVal - 1)
			if len(self.templateTypes) == 0:
				self.templateTypes.append(self.originalRef)
			self.changeReferencedGroup(mainState.getGroup("Pointer"))


	def getHeaderName(self, pointerLevelAdjust=0):
		if self.getUserTypePointerLevel() == 0:
			return f"{self.originalRef.getHeaderName(pointerLevelAdjust=pointerLevelAdjust)}"
		else:
			return f"{self.originalRef.getHeaderName(pointerLevelAdjust=pointerLevelAdjust + 1)}"


	def getAppliedHeaderName(self, mainState: MainState, sourceGroup: Group, templateMappingTracker: TemplateMappingTracker, pointerLevelAdjust=0, useUsertypeOverride=False):
		if self.getUserTypePointerLevel() == 0:
			return self.originalRef.getAppliedHeaderName(mainState, sourceGroup, templateMappingTracker, pointerLevelAdjust=pointerLevelAdjust, useUsertypeOverride=useUsertypeOverride)
		else:
			innerType = self.originalRef.checkReplaceTemplateType(mainState, sourceGroup, templateMappingTracker)
			return f"{innerType.getAppliedHeaderName(mainState, sourceGroup, templateMappingTracker, pointerLevelAdjust=pointerLevelAdjust + 1, useUsertypeOverride=useUsertypeOverride)}"


	def getAppliedUserTypeName(self, mainState: MainState, sourceGroup: Group, templateMappingTracker: TemplateMappingTracker, useUsertypeOverride=False):
		if self.getUserTypePointerLevel() == 0:
			return self.originalRef.getAppliedUserTypeName(mainState, sourceGroup, templateMappingTracker, useUsertypeOverride=useUsertypeOverride)
		else:
			innerType = self.originalRef.checkReplaceTemplateType(mainState, sourceGroup, templateMappingTracker)
			innerStr: str = None
			if innerType.getUserTypePointerLevel() == 0 and not innerType.isPrimitive():
				innerStr = innerType.getAppliedUserTypeName(mainState, sourceGroup, templateMappingTracker, useUsertypeOverride=useUsertypeOverride)
			else:
				innerStr = f"Pointer<{innerType.getAppliedHeaderName(mainState, sourceGroup, templateMappingTracker, useUsertypeOverride=useUsertypeOverride)}>"
			return innerStr


	def getTemplates(self, mainState: MainState, askingGroup: Group=None):
		if askingGroup.name == "Pointer":
			return self.templateTypes
		elif self.getUserTypePointerLevel() == 0:
			return self.originalRef.getTemplates(mainState)
		else:
			realRef = self.originalRef.shallowCopy()
			realRef.adjustUserTypePointerLevel(mainState, 1)
			return realRef.getTemplates(mainState)


	def getAllTypeReferences(self, mainState: MainState):
		parts = [self]
		if self.getUserTypePointerLevel() == 0:
			for v in self.originalRef.getAllTypeReferences(mainState):
				parts.append(v)
		else:
			realRef = self.originalRef.shallowCopy()
			realRef.adjustUserTypePointerLevel(mainState, 1)
			for v in realRef.getAllTypeReferences(mainState):
				parts.append(v)

		return parts


	def toString(self, pointerLevelAdjust=0, useUsertypeOverride=False, templatesUseHeaderName=False, iKnowWhatIAmDoing=False) -> str:
		assert iKnowWhatIAmDoing, "You don't know what you're doing!"
		effectivePointerAdj = pointerLevelAdjust if self.getUserTypePointerLevel() == 0 else pointerLevelAdjust + 1
		return self.originalRef.toString(pointerLevelAdjust=effectivePointerAdj, useUsertypeOverride=useUsertypeOverride, templatesUseHeaderName=templatesUseHeaderName, iKnowWhatIAmDoing=iKnowWhatIAmDoing)



class CharReferenceMode(Enum):
	PRIMITIVE_ONLY = 1
	USER_TYPE_ONLY = 2
	MORPHING       = 3


class CharReference(TypeReference):

	def __init__(self):
		super().__init__()
		self.mode: CharReferenceMode = None
		self.charPointerLevel: int = None


	@staticmethod
	def create(mainState: MainState, originalRef: TypeReference, mode: CharReferenceMode):

		obj = CharReference()
		obj.copyTrivialFields(originalRef)

		obj.mode = mode
		obj.charPointerLevel = 0
		if obj.mode in (CharReferenceMode.PRIMITIVE_ONLY, CharReferenceMode.USER_TYPE_ONLY):
			obj.changeReferencedGroup(originalRef.group)

		obj.setUserTypePointerLevel(mainState, originalRef.getUserTypePointerLevel())
		return obj


	def shallowCopy(self, copyObj=None):
		copyObj = copyObj or CharReference()
		super().shallowCopy(copyObj)
		copyObj.mode = self.mode
		copyObj.charPointerLevel = self.charPointerLevel
		return copyObj


	def setUserTypePointerLevel(self, mainState: MainState, newVal: int) -> None:
		if self.mode == CharReferenceMode.PRIMITIVE_ONLY:
			super().setUserTypePointerLevel(mainState, newVal)
			self.charPointerLevel = newVal
		elif self.mode == CharReferenceMode.USER_TYPE_ONLY:
			super().setUserTypePointerLevel(mainState, newVal)
			self.charPointerLevel = newVal + 1
		elif self.mode == CharReferenceMode.MORPHING:
			newVal = newVal if self.charPointerLevel != 1 else newVal + 1 
			self.charPointerLevel = newVal
			if newVal == 1:
				super().setUserTypePointerLevel(mainState, 0)
				self.changeReferencedGroup(mainState.getGroup(f"{'Const' if self.const else ''}CharString"))
			else:
				super().setUserTypePointerLevel(mainState, newVal)
				self.changeReferencedGroup(mainState.getGroup("char"))


	def getHeaderName(self, pointerLevelAdjust=0):
		if self.mode == CharReferenceMode.MORPHING:
			return f"{self.getModifierStr()}char{'*'*(self.charPointerLevel + pointerLevelAdjust)}"
		else:
			return f"{self.getModifierStr()}{self.group.name}{'*'*(self.getUserTypePointerLevel() + pointerLevelAdjust)}"


	def getAppliedHeaderName(self, mainState: MainState, sourceGroup: Group, templateMappingTracker: TemplateMappingTracker, pointerLevelAdjust=0, useUsertypeOverride=False):
		return self.getHeaderName(pointerLevelAdjust=pointerLevelAdjust)


	def getAppliedUserTypeName(self, mainState: MainState, sourceGroup: Group, templateMappingTracker: TemplateMappingTracker, useUsertypeOverride=False):
		charLevel = self.charPointerLevel
		if charLevel == 0:
			return f"char"
		elif charLevel == 1:
			return f"{'Const' if self.const else ''}CharString"
		elif self.mode == CharReferenceMode.USER_TYPE_ONLY and charLevel == 2:
			return self.group.name
		else:
			return f"Pointer<char{'*'*(charLevel - 1)}>"



class VoidPointerReference(TypeReference):

	@staticmethod
	def create(mainState: MainState, originalRef: TypeReference):

		obj = VoidPointerReference()
		obj.copyTrivialFields(originalRef)

		obj.setUserTypePointerLevel(mainState, originalRef.getUserTypePointerLevel())
		return obj


	def shallowCopy(self, copyObj=None):
		copyObj = copyObj or VoidPointerReference()
		super().shallowCopy(copyObj)
		return copyObj


	def setUserTypePointerLevel(self, mainState: MainState, newVal: int) -> None:
		super().setUserTypePointerLevel(mainState, newVal)
		if newVal > 1:
			self.changeReferencedGroup(mainState.getGroup("void"))
		elif newVal == 1:
			self.changeReferencedGroup(mainState.getGroup("VoidPointer"))


	def getHeaderName(self, pointerLevelAdjust=0):
		return f"void{'*'*(self.getUserTypePointerLevel() + pointerLevelAdjust)}"


	def getAppliedHeaderName(self, mainState: MainState, sourceGroup: Group, templateMappingTracker: TemplateMappingTracker, pointerLevelAdjust=0, useUsertypeOverride=False):
		return self.getHeaderName(pointerLevelAdjust=pointerLevelAdjust)


	def getAppliedUserTypeName(self, mainState: MainState, sourceGroup: Group, templateMappingTracker: TemplateMappingTracker, useUsertypeOverride=False):
		if (pointerLevel := self.getUserTypePointerLevel()) == 1:
			return "VoidPointer"
		else:
			return f"Pointer<void{'*'*(pointerLevel - 1)}>"


	def toString(self, pointerLevelAdjust=0, useUsertypeOverride=False, templatesUseHeaderName=False, iKnowWhatIAmDoing=False) -> str:
		return self.getHeaderName(pointerLevelAdjust)


def templateUseHasGeneric(currentTemplate: tuple[TypeReference]):
	if currentTemplate != None:
		for templateRef in currentTemplate:
			if templateRef.isGenericTemplate():
				return True
	return False


class FunctionImplementationParameter:

	def __init__(self):
		self.type: TypeReference = None
		self.name: str = None


class FunctionImplementation:

	def __init__(self):
		self.isStatic = None
		self.returnType: TypeReference = None
		self.callingConvention: str = None
		self.name: str = None
		self.parameters: list[FunctionImplementationParameter] = []
		self.body: list[str] = []
		self.isInternal = None
		self.isConstructor: bool = False
		self.customReturnCount: int = None
		self.noBinding: bool = False
		self.group = None
		self.virtual: bool = False


	def getAllTypeReferences(self, mainState: MainState):
		
		refs = []

		if self.returnType != None:
			refs.append(self.returnType)

		for param in self.parameters:
			for paramRef in param.type.getAllTypeReferences(mainState):
				refs.append(paramRef)

		return refs


	def toString(self, indent=""):

		parts: list[str] = [indent, "\t"]

		if self.virtual:
			parts.append("virtual ")

		if self.isStatic:
			parts.append("static ")

		if not self.isConstructor:
			parts.append(self.returnType.getHeaderName())
			parts.append(" ")
			parts.append(self.name)
		else:
			parts.append(self.group.singleName)

		parts.append("(")

		if self.customReturnCount:
			parts.append("lua_State* L")
			parts.append(", ")

		for parameter in self.parameters:
			parts.append(parameter.type.getHeaderName())
			parts.append(" ")
			parts.append(parameter.name)
			parts.append(", ")

		if self.customReturnCount or len(self.parameters) > 0:
			parts.pop()

		parts.append(")\n")

		if not self.isInternal:
			for bodyLine in self.body:
				parts.append(indent)
				parts.append(bodyLine)
				parts.append("\n")
		else:
			parts.append(f"{indent}")
			parts.append("\t{\n")
			parts.append(f"{indent}\t\t")

			if not self.returnType.isVoid():
				parts.append("return ")

			parts.append(f"{indent}p_{self.group.name}_{self.name}(")

			if not self.isStatic:
				parts.append("this")
				parts.append(", ")

			for parameter in self.parameters:
				parts.append(parameter.name)
				parts.append(", ")

			if not self.isStatic or len(self.parameters) > 0:
				del parts[-1]

			parts.append(");\n")
			parts.append(f"{indent}")
			parts.append("\t}\n")

		return "".join(parts)


class CheckLinesState:

	def __init__(self):
		self.bracketLevel = 0
		self.hitFirstBracket = False
		self.functionImplementationBody: list[str] = []
		self.currentFunctionImplementation = None


class CheckUnnamedStructsState:

	def __init__(self):
		self.groupType: str = None
		self.preBracketLevel: int = None
		self.bracketLevel = 0
		self.lines: list[str] = []


variablePatternGlobal = "^((?:(?:nobinding|static)\s+)*)(?!class|enum|struct|typedef|union)(?:__unaligned\s+){0,1}(?:__declspec\(align\(\d+\)\)\s+){0,1}([, _a-zA-Z0-9*:<>\-$]+?)\s*([_a-zA-Z0-9~]+)((?:\[[_a-zA-Z0-9+]+\])+)*(?:\s*:\s*([^\s>]+?)){0,1}(?:\s|(?:\/\*(?:(?!\*\/).)*\*\/))*;(?:\s|(?:\/\/.*)|(?:\/\*(?:(?!\*\/).)*\*\/))*$"
variablePatternLocal = "^\t((?:(?:nobinding|static)\s+)*)(?:__unaligned\s+){0,1}(?:__declspec\(align\(\d+\)\)\s+){0,1}([, _a-zA-Z0-9*:<>\-$]+?)\s*([_a-zA-Z0-9~]+)((?:\[[_a-zA-Z0-9+]+\])+)*(?:\s*:\s*([^\s>]+?)){0,1}(?:\s|(?:\/\*(?:(?!\*\/).)*\*\/))*;(?:\s|(?:\/\/.*)|(?:\/\*(?:(?!\*\/).)*\*\/))*$"	

def processCommonGroupLines(mainState: MainState, state: CheckLinesState, line: str, group: Group):

	functionImplementationMatch: Match = re.match("^\s*(?!typedef)(\$nobinding\s+){0,1}(?:(static)\s+){0,1}([, _a-zA-Z0-9*&:<>$]+?)\s+(?:(__cdecl|__stdcall|__thiscall)\s+){0,1}([_a-zA-Z0-9\[\]]+)\s*\(\s*((?:[, _a-zA-Z0-9*:<>]+?\s+[_a-zA-Z0-9]+(?:\s*,(?!\s*\))){0,1})*)\s*\)(?:(;)){0,1}$", line)
	if functionImplementationMatch:

		state.currentFunctionImplementation = FunctionImplementation()
		state.currentFunctionImplementation.group = group
		state.currentFunctionImplementation.noBinding = functionImplementationMatch.group(1) != None
		state.currentFunctionImplementation.isStatic = functionImplementationMatch.group(2) != None

		retTypeStr = functionImplementationMatch.group(3)

		if customReturnMatch := re.match("^\$custom_return_(\d+)$", retTypeStr):
			state.currentFunctionImplementation.customReturnCount = int(customReturnMatch.group(1))
			retTypeStr = "void"
		elif retTypeStr.startswith("$constructor"):
			state.currentFunctionImplementation.isConstructor = True
			if retTypeStr == "$constructor_copy":
				group.copyConstructor = state.currentFunctionImplementation
			else:
				assert retTypeStr == "$constructor", "Bad bindings directive"

			retTypeStr = "void"

		state.currentFunctionImplementation.returnType = defineTypeRef(mainState, group, retTypeStr, TypeRefSourceType.FUNCTION)
		state.currentFunctionImplementation.callingConvention = functionImplementationMatch.group(4)

		state.currentFunctionImplementation.name = functionImplementationMatch.group(5)

		parameterStr = functionImplementationMatch.group(6)
		if parameterStr != None and parameterStr != "":
			for commaSplitPart in splitKeepBrackets(parameterStr, [","]):

				spaceSplit = splitKeepBrackets(commaSplitPart, [" "])
				spaceSplitLen = len(spaceSplit)
				parts = []
				for i in range(0, spaceSplitLen - 1):
					parts.append(spaceSplit[i])
					parts.append(" ")

				if spaceSplitLen > 0:
					parts.pop()

				typeStr = "".join(parts)
				funcParameter = FunctionImplementationParameter()
				funcParameter.type = defineTypeRef(mainState, group, typeStr, TypeRefSourceType.FUNCTION)
				funcParameter.name = spaceSplit[-1]

				state.currentFunctionImplementation.parameters.append(funcParameter)

		state.currentFunctionImplementation.isInternal = functionImplementationMatch.group(7) != None


	if state.currentFunctionImplementation != None:

		if state.currentFunctionImplementation.isInternal:
			group.functionImplementations.append(state.currentFunctionImplementation)
			state.currentFunctionImplementation = None
		else:

			state.bracketLevel += line.count("{")
			state.hitFirstBracket = state.hitFirstBracket or state.bracketLevel > 0
			state.bracketLevel -= line.count("}")

			if state.hitFirstBracket:

				state.functionImplementationBody.append(line)

				if state.bracketLevel == 0:

					state.currentFunctionImplementation.body = state.functionImplementationBody
					group.functionImplementations.append(state.currentFunctionImplementation)

					state.hitFirstBracket = False
					state.functionImplementationBody = []
					state.currentFunctionImplementation = None
	

	variableMatch: Match = re.match(variablePatternGlobal if group == globalGroup else variablePatternLocal, line)
	if variableMatch != None:

		variableField = VariableField()

		if keywordMatch := variableMatch.group(1):
			for keyword in keywordMatch.strip().split(" "):
				if keyword == "nobinding":
					assert not variableField.nobinding, "nobinding already defined"
					variableField.nobinding = True
				elif keyword == "static":
					assert not variableField.static, "static already defined"
					variableField.static = True

		variableField.variableType = defineTypeRef(mainState, group, variableMatch.group(2), TypeRefSourceType.VARIABLE, variableMatch.group(4))
		variableField.variableType.bitFieldPart = variableMatch.group(5)

		variableField.variableName = variableMatch.group(3)

		group.addField(variableField)



class UniqueTemplateUsesByHeaderName(UniqueList[tuple[TypeReference]]):

	def pHash(use: tuple[TypeReference]):
		toReturn = 0
		for ref in use:
			toReturn += 3 * hash(ref.getHeaderName())
		return toReturn

	def pEq(a: tuple[TypeReference], b: tuple[TypeReference]):
		if len(a) != len(b):
			return False
		for i in range(len(a)):
			if a[i].getHeaderName() != b[i].getHeaderName():
				return False
		return True

	def __init__(self) -> None:
		super().__init__(pHash=UniqueTemplateUsesByHeaderName.pHash, pEq=UniqueTemplateUsesByHeaderName.pEq)



class Group:

	def __init__(self):

		self.template: str = None  # String filled with the template definition as found in the input file. Example: template<class T, int size>
		self.groupType: str = None # "struct" / "class" / "enum" / "union" / (possibly "undefined").

		self.name: str = None # String filled with the name of the group, as defined in the input file. Examples:
							  # "CPtrList" / "CPtrList::CNode"

		self.singleName: str = None # String filled with the name of the group. If group is a sub-group, contains only the last group name. Example:
									# self.name = "CPtrList::CNode" => self.singleName = "CNode"

		self.defined: bool = False  # True if the group was defined in a header file
		self.lines: list[str] = []  # List of all lines in the group's definition.
		self.linesProcessed = False # True if the group's lines have already been processed.

		self.ignoreHeader: bool = False        # If True the group's header won't be written to the .h file. The group's bindings will still be written.
		self.overrideUsertypeSingleName = None # Used to override normal singleName when writing Lua bindings,
		                                       # (for instances when the engine already uses the normal name).

		self.dependsOn: dict[str,bool] = {}      # Map of group names which this group needs to be defined in order to be valid.
		self.lightDependsOn: dict[str,bool] = {} # Map of group names which this group needs to be declared in order to be valid.
		
		self.listIndex: int = None      # Position in MainState groups list.
		self.sortedPosition: int = None # Position in MainState filteredGroups list.

		self.templateTypeNames: list[str] = []               # List of template names that appear in the group's definition.
		self.templateTypeNameMapping: dict[str,Group] = {}   # Map of <template name => Group> for the group (or any super group) template names.
		self.templateUses = UniqueTemplateUsesByHeaderName() # List of all TypeReferences to the group which use templates.

		self.superGroup: Group = None                    # Group that this group immediately resides in.
		self.subGroups: UniqueList[Group] = UniqueList() # Groups that this group immediately contains.

		self.isDirectlyWanted: bool = False # True if the group was listed in -wantedFile.
		self.isSoftWanted: bool = False
		
		self.fieldsMap: dict[str, Field] = {}                           # Map of fields the group immediately contains.
		self.fields: list[Field] = []                                   # List of fields the group immediately contains.

		self.extends: list[TypeReference] = []                          # List of TypeReferences the group extends.
		self.enumTuples: list[tuple[str,int]] = []                      # List of enum values, (in the case of groupType="enum").
		self.functionImplementations: list[FunctionImplementation] = [] # List of function implementations the group immediately contains.

		self.inwardTypeRefs: UniqueList[TypeReference] = UniqueList() # List of all TypeReferences to the group.
		self.uniqueUseRepresentations: dict[str, TypeReference] = {}  # List of TypeReferences that each represent a unique use of the group.

		self.copyConstructor: FunctionImplementation = None # Specially-defined copy constructor implementation
		self.pack: int = None                               # Specially-defined struct packing
		self.vGroup: Group = None
		self.vFuncs: list[FunctionField] = []


	def isSubgroup(self):

		"""
		True/False depending on whether the group is a sub-group. Examples:\n
		self.name = "CPtrList" => self.isSubgroup() -> False\n
		self.name = "CPtrList::CNode" => self.isSubgroup() -> True
		"""

		return self.superGroup != None


	def isSubgroupOf(self, group: Group):
		superGroup = self.superGroup
		while superGroup:
			if superGroup is group:
				return True
			superGroup = superGroup.superGroup
		return False


	def isPrimitive(self):
		return self.name in primitives


	def hasDefinedTop(self):
		topGroup = self
		while temp := topGroup.superGroup:
			topGroup = temp

		return topGroup.groupType != "undefined"


	def hasField(self, fieldName):
		return self.fieldsMap.get(fieldName) != None


	def retypeField(self, mainState: MainState, fieldName: str, newTypeStr: str):

		field = self.fieldsMap[fieldName]
		assert field.type == FieldType.VARIABLE, "Unhandled field.type in Group.retypeField()"

		varField: VariableField = field

		for ref in varField.variableType.getAllTypeReferences(mainState):
			ref.removeFromGroupRefs()

		varField.variableType = defineTypeRef(mainState, self, newTypeStr, TypeRefSourceType.VARIABLE)


	def removeField(self, mainState: MainState, fieldName: str):

		field = self.fieldsMap[fieldName]

		for ref in field.getAllTypeReferences(mainState):
			ref.removeFromGroupRefs()

		del self.fieldsMap[fieldName]
		del self.fields[field.listI]
		for i in range(field.listI, len(self.fields)):
			self.fields[i].listI -= 1


	def addField(self, field: Field, insertI: int=None):

		name: str = None

		assert field.type in (FieldType.VARIABLE, FieldType.FUNCTION), "Unhandled field.type in Group.addField()"
		if field.type == FieldType.VARIABLE:
			name = field.variableName
		elif field.type == FieldType.FUNCTION:
			name = field.functionName

		self.fieldsMap[name] = field

		if insertI != None:
			field.listI = insertI
			self.fields.insert(insertI, field)
			for i in range(insertI + 1, len(self.fields)):
				self.fields[i].listI += 1 
		else:
			field.listI = len(self.fields)
			self.fields.append(field)


	def addVariableField(self, mainState: MainState, fieldName: str, typeStr: str, insertI: int=None):
		field = VariableField()
		field.variableName = fieldName
		field.variableType = defineTypeRef(mainState, self, typeStr, TypeRefSourceType.VARIABLE)
		self.addField(field, insertI=insertI)


	def processLinesFillTypes(self, mainState: MainState):

		"""
		Fills: self.templateTypeNames, self.extends, self.fields, and self.enumTuples\n
		and calls defineTypeRef() to define any relevant TypeReferences in the process. 
		"""

		self.linesProcessed = True

		if self.template != None:
			templateInner = self.template[self.template.find("<")+1:self.template.find(">")]
			for templateType in templateInner.split(","):
				templateTypeSplit = splitMulti(templateType, [" "])
				self.templateTypeNames.append(templateTypeSplit[1])

		state: CheckLinesState = CheckLinesState()
		unnamedStructsState = CheckUnnamedStructsState()

		for line in self.lines:

			checkUnnamedStructs(mainState, unnamedStructsState, self, line)

			# Define extends types
			declMatch: Match = re.match("^(?:\$pack_(\d+)\s+){0,1}(?:const\s+){0,1}(?:struct|class|enum|union)\s+(?:\/\*VFT\*\/\s+){0,1}(?:__cppobj\s+){0,1}(?:__unaligned\s+){0,1}(?:__declspec\(align\(\d+\)\)\s+){0,1}[^;]*?(?:\s+\:\s+(.*?)){0,1}\s*$", line)
			if declMatch != None:
				if packGroup := declMatch.group(1):
					self.pack = int(packGroup)
				extendsStr = declMatch.group(2)
				if extendsStr != None:
					for extendsType in splitKeepBrackets(extendsStr, [","]):
						self.extends.append(defineTypeRef(mainState, self, extendsType, TypeRefSourceType.VARIABLE))

			# Define function fields
			functionVariableMatch: Match = re.match("^\t([, _a-zA-Z0-9*:<>]+?)\s*\(\s*(?:([_a-zA-Z]+?)\s*){0,1}\*\s*([_a-zA-Z0-9~]+)\s*\)\s*\((?:\s*([, _a-zA-Z0-9*:<>]+?)\s+\*\s*this(?:\s*,\s+){0,1}){0,1}(?:([, _a-zA-Z0-9*:<>]+?)\s+\*\s*result(?:\s*,\s+){0,1}){0,1}\s*((?:[ _a-zA-Z0-9*:<>][, _a-zA-Z0-9*:<>]*?){0,1}(?:\.\.\.(?=\s*\))){0,1}){0,1}\s*\)\;$", line)
			if functionVariableMatch != None:

				functionField = FunctionField()
				functionField.returnType = defineTypeRef(mainState, self, functionVariableMatch.group(1), TypeRefSourceType.FUNCTION)
				functionField.callConvention = functionVariableMatch.group(2)
				functionField.functionName = functionVariableMatch.group(3)

				if functionField.functionName.startswith("~"):
					functionField.functionName = functionField.functionName[1:] + "_Destructor"

				if thisTypeNoPtrMatch := functionVariableMatch.group(4):
					functionField.thisType = defineTypeRef(mainState, self, f"{thisTypeNoPtrMatch}*", TypeRefSourceType.FUNCTION)

				if resultTypeNoPtrMatch := functionVariableMatch.group(5):
					functionField.resultType = defineTypeRef(mainState, self, f"{resultTypeNoPtrMatch}*", TypeRefSourceType.FUNCTION)

				parameterStr = functionVariableMatch.group(6)
				if parameterStr != None and parameterStr != "":
					for paramType in splitKeepBrackets(parameterStr, [","]):
						functionField.parameterTypes.append(defineTypeRef(mainState, self, paramType, TypeRefSourceType.FUNCTION))

				self.addField(functionField)

			processCommonGroupLines(mainState, state, line, self)

			# Define certain enum values in group.enumTuples, else print to console
			if self.groupType == "enum":
				enumLineMatch: Match = re.match("^\t([_a-zA-Z0-9]+)\s*=\s*(.+?)\s*,\s*$", line)
				if enumLineMatch:
					firstExtendName = self.extends[0].getName()
					if firstExtendName == "__int8":
						value = int(enumLineMatch.group(2), 16)
						if value & 0x80 != 0: value = -1 - (0xFF - value)
						self.enumTuples.append((enumLineMatch.group(1), value))
					elif firstExtendName == "__int32":
						value = int(enumLineMatch.group(2), 16)
						if value & 0x80000000 != 0: value = -1 - (0xFFFFFFFF - value)
						self.enumTuples.append((enumLineMatch.group(1), value))
					elif firstExtendName == "__int64":
						value = int(enumLineMatch.group(2), 16)
						if value & 0x8000000000000000 != 0: value = -1 - (0xFFFFFFFFFFFFFFFF - value)
						self.enumTuples.append((enumLineMatch.group(1), value))
					else:
						print(f"[!] Unknown enum extend type: \"{firstExtendName}")


	def mapTemplateTypeNames(self):

		"""
		Fills:
			templateTypeNameMapping
			
		Maps the template names that appear in this Group's inheritance hierarchy to their originating Group.
		"""

		def process(group: Group):
			if group.superGroup: process(group.superGroup)
			for templateTypeName in group.templateTypeNames:
				self.templateTypeNameMapping[templateTypeName] = group

		process(self)


	def addTemplateUse(self, useEntry: tuple[TypeReference]):
		self.templateUses.addUnique(useEntry)


	def scanInwardTypeRefs(self, mainState: MainState):

		"""
		Fills:
			templateUses \n
			uniqueUseRepresentations

		Scans inwardTypeRefs for uses of this Group's template definition and adds tuples representing these
		template uses to templateUses, (duplicate entries are discarded).\n\n
		Also fills uniqueUseRepresentations, which is a series of TypeRefs representing every unique way this group has been used.
		"""

		for typeRef in self.inwardTypeRefs:

			# The Group that generated this TypeReference must be in view
			if not typeRef.getGroup() or not typeRef.sourceGroup or not typeRef.sourceGroup.isUsed(mainState) or typeRef.isUnparameterized():
				continue

			templates = typeRef.getTemplates(mainState, askingGroup=self)

			if len(templates) > 0:

				# All Groups used as templateTypes must be in view and parameterized
				needContinue = False
				for templateRef in templates:
					if not templateRef.isGroupUsed(mainState) or templateRef.isUnparameterized():
						needContinue = True
						break

				if needContinue:
					continue

				self.addTemplateUse(tuple(templates))

			self.uniqueUseRepresentations[typeRef.getHeaderName()] = typeRef


	def getAllTypeReferences(self, mainState: MainState):

		parts: list[TypeReference] = []

		myself = TypeReference()
		myself.name = self.name
		myself.group = self
		parts.append(myself)

		for subgroup in self.subGroups:
			for ref in subgroup.getAllTypeReferences(mainState):
				parts.append(ref)

		for extendRef in self.extends:
			for ref in extendRef.getAllTypeReferences(mainState):
				parts.append(ref)

		for field in self.fields:
			for ref in field.getAllTypeReferences(mainState):
				parts.append(ref)

		for funcImp in self.functionImplementations:
			for ref in funcImp.getAllTypeReferences(mainState):
				parts.append(ref)

		return parts


	def mapDependsOn(self, mainState: MainState):

		"""
		Fills:
			dependsOn \n
			lightDependsOn

		Attempts to derive type dependencies and light dependencies (those that need forward declarations).
		"""

		for typeRef in self.getAllTypeReferences(mainState):

			if typeRef.isGenericTemplate() or (typeRef.group and typeRef.group.isSubgroupOf(self)):
				continue

			assert (pointerLevel := typeRef.getUserTypePointerLevel()) >= 0, "Invalid typeRef.getUserTypePointerLevel() in Group.mapDependsOn()"

			typeName = typeRef.getName()
			if pointerLevel == 0:
				self.dependsOn[typeName] = True
			elif pointerLevel > 0:
				self.lightDependsOn[typeName] = True


	def broadcastName(self: Group, mainState: MainState):
		for subGroup in self.subGroups:
			subGroup.updateName(mainState)


	def updateName(self, mainState: MainState):
		newName = f"{self.superGroup.name}::{self.singleName}" if self.superGroup else self.singleName
		mainState.updateGroupNameMapping(self, newName)
		self.broadcastName(mainState)


	def updateSingleName(self, mainState: MainState, newSingleName: str):
		self.singleName = newSingleName
		self.updateName(mainState)


	def updateNesting(self: Group, mainState: MainState):

		# Not using updateSingleName() as I'm in the middle of building the hierarchy.

		# broadcastName() needs to be called manually after this function
		# if the hierarchy was changed after it was already built.

		# If changing a group's location, the change MUST be registered
		# with updateGroupNameMapping() before calling this function.

		def getOrCreateGroup(newSuperGroup: Group, name: str, singleName: str):

			toReturn: Group = None
			if existingGroup := mainState.tryGetGroup(name):

				if existingSuperGroup := existingGroup.superGroup:
					existingSuperGroup.subGroups.removeUnique(existingGroup)

				existingGroup.singleName = singleName
				toReturn = existingGroup

			else:
				newGroup = Group()
				newGroup.groupType = "undefined"
				newGroup.name = name
				newGroup.singleName = singleName
				mainState.addGroup(newGroup)
				toReturn = newGroup

			toReturn.superGroup = newSuperGroup
			return toReturn


		split = splitKeepBrackets(self.name, ["::"])
		if len(split) <= 1:
			# Not a nested struct
			return

		lastGroup = getOrCreateGroup(None, split[0], split[0])
		for namePartI in range(1, len(split)):
			subGroup = getOrCreateGroup(lastGroup, f"{lastGroup.name}::{split[namePartI]}", split[namePartI])
			lastGroup.subGroups.addUnique(subGroup)
			lastGroup = subGroup


	def rebuildInwardTypeRefs(self, mainState: MainState):
		# Rebuild reference chains
		# TODO: Handle templates?
		parts = splitKeepBrackets(stripUnnecessaryTypeSpaces(self.name), ["::"])
		partsLen = len(parts)

		if partsLen > 1:

			for inRef in list(self.inwardTypeRefs):

				topRef = inRef
				while topRef.superRef:
					topRef = topRef.superRef

				lastRef: TypeReference = defineTypeRefPart(mainState, None, topRef.sourceGroup, parts[0], TypeRefSourceType.VARIABLE)
				for i in range(1, partsLen - 1):
					lastRef = defineTypeRefPart(mainState, lastRef, lastRef.group, parts[i], TypeRefSourceType.VARIABLE)

				inRef.sourceGroup = lastRef.group
				lastRef.subRef = inRef
				inRef.superRef = lastRef


	def relocate(self: Group, mainState: MainState, newStructPath):
		mainState.updateGroupNameMapping(self, newStructPath)
		self.updateNesting(mainState)
		self.broadcastName(mainState)
		self.rebuildInwardTypeRefs(mainState)


	def getAppliedName(self, mainState: MainState, templateMappingTracker: TemplateMappingTracker, useUsertypeOverride=False, noTemplate=False, singleName=False, templateTypeMode: TemplateTypeMode=None):

		"""
		Given a Group in which the caller wants to express an arbritary series of template uses, returns a
		string representation of the current Group name as if its template types were filled with the information
		held by templateMappingTracker.
		"""

		assert templateTypeMode, "templateTypeMode must be defined in Group.getAppliedName()!"

		groupNameParts = []

		if not singleName and self.superGroup:
			groupNameParts.append(self.superGroup.getAppliedName(mainState, templateMappingTracker, templateTypeMode=templateTypeMode))
			groupNameParts.append("::")

		groupNameParts.append(self.overrideUsertypeSingleName if useUsertypeOverride and self.overrideUsertypeSingleName != None else self.singleName)

		if not noTemplate and templateMappingTracker != None and (v := templateMappingTracker.getMapping(self.name)) != None:

			groupNameParts.append("<")

			if templateTypeMode == TemplateTypeMode.USER_TYPE:
				for typeRef in v:
					groupNameParts.append(typeRef.checkReplaceTemplateType(mainState, self, templateMappingTracker).getAppliedUserTypeName(mainState, self, templateMappingTracker, useUsertypeOverride=useUsertypeOverride))
					groupNameParts.append(",")
			elif templateTypeMode == TemplateTypeMode.HEADER:
				for typeRef in v:
					groupNameParts.append(typeRef.checkReplaceTemplateType(mainState, self, templateMappingTracker).getAppliedHeaderName(mainState, self, templateMappingTracker, useUsertypeOverride=useUsertypeOverride))
					groupNameParts.append(",")

			groupNameParts.pop()
			groupNameParts.append(">")

		return "".join(groupNameParts)


	def checkForVGroup(self, mainState: MainState) -> None:

		"""
		Fills:
			vGroup
		
		Fills vGroup and removes __vftable field if present.
		"""

		vtblStruct = mainState.tryGetGroup(f"{self.name}_vtbl")
		if vtblStruct == None:
			return

		self.vGroup = vtblStruct
		vtblStruct.relocate(mainState, f"{self.name}::vtbl")

		if self.hasField("__vftable"):
			self.removeField(mainState, "__vftable")

		seenFuncNames: dict[str,int] = {}
		for field in vtblStruct.fields:

			if field.type != FieldType.FUNCTION:
				#print(f"vtblStruct {vtblStruct.name} has non-function field: {field.toString(mainState)}, breaking!")
				break

			functionField: FunctionField = field

			# Rename clashing function names in vftables
			# These are overloaded functions, but they can't
			# have the same name in a struct.
			seenCount = seenFuncNames.get(functionField.functionName, 0) + 1
			seenFuncNames[functionField.functionName] = seenCount
			if seenCount > 1:
				functionField.functionName += f"_{seenCount}"

			thisType = functionField.thisType
			if thisType and thisType.getGroup() != self:
				continue

			impl: FunctionImplementation = functionField.toImplementation(self)
			impl.name = f"virtual_{functionField.functionName}"

			impl.body = ["\t{"]
			
			if not impl.returnType.isVoid():
				impl.body.append(f"\t\treturn *({impl.returnType.getHeaderName()}*)nullptr;")

			impl.body.append("\t}")

			impl.virtual = True
			self.functionImplementations.append(impl)


	def writeHeader(self, mainState, internalPointersOut, internalPointersListOut: list[tuple[str,str]], headerType: HeaderType, indent="") -> str:

		parts = [indent]

		def writeGroupInternalFunctionPointers(group: Group):

			isNormal: bool = group != globalGroup
			wroteSomething = False

			for functionImp in group.functionImplementations:

				if functionImp.isInternal:

					identifier1: str = f"{group.name}_{functionImp.name}" if isNormal else functionImp.name
					identifier2: str = f"{group.name}::{functionImp.name}" if isNormal else functionImp.name

					bindingPtrTypeName = f"type_{identifier1}"
					conventionStr: str = f"{functionImp.callingConvention} " if functionImp.callingConvention != None else ""
					parts.append(f"typedef {functionImp.returnType.getHeaderName()} ({conventionStr}*{bindingPtrTypeName})(")

					if isNormal and not functionImp.isStatic:
						parts.append(f"{group.name}* pThis")
						parts.append(", ")

					for param in functionImp.parameters:
						parts.append(f"{param.type.getHeaderName()} {param.name}")
						parts.append(", ")

					if (isNormal and not functionImp.isStatic) or len(functionImp.parameters) > 0:
						del parts[-1]

					parts.append(");\n")
					internalPointersOut.write(f"{bindingPtrTypeName} p_{identifier1};\n")
					internalPointersListOut.append((f"{identifier2}", f"p_{identifier1}"))
					parts.append(f"{indent}extern {bindingPtrTypeName} p_{identifier1};")
					parts.append("\n\n")
					wroteSomething = True

			if isNormal:
				for field in group.fields:
					if field.type == FieldType.VARIABLE:
						varField: VariableField = field
						if varField.static:
							varNameP = f"{self.name}::p_{varField.variableName}"
							internalPointersOut.write(f"{varField.variableType.getHeaderName()}* {varNameP};\n")
							internalPointersListOut.append((f"{self.name}::{varField.variableName}", varNameP))
			else:
				for field in group.fields:
					if field.type == FieldType.VARIABLE:
						varField: VariableField = field
						varStr = f"{varField.variableType.getHeaderName(pointerLevelAdjust=1)} p_{varField.variableName};"
						internalPointersOut.write(f"{varStr}\n")
						internalPointersListOut.append((varField.variableName, f"p_{varField.variableName}"))
						parts.append(f"extern {varStr}")
						parts.append("\n")
						wroteSomething = True
					else:
						print("BAD FIELD TYPE")


			for subGroup in group.subGroups:
				if writeGroupInternalFunctionPointers(subGroup):
					wroteSomething = True

			return wroteSomething


		wroteSomething = False
		if not self.isSubgroup():
			wroteSomething = writeGroupInternalFunctionPointers(self)

		isNormal: bool = self != globalGroup

		if isNormal:

			if self.pack:
				parts.append("#pragma pack(push, ")
				parts.append(str(self.pack))
				parts.append(")\n")

			if headerType == HeaderType.NORMAL and self.template != None:
				parts.append(self.template)
				parts.append("\n")

			if self.groupType == "undefined":
				parts.append("struct")
			elif self.groupType == "enum":
				parts.append("enum class")
			else:
				parts.append(self.groupType)

			parts.append(" ")
			parts.append(self.singleName if self.singleName else self.name)

			if len(self.extends) > 0:

				parts.append(" : ")

				for extendsType in self.extends:
					parts.append(extendsType.getHeaderName())
					parts.append(", ")

				parts.pop()

			parts.append("\n")
			parts.append(indent)
			parts.append("{\n")

			nextIndent = indent + "\t"

			if headerType == HeaderType.CLEANED and self.template != None:
				parts.append(nextIndent)
				parts.append("TOLUA_TEMPLATE_BIND(")

				defNames = self.templateTypeNames[self.name]
				for defName in defNames:
					parts.append(defName)
					parts.append(" ")

				parts.pop()
				parts.append(",")

				for templateUse in self.templateUses:

					for useType in templateUse:
						parts.append(useType.toString())
						parts.append(" ")

					parts.pop()
					parts.append(",")

				parts.pop()
				parts.append(")\n")

			wroteSomethingBeforeFuncImps = False

			for subgroup in self.subGroups:
				if not subgroup.isUsed(mainState): continue
				parts.append(subgroup.writeHeader(mainState, internalPointersOut, internalPointersListOut, headerType, nextIndent))
				parts.append("\n\n")
				wroteSomethingBeforeFuncImps = True

			for enumTuple in self.enumTuples:
				parts.append(nextIndent)
				parts.append(enumTuple[0])
				parts.append(" = ")
				parts.append(str(enumTuple[1]))
				parts.append(",\n")
				wroteSomethingBeforeFuncImps = True

			for field in self.fields:
				parts.append(field.toString(mainState, nextIndent))
				parts.append("\n")
				wroteSomethingBeforeFuncImps = True

			if wroteSomethingBeforeFuncImps and len(self.functionImplementations) > 0:
				parts.append("\n")

		for functionImplementation in self.functionImplementations:
			if isNormal or not functionImplementation.isInternal:
				parts.append(functionImplementation.toString(indent))
				parts.append("\n")
				wroteSomething = True

		if wroteSomething:
			parts.pop()

		if isNormal:
			parts.append(indent)
			parts.append("};")
			if self.pack:
				parts.append("\n#pragma pack(pop)")

		return "".join(parts)


	def isUsed(self, mainState: MainState, dontCheckSuper=False, processed: set[Group]=None):

		processed = processed or set()

		if self in processed:
			return False

		processed.add(self)

		# If I'm not in the filtered list or my top-level group wasn't in a header file
		# then I'm definitely not going to be outputted.
		if (not mainState.filteredGroups.containsUnique(self)
			or (self.name != "void" and not self.isPrimitive() and not self.hasDefinedTop())
		):
			return False

		# If I was directly requested in wanted_types.txt I'll be outputted (top level structs).
		if self.isDirectlyWanted:
			return True

		# Check all inward type refs to see if there's a reference to me that's in-view.
		for inRef in self.inwardTypeRefs:
			if inRef.sourceGroup and inRef.sourceGroup.isUsed(mainState, processed=processed):
				return True

		# If one of my subgroups is used I have to be present for output.
		for subGroup in self.subGroups:
			if subGroup.isUsed(mainState, dontCheckSuper=True, processed=processed):
				return True

		# Check if I am requested when my supergroup is being used, (isSoftWanted).
		return not dontCheckSuper and self.isSoftWanted and self.superGroup and self.superGroup.isUsed(mainState, dontCheckSuper=True, processed=processed)



def checkUnnamedStructs(mainState: MainState, state: CheckUnnamedStructsState, superGroup: Group, line: str):

	unnamedStructStart: Match = re.match("^\s*(struct|class|enum|union)(?:\s+__declspec\(align\(\d+\)\)){0,1}\s*$", line)
	if unnamedStructStart != None and state.preBracketLevel == None:
		state.groupType = unnamedStructStart.group(1)
		state.preBracketLevel = state.bracketLevel

	bracketLevelBeforeChange = state.bracketLevel
	state.bracketLevel += line.count("{")
	state.bracketLevel -= line.count("}")

	unnamedStructEnd: Match = re.match("^\s*}\s*([_a-zA-Z0-9]+)\s*;\s*$", line)
	if unnamedStructEnd != None and state.bracketLevel == state.preBracketLevel:

		myName = unnamedStructEnd.group(1)
		myTypeName = f"{myName}_t"
		myFullName = f"{superGroup.name}::{myTypeName}"

		subGroup = Group()
		subGroup.groupType = state.groupType
		subGroup.defined = True
		subGroup.lines = state.lines
		subGroup.superGroup = superGroup
		
		subGroup.updateSingleName(mainState, myTypeName)
		superGroup.subGroups.addUnique(subGroup)

		mainState.addGroup(subGroup)
		subGroup.processLinesFillTypes(mainState)

		newSuperField = VariableField()
		newSuperField.variableType = defineTypeRef(mainState, superGroup, myFullName, TypeRefSourceType.VARIABLE)
		newSuperField.variableName = myName
		superGroup.addField(newSuperField)

		state.preBracketLevel = None
		state.lines = []

	if state.preBracketLevel != None:
		if bracketLevelBeforeChange != state.preBracketLevel and state.bracketLevel > state.preBracketLevel:
			adjustedLine = line[1:] if len(line) > 0 and line[0] == "\t" else line
			state.lines.append(adjustedLine)



class FieldType(Enum):
	VARIABLE = 1
	FUNCTION = 2


class Field:
	def __init__(self):
		self.type: FieldType = None
		self.listI: int = None

	def getName(self) -> str:
		assert False, "Field.getName() intentionally unimplemented"

	def toString(self, indent="") -> str:
		assert False, "Field.toString() intentionally unimplemented"

	def getAllTypeReferences(self, mainState: MainState) -> list[TypeReference]:
		assert False, "Field.getAllTypeReferences() intentionally unimplemented"


class FunctionField(Field):

	def __init__(self):
		super().__init__()
		self.type = FieldType.FUNCTION
		self.returnType: TypeReference = None
		self.callConvention: str = None
		self.functionName: str = None
		self.thisType: TypeReference = None
		self.resultType: TypeReference = None
		self.parameterTypes: list[TypeReference] = []


	def toImplementation(self, group: Group) -> FunctionImplementation:

		impl = FunctionImplementation()

		impl.returnType = self.returnType
		impl.callingConvention = self.callConvention
		impl.name = self.functionName

		for i in range(len(self.parameterTypes)):
			implParam = FunctionImplementationParameter()
			implParam.name = f"_{i}"
			implParam.type = self.parameterTypes[i]
			impl.parameters.append(implParam)

		impl.customReturnCount = None
		impl.group = group

		return impl


	def getName(self):
		return self.functionName


	def toString(self, mainState: MainState, indent="") -> str:

		parts = [indent, self.returnType.getHeaderName(), " ("]

		if self.callConvention:
			parts.append(self.callConvention)
			parts.append(" ")

		parts.append("*")
		parts.append(self.functionName)
		parts.append(")(")

		hadParam = False

		if self.thisType:
			parts.append(self.thisType.getHeaderName())
			parts.append(", ")
			hadParam = True

		if self.resultType:
			parts.append(self.resultType.getHeaderName())
			parts.append(", ")
			hadParam = True

		for parameterType in self.parameterTypes:
			parts.append(parameterType.getHeaderName())
			parts.append(", ")
			hadParam = True

		if hadParam:
			parts.pop()

		parts.append(");")
		return "".join(parts)


	def getAllTypeReferences(self, mainState: MainState):

		parts = []

		for v in self.returnType.getAllTypeReferences(mainState):
			parts.append(v)

		if self.thisType != None:
			for v in self.thisType.getAllTypeReferences(mainState):
				parts.append(v)

		if self.resultType != None:
			for v in self.resultType.getAllTypeReferences(mainState):
				parts.append(v)

		for typeReference in self.parameterTypes:
			for v in typeReference.getAllTypeReferences(mainState):
				parts.append(v)

		return parts


class VariableField(Field):

	def __init__(self):
		super().__init__()
		self.type = FieldType.VARIABLE
		self.variableType: TypeReference = None
		self.variableName: str = None
		self.nobinding: bool = False
		self.static: bool = False


	def getName(self):
		return self.variableName


	def toString(self, mainState: MainState, indent="") -> str:

		parts = [indent]

		if self.static:
			parts.append("static ")

		#TODO: Handle nested Arrays
		if (not mainState.noCustomTypes) or self.variableType.getName() != "Array":
			parts.append(f"{self.variableType.getHeaderName()}{'*' if self.static else ''}")
			parts.append(" ")
			parts.append(f"{'p_' if self.static else ''}{self.variableName}")
		else:
			#TODO: Staticify
			assert isinstance(self.variableType, PointerReference), f"Array not wrapped in PointerReference ({type(self.variableType).__name__})"
			arrayRef: TypeReference = self.variableType.originalRef
			parts.append(arrayRef.templateTypes[0].getHeaderName())
			parts.append(" ")
			parts.append(self.variableName)
			parts.append(f"[{arrayRef.templateTypes[1].getHeaderName()}]")

		for arrayPart in self.variableType.getArrayParts():
			parts.append("[")
			parts.append(arrayPart)
			parts.append("]")

		if self.variableType.bitFieldPart != None:
			parts.append(" : ")
			parts.append(self.variableType.bitFieldPart)

		parts.append(";")		
		return "".join(parts)


	def getAllTypeReferences(self, mainState: MainState):
		return self.variableType.getAllTypeReferences(mainState)



class TypeRefSourceType(Enum):
	VARIABLE = 1
	FUNCTION = 2


def defineTypeRefPart(mainState: MainState, superRef: TypeReference, sourceGroup: Group, inStr: str, src: TypeRefSourceType, arrayStr: str=None):

	assert inStr != None
	str = inStr

	primitive = False
	noconst = False
	while True:
		if primitiveMatch := re.fullmatch("primitive\s+(.*)", str):
			primitive = True
			str = primitiveMatch.group(1)
		elif noconstMatch := re.fullmatch("noconst\s+(.*)", str):
			noconst = True
			str = noconstMatch.group(1)
		else:
			break

	needArrayPart = False
	# Transform arrays into Array types
	if arrayStr != None:
		if sourceGroup == None or sourceGroup.name != "Array":
			allMatches = [x for x in re.finditer("\[(\d+)\]", arrayStr)]
			all = [x.group(0) for x in allMatches]
			nextArrayStr = "".join(all[:-1]) if len(all) > 1 else None
			return defineTypeRef(mainState, sourceGroup, f"Array<{str},{allMatches[-1].group(1)}>", src, nextArrayStr)
		else:
			needArrayPart = True

	splits = splitKeepBrackets(stripUnnecessaryTypeSpaces(str), ["*", "&"], includeToSplit=True)
	typeRef = TypeReference()
	typeRef.sourceGroup = sourceGroup
	typeRef.sourceString = inStr

	hitName = False

	def doBaseProcess(name: str):

		nonlocal hitName

		name, unsignedCount = removeRegexCount(name, "unsigned\s+")
		if unsignedCount == 1:
			typeRef.unsigned = True
		else:
			assert unsignedCount == 0, "Invalid number of 'unsigned' keywords"

		if hitName:
			name, constCount = removeRegexCount(name, "const")
		else:
			name, constCount = removeRegexCount(name, "const\s+")

		if volatileMatch := re.match("^volatile\s+(.*)", name):
			typeRef.volatile = True
			name = volatileMatch.group(1)

		if longMatch := re.match("^long\s+(.*)", name):
			typeRef.long = True
			name = longMatch.group(1)

		if constCount == 1:
			typeRef.const = True
		else:
			assert constCount == 0, "Invalid number of 'const' keywords"

		if hitName: return
		name = name.strip()
		if name == "": return

		hitName = True

		struct = False
		if structMatch := re.match("^struct\s+(.*)", name):
			struct = True
			name = structMatch.group(1)

		# Create a Group for the type if it hasn't been found already
		# (varargs type and completely numeric types obviously aren't real, so exclude them)
		if typeRef.sourceString != "..." and not typeRef.sourceString.isnumeric():

			groupName = f"{superRef.group.name}::{name}" if superRef else name
			typeGroup = mainState.tryGetGroup(groupName)

			if not typeGroup:
				typeGroup = Group()
				typeGroup.groupType = "struct" if struct else "undefined"
				typeGroup.updateSingleName(mainState, groupName)
				mainState.addGroup(typeGroup)

			typeRef.group = typeGroup


	for split in splits:

		typeBracketStarts = findTemplateBracketStarts(split)
		if len(typeBracketStarts) > 0:

			for typeStartI in typeBracketStarts:
				name, parts = separateTemplateTypeParts(split, typeStartI)
				doBaseProcess(name)
				for templateType in splitKeepBrackets(parts, [","]):
					typeRef.templateTypes.append(defineTypeRef(mainState, sourceGroup, templateType, TypeRefSourceType.VARIABLE))

		elif split in ("*", "&"):

			if split == "&":
				assert not typeRef.reference, "Cannot handle rvalue reference"
				typeRef.reference = True

			typeRef.pointerLevel += 1
		else:
			doBaseProcess(split)

	if needArrayPart:
		for arrayPartMatch in re.finditer("\[([a-zA-Z0-9_]+)\]", arrayStr):
			typeRef.arrayParts.append(arrayPartMatch.group(1))

	typeRef.primitive = primitive
	typeRef.noconst = noconst

	if superRef:
		superRef.subRef = typeRef
		typeRef.superRef = superRef

	groupName = typeRef.group and typeRef.group.name or ""

	if groupName in ("CharString", "ConstCharString"):
		return CharReference.create(mainState, typeRef, CharReferenceMode.USER_TYPE_ONLY)

	# Transform char into CharReference
	elif groupName == "char":
		mode = CharReferenceMode.PRIMITIVE_ONLY if primitive else CharReferenceMode.MORPHING
		charRef = CharReference.create(mainState, typeRef, mode)
		return charRef

	# Transform void pointers into VoidPointerReference
	elif groupName == "void" and typeRef.pointerLevel > 0:
		return VoidPointerReference.create(mainState, typeRef)

	# Transform pointers into PointerReference
	else:
		assert groupName != "Array" or len(typeRef.templateTypes) == 2, "defineTypeRefPart() created invalid Array"
		return PointerReference.create(mainState, typeRef)



def defineTypeRef(mainState: MainState, sourceGroup: Group, str: str, src: TypeRefSourceType, arrayStr: str=None):

	if str == None:
		return

	splits = splitKeepBrackets(stripUnnecessaryTypeSpaces(str), ["::"])
	numSplits = len(splits)

	if numSplits == 0:
		return

	lastRef = defineTypeRefPart(mainState, None, sourceGroup, splits[0], src, arrayStr)
	for i in range(1, numSplits):
		lastRef = defineTypeRefPart(mainState, lastRef, sourceGroup, splits[i], src, None)

	return lastRef



def relocateGroup(mainState: MainState, existingPath: str, newPath: str):
	mainState.getGroup(existingPath).relocate(mainState, newPath)



def moveElementAfter(list: list, originalIndex, afterIndex):
	temp = list[originalIndex]
	del list[originalIndex]
	list.insert(afterIndex if originalIndex <= afterIndex else afterIndex + 1, temp)



def tryResolveDependencyOrder(groups: list[Group]):

	"""
	Brute force dependency order, moving groups when needed. \n
	OH the time complexity!
	"""

	# Sort groups alphabetically based on name
	groups.sort(key=lambda x: x.name)

	curCheckI = 0
	while curCheckI < len(groups):

		group = groups[curCheckI]

		if len(group.dependsOn) > 0:

			maxDependIndex = 0
			for dependName in group.dependsOn:
				i = 0
				for checkGroup in groups:
					if checkGroup.name == dependName:
						maxDependIndex = max(maxDependIndex, i)
					i += 1

			#print(f"{group.name} at [{curCheckI}] needs to go after {groups[maxDependIndex].name} at [{maxDependIndex}]")
			if curCheckI < maxDependIndex:
				moveElementAfter(groups, curCheckI, maxDependIndex)
				assert group != groups[curCheckI], "Duplicate group in list"
				continue

		curCheckI += 1

	for group in groups:
		tryResolveDependencyOrder(group.subGroups)
		group.subGroups.rebuildIndexMapping()



def writeBindings(mainState: MainState, groups: list[Group], out: TextIOWrapper, baseclassHeaderOut: TextIOWrapper, baseclassOut: TextIOWrapper) -> None:

	baseclassHeaderOut.write("\n#pragma once\n\n")
	baseclassHeaderOut.write("#include <unordered_map>\n\n")
	baseclassHeaderOut.write("#include \"Baldur-v2.6.6.0_generated.h\"\n\n")
	baseclassHeaderOut.write("extern std::unordered_map<const char*, std::unordered_map<const char*, uintptr_t>> baseclassOffsets;\n")

	baseclassOut.write("\n#include \"EEexLua_generated_baseclass_offsets.h\"\n\n")
	baseclassOut.write("template<typename Derived, typename Base>\n")
	baseclassOut.write("constexpr uintptr_t offsetofbase() {\n")
	baseclassOut.write("\treturn reinterpret_cast<uintptr_t>(static_cast<Base*>(reinterpret_cast<Derived*>(1))) - 1;\n")
	baseclassOut.write("}\n\n")
	baseclassOut.write("std::unordered_map<const char*, std::unordered_map<const char*, uintptr_t>> baseclassOffsets {\n")

	class OpenFieldData:
		def __init__(self) -> None:
			self.fieldBindingName: str = None
			self.getBindingName: str = None
			self.setBindingName: str = None


	class OpenConstantType(Enum):
		INTEGER = 1,
		STRING = 2,

	class OpenConstantData:
		def __init__(self) -> None:
			self.name: str = None
			self.valueType: OpenConstantType = None
			self.value = None


	class OpenGroupData:

		def __init__(self) -> None:
			self.appliedNameUsertypeNoOverride: str = None
			self.appliedNameUsertype: str = None
			self.appliedNameUsertypeFunc: str = None
			self.appliedHeaderName: str = None
			self.group: Group = None
			self.fieldBindings: list[OpenFieldData] = []
			self.functionBindings: list[OpenFunctionData] = []
			self.constantBindings: list[OpenConstantData] = []


	class OpenFunctionData:

		def __init__(self) -> None:
			self.functionName: str = None
			self.functionBindingName: str = None


	openDataGroups: list[OpenGroupData] = []


	def writeGroupWithTemplateUse(group: Group, templateMappingTracker: TemplateMappingTracker, currentTemplate: tuple[TypeReference]=None):

		groupOpenData = OpenGroupData()
		groupOpenData.group = group
		openDataGroups.append(groupOpenData)

		if currentTemplate != None:
			templateMappingTracker.registerMapping(group.name, currentTemplate)

		groupOpenData.appliedNameUsertypeNoOverride = group.getAppliedName(mainState, templateMappingTracker, templateTypeMode=TemplateTypeMode.HEADER)
		groupOpenData.appliedNameUsertype = group.getAppliedName(mainState, templateMappingTracker, useUsertypeOverride=True, templateTypeMode=TemplateTypeMode.HEADER)
		groupOpenData.appliedNameUsertypeFunc = group.getAppliedName(mainState, templateMappingTracker, templateTypeMode=TemplateTypeMode.HEADER)
		groupOpenData.appliedHeaderName = group.getAppliedName(mainState, templateMappingTracker, templateTypeMode=TemplateTypeMode.HEADER)
		groupNameStrIden, _ = re.subn("[^a-zA-Z0-9_]", "_", groupOpenData.appliedNameUsertypeNoOverride)

		# Writing getInternalReference() function which returns the userdata's internal pointer
		if group != globalGroup and group.groupType != "enum" and group.name not in ("Pointer", "Array"):
	
			getTypeFunc = OpenFunctionData()
			getTypeFunc.functionBindingName = f"tolua_function_{groupNameStrIden}_getInternalReference"
			getTypeFunc.functionName = "getInternalReference"

			out.write(f"static int {getTypeFunc.functionBindingName}(lua_State* L)\n")
			out.write("{\n")
			out.write(f"\tvoid** ptr = (void**)lua_touserdata(L, 1);\n")
			out.write(f"\ttolua_pushusertype(L, ptr, \"Pointer<{groupOpenData.appliedHeaderName}>\");\n")
			out.write("\treturn 1;\n")
			out.write("}\n\n")

			groupOpenData.functionBindings.append(getTypeFunc)

		# Writing sizeof variable which returns the value of the sizeof operator when run on the usertype
		if group != globalGroup and group.groupType != "enum" and group.name != "void":

			sizeofConstant = OpenConstantData()
			sizeofConstant.name = "sizeof"
			sizeofConstant.valueType = OpenConstantType.STRING
			sizeofConstant.value = f"sizeof({groupOpenData.appliedHeaderName})"
			groupOpenData.constantBindings.append(sizeofConstant)


		def writeAccessSelf(errorMsg: str):
			out.write(f"\t{groupOpenData.appliedHeaderName}* self = ({groupOpenData.appliedHeaderName}*)tolua_tousertype_dynamic(L, 1, 0, \"{groupOpenData.appliedNameUsertype}\");\n")
			out.write(f"\tif (!self) tolua_error(L, \"{errorMsg}\", NULL);\n")


		def handleField(field: Field, isPointerCast=False):

			"""
			Writes getter function for given field, (and an reference_ function that returns a pointer to the field).
			"""

			fieldNameStr = None

			assert field.type in (FieldType.VARIABLE, FieldType.FUNCTION), "field.type unhandled in writeGroupWithTemplateUse()"
			if field.type == FieldType.VARIABLE:
				variableField: VariableField = field
				if variableField.nobinding: return
				if len(variableField.variableType.arrayParts) > 0: return # These use GenericArray functions
				fieldNameStr = variableField.variableName
			elif field.type == FieldType.FUNCTION:
				functionField: FunctionField = field
				fieldNameStr = functionField.functionName

			fieldOpenData = OpenFieldData()
			isNormal: bool = group != globalGroup
			shouldWritePointerCast = isNormal and not isPointerCast and not group.name == "Pointer"
			primitiveReturned = False
			
			addressPrefix = "reference_" if isPointerCast else ""

			groupOpenData.fieldBindings.append(fieldOpenData)
			fieldOpenData.fieldBindingName = f"{addressPrefix}{fieldNameStr}"

			if isNormal:
				fieldOpenData.getBindingName = f"tolua_get_{groupNameStrIden}_{addressPrefix}{fieldNameStr}"
			else:
				fieldOpenData.getBindingName = f"tolua_get_{addressPrefix}{fieldNameStr}"

			# GETTER START

			out.write(f"static int {fieldOpenData.getBindingName}(lua_State* L)\n")
			out.write("{\n")

			if field.type == FieldType.VARIABLE:

				variableField: VariableField = field
				varType: TypeReference = variableField.variableType.checkReplaceTemplateType(mainState, group, templateMappingTracker)

				if isNormal and not variableField.static:
					out.write(f"\t{groupOpenData.appliedNameUsertypeFunc}* self = ({groupOpenData.appliedNameUsertypeFunc}*)tolua_tousertype_dynamic(L, 1, 0, \"{groupOpenData.appliedNameUsertype}\");\n")
					out.write(f"\tif (!self) tolua_error(L, \"invalid 'self' in accessing variable '{variableField.variableName}'\", NULL);\n")

				varNameHeader = variableField.variableName if (isNormal and not variableField.static) else f"p_{variableField.variableName}"
				selfStr: str = None
				if isNormal:
					if variableField.static:
						selfStr = f"{groupOpenData.appliedHeaderName}::"
					else:
						selfStr = "self->"
				else:
					selfStr = ""

				def checkPrimitiveHandling(varType: TypeReference):

					if isPointerCast:
						return False

					effectivePtrLevel = varType.getUserTypePointerLevel() if (isNormal and not variableField.static) else varType.getUserTypePointerLevel() + 1
					checkType = varType

					# Enums are fancy primitives!
					if varType.group and varType.group.groupType == "enum":
						checkType = varType.group.extends[0]

					checkTypeName = checkType.getName()

					if checkType.isPrimitiveNumber():
						out.write(f"\ttolua_pushnumber(L, (lua_Number){'*'*effectivePtrLevel}{selfStr}{varNameHeader});\n")
						return True
					elif checkTypeName == "bool":
						out.write(f"\ttolua_pushboolean(L, (bool){'*'*effectivePtrLevel}{selfStr}{varNameHeader});\n")
						return True
					elif checkTypeName == "char":
						if checkType.getUserTypePointerLevel() == 1:
							out.write(f"\ttolua_pushstring(L, (const char*){'*'*(effectivePtrLevel - 1)}{selfStr}{varNameHeader});\n")
							return True
						elif checkType.getUserTypePointerLevel() == 0:
							out.write(f"\tlua_pushlstring(L, (const char*){'*'*(effectivePtrLevel - 1)}{selfStr}{varNameHeader}, 1);\n")
							return True

					return False


				if not checkPrimitiveHandling(varType):

					effectivePtrLevel = varType.getUserTypePointerLevel() if (isNormal and not variableField.static) else varType.getUserTypePointerLevel() + 1

					if isPointerCast:
						out.write("\ttolua_pushusertypepointer(L, (void*)&")
					else:
						out.write("\ttolua_pushusertype(L, (void*)")
						if effectivePtrLevel == 0:
							out.write("&")

					if isNormal:
						out.write(f"{selfStr}{varNameHeader}")
					else:
						out.write(f"{'*'*varType.getUserTypePointerLevel()}{varNameHeader}")

					if isPointerCast:
						pointerRef = varType.shallowCopy()
						pointerRef.adjustUserTypePointerLevel(mainState, 1)
						pointerTypeName = pointerRef.getAppliedUserTypeName(mainState, group, templateMappingTracker, useUsertypeOverride=True)
						out.write(f", \"{pointerTypeName}\"")
					else:
						primitiveReturned = varType.getUserTypePointerLevel() > 0
						typeStr = varType.getAppliedUserTypeName(mainState, group, templateMappingTracker, useUsertypeOverride=True)
						out.write(f", \"{typeStr}\"")

					out.write(");\n")
				else:
					primitiveReturned = True

				out.write("\treturn 1;\n")

				if varType.bitFieldPart != None:
					shouldWritePointerCast = False

			elif field.type == FieldType.FUNCTION:
				# TODO: Not implemented
				functionField: FunctionField = field
				fieldNameStr = functionField.functionName
				out.write("\treturn 1;\n")

			out.write("}\n\n")

			# GETTER END

			# SETTER START

			allowSetter = not isPointerCast

			if allowSetter and field.type == FieldType.VARIABLE:
				variableField: VariableField = field
				varType: TypeReference = variableField.variableType.checkReplaceTemplateType(mainState, group, templateMappingTracker)

				# Enums are fancy primitives!
				if varType.group and varType.group.groupType == "enum":
					varType = varType.group.extends[0]

				allowSetter = varType.isPrimitive() or varType.getUserTypePointerLevel() > 0

			if allowSetter:

				if isNormal:
					fieldOpenData.setBindingName = f"tolua_set_{groupNameStrIden}_{addressPrefix}{fieldNameStr}"
				else:
					fieldOpenData.setBindingName = f"tolua_set_{addressPrefix}{fieldNameStr}"

				out.write(f"static int {fieldOpenData.setBindingName}(lua_State* L)\n")
				out.write("{\n")

				if field.type == FieldType.VARIABLE:

					variableField: VariableField = field
					varType: TypeReference = variableField.variableType.checkReplaceTemplateType(mainState, group, templateMappingTracker)

					if isNormal and not variableField.static:
						out.write(f"\t{groupOpenData.appliedNameUsertypeFunc}* self = ({groupOpenData.appliedNameUsertypeFunc}*)tolua_tousertype_dynamic(L, 1, 0, \"{groupOpenData.appliedNameUsertype}\");\n")
						out.write(f"\tif (!self) tolua_error(L, \"invalid 'self' in accessing variable '{variableField.variableName}'\", NULL);\n")

					varNameHeader = variableField.variableName if (isNormal and not variableField.static) else f"p_{variableField.variableName}"
					selfStr: str = None
					if isNormal:
						if variableField.static:
							selfStr = f"{groupOpenData.appliedHeaderName}::"
						else:
							selfStr = "self->"
					else:
						selfStr = "*"*(varType.getUserTypePointerLevel() + 1)

					def checkPrimitiveHandling(varType: TypeReference):

						varTypeName = varType.getName()
						if isNormal and ((varTypeName != "char" and varType.getUserTypePointerLevel() > 0) or (varTypeName == "char" and varType.getUserTypePointerLevel() > 1)): return False

						enumCastStr = ""
						checkType = varType

						# Enums are fancy primitives!
						if varType.group and varType.group.groupType == "enum":
							enumCastStr = f"({varType.group.name})"
							checkType = varType.group.extends[0]

						if checkType.isPrimitiveNumber():
							out.write(f"\t{selfStr}{varNameHeader} = ")

							if (not enumCastStr) and varTypeName == "__int64":
								out.write("(__int64)")

							if varTypeName == "float":
								out.write(f"{enumCastStr}lua_tonumber(L, 2);\n")
							else:
								out.write(f"{enumCastStr}lua_tointeger(L, 2);\n")

							return True

						elif varTypeName == "bool":
							out.write(f"\t{selfStr}{varNameHeader} = lua_toboolean(L, 2);\n")
							return True

						return False


					if not checkPrimitiveHandling(varType):
						selfStr = "self->" if isNormal else "*"
						out.write(f"\t{selfStr}{varNameHeader} = ({varType.getAppliedHeaderName(mainState, group, templateMappingTracker)})tolua_tousertype_dynamic(L, 2, 0, \"{varType.getAppliedUserTypeName(mainState, group, templateMappingTracker, useUsertypeOverride=True)}\");\n")

					out.write("\treturn 0;\n")

				elif field.type == FieldType.FUNCTION:
					# TODO: Not implemented
					functionField: FunctionField = field
					fieldNameStr = functionField.functionName
					out.write("\treturn 0;\n")

				out.write("}\n\n")

			# SETTER END

			if shouldWritePointerCast and primitiveReturned:
				handleField(field, isPointerCast=True)


		def handleFunctionImplementation(functionImplementation: FunctionImplementation):

			# TODO: I can't return / pass non-pointer, non-primitives to functions yet

			returnType: TypeReference = functionImplementation.returnType.checkReplaceTemplateType(mainState, group, templateMappingTracker)

			# Must be void, primitive, or pointer
			if not returnType.isVoid() and not returnType.isPrimitive() and returnType.getUserTypePointerLevel() == 0:
				return

			for param in functionImplementation.parameters:

				paramType = param.type.checkReplaceTemplateType(mainState, group, templateMappingTracker)

				# Can't have conflicting const requirements (the noconst directive prevents the function binding from generating for const types)
				if paramType.const and paramType.noconst:
					return


			isNormal: bool = group != globalGroup
			functionOpenData = OpenFunctionData()

			functionOpenData.functionName = functionImplementation.name
			groupIden = f"{groupNameStrIden}_" if isNormal else ""
			functionOpenData.functionBindingName = f"tolua_function_{groupIden}{functionImplementation.name}"

			groupOpenData.functionBindings.append(functionOpenData)

			out.write(f"static int {functionOpenData.functionBindingName}(lua_State* L)\n")
			out.write("{\n")

			if isNormal and not functionImplementation.isStatic:
				writeAccessSelf(f"invalid 'self' in calling function '{functionImplementation.name}'")

			callArgParts: list[str] = []
			def checkPrimitiveHandling(paramType: TypeReference, luaVarIndex: int):

				paramTypeName = paramType.getName()

				if paramType.isPrimitiveNumber() and paramType.getUserTypePointerLevel() == 0:
					callArgParts.append(f"tolua_tonumber(L, {luaVarIndex}, NULL)")
					callArgParts.append(", ")
					return True
				elif paramTypeName == "bool" and paramType.getUserTypePointerLevel() == 0:
					callArgParts.append(f"tolua_toboolean(L, {luaVarIndex}, NULL)")
					callArgParts.append(", ")
					return True
				elif paramTypeName == "char" and not paramType.unsigned:
					if paramType.getUserTypePointerLevel() == 1:
						nonConstCast = "(char*)" if not paramType.const else ""
						callArgParts.append(f"{nonConstCast}tolua_tostring(L, {luaVarIndex}, NULL)")
						callArgParts.append(", ")
						return True
					elif paramType.getUserTypePointerLevel() == 0:
						callArgParts.append(f"*tolua_tostring(L, {luaVarIndex}, NULL)")
						callArgParts.append(", ")
						return True

				return False

			out.write("\t")

			parameterIMod: int = None
			functionNameHeader = f"p_{functionImplementation.name}" if (not isNormal and functionImplementation.isInternal) else functionImplementation.name

			if isNormal and not functionImplementation.isStatic:
				parameterIMod = 2
			else:
				parameterIMod = 1

			if not returnType.isVoid():
				returnTypeStr = returnType.getAppliedHeaderName(mainState, group, templateMappingTracker)
				out.write(f"{returnTypeStr} returnVal = ")

			if functionImplementation.isConstructor:
				out.write(f"new (self) {groupOpenData.appliedHeaderName}(")
			elif isNormal and not functionImplementation.isStatic:
				out.write(f"self->{functionNameHeader}(")
			else:
				classStr = f"{groupOpenData.appliedHeaderName}::" if isNormal else ""
				out.write(f"{classStr}{functionNameHeader}(")

			if functionImplementation.customReturnCount:
				out.write("L")
				callArgParts.append(", ")

			for i, parameter in enumerate(functionImplementation.parameters):
				i += parameterIMod
				paramType = parameter.type.checkReplaceTemplateType(mainState, group, templateMappingTracker)
				if not checkPrimitiveHandling(paramType, i):

					dereferenceStr = ""
					if paramType.getUserTypePointerLevel() == 0:
						paramType = paramType.shallowCopy()
						paramType.adjustUserTypePointerLevel(mainState, 1)
						dereferenceStr = "*"

					appliedParamName = paramType.getAppliedHeaderName(mainState, group, templateMappingTracker)
					appliedParamUsertype = paramType.getAppliedUserTypeName(mainState, group, templateMappingTracker, useUsertypeOverride=True)
					
					callArgParts.append(f"{dereferenceStr}({appliedParamName})tolua_tousertype_dynamic(L, {i}, 0, \"{appliedParamUsertype}\")")
					callArgParts.append(", ")
			
			if functionImplementation.customReturnCount or len(functionImplementation.parameters) > 0:
				callArgParts.pop()

			callArgParts.append(");\n")
			out.write("".join(callArgParts))


			if not returnType.isVoid():

				out.write("\t")

				def checkPrimitiveHandling(varType: TypeReference):

					varTypeName = varType.getName()

					if varType.isPrimitiveNumber() and varType.getUserTypePointerLevel() == 0:
						out.write("tolua_pushnumber(L, (lua_Number)returnVal);\n")
						return True
					elif varTypeName == "bool" and varType.getUserTypePointerLevel() == 0:
						out.write("tolua_pushboolean(L, (bool)returnVal);\n")
						return True
					elif varTypeName == "char":
						if varType.getUserTypePointerLevel() == 1:
							out.write("tolua_pushstring(L, (const char*)returnVal);\n")
							return True
						elif varType.getUserTypePointerLevel() == 0:
							out.write("lua_pushlstring(L, (const char*)&returnVal, 1);\n")
							return True

					return False


				if not checkPrimitiveHandling(returnType):
					out.write("tolua_pushusertype(L, (void*)returnVal, \"")
					if mainState.tryGetGroup(returnType.getName()) != None:
						returnUserTypeStr = returnType.getAppliedUserTypeName(mainState, group, templateMappingTracker, useUsertypeOverride=True)
						out.write(returnUserTypeStr)
					else:
						out.write("UnmappedUserType")

					out.write("\");\n")


			if functionImplementation.customReturnCount:	
				out.write(f"\treturn {functionImplementation.customReturnCount};\n")
			elif not returnType.isVoid():
				out.write("\treturn 1;\n")
			else:
				out.write("\treturn 0;\n")

			out.write("}\n\n")

			# reference_ functions for internal function implementations
			if (not isNormal) or functionImplementation.isStatic:

				addressVar = OpenFieldData()
				addressVar.fieldBindingName = f"reference_{functionImplementation.name}"
				addressVar.getBindingName = f"tolua_get_reference_{groupIden}{functionImplementation.name}"

				out.write(f"static int {addressVar.getBindingName}(lua_State* L)\n")
				out.write("{\n")
				out.write(f"\ttolua_pushusertype(L, {f'{groupOpenData.appliedNameUsertypeFunc}::{functionNameHeader}' if isNormal else f'*{functionNameHeader}'}, \"UnmappedUserType\");\n")	
				out.write("\treturn 1;\n")
				out.write("}\n\n")

				groupOpenData.fieldBindings.append(addressVar)


		def handleEnumTuple(enumTuple: Tuple[str, str]):
			openConstantData = OpenConstantData()
			openConstantData.name = enumTuple[0]
			openConstantData.valueType = OpenConstantType.INTEGER
			openConstantData.value = enumTuple[1]
			groupOpenData.constantBindings.append(openConstantData)



		for field in group.fields:
			handleField(field)

		for functionImplementation in group.functionImplementations:
			if functionImplementation.noBinding: continue
			handleFunctionImplementation(functionImplementation)

		for enumTuple in group.enumTuples:
			handleEnumTuple(enumTuple)

		for subGroup in group.subGroups:
			writeGroup(subGroup, templateMappingTracker)

		if currentTemplate != None:
			templateMappingTracker.deregisterMapping(group.name)



	def writeGroup(group: Group, templateMappingTracker: TemplateMappingTracker):

		if not group.isUsed(mainState):
			return

		if group.template != None:
			for templateUse in group.templateUses:
				if templateUseHasGeneric(templateUse):
					# Don't treat a use of a generic template as an actual use 
					continue
				writeGroupWithTemplateUse(group, templateMappingTracker, templateUse)
		else:
			writeGroupWithTemplateUse(group, templateMappingTracker)



	out.write("\n")

	templateMappingTracker = TemplateMappingTracker() 
	for group in groups:
		if group.isSubgroup(): continue
		writeGroup(group, templateMappingTracker)


	out.write("static void tolua_reg_types(lua_State* L)\n")
	out.write("{\n")

	for openData in openDataGroups:
		out.write(f"\ttolua_usertype(L, \"{openData.appliedNameUsertype}\");\n")

	out.write("}\n\n")

	out.write("int tolua_EEexLua_open(lua_State* L)\n")
	out.write("{\n")
	out.write("\ttolua_open(L);\n")
	out.write("\ttolua_reg_types(L);\n")
	out.write("\ttolua_module(L, NULL, 0);\n")
	out.write("\ttolua_beginmodule(L, NULL);\n")
	for openData in openDataGroups:

		# Write global mappings
		if openData.group == globalGroup:

			out.write(f"\ttolua_cclass(L, \"EngineGlobals\", \"EngineGlobals\", {{}}, NULL);\n")
			out.write("\ttolua_beginmodule(L, \"EngineGlobals\");\n")

			for functionOpenData in openData.functionBindings:
				out.write(f"\t\ttolua_function(L, \"{functionOpenData.functionName}\", {functionOpenData.functionBindingName});\n")

			for fieldOpenData in openData.fieldBindings:
				out.write(f"\t\ttolua_variable(L, \"{fieldOpenData.fieldBindingName}\", {fieldOpenData.getBindingName}, {fieldOpenData.setBindingName or 'NULL'});\n")

			out.write("\ttolua_endmodule(L);\n")
			continue

		out.write(f"\ttolua_cclass(L, \"{openData.appliedNameUsertype}\", \"{openData.appliedNameUsertype}\", {{")

		hasNonPrimitiveBase = False
		for extendRef in openData.group.extends:
			if not extendRef.isPrimitive():
				hasNonPrimitiveBase = True
				break

		if not openData.group.isPrimitive() and hasNonPrimitiveBase:
			baseclassOut.write(f"\t{{\"{openData.appliedNameUsertype}\", {{")

		if len(openData.group.extends) > 0:

			if hasNonPrimitiveBase:
				baseclassOut.write("\n")

			parts: list[str] = []

			for extendRef in openData.group.extends:

				extendRefUT = extendRef.toString(useUsertypeOverride=True, iKnowWhatIAmDoing=True)

				parts.append(f"\"{extendRefUT}\"")
				parts.append(",")

				if extendRef.isPrimitive():
					continue

				if hasNonPrimitiveBase:
					baseclassOut.write(f"\t\t{{\"{extendRefUT}\", ")
					baseclassOut.write(f"offsetofbase<{openData.appliedHeaderName}, {extendRef.toString(iKnowWhatIAmDoing=True)}>()")
					baseclassOut.write("},\n")

			parts.pop()
			out.write("".join(parts))

			if hasNonPrimitiveBase:
				baseclassOut.write("\t")

		if not openData.group.isPrimitive() and hasNonPrimitiveBase:
			baseclassOut.write("}},\n")

		out.write("}, NULL);\n")
		out.write(f"\ttolua_beginmodule(L, \"{openData.appliedNameUsertype}\");\n")

		# Write field mappings
		for fieldOpenData in openData.fieldBindings:

			out.write(f"\t\ttolua_variable(L, \"{fieldOpenData.fieldBindingName}\", ")

			if fieldOpenData.getBindingName:
				out.write(fieldOpenData.getBindingName)
			else:
				out.write("NULL")

			out.write(", ")

			if fieldOpenData.setBindingName:
				out.write(fieldOpenData.setBindingName)
			else:
				out.write("NULL")

			out.write(");\n")


		for functionOpenData in openData.functionBindings:
			out.write(f"\t\ttolua_function(L, \"{functionOpenData.functionName}\", &{functionOpenData.functionBindingName});\n")

		# Write constant mappings
		for constantOpenData in openData.constantBindings:
			out.write(f"\t\ttolua_constant(L, \"{constantOpenData.name}\", {constantOpenData.value});\n")

		out.write("\ttolua_endmodule(L);\n")


	out.write("\ttolua_endmodule(L);\n")
	out.write("\treturn 1;\n")
	out.write("}\n")

	baseclassOut.write("};\n")


def fileAsLines(fileName: str):
	lines = []
	with open(fileName) as file:
		for line in file:
			lines.append(line)
	return lines


def pathToFileName(filePath: str) -> str:
	leftIndex = max(filePath.rfind('\\'), filePath.rfind('/'))
	leftIndex = 0 if leftIndex == -1 else leftIndex + 1
	return "" if leftIndex >= len(filePath) else filePath[leftIndex:]


def pathToFileNameNoExt(filePath: str) -> str:
	fileName = pathToFileName(filePath)
	periodI = fileName.rfind('.')
	return "" if periodI == -1 else fileName[0:periodI]


def separatePath(filePath: str) -> str:
	leftIndex = max(filePath.rfind('\\'), filePath.rfind('/'))
	leftIndex = 0 if leftIndex == -1 else leftIndex + 1
	return filePath[0:leftIndex], "" if leftIndex >= len(filePath) else filePath[leftIndex:]


def separatePathNoExt(filePath: str) -> str:
	leftIndex = max(filePath.rfind('\\'), filePath.rfind('/'))
	leftIndex = 0 if leftIndex == -1 else leftIndex + 1
	fileName = "" if leftIndex >= len(filePath) else filePath[leftIndex:]
	periodI = fileName.rfind('.')
	return filePath[0:leftIndex], "" if periodI == -1 else fileName[0:periodI]


def registerPointerTypes(mainState: MainState):

	"""
	Registers pointer types for every group, (for reference_ functions)
	"""

	array = mainState.getGroup("Array")
	pointer = mainState.getGroup("Pointer")

	def registerPointerType(group: Group, tracker: TemplateMappingTracker):
		for uniqueRepresentation in group.uniqueUseRepresentations.values():
			specialRef = uniqueRepresentation.shallowCopy()
			specialRef.adjustUserTypePointerLevel(mainState, 1)
			pointer.addTemplateUse( (specialRef,) )

	def registerPointerTypesForGroup(group: Group, tracker: TemplateMappingTracker):

		if not group.isUsed(mainState):
			#print(f"Excluding {group.name}: Not used")
			return

		if group.template:
			for templateUse in group.templateUses:

				tracker.registerMapping(group.name, templateUse)
				registerPointerType(group, tracker)
				for subGroup in group.subGroups:
					registerPointerTypesForGroup(subGroup, tracker)

				tracker.deregisterMapping(group.name)
		else:
			registerPointerType(group, tracker)
			for subGroup in group.subGroups:
				registerPointerTypesForGroup(subGroup, tracker)

	for group in mainState.filteredGroups:
		if group.isSubgroup() or group in (globalGroup, array, pointer):
			continue
		registerPointerTypesForGroup(group, TemplateMappingTracker())


def fileAsSet(filePath):
	s = set()
	if filePath != None:
		with open(filePath) as fileIn:
			for line in fileIn:
				s.add(line.strip())
	return s


def outputFile(filePath, out: TextIOWrapper):
	if filePath != None:
		with open(filePath) as fileIn:
			for line in fileIn:
				out.write(line)


def filterGroups(mainState: MainState, wantedFile: str, ignoreHeaderFile: str, packingFile: str):
	
	"""
	Filter groups down to what is requested in wanted_types.txt and their subclasses / referenced types.
	"""

	wantedNames = fileAsSet(wantedFile)
	wantedNames.add("EngineGlobals")
	wantedNames.add("Pointer") # WORKAROUND
	wantedNames.add("UnmappedUserType")

	if mainState.noCustomTypes:
		mainState.getGroup("Pointer").ignoreHeader = True
		mainState.getGroup("Array").ignoreHeader = True
		mainState.getGroup("CharString").ignoreHeader = True
		mainState.getGroup("ConstCharString").ignoreHeader = True
		mainState.getGroup("VoidPointer").ignoreHeader = True

	pendingProcessed: list[str] = []
	for wantedName in wantedNames:
		wantedGroup = mainState.tryGetGroup(wantedName)
		if wantedGroup == None: continue
		wantedGroup.isDirectlyWanted = True
		pendingProcessed.append(wantedName)

	while len(pendingProcessed) > 0:

		wantedGroup = mainState.tryGetGroup(pendingProcessed.pop())
		if wantedGroup == None: continue

		if vGroup := wantedGroup.vGroup:
			vGroup.isSoftWanted = True

		mainState.filteredGroups.addUnique(wantedGroup)

		for dependsOnName in wantedGroup.dependsOn:
			if dependsOnName in wantedNames: continue
			pendingProcessed.append(dependsOnName)
			wantedNames.add(dependsOnName)
		for dependsOnName in wantedGroup.lightDependsOn:
			if dependsOnName in wantedNames: continue
			pendingProcessed.append(dependsOnName)
			wantedNames.add(dependsOnName)
		for subGroup in wantedGroup.subGroups:
			if subGroup.name in wantedNames: continue
			pendingProcessed.append(subGroup.name)
			wantedNames.add(subGroup.name)

	if ignoreHeaderFile:
		with open(ignoreHeaderFile) as fileIn:
			for line in fileIn:
				if group := mainState.tryGetGroup(line.strip()):
					toProcess: list[Group] = [group]
					while len(toProcess) > 0:
						curGroup = toProcess.pop()
						curGroup.ignoreHeader = True
						for subGroup in curGroup.subGroups:
							toProcess.append(subGroup)

	if packingFile:
		with open(packingFile) as fileIn:
			for line in fileIn:
				split = line.strip().split(" ")
				if group := mainState.tryGetGroup(split[0]):
					group.pack = int(split[1])

	#print("Filtered groups include:")
	#for group in mainState.filteredGroups:
	#	print(f"    {group.name}")



def checkRename(mainState, alreadyDefinedUsertypesFile: str):

	"""
	Rename groups to remove invalid characters / improve autogenerated names, fix clashing function fields, and fix clashing usertype names.
	"""

	toProcess: list[Group] = []

	for topGroup in mainState.filteredGroups:

		if topGroup.isSubgroup(): continue
		toProcess.append(topGroup)

		while len(toProcess) > 0:

			group = toProcess.pop()
			newName = group.singleName
			needRecalc = False

			# Rename unnamed types to something more reasonable
			unnamedTypeMatch = re.fullmatch("<unnamed_(?:type|enum)_(\S+)>", newName)
			if unnamedTypeMatch:
				newName = f"{unnamedTypeMatch.group(1)}_t"
				needRecalc = True

			# Replace disallowed type characters with _
			newName, numReplacements = re.subn("[^a-zA-Z0-9_]", "_", newName)
			if numReplacements > 0: needRecalc = True

			if needRecalc:
				group.updateSingleName(mainState, newName)

			for subGroup in group.subGroups:
				toProcess.append(subGroup)

	# The engine already defines some usertypes
	# add prefix to prevent clashing with binding names
	if alreadyDefinedUsertypesFile != None:
		with open(alreadyDefinedUsertypesFile) as fileIn:
			for line in fileIn:
				groupName = line.strip()
				group = mainState.getGroup(groupName)
				group.overrideUsertypeSingleName = "EEex_" + groupName


def outputForwardDeclarations(mainState: MainState, out: TextIOWrapper):

	# Store final sorted positions in groups
	i = 0
	for group in mainState.filteredGroups:
		group.sortedPosition = i
		i += 1

	forwardDeclarations: set[str] = set()

	# Attempt to derive needed forward declarations
	for group in mainState.filteredGroups:

		if group.isSubgroup() or group.ignoreHeader or not group.isUsed(mainState): continue

		for lightDependency in group.lightDependsOn:

			lightDepend = mainState.tryGetGroup(lightDependency)
			
			if (not lightDepend or lightDepend == globalGroup
				or lightDepend.isPrimitive() or lightDepend.name == "void"
				or lightDepend.isSubgroup() or lightDepend.ignoreHeader or not lightDepend.isUsed(mainState)
				or (lightDepend.defined and lightDepend.sortedPosition <= group.sortedPosition)
			):
				continue

			forwardDeclarations.add(lightDependency)

		# Non-static internal member functions need a forward def for the 'this' pointer.
		if group != globalGroup:
			for funcImp in group.functionImplementations:
				if not funcImp.isStatic and funcImp.isInternal:
					forwardDeclarations.add(group.name)
					break

	# Output forward declarations
	for forwardDeclaration in sorted(forwardDeclarations):
		group = mainState.getGroup(forwardDeclaration)
		if group.template != None: out.write(group.template + "\n")
		out.write(group.groupType + " " + group.name + ";\n")

	out.write("\n")


def outputHeader(mainState: MainState, outputFileName: str, out: TextIOWrapper):

	def doOutput(internalPointersOut: TextIOWrapper):

		internalPointersList = []

		if internalPointersOut:
			internalPointersOut.write(f"\n#include \"{pathToFileName(outputFileName)}\"\n\n")

		newline: str = ""

		# Output groups
		for group in mainState.filteredGroups:
			if group.isSubgroup() or group.ignoreHeader: continue
			if not group.isUsed(mainState) or group.groupType == "undefined": continue
			out.write(newline)
			groupStr = group.writeHeader(mainState, internalPointersOut, internalPointersList, HeaderType.NORMAL)
			if groupStr != "":
				out.write(groupStr)
				newline = "\n\n"

		out.write("\n")

		if internalPointersOut:

			out.write("\nextern std::vector<std::pair<const TCHAR*, void**>> internalPointersMap;\n")

			if len(internalPointersList) > 0:
				internalPointersOut.write("\n")

			internalPointersOut.write("std::vector<std::pair<const TCHAR*, void**>> internalPointersMap {\n")
			for internalPointerNameTup in internalPointersList:
				internalPointersOut.write(f"\tstd::pair{{TEXT(\"{internalPointerNameTup[0]}\"), reinterpret_cast<void**>(&{internalPointerNameTup[1]})}},\n")

			internalPointersOut.write("};\n")


	if not mainState.noCustomTypes:
		outputInternalPointersFile = outputFileName[0:outputFileName.rindex('.')] + "_internal_pointers.cpp"
		with open(outputInternalPointersFile, "w") as internalPointersOut:
			doOutput(internalPointersOut)
	else:
		doOutput(None)


def processInputHeader(mainState: MainState, filePath: str=None, blob: str=None) -> None:

	state: CheckLinesState = CheckLinesState()

	currentGroup = None
	groupLevel = 0
	hitFirstBracket = False
	previousTemplate: str = None
	alreadyExisted = False

	def processLine(line: str):

		nonlocal state
		nonlocal currentGroup
		nonlocal groupLevel
		nonlocal hitFirstBracket
		nonlocal previousTemplate
		nonlocal alreadyExisted

		line = line.rstrip()
		leftOfExtends = None
		try:
			colonIndex = line.index(":")
			leftOfExtends = line[:colonIndex].strip()
		except ValueError:
			leftOfExtends = line

		split = splitKeepBrackets(leftOfExtends, [" "])
		declMatch: Match = re.match("^(?:\$pack_\d+\s+){0,1}(?:const\s+){0,1}(struct|class|enum|union)\s+(?:\/\*VFT\*\/\s+){0,1}(?:__cppobj\s+){0,1}(?:__unaligned\s+){0,1}(?:__declspec\(align\(\d+\)\)\s+){0,1}([^;]*?)(?:\s+\:\s+(.*?)){0,1}\s*$", line)

		# Attempt to start Group and fill .template, .groupType, .name, and .singleName
		if declMatch != None:
			
			nameStr: str = declMatch.group(2)
			
			existingGroup = mainState.tryGetGroup(nameStr)
			if existingGroup and existingGroup.defined:
				alreadyExisted = True
				currentGroup = existingGroup
			else:
				# Don't add explicitly defined template types (these need to be defined manually by me)
				nameParts = splitKeepBrackets(nameStr, ["::"])
				needContinue = False
				for namePart in nameParts:
					if namePart.startswith("<"): continue
					if namePart.find("<") != -1:
						needContinue = True
						break

				if needContinue:
					return

				currentGroup = Group()
				currentGroup.template = previousTemplate
				currentGroup.groupType = declMatch.group(1)
				currentGroup.defined = True
				currentGroup.updateSingleName(mainState, nameStr)
		
		# Track template lines, (previousTemplate is only set if the previous line was a template declaration outside of a Group)
		if currentGroup == None and len(split) >= 1 and stripTypeBrackets(split[0]) == "template":
			previousTemplate = line
		else:
			previousTemplate = None

		# Track Group lines
		if currentGroup != None:

			openBracketCount = line.count("{")
			groupLevel += openBracketCount
			groupLevel -= line.count("}")

			# TODO: Store struct declaration seperately so separately definitions can override the previous ones
			if (not alreadyExisted or (groupLevel > 0 and hitFirstBracket)):
				currentGroup.lines.append(line)

			if openBracketCount > 0: hitFirstBracket = True

			if hitFirstBracket and groupLevel == 0:
				# Register Group
				if not alreadyExisted:
					mainState.addGroup(currentGroup)

				currentGroup = None
				hitFirstBracket = False
				alreadyExisted = False

		else:
			processCommonGroupLines(mainState, state, line, globalGroup)

	if filePath:
		with open(filePath) as file:
			for line in file:
				processLine(line)
	elif blob:
		for line in blob.split("\n"):
			processLine(line)

	# Register last Group
	if (not alreadyExisted) and currentGroup != None:
		mainState.addGroup(currentGroup)



def main():

	mainState = MainState()

	inputFileName: str = None
	outputFileName: str = None
	bindingsFileName: str = None
	fixupFileName: str = None
	preludeFile: str = None
	bindingsPreludeFile: str = None
	ignoreHeaderFile: str = None
	wantedFile: str = None
	manualTypesFile: str = None
	alreadyDefinedUsertypesFile: str = None
	packingFile: str = None

	for k in islice(sys.argv, 1, None):
		if   k == "-normal":  assert False, "-normal removed"
		elif k == "-cleaned": assert False, "-cleaned removed"
		elif k == "-noCustomTypes": mainState.noCustomTypes = True
		elif (v := re.search("-inFile=(.+)",                      k)) != None: inputFileName               = v.group(1)
		elif (v := re.search("-outFile=(.+)",                     k)) != None: outputFileName              = v.group(1)
		elif (v := re.search("-bindingsOutFile=(.+)",             k)) != None: bindingsFileName            = v.group(1)
		elif (v := re.search("-fixupFile=(.+)",                   k)) != None: fixupFileName               = v.group(1)
		elif (v := re.search("-preludeFile=(.+)",                 k)) != None: preludeFile                 = v.group(1)
		elif (v := re.search("-bindingsPreludeFile=(.+)",         k)) != None: bindingsPreludeFile         = v.group(1)
		elif (v := re.search("-ignoreHeaderFile=(.+)",            k)) != None: ignoreHeaderFile            = v.group(1)
		elif (v := re.search("-wantedFile=(.+)",                  k)) != None: wantedFile                  = v.group(1)
		elif (v := re.search("-manualTypesFile=(.+)",             k)) != None: manualTypesFile             = v.group(1)
		elif (v := re.search("-alreadyDefinedUsertypesFile=(.+)", k)) != None: alreadyDefinedUsertypesFile = v.group(1)
		elif (v := re.search("-packingFile=(.+)",                 k)) != None: packingFile                 = v.group(1)


	builtins.globalGroup = Group()
	globalGroup.updateSingleName(mainState, "EngineGlobals")
	globalGroup.defined = True
	mainState.addGroup(globalGroup)

	if mainState.noCustomTypes:
		processInputHeader(mainState, blob="""
template<class T, int size>
struct Array
{
};

template<class POINTED_TO_TYPE>
struct Pointer
{
};

struct VoidPointer
{
};

struct CharString
{
};

struct ConstCharString
{
};
		""")

	with open(outputFileName, "w") as out:

		if manualTypesFile != None:
			processInputHeader(mainState, manualTypesFile)

		processInputHeader(mainState, inputFileName)

		# Process Group lines to derive types
		for group in mainState.groups:
			if group.linesProcessed: continue
			group.processLinesFillTypes(mainState)

		# Move multi-layer structs so that they nest properly
		for group in mainState.groups:
			group.updateNesting(mainState)

		# Run fixup file to make some necessary changes
		if fixupFileName != None:
			my_module = importlib.import_module(fixupFileName)
			my_module.fixup(mainState)

		for group in mainState.groups:
			group.checkForVGroup(mainState) # Fills vGroup and removes __vftable field if present.
			group.mapTemplateTypeNames()    # Maps the template names that appear in this Group's inheritance hierarchy to their originating Group.
			group.mapDependsOn(mainState)   # Attempts to derive type dependencies and light dependencies (those that need forward declarations).

		# Filter groups down to what is requested in wanted_types.txt and their subclasses / referenced types.
		filterGroups(mainState, wantedFile, ignoreHeaderFile, packingFile)

		# Fill templateUses and uniqueUseRepresentations
		for group in mainState.filteredGroups:
			group.scanInwardTypeRefs(mainState)

		# Try to fix dependency order (SLOW)
		tryResolveDependencyOrder(mainState.filteredGroups)

		# Rename groups to remove invalid characters / improve autogenerated names, fix clashing function fields, and fix clashing usertype names.
		checkRename(mainState, alreadyDefinedUsertypesFile)

		# Registers pointer types for every group, (for reference_ functions)
		registerPointerTypes(mainState)

		# Write bindings file
		if bindingsFileName:
			outBindingsPath, outBindingsBase = separatePathNoExt(bindingsFileName)
			with \
			open(bindingsFileName, "w") as bindingsOut, \
			open(f"{outBindingsPath}{outBindingsBase}_baseclass_offsets.h", "w") as baseclassHeaderOut, \
			open(f"{outBindingsPath}{outBindingsBase}_baseclass_offsets.cpp", "w") as baseclassOut:
				outputFile(bindingsPreludeFile, bindingsOut)
				writeBindings(mainState, mainState.filteredGroups, bindingsOut, baseclassHeaderOut, baseclassOut)

		# Write header prelude
		outputFile(preludeFile, out)

		# Write forward declarations
		outputForwardDeclarations(mainState, out)

		# Write header
		outputHeader(mainState, outputFileName, out)



if __name__ == "__main__":
    main()
