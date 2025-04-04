
###################################################################
# Generates the .h/.cpp files required to build the bindings DLL. #
# This file has been hacked together.                             #
# Good luck - here be dragons.                                    #
###################################################################

from enum import Enum
from io import TextIOWrapper
from itertools import islice
from typing import Callable, Generic, Match, Pattern, Tuple, TypeVar
import importlib.util
import os
import re
import sys
import threading # type: ignore - For attaching debugger


T = TypeVar("T")

class UniqueList(Generic[T]): pass

class UniqueWrapper(Generic[T]):

	__slots__ = ("list", "value")
	def __init__(self, list: UniqueList[T], value: T) -> None:
		self.list: UniqueList[T] = list
		self.value: T = value

	def __hash__(self) -> int:
		return self.list.pHash(self.value)

	def __eq__(self, other: object) -> bool:
		return isinstance(other, UniqueWrapper) and self.list.pEq(self.value, other.value)

class UniqueListNode(Generic[T]):

	__slots__ = ("previous", "next", "value")
	def __init__(self, previous, next, value) -> None:
		self.previous: UniqueListNode[T] = previous
		self.next: UniqueListNode[T] = next
		self.value: T = value

class UniqueListValueIterator(Generic[T]): pass
class UniqueListValueIterator(Generic[T]):

	__slots__ = ("node")
	def __init__(self, node) -> None:
		self.node: UniqueListNode[T] = node

	def __iter__(self) -> UniqueListValueIterator[T]:
		return self

	def __next__(self) -> T:
		if self.node.next:
			toReturn: T = self.node.value
			self.node = self.node.next
			return toReturn
		else:
			raise StopIteration

class UniqueListNodeIterator(Generic[T]): pass
class UniqueListNodeIterator(Generic[T]):

	__slots__ = ("node")
	def __init__(self, node) -> None:
		self.node: UniqueListNode[T] = node

	def __iter__(self) -> UniqueListNodeIterator[T]:
		return self

	def __next__(self) -> UniqueListNode[T]:
		if self.node.next:
			toReturn: UniqueListNode[T] = self.node
			self.node = self.node.next
			return toReturn
		else:
			raise StopIteration

class UniqueList(Generic[T]):

	def defaultHash(object: T) -> int:
		return id(object)

	def defaultEq(a: T, b: T) -> bool:
		return a is b

	__slots__ = ("head", "tail", "size", "pHash", "pEq", "map", "tempKey")
	def __init__(self, pHash: Callable[[T], int]=None, pEq: Callable[[T, T], bool]=None) -> None:
		super().__init__()
		self.head: UniqueListNode[T] = UniqueListNode(None, None, None)
		self.tail: UniqueListNode[T] = UniqueListNode(None, None, None)
		self.head.next = self.tail
		self.tail.previous = self.head
		self.size = 0
		self.pHash: Callable[[T], int] = pHash or UniqueList.defaultHash
		self.pEq: Callable[[T, T], bool] = pEq or UniqueList.defaultEq
		self.map: dict[UniqueWrapper, UniqueListNode] = {}
		self.tempKey: UniqueWrapper[T] = UniqueWrapper(self, None)

	def __iter__(self) -> UniqueListValueIterator[T]:
		return UniqueListValueIterator(self.head.next)

	def nodes(self) -> UniqueListNodeIterator[T]:
		return UniqueListNodeIterator(self.head.next)

	def addUnique(self, value: T) -> None:
		valueWrapper: UniqueWrapper[T] = UniqueWrapper(self, value)
		if not valueWrapper in self.map:
			self.map[valueWrapper] = self.append(value)
			self.size += 1

	def containsUnique(self, value: T) -> bool:
		self.tempKey.value = value
		return self.tempKey in self.map

	def getUnique(self, value: T) -> T:
		self.tempKey.value = value
		node: UniqueListNode[T] = self.map.get(self.tempKey)
		return node.value if node else None

	def removeUnique(self, value: T) -> None:
		self.tempKey.value = value
		if node := self.map.get(self.tempKey):
			del self.map[self.tempKey]
			self.remove(node)
			self.size -= 1

	def append(self, value: T) -> UniqueListNode[T]:
		node: UniqueListNode[T] = UniqueListNode(self.tail.previous, self.tail, value)
		self.tail.previous.next = node
		self.tail.previous = node
		self.size += 1
		return node

	def insertNodeBefore(self, node: UniqueListNode[T], insertingNode: UniqueListNode[T]) -> None:
		assert node != self.head
		insertingNode.previous = node.previous.previous
		insertingNode.next = node
		node.previous.next = insertingNode
		node.previous = insertingNode
		self.size += 1

	def insertNodeAfter(self, node: UniqueListNode[T], insertingNode: UniqueListNode[T]) -> None:
		assert node != self.tail
		insertingNode.previous = node
		insertingNode.next = node.next
		node.next.previous = insertingNode
		node.next = insertingNode
		self.size += 1

	def insertBefore(self, node: UniqueListNode[T], value: T) -> None:
		self.insertNodeBefore(node, UniqueListNode(None, None, value))
		self.size += 1

	def insertAfter(self, node: UniqueListNode[T], value: T) -> None:
		self.insertNodeAfter(node, UniqueListNode(None, None, value))
		self.size += 1

	def moveNodeBefore(self, movingNode: UniqueListNode[T], node: UniqueListNode[T]) -> None:
		self.remove(movingNode)
		self.insertNodeBefore(node, movingNode)

	def moveNodeAfter(self, movingNode: UniqueListNode[T], node: UniqueListNode[T]) -> None:
		self.remove(movingNode)
		self.insertNodeAfter(node, movingNode)

	def remove(self, node: UniqueListNode[T]) -> None:
		assert node != self.head and node != self.tail
		node.previous.next = node.next
		node.next.previous = node.previous
		self.size -= 1

	def insertionSort(self, comparator: Callable[[T, T], int]):

		curMovingNode: UniqueListNode[T] = self.head.next
		while curMovingNode != self.tail:

			curCompareNode: UniqueListNode[T] = curMovingNode
			while True:

				curCompareNode = curCompareNode.previous
				if curCompareNode == self.head:
					break

				if comparator(curCompareNode.value, curMovingNode.value) < 0:
					break

			curMovingNode = curMovingNode.next
			self.moveNodeAfter(curMovingNode.previous, curCompareNode)

	def getSize(self):
		return self.size



##################
# String Utility #
##################

def manipulate(typeManipulator: Callable[[str], str], typeStr: str) -> str:
	if typeManipulator:
		manipulated, _ = typeManipulator(typeStr)
		return manipulated
	else:
		return typeStr


def attemptManipulate(typeManipulator: Callable[[str], str], typeStr: str) -> tuple[str,bool]:
	if typeManipulator:
		return typeManipulator(typeStr)
	else:
		return typeStr, False


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


# Forward declarations just to suppress warnings
class Group: pass
class TypeReference: pass
class Field: pass
class LineGroupFlags: pass

class FlagSource(Enum):
	DEFAULT = 1
	EXPLICIT = 2


class LineGroupFlags:

	__slots__ = ("flags")
	def __init__(self):
		self.flags: dict = {}

	def getFlag(self, name: str):
		return self.flags.get(name)

	def setFlag(self, name: str, value) -> bool:
		if value == None:
			del self.flags[name]
		else:
			self.flags[name] = value

	def isFlagDefined(self, name: str) -> bool:
		return name in self.flags

	def isFlagged(self, name: str) -> bool:
		# Ternary to do "truthy" evaluation
		return True if self.flags.get(name) else False

	def isExplicitlyFlagged(self, name: str) -> bool:
		return self.flags.get(name) == FlagSource.EXPLICIT

	def applyTo(self, other: LineGroupFlags):
		for name, flag in self.flags.items():
			other.flags[name] = flag

	def transferTo(self, other: LineGroupFlags, name: str):
		if (flag := self.flags.get(name)) != None:
			other.flags[name] = flag


class MainState:

	def __init__(self):
		self.groupsDict: dict[str,Group] = {}
		self.groups: list[Group] = []
		self.globalGroup: Group = None
		self.filteredGroups: UniqueList[Group] = UniqueList()
		self.noCustomTypes: bool = None
		self.manualPatternHandling: bool = False
		self.forceByteStrings: bool = False
		self.printFuncByteString: str = None
		self.printFuncWideString: str = None
		self.printFuncOmitNewline: bool = False
		self.idaUnnamedScheme: bool = False
		self.lineGroupFlags: LineGroupFlags = LineGroupFlags()


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
					group.addInwardTypeRef(inRef)

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
					print(f"\t\t[{j}]=\"{tup[j].getHeaderName()}\"")



class TemplateTypeMode(Enum):
	USER_TYPE = 1
	HEADER = 2



primitives          = { "byte", "short", "ushort", "uint", "ptrdiff_t", "intptr_t", "uintptr_t", "size_t", "int", "__int8", "__int16", "__int32", "__int64", "int8_t", "uint8_t", "int16_t", "uint16_t", "int32_t", "uint32_t", "int64_t", "uint64_t", "long", "bool", "char", "float", "wchar_t", "double", "long double", "BOOL", "DWORD", "HRESULT", "INT", "LONG", "LPCSTR", "LRESULT", "UINT" }
handledPrimitives   = { "byte", "short", "ushort", "uint", "ptrdiff_t", "intptr_t", "uintptr_t", "size_t", "int", "__int8", "__int16", "__int32", "__int64", "int8_t", "uint8_t", "int16_t", "uint16_t", "int32_t", "uint32_t", "int64_t", "uint64_t", "long", "bool", "char", "float",            "double", "long double", "BOOL", "DWORD", "HRESULT", "INT", "LONG", "LPCSTR", "LRESULT", "UINT" }
primitiveNumbers    = { "byte", "short", "ushort", "uint", "ptrdiff_t", "intptr_t", "uintptr_t", "size_t", "int", "__int8", "__int16", "__int32", "__int64", "int8_t", "uint8_t", "int16_t", "uint16_t", "int32_t", "uint32_t", "int64_t", "uint64_t", "long",                 "float",            "double", "long double", "BOOL", "DWORD", "HRESULT", "INT", "LONG",           "LRESULT", "UINT" }
primitiveStrings    = { "char",                                           "LPCSTR"    }
stringPointerLevels = { "char": 0, "CharString": 1, "ConstCharString": 1, "LPCSTR": 1 }
stringImplicitConst = {                             "ConstCharString",    "LPCSTR"    }
pointerAliases      = {
	"HANDLE":  {"type": "void",  "pointerLevel": 1 },
	"HWND":    {"type": "void",  "pointerLevel": 1 },
	"LPMSG":   {"type": "MSG",   "pointerLevel": 1 },
	"LPPOINT": {"type": "POINT", "pointerLevel": 1 },
	"LPVOID":  {"type": "void",  "pointerLevel": 1 },
}

class TypeReference:

	def __init__(self):

		self.sourceGroup: Group = None
		self.sourceType: TypeRefSourceType = None
		self.sourceString: str = None
		self.isDirectlyWanted: bool = None

		self.group: Group = None

		self.pointerLevel: int = 0
		self.reference: bool = False
		self.arrayParts: list = []
		self.bitFieldPart: str = None
		self.templateTypes: list[TypeReference] = []

		self.primitive: bool = False
		self.noconst: bool = False

		self.unsigned: bool = False
		self.const: bool = False
		self.implicitConst: bool = False
		self.volatile: bool = False
		self.long: bool = False

		self.superRef: TypeReference = None
		self.subRef: TypeReference = None


	def __repr__(self):
		return self.getHeaderName()


	def copyTrivialFields(self, other):
		self.const = other.const
		self.long = other.long
		self.noconst = other.noconst
		self.primitive = other.primitive
		self.sourceGroup = other.sourceGroup
		self.sourceString = other.sourceString
		self.sourceType = other.sourceType
		self.unsigned = other.unsigned
		self.volatile = other.volatile


	def getModifierStr(self):
		parts: list[str] = []
		if self.const and not self.implicitConst: parts.append("const ")
		if self.unsigned:                         parts.append("unsigned ")
		if self.volatile:                         parts.append("volatile ")
		if self.long:                             parts.append("long ")
		return "".join(parts)


	def getCastModifierStr(self):
		parts: list[str] = []
		if self.const:    parts.append("const ")
		if self.unsigned: parts.append("unsigned ")
		if self.long:     parts.append("long ")
		return "".join(parts)


	def isAbstractValue(self):
		return self.group is not None and self.group.abstract and self.getUserTypePointerLevel() == 0


	def isConst(self):
		return self.const


	def setConst(self, newVal: bool):
		self.const = newVal


	def removeFromGroupRefs(self):
		if self.group:
			self.group.inwardTypeRefs.removeUnique(self)


	def changeReferencedGroup(self, newGroup: Group):
		if not (self.group is newGroup):
			self.removeFromGroupRefs()
			self.group = newGroup
			if newGroup != None:
				self.group.addInwardTypeRef(self)


	def shallowCopy(self, copyObj: TypeReference=None, noTemplateTypes=False) -> TypeReference:

		copyObj = copyObj or TypeReference()
		copyObj.copyTrivialFields(self)
		copyObj.arrayParts = self.arrayParts
		copyObj.bitFieldPart = self.bitFieldPart
		copyObj.group = self.group
		copyObj.pointerLevel = self.pointerLevel
		copyObj.subRef = self.subRef
		copyObj.superRef = self.superRef

		copyTemplateTypes: list[TypeReference] = []

		if not noTemplateTypes:
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


	def getCastName(self):
		return f"{self.getCastModifierStr()}{self.getName()}"


	def getSingleName(self):
		return self.group and self.group.singleName or self.sourceString


	def getTemplates(self, mainState: MainState, askingGroup: Group=None):
		return self.templateTypes


	def getTemplateList(self) -> list[TypeReference]:
		return self.templateTypes


	def isNonPointerVoid(self):
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
		return self.group and len(self.group.templateTypeNames) > 0 and len(self.templateTypes) == 0


	def isTemplateIncomplete(self, mainState: MainState, askingGroup: Group=None):

		"""
		Returns true if any part of the TypeReference is either:
		1) Unparameterized (should have templates, but doesn't)
		2) Generic (a template type placeholder)
		"""

		if self.isUnparameterized():
			return True

		for templateRef in self.getTemplates(mainState, askingGroup=askingGroup):
			if templateRef.isGenericTemplate() or templateRef.isTemplateIncomplete(mainState, askingGroup=askingGroup):
				return True

		return self.superRef is not None and self.superRef.isTemplateIncomplete(mainState, askingGroup=askingGroup)


	def isPrimitive(self):
		return self.getName() in primitives


	def isPrimitiveNumber(self):
		return self.getName() in primitiveNumbers


	def isPrimitiveString(self):
		return self.getName() in primitiveStrings


	def isEnum(self) -> bool:
		"""
		Returns `True` if `self` references an enum `Group`
		"""
		return self.group and self.group.groupType == "enum"


	def getEnumName(self) -> str:
		"""
		Returns the name of the enum `Group` that `self` references
		"""
		assert self.isEnum(), "Not an enum"
		return self.getName()


	def getPrimitiveEnumType(self, mainState: MainState) -> TypeReference:
		"""
		Returns the primitive enum `TypeReference` that `self` references
		"""
		assert self.isEnum(), "Not an enum"
		copy: TypeReference = self.shallowCopy()
		copy.changeReferencedGroup(self.getExtends()[0].getGroup())
		return copy


	def getExtends(self) -> list[TypeReference]:
		"""
		Returns a `list[TypeReference]` that holds the `TypeReference`s that `self`'s `Group` extends
		"""
		return self.group.extends if self.group else []


	def setUserTypePointerLevel(self, mainState: MainState, newVal: int) -> None:
		assert newVal >= 0, "self.pointerLevel cannot be negative"
		self.pointerLevel = newVal


	def getUserTypePointerLevel(self):
		return self.pointerLevel


	def getHeaderPointerLevel(self):
		return self.pointerLevel


	def adjustUserTypePointerLevel(self, mainState: MainState, adjustAmount: int) -> None:
		self.setUserTypePointerLevel(mainState, self.getUserTypePointerLevel() + adjustAmount)


	def replaceTemplateType(self, mainState: MainState, sourceGroup: Group, templateMappingTracker: TemplateMappingTracker) -> TypeReference:

		"""
		Replaces this type reference with a template mapping stored in `templateMappingTracker`, else returns None.
		"""

		toReturn: TypeReference = None
		selfName: str = self.getName()

		if sourceGroup and (v := sourceGroup.templateTypeNameMapping.get(selfName)) != None:

			index: int = v.templateTypeNames.index(selfName)
			mapped: TypeReference = templateMappingTracker.getMapping(v.name)[index]

			# HACK HACK HACK HACK HACK HACK HACK HACK HACK HACK HACK HACK HACK HACK HACK HACK HACK
			# HACK PointerReferences store their internal TypeReference as their template     HACK
			# HACK parameter. These still need to be exposed as a PointerReference so they    HACK
			# HACK properly handle their pointer level being changed. Getting the header      HACK
			# HACK name of the internal reference and defining it again to transform it into  HACK
			# HACK a PointerReference.                                                        HACK
			# HACK HACK HACK HACK HACK HACK HACK HACK HACK HACK HACK HACK HACK HACK HACK HACK HACK
			if sourceGroup.name == "Pointer":
				toReturn = defineTypeRef(mainState, sourceGroup, mapped.getHeaderName(pointerLevelAdjust=self.getUserTypePointerLevel()), self.sourceType, debugLine="checkReplaceTemplateType()")
			else:
				toReturn = mapped.shallowCopy()
				toReturn.adjustUserTypePointerLevel(mainState, self.getUserTypePointerLevel())

			toReturn.primitive = toReturn.primitive or self.primitive
			toReturn.noconst = toReturn.noconst or self.noconst
			toReturn.setConst(toReturn.isConst() or self.isConst())

		return toReturn


	def checkReplaceTemplateType(self, mainState: MainState, sourceGroup: Group, templateMappingTracker: TemplateMappingTracker) -> TypeReference:
		toReturn: TypeReference = self.replaceTemplateType(mainState, sourceGroup, templateMappingTracker)
		return toReturn if toReturn else self


	def resolveTemplateTypes(self, mainState: MainState, sourceGroup: Group, templateMappingTracker: TemplateMappingTracker) -> TypeReference:

		"""
		Completely resolves template types for the current TypeReference as mapped by `templateMappingTracker`.
		Returns None if no substitution occurs.
		"""

		# Is the type itself generic?
		topLevelAttempt: TypeReference = self.replaceTemplateType(mainState, sourceGroup, templateMappingTracker)
		if topLevelAttempt is not None:
			return topLevelAttempt

		resolvedTemplateRefs: list[TypeReference] = []
		replacedSomething: bool = False

		# Try to resolve each template parameter
		for templateRef in self.getTemplates(mainState, askingGroup=self.getGroup()):

			# Attempt resolve of template parameter (recursive)
			templateReplaceAttempt: TypeReference = templateRef.resolveTemplateTypes(mainState, sourceGroup, templateMappingTracker)

			if templateReplaceAttempt is not None:
				# Template parameter replaced, track replacement
				resolvedTemplateRefs.append(templateReplaceAttempt)
				replacedSomething = True
			else:
				# Template parameter NOT replaced, track original
				resolvedTemplateRefs.append(templateRef.shallowCopy())

		if not replacedSomething:
			# Nothing replaced, return None
			return None

		# Copy self and replace template types with resolved references
		selfCopy: TypeReference = self.shallowCopy(noTemplateTypes=True)
		selfCopy.getTemplateList().extend(resolvedTemplateRefs)
		return selfCopy


	def _getAppliedNameInternal(self, mainState: MainState, sourceGroup: Group, templateMappingTracker: TemplateMappingTracker,
		pointerLevelAdjust=0, useUsertypeOverride=False, noModifiers=False, templateTypeMode: TemplateTypeMode=None,
		typeManipulator: Callable[[str], str]=None, noTemplate: bool=False, noPointers: bool=False):

		"""
		Given a TypeRef in which the caller wants to express an arbitrary series of template uses, returns a
		string representation of the current TypeRef's group name as if its template types were filled with the information
		held by templateMappingTracker.

		If the current TypeRef does not have an attached Group, simply returns the TypeRef's name.
		"""

		assert templateTypeMode, "templateTypeMode must be defined!"

		parts: list[str] = []

		if not noModifiers:
			parts.append(self.getModifierStr())

		alreadyHaveName = False

		if superRef := self.getSuperRef():

			manipulatedNameNoTemplatesOrPointers: str = None
			manipulated: bool = False

			if typeManipulator:

				manipulatedNameNoTemplatesOrPointers, manipulated = attemptManipulate(typeManipulator, self._getAppliedNameInternal(mainState, sourceGroup,
					templateMappingTracker, useUsertypeOverride=useUsertypeOverride, templateTypeMode=templateTypeMode, noModifiers=True, noTemplate=True, noPointers=True))

			if manipulated:
				parts.append(manipulatedNameNoTemplatesOrPointers)
				alreadyHaveName = True
			else:
				parts.append(superRef._getAppliedNameInternal(mainState, sourceGroup, templateMappingTracker, useUsertypeOverride=useUsertypeOverride,
					templateTypeMode=templateTypeMode, typeManipulator=typeManipulator))
				parts.append("::")

		templateTypes: list[TypeReference] = self.getTemplates(mainState, askingGroup=self.group)
		if len(templateTypes) > 0:

			if not alreadyHaveName:
				parts.append(manipulate(typeManipulator, self.getSingleName()))

			assert parts[-1] != None, "Using bad self.getSingleName()"

			if not noTemplate:

				parts.append("<")

				if templateTypeMode == TemplateTypeMode.USER_TYPE:
					for templateType in templateTypes:
						replaced = templateType.checkReplaceTemplateType(mainState, sourceGroup, templateMappingTracker)
						parts.append(replaced.getAppliedUserTypeName(mainState, sourceGroup, templateMappingTracker, useUsertypeOverride=useUsertypeOverride,
							typeManipulator=typeManipulator))
						assert parts[-1] != None, f"Using bad templateType.getAppliedUserTypeName() for (original: {type(templateType).__name__}, replaced: {type(replaced).__name__}) [TemplateTypeMode.USER_TYPE]"
						parts.append(",")
				elif templateTypeMode == TemplateTypeMode.HEADER:
					for templateType in templateTypes:
						replaced = templateType.checkReplaceTemplateType(mainState, sourceGroup, templateMappingTracker)
						parts.append(replaced.getAppliedHeaderName(mainState, sourceGroup, templateMappingTracker, useUsertypeOverride=useUsertypeOverride,
							typeManipulator=typeManipulator))
						assert parts[-1] != None, f"Using bad templateType.getAppliedUserTypeName() for (original: {type(templateType).__name__}, replaced: {type(replaced).__name__}) [TemplateTypeMode.HEADER]"
						parts.append(",")

				parts.pop()
				parts.append(">")

		elif self.group:
			parts.append(self.group.getAppliedName(mainState, templateMappingTracker, useUsertypeOverride=useUsertypeOverride, templateTypeMode=templateTypeMode,
				singleName=True, typeManipulator=typeManipulator, noTemplate=noTemplate, noName=alreadyHaveName))
			assert parts[-1] != None, "Using bad group.getAppliedName()"
		else:
			parts.append(manipulate(typeManipulator, self.sourceString))
			assert parts[-1] != None, "Using bad self.sourceString"

		if not noPointers:
			for _ in range(self.getUserTypePointerLevel() + pointerLevelAdjust):
				parts.append("*")

		return "".join(parts)


	def getHeaderName(self, pointerLevelAdjust=0, useUsertypeOverride: bool=False, typeManipulator: Callable[[str], str]=None):
		return self.toString(pointerLevelAdjust=pointerLevelAdjust, useUsertypeOverride=useUsertypeOverride, templatesUseHeaderName=True, iKnowWhatIAmDoing=True, typeManipulator=typeManipulator)


	def getAppliedHeaderName(self, mainState: MainState, sourceGroup: Group, templateMappingTracker: TemplateMappingTracker, pointerLevelAdjust=0, useUsertypeOverride=False,
		typeManipulator: Callable[[str], str]=None):

		return self._getAppliedNameInternal(mainState, sourceGroup, templateMappingTracker, pointerLevelAdjust=pointerLevelAdjust, useUsertypeOverride=useUsertypeOverride,
			templateTypeMode=TemplateTypeMode.HEADER, typeManipulator=typeManipulator)


	def getAppliedUserTypeName(self, mainState: MainState, sourceGroup: Group, templateMappingTracker: TemplateMappingTracker, useUsertypeOverride=False,
		typeManipulator: Callable[[str], str]=None, forcePointer: bool=False):

		return self._getAppliedNameInternal(mainState, sourceGroup, templateMappingTracker, useUsertypeOverride=useUsertypeOverride, noModifiers=True,
			templateTypeMode=TemplateTypeMode.HEADER, typeManipulator=typeManipulator)


	def toString(self, pointerLevelAdjust=0, useUsertypeOverride=False, templatesUseHeaderName=False, iKnowWhatIAmDoing=False,
		typeManipulator: Callable[[str], str]=None, noModifiers: bool=False, noTemplate: bool=False, noPointers: bool=False) -> str:

		parts: list[str] = []

		if not noModifiers:
			parts.append(self.getModifierStr())

		alreadyHaveName: bool = False

		if superRef := self.getSuperRef():

			manipulatedNameNoTemplatesOrPointers: str = None
			manipulated: bool = False

			if typeManipulator:

				manipulatedNameNoTemplatesOrPointers, manipulated = attemptManipulate(typeManipulator, self.toString(self, useUsertypeOverride=useUsertypeOverride,
					templatesUseHeaderName=templatesUseHeaderName, iKnowWhatIAmDoing=iKnowWhatIAmDoing, noModifiers=True, noTemplate=True, noPointers=True))

			if manipulated:
				parts.append(manipulatedNameNoTemplatesOrPointers)
				alreadyHaveName = True
			else:
				parts.append(superRef.toString(useUsertypeOverride=useUsertypeOverride, templatesUseHeaderName=templatesUseHeaderName,
					iKnowWhatIAmDoing=iKnowWhatIAmDoing, typeManipulator=typeManipulator))
				parts.append("::")

		if not alreadyHaveName:
			if useUsertypeOverride and self.group != None and self.group.overrideUsertypeSingleName != None:
				parts.append(manipulate(typeManipulator, self.group.overrideUsertypeSingleName))
			else:
				parts.append(manipulate(typeManipulator, self.getSingleName()))

		if not noTemplate:

			if len(self.templateTypes) > 0:

				parts.append("<")

				if templatesUseHeaderName:
					for templateType in self.templateTypes:
						parts.append(templateType.getHeaderName(typeManipulator=typeManipulator))
						parts.append(",")
				else:
					for templateType in self.templateTypes:
						parts.append(templateType.toString(iKnowWhatIAmDoing=iKnowWhatIAmDoing, typeManipulator=typeManipulator))
						parts.append(",")

				parts.pop()
				parts.append(">")

		if not noPointers:

			adjustedPointerLevel: int = self.getUserTypePointerLevel() + pointerLevelAdjust

			for _ in range(adjustedPointerLevel if not self.reference else adjustedPointerLevel - 1):
				parts.append("*")

			if self.reference and adjustedPointerLevel > 0:
				parts.append("&")

		return "".join(parts)


	# TODO: This is a really bad way of doing this
	def sameTypeAs(self, other: TypeReference):
		return self.getHeaderName() == other.getHeaderName()


	def getDereferenceStr(self: TypeReference, mainState: MainState, sourceGroup: Group, templateMappingTracker: TemplateMappingTracker, i: int):

		dereferenceStr = ""
		if self.getUserTypePointerLevel() == 0:
			# UserData objects only hold pointers; parameters that are passed-by-value need to be dereferenced
			self = self.shallowCopy()
			self.adjustUserTypePointerLevel(mainState, 1)
			dereferenceStr = "*"

		adjustedRef = self
		forcePointer: bool = False
		primitiveLike: bool = self.isPrimitive() or self.isEnum()

		if self.getUserTypePointerLevel() > (0 if primitiveLike else 1):
			# UserData objects are initialized with the value of the pointer
			# which essentially removes one pointer level from the type
			# (TODO: this should probably be templated somewhere)
			adjustedRef = self.shallowCopy()
			adjustedRef.adjustUserTypePointerLevel(mainState, -1)
			forcePointer = not primitiveLike

		appliedParamName = self.getAppliedHeaderName(mainState, sourceGroup, templateMappingTracker)
		appliedParamUsertype = adjustedRef.getAppliedUserTypeName(mainState, sourceGroup, templateMappingTracker, useUsertypeOverride=True, forcePointer=forcePointer)
		return f"{dereferenceStr}({appliedParamName})tolua_tousertype_dynamic(L, {i}, 0, \"{appliedParamUsertype}\")"


	def debugDump(self: TypeReference, indent: str=""):
		parts = []
		parts.append(f"{indent}class: {type(self).__name__}\n")
		parts.append(f"{indent}sourceString: {self.sourceString}\n")
		parts.append(f"{indent}group: {self.group.name if self.group else "None"}\n")
		parts.append(f"{indent}sourceGroup: {self.sourceGroup.name if self.sourceGroup else "None"}\n")
		parts.append(f"{indent}pointerLevel: {self.pointerLevel}\n")
		parts.append(f"{indent}reference: {self.reference}\n")
		parts.append(f"{indent}arrayParts: {self.arrayParts}\n")
		parts.append(f"{indent}bitFieldPart: {self.bitFieldPart}\n")
		parts.append(f"{indent}templateTypes: {self.templateTypes}\n")
		parts.append(f"{indent}primitive: {self.primitive}\n")
		parts.append(f"{indent}noconst: {self.noconst}\n")
		parts.append(f"{indent}unsigned: {self.unsigned}\n")
		parts.append(f"{indent}const: {self.const}\n")
		parts.append(f"{indent}volatile: {self.volatile}\n")
		parts.append(f"{indent}long: {self.long}\n")
		parts.append(f"{indent}superRef: {self.superRef}\n")
		parts.append(f"{indent}subRef: {self.subRef}\n")
		return "".join(parts)



class PointerReference: pass
class PointerReference(TypeReference):

	def __init__(self):
		super().__init__()
		self.originalRef: TypeReference = None
		self.intrinsicPointerAdjust: int = 0


	@staticmethod
	def create(mainState: MainState, originalRef: TypeReference, debugLine: str=""):

		assert not isinstance(originalRef, PointerReference), "Wrapception: PointerReference"
		obj = PointerReference()
		obj.copyTrivialFields(originalRef)

		obj.originalRef = originalRef
		obj.setUserTypePointerLevel(mainState, originalRef.getUserTypePointerLevel())

		if originalRef.group:
			originalRef.group.addInwardTypeRef(originalRef)
			alias = pointerAliases.get(originalRef.group.name)
			obj.intrinsicPointerAdjust = alias["pointerLevel"] if alias is not None else 0

		return obj


	def shallowCopy(self, copyObj=None, noTemplateTypes=False):
		copyObj = copyObj or PointerReference()
		super().shallowCopy(copyObj)
		originalRef: TypeReference = copyObj.templateTypes[0] if len(copyObj.templateTypes) > 0 else self.originalRef
		copyObj.originalRef = originalRef.shallowCopy(noTemplateTypes=noTemplateTypes)
		return copyObj


	def getSuperRef(self):
		return self.originalRef.superRef


	def isGroupUsed(self, mainState: MainState):
		return self.originalRef.isGroupUsed(mainState)


	def isEnum(self):
		return self.originalRef.isEnum()


	def getEnumName(self):
		return self.originalRef.getEnumName()


	def getPrimitiveEnumType(self, mainState: MainState):
		# The wrapping PointerReference might have changed the contained enum TypeReference's pointer level
		toReturn: TypeReference = self.originalRef.getPrimitiveEnumType(mainState)
		toReturn.setUserTypePointerLevel(mainState, self.getUserTypePointerLevel()) # Correct the pointer level
		return toReturn


	def getExtends(self):
		return self.originalRef.getExtends()


	def isConst(self):
		return self.originalRef.isConst()


	def setConst(self, newVal: bool):
		self.originalRef.setConst(newVal)


	def isUnparameterized(self):
		return self.originalRef.isUnparameterized()


	def getGroup(self):
		return self.originalRef.group


	def getArrayParts(self):
		return self.originalRef.getArrayParts()


	def getName(self):
		return self.originalRef.getName()


	def getHeaderPointerLevel(self):
		return self.getUserTypePointerLevel() + 1


	def getUserTypePointerLevel(self):
		return super().getUserTypePointerLevel() + self.intrinsicPointerAdjust


	def setUserTypePointerLevel(self, mainState: MainState, newVal: int) -> None:

		super().setUserTypePointerLevel(mainState, newVal)

		if newVal == 0:

			self.originalRef.setUserTypePointerLevel(mainState, 0)
			if len(self.templateTypes) > 0:
				self.templateTypes.pop()

			if self.originalRef.isPrimitive() or self.originalRef.isEnum():
				# Primitive and enum values (pointer level of 0) are exposed using the "Primitive" group when
				# their value is being referenced instead of directly exported as a comparable Lua type.
				self.changeReferencedGroup(mainState.getGroup("Primitive"))
			else:
				self.changeReferencedGroup(self.originalRef.group)

		else:

			self.originalRef.setUserTypePointerLevel(mainState, newVal - 1)
			if len(self.templateTypes) == 0:
				self.templateTypes.append(self.originalRef)

			if self.originalRef.isNonPointerVoid() and newVal <= 2:
				if newVal == 1:
					# Binding `ud->void` - No idea what type is on the other side
					self.changeReferencedGroup(mainState.getGroup("UnmappedUserType"))
				elif newVal == 2:
					# Binding `ud->void*` - `VoidPointer` disallows dereferencing
					self.changeReferencedGroup(mainState.getGroup("VoidPointer"))
			else:
				self.changeReferencedGroup(mainState.getGroup("Pointer"))


	def getHeaderName(self, pointerLevelAdjust=0, useUsertypeOverride: bool=False, typeManipulator: Callable[[str], str]=None):
		if self.getUserTypePointerLevel() == 0:
			return f"{self.originalRef.getHeaderName(pointerLevelAdjust=pointerLevelAdjust, useUsertypeOverride=useUsertypeOverride, typeManipulator=typeManipulator)}"
		else:
			pointerLevelAdjust = pointerLevelAdjust + 1 - self.intrinsicPointerAdjust
			return f"{self.originalRef.getHeaderName(pointerLevelAdjust=pointerLevelAdjust, useUsertypeOverride=useUsertypeOverride, typeManipulator=typeManipulator)}"


	def getAppliedHeaderName(self, mainState: MainState, sourceGroup: Group, templateMappingTracker: TemplateMappingTracker, pointerLevelAdjust=0, useUsertypeOverride=False,
		typeManipulator: Callable[[str], str]=None):

		if self.getUserTypePointerLevel() == 0:
			return self.originalRef.getAppliedHeaderName(mainState, sourceGroup, templateMappingTracker, pointerLevelAdjust=pointerLevelAdjust,
				useUsertypeOverride=useUsertypeOverride, typeManipulator=typeManipulator)
		else:
			innerType = self.originalRef.checkReplaceTemplateType(mainState, sourceGroup, templateMappingTracker)
			pointerLevelAdjust = pointerLevelAdjust + 1 - self.intrinsicPointerAdjust
			return f"{innerType.getAppliedHeaderName(mainState, sourceGroup, templateMappingTracker, pointerLevelAdjust=pointerLevelAdjust, useUsertypeOverride=useUsertypeOverride, typeManipulator=typeManipulator)}"


	def getAppliedUserTypeName(self, mainState: MainState, sourceGroup: Group, templateMappingTracker: TemplateMappingTracker, useUsertypeOverride=False,
		typeManipulator: Callable[[str], str]=None, forcePointer: bool=False):

		if self.getUserTypePointerLevel() == 0:
			assert not self.originalRef.isNonPointerVoid(), "Literal 'void' should never appear"
			if self.originalRef.isPrimitive() or self.originalRef.isEnum():
				# Primitive<x>
				return f"{manipulate(typeManipulator, self.group.name)}<{manipulate(typeManipulator, self.originalRef.group.name)}>"
			else:
				return self.originalRef.getAppliedUserTypeName(mainState, sourceGroup, templateMappingTracker, useUsertypeOverride=useUsertypeOverride,
					typeManipulator=typeManipulator)
		elif self.originalRef.isNonPointerVoid() and self.getUserTypePointerLevel() <= 2:
			if forcePointer and self.getUserTypePointerLevel() == 1:
				return manipulate(typeManipulator, "VoidPointer")
			else:
				# 1 = UnmappedUserType, 2 = VoidPointer
				return manipulate(typeManipulator, self.group.name)
		else:
			innerType = self.originalRef.checkReplaceTemplateType(mainState, sourceGroup, templateMappingTracker)
			innerStr: str = None
			# Primitives and Enums are only allowed to bind through Primitive<x>, not their raw type
			if not forcePointer and innerType.getUserTypePointerLevel() == 0 and not innerType.isPrimitive() and not innerType.isEnum():
				innerStr = innerType.getAppliedUserTypeName(mainState, sourceGroup, templateMappingTracker, useUsertypeOverride=useUsertypeOverride,
					typeManipulator=typeManipulator)
			else:
				innerStr = f"{manipulate(typeManipulator, self.group.name)}<{innerType.getAppliedHeaderName(mainState, sourceGroup, templateMappingTracker, useUsertypeOverride=useUsertypeOverride, typeManipulator=typeManipulator)}>"
			return innerStr


	def getTemplates(self, mainState: MainState, askingGroup: Group=None):
		if askingGroup is not None and askingGroup.name in ("Pointer", "VoidPointer"):
			return self.templateTypes
		elif self.getUserTypePointerLevel() == 0:
			return self.originalRef.getTemplates(mainState)
		else:
			realRef = self.originalRef.shallowCopy()
			realRef.adjustUserTypePointerLevel(mainState, 1)
			return realRef.getTemplates(mainState)


	def getTemplateList(self) -> list[TypeReference]:
		return self.originalRef.templateTypes


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


	def toString(self, pointerLevelAdjust=0, useUsertypeOverride=False, templatesUseHeaderName=False, iKnowWhatIAmDoing=False,
		typeManipulator: Callable[[str], str]=None) -> str:

		assert iKnowWhatIAmDoing, "You don't know what you're doing!"
		effectivePointerAdj = pointerLevelAdjust if self.getUserTypePointerLevel() == 0 else pointerLevelAdjust + 1
		return self.originalRef.toString(pointerLevelAdjust=effectivePointerAdj, useUsertypeOverride=useUsertypeOverride, templatesUseHeaderName=templatesUseHeaderName,
			iKnowWhatIAmDoing=iKnowWhatIAmDoing, typeManipulator=typeManipulator)


	def getDereferenceStr(self: PointerReference, mainState: MainState, sourceGroup: Group, templateMappingTracker: TemplateMappingTracker, i: int):
		# if self.originalRef.isPrimitive():
		# 	extraDereference = 1 if self.originalRef.isPrimitive() else 0
		# 	appliedParamName = self.getAppliedHeaderName(mainState, sourceGroup, templateMappingTracker, pointerLevelAdjust=extraDereference)
		# 	appliedParamUsertype = self.getAppliedUserTypeName(mainState, sourceGroup, templateMappingTracker, useUsertypeOverride=True)
		# 	return f"{'*'*extraDereference}({appliedParamName})tolua_tousertype_dynamic(L, {i}, 0, \"{appliedParamUsertype}\")"
		# else:
			return super().getDereferenceStr(mainState, sourceGroup, templateMappingTracker, i)


	def debugDump(self: PointerReference, indent: str=""):
		parts = []
		parts.append(f"{indent}class: {type(self).__name__}\n")
		parts.append(f"{indent}originalRef:\n")
		parts.append(self.originalRef.debugDump(indent=f"{indent}\t"))
		return "".join(parts)



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

		if not obj.const and originalRef.group.name in stringImplicitConst:
			obj.const = True
			obj.implicitConst = True

		obj.mode = mode
		if obj.mode == CharReferenceMode.PRIMITIVE_ONLY:
			obj.changeReferencedGroup(originalRef.group)
			obj.setUserTypePointerLevel(mainState, originalRef.getUserTypePointerLevel())
		elif obj.mode == CharReferenceMode.USER_TYPE_ONLY:
			obj.changeReferencedGroup(originalRef.group)
			obj.setUserTypePointerLevel(mainState, originalRef.getUserTypePointerLevel() + stringPointerLevels[originalRef.group.name] - 1)
		elif obj.mode == CharReferenceMode.MORPHING:
			obj.setUserTypePointerLevel(mainState, originalRef.getUserTypePointerLevel() + stringPointerLevels[originalRef.group.name])

		return obj


	def shallowCopy(self, copyObj=None, noTemplateTypes=False):
		copyObj = copyObj or CharReference()
		super().shallowCopy(copyObj, noTemplateTypes=noTemplateTypes)
		copyObj.mode = self.mode
		copyObj.charPointerLevel = self.charPointerLevel
		return copyObj


	def getHeaderPointerLevel(self):
		return self.charPointerLevel


	def setUserTypePointerLevel(self, mainState: MainState, newVal: int) -> None:
		if self.mode == CharReferenceMode.PRIMITIVE_ONLY:
			newVal += stringPointerLevels[self.group.name]
			self.charPointerLevel = newVal
			super().setUserTypePointerLevel(mainState, newVal)
		elif self.mode == CharReferenceMode.USER_TYPE_ONLY:
			self.charPointerLevel = newVal + 1
			super().setUserTypePointerLevel(mainState, newVal)
		elif self.mode == CharReferenceMode.MORPHING:
			newVal = newVal if self.charPointerLevel != 1 else newVal + 1
			self.charPointerLevel = newVal
			if newVal == 1:
				super().setUserTypePointerLevel(mainState, 0)
				self.changeReferencedGroup(mainState.getGroup(f"{'Const' if self.const else ''}CharString"))
			else:
				super().setUserTypePointerLevel(mainState, newVal)
				self.changeReferencedGroup(mainState.getGroup("char"))


	def getHeaderName(self, pointerLevelAdjust=0, useUsertypeOverride: bool=False, typeManipulator: Callable[[str], str]=None):
		if self.mode == CharReferenceMode.PRIMITIVE_ONLY:
			pointerLevelAdjust -= stringPointerLevels[self.group.name]
			return f"{self.getModifierStr()}{manipulate(typeManipulator, self.group.name)}{'*'*(self.getUserTypePointerLevel() + pointerLevelAdjust)}"
		elif self.mode == CharReferenceMode.USER_TYPE_ONLY:
			return f"{self.getModifierStr()}{manipulate(typeManipulator, self.group.name)}{'*'*(self.getUserTypePointerLevel() + pointerLevelAdjust)}"
		elif self.mode == CharReferenceMode.MORPHING:
			return f"{self.getModifierStr()}{manipulate(typeManipulator, 'char')}{'*'*(self.charPointerLevel + pointerLevelAdjust)}"


	def getAppliedHeaderName(self, mainState: MainState, sourceGroup: Group, templateMappingTracker: TemplateMappingTracker, pointerLevelAdjust=0, useUsertypeOverride=False,
		typeManipulator: Callable[[str], str]=None):

		return self.getHeaderName(pointerLevelAdjust=pointerLevelAdjust, typeManipulator=typeManipulator)


	def getAppliedUserTypeName(self, mainState: MainState, sourceGroup: Group, templateMappingTracker: TemplateMappingTracker, useUsertypeOverride=False,
		typeManipulator: Callable[[str], str]=None, forcePointer: bool=False):

		charLevel = self.charPointerLevel
		if charLevel == 0:
			return f"{self.getModifierStr()}{manipulate(typeManipulator, 'char')}"
		elif charLevel == 1:
			return manipulate(typeManipulator, f"{'Const' if self.const else ''}CharString")
		elif self.mode == CharReferenceMode.USER_TYPE_ONLY and charLevel == 2:
			return self.group.name
		else:
			return f"{manipulate(typeManipulator, 'Pointer')}<{self.getModifierStr()}{manipulate(typeManipulator, 'char')}{'*'*(charLevel - 1)}>"


class FunctionParameter:

	def __init__(self):
		self.type: TypeReference = None
		self.name: str = None

	def shallowCopy(self, copy=None):
		copy = copy if copy != None else FunctionParameter()
		copy.type = self.type.shallowCopy()
		copy.name = self.name
		return copy


class FunctionImplementation:

	def __init__(self):
		self.hasVarargs: bool = None
		self.isConst: bool = None
		self.isStatic: bool = None
		self.returnType: TypeReference = None
		self.callingConvention: str = None
		self.operatorStr: str = None
		self.name: str = None
		self.funcPtrName: str = None
		self.removedThisType: TypeReference = None
		self.parameters: list[FunctionParameter] = []
		self.body: list[str] = []
		self.noBody: bool = None
		self.noDeclaration: bool = False
		self.isConstructor: bool = False
		self.isFakeConstructor: bool = False
		self.isDestructor: bool = False
		self.isFunctionPointer: bool = False
		self.customReturnCount: int = None
		self.group: Group = None
		self.virtual: bool = False
		self.externalImplementation: bool = False
		self.passLuaState: bool = False
		self.eofBody: bool = False
		self.bindingName: str = None
		self.patternName: str = None
		self.lineGroupFlags: LineGroupFlags = LineGroupFlags()

	def shallowCopy(self, copy=None):
		copy = copy if copy != None else FunctionImplementation()
		copy.hasVarargs = self.hasVarargs
		copy.isConst = self.isConst
		copy.isStatic = self.isStatic
		copy.returnType = self.returnType.shallowCopy()
		copy.callingConvention = self.callingConvention
		copy.name = self.name
		copy.funcPtrName = self.funcPtrName
		copy.removedThisType = self.removedThisType.shallowCopy() if self.removedThisType != None else None

		for parameter in self.parameters:
			copy.parameters.append(parameter.shallowCopy())

		for line in self.body:
			copy.body.append(line)

		copy.noBody = self.noBody
		copy.noDeclaration = self.noDeclaration
		copy.isConstructor = self.isConstructor
		copy.isFakeConstructor = self.isFakeConstructor
		copy.isDestructor = self.isDestructor
		copy.customReturnCount = self.customReturnCount
		copy.group = self.group
		copy.virtual = self.virtual
		copy.externalImplementation = self.externalImplementation
		copy.passLuaState = self.passLuaState
		copy.eofBody = self.eofBody
		copy.bindingName = self.bindingName
		copy.patternName = self.patternName
		self.lineGroupFlags.applyTo(copy.lineGroupFlags)
		return copy

	def setName(self, name: str, wasOperator: bool = False):
		self.name = name
		# This is normally called after setBindingName().
		# Only replace funcPtrName if it wasn't set by
		# setBindingName().
		if self.funcPtrName == None:
			name = f"operator{name}" if wasOperator else name
			self.funcPtrName = name.replace("=", "_equ")

	def setBindingName(self, bindingName: str):
		self.bindingName = bindingName
		self.funcPtrName = bindingName

	def getAllTypeReferences(self, mainState: MainState):

		refs = []

		if self.returnType != None:
			refs.append(self.returnType)

		if self.removedThisType != None:
			refs.append(self.removedThisType)

		for param in self.parameters:
			for paramRef in param.type.getAllTypeReferences(mainState):
				refs.append(paramRef)

		return refs


	def toString(self, mainState: MainState, indent="", eof: bool = False):

		parts: list[str] = [indent]

		if self.hasVarargs:

			if not eof:
				parts.append("\t")

			parts.append("template<typename... VarArgs>\n")
			parts.append(indent)

		if self.group != mainState.globalGroup:
			if not eof:
				parts.append("\t")
			else:
				parts.append("inline ")

		if self.virtual:
			parts.append("virtual ")

		if self.isStatic:
			parts.append("static ")

		namespace = f"{self.group.name}::" if self.eofBody and eof else ""

		if self.isFakeConstructor:
			parts.append(f"{self.returnType.getHeaderName()} {namespace}Construct")
		elif not self.isConstructor and not self.isDestructor:
			if self.returnType != None:
				parts.append(self.returnType.getHeaderName())
				parts.append(" ")
			parts.append(namespace)
			if self.operatorStr != None: parts.append(self.operatorStr)
			parts.append(self.name)
		else:
			parts.append(namespace)
			if self.isDestructor: parts.append("~")
			parts.append(self.group.singleName)

		parts.append("(")

		if self.customReturnCount or self.passLuaState:
			parts.append("lua_State* L")
			parts.append(", ")

		for parameter in self.parameters:
			parts.append(parameter.type.getHeaderName())
			parts.append(" ")
			parts.append(parameter.name)
			parts.append(", ")

		if self.hasVarargs:
			parts.append("VarArgs... varArgs")
		elif self.customReturnCount or self.passLuaState or len(self.parameters) > 0:
			parts.pop()

		parts.append(")")

		if self.isConst:
			parts.append(" const")

		if self.virtual:

			parts.append("\n")
			parts.append(f"{indent}\t{{\n")

			if not self.returnType.isNonPointerVoid():
				parts.append(f"{indent}\t\treturn *({self.returnType.getHeaderName()}*)nullptr;\n")

			parts.append(f"{indent}\t}}\n")

		elif not self.noBody:
			assert not self.externalImplementation, "Function cannot be header-defined and externally-defined"
			if not self.eofBody or eof:
				parts.append("\n")
				for bodyLine in self.body:
					parts.append(indent)
					parts.append(bodyLine if not eof else bodyLine[1:])
					parts.append("\n")
			else:
				parts.append(";\n")

		elif not self.externalImplementation:

			parts.append("\n")
			parts.append(f"{indent}\t{{\n")
			parts.append(f"{indent}\t\t")

			if not self.returnType.isNonPointerVoid():
				parts.append("return ")

			parts.append(f"{indent}p_{self.funcPtrName}(")

			if not self.isStatic:
				parts.append("this")
				parts.append(", ")

			for parameter in self.parameters:
				parts.append(parameter.name)
				parts.append(", ")

			if self.hasVarargs:
				parts.append("varArgs...")
			elif not self.isStatic or len(self.parameters) > 0:
				del parts[-1]

			parts.append(");\n")
			parts.append(f"{indent}\t}}\n")
		else:
			parts.append(";\n")

		return "".join(parts)


class CheckLinesState:

	def __init__(self):
		self.bracketLevel: int = 0
		self.hitFirstBracket: bool = False
		self.functionImplementationBody: list[str] = []
		self.currentFunctionImplementation: FunctionImplementation = None
		self.lineGroupFlags: LineGroupFlags = LineGroupFlags()


class CheckUnnamedStructsState:

	def __init__(self):
		self.groupType: str = None
		self.preBracketLevel: int = None
		self.bracketLevel: int = 0
		self.lines: list[str] = []
		self.lineGroupFlags: LineGroupFlags = LineGroupFlags()


variablePatternGlobal = "^((?:(?:nopointer|nobinding|static)\\s+)*)(?!class|enum|struct|typedef|union)(?:__unaligned\\s+){0,1}(?:__declspec\\(align\\(\\d+\\)\\)\\s+){0,1}([, _a-zA-Z0-9*&:<>\\-$]+?)\\s*([_a-zA-Z0-9~]+)((?:\\[[_a-zA-Z0-9+]+\\])+)*(?:\\s*:\\s*([^\\s>]+?)){0,1}(?:\\s|(?:\\/\\*(?:(?!\\*\\/).)*\\*\\/))*;(?:\\s|(?:\\/\\/.*)|(?:\\/\\*(?:(?!\\*\\/).)*\\*\\/))*$"
variablePatternLocal = "^\t((?:(?:nopointer|nobinding|static)\\s+)*)(?:__unaligned\\s+){0,1}(?:__declspec\\(align\\(\\d+\\)\\)\\s+){0,1}([, _a-zA-Z0-9*&:<>\\-$]+?)\\s*([_a-zA-Z0-9~]+)((?:\\[[_a-zA-Z0-9+]+\\])+)*(?:\\s*:\\s*([^\\s>]+?)){0,1}(?:\\s|(?:\\/\\*(?:(?!\\*\\/).)*\\*\\/))*;(?:\\s|(?:\\/\\/.*)|(?:\\/\\*(?:(?!\\*\\/).)*\\*\\/))*$"
functionParameterTypeModifiers = [
	"signed", "unsigned", "short", "long", "const", "volatile",
	"noconst", "primitive" # Bindings specific
]

def processCommonGroupLines(mainState: MainState, state: CheckLinesState, line: str, group: Group):

	isGlobal = group == mainState.globalGroup


	def functionParameters(parameterStr: str, allowReferences = False):
		nonlocal mainState
		nonlocal state
		nonlocal line
		nonlocal group

		for commaSplitPart in splitKeepBrackets(parameterStr, [","]):

			spaceSplit = splitKeepBrackets(commaSplitPart, [" "])
			spaceSplitLen = len(spaceSplit)
			typeParts = []

			i: int = 0
			for i, spaceSplitPart in enumerate(spaceSplit):
				if spaceSplitPart in functionParameterTypeModifiers:
					typeParts.append(spaceSplitPart)
					typeParts.append(" ")
				else:
					i -= 1
					break
			i += 1

			if i == 0 or i < spaceSplitLen - 1:
				typeParts.append(spaceSplitPart)
				typeParts.append(" ")
				i += 1

			if len(typeParts) > 0:
				typeParts.pop()

			typeStr = "".join(typeParts)
			nameStr = spaceSplit[i] if i < spaceSplitLen else ""

			funcParameter = FunctionParameter()
			funcParameter.type = defineTypeRef(mainState, group, typeStr, TypeRefSourceType.FUNCTION_PARAMETER, allowReference=allowReferences, debugLine=f"processCommonGroupLines()-2 {line}")
			funcParameter.name = nameStr
			yield funcParameter


	functionImplementationMatch: Match = re.match("^\\s*(?!typedef)((?:(?:\\$nobinding|\\$nodeclaration|\\$external_implementation|\\$pass_lua_state|\\$eof_body|\\$binding_name\\(\\S+\\)|\\$pattern_name\\(\\S+\\)|\\$allow_references)\\s+)*)(?:(static)\\s+)?(?:(?:(?:([, _a-zA-Z0-9*&:<>$]+?)\\s+)?(?:(__cdecl|__stdcall|__thiscall)\\s+)?(operator\\s*)([_a-zA-Z0-9\\[\\]=*& ]+?))|(?:([, _a-zA-Z0-9*&:<>$]+?)\\s+(?:(__cdecl|__stdcall|__thiscall)\\s+)?([_a-zA-Z0-9]+)))\\s*\\(\\s*((?:[, _a-zA-Z0-9*:<>&]+?\\s+[_a-zA-Z0-9]+(?:\\s*,(?!\\s*\\)))?)*)\\s*(?:(\\.\\.\\.)\\s*)?\\)\\s*(const)?\\s*(?:(;))?$", line)
	if functionImplementationMatch:

		state.currentFunctionImplementation = FunctionImplementation()
		state.currentFunctionImplementation.group = group
		state.lineGroupFlags.applyTo(state.currentFunctionImplementation.lineGroupFlags)

		allowReferences: bool = False

		if keywordMatch := functionImplementationMatch.group(1):
			for keyword in keywordMatch.strip().split(" "):
				if keyword == "$nobinding":
					assert not state.currentFunctionImplementation.lineGroupFlags.isExplicitlyFlagged("noBindings"), "nobinding already defined"
					state.currentFunctionImplementation.lineGroupFlags.setFlag("noBindings", FlagSource.EXPLICIT)
				elif keyword == "$nodeclaration":
					assert not state.currentFunctionImplementation.noDeclaration, "nodeclaration already defined"
					state.currentFunctionImplementation.noDeclaration = True
				elif keyword == "$external_implementation":
					assert not state.currentFunctionImplementation.externalImplementation, "external_implementation already defined"
					state.currentFunctionImplementation.externalImplementation = True
				elif keyword == "$pass_lua_state":
					assert not state.currentFunctionImplementation.passLuaState, "pass_lua_state already defined"
					state.currentFunctionImplementation.passLuaState = True
				elif keyword == "$eof_body":
					assert not state.currentFunctionImplementation.eofBody, "eof_body already defined"
					state.currentFunctionImplementation.eofBody = True
				elif bindingNameMatch := re.match("^\\$binding_name\\((\\S+)\\)$", keyword):
					assert not state.currentFunctionImplementation.bindingName, "bindingName already defined"
					state.currentFunctionImplementation.setBindingName(bindingNameMatch.group(1))
				elif patternNameMatch := re.match("^\\$pattern_name\\((\\S+)\\)$", keyword):
					assert not state.currentFunctionImplementation.patternName, "pattern_name already defined"
					state.currentFunctionImplementation.patternName = patternNameMatch.group(1)
				elif keyword == "$allow_references":
					allowReferences = True
				else:
					assert False, "Bad bindings directive"

		state.currentFunctionImplementation.isStatic = functionImplementationMatch.group(2) != None

		def processRetType(groupIndex):
			nonlocal state
			nonlocal functionImplementationMatch
			nonlocal group

			retTypeStr: str = functionImplementationMatch.group(groupIndex)
			if retTypeStr == None:
				return None

			if customReturnMatch := re.match("^\\$custom_return_(\\d+)$", retTypeStr):
				state.currentFunctionImplementation.customReturnCount = int(customReturnMatch.group(1))
				return "void"

			elif retTypeStr.startswith("$constructor"):

				if retTypeStr == "$constructor_copy":
					group.copyConstructor = state.currentFunctionImplementation
					state.currentFunctionImplementation.isConstructor = True
				elif retTypeStr == "$constructor_fake":
					state.currentFunctionImplementation.isFakeConstructor = True
				else:
					assert retTypeStr == "$constructor", "Bad bindings directive"
					state.currentFunctionImplementation.isConstructor = True

				return "void"

			elif retTypeStr.startswith("$destructor"):
				state.currentFunctionImplementation.isDestructor = True
				return "void"

			return retTypeStr


		if (operatorStr := functionImplementationMatch.group(5)) != None:
			retTypeStr = processRetType(3)
			if retTypeStr: state.currentFunctionImplementation.returnType = defineTypeRef(mainState, group, retTypeStr, TypeRefSourceType.FUNCTION_RETURN, allowReference=True, debugLine=f"processCommonGroupLines()-1 {line}")
			state.currentFunctionImplementation.callingConvention = functionImplementationMatch.group(4)
			state.currentFunctionImplementation.operatorStr = operatorStr
			state.currentFunctionImplementation.setName(functionImplementationMatch.group(6), wasOperator=True)
		else:
			retTypeStr = processRetType(7)
			state.currentFunctionImplementation.returnType = defineTypeRef(mainState, group, retTypeStr, TypeRefSourceType.FUNCTION_RETURN, allowReference=allowReferences, debugLine=f"processCommonGroupLines()-1 {line}")
			state.currentFunctionImplementation.callingConvention = functionImplementationMatch.group(8)
			state.currentFunctionImplementation.setName(functionImplementationMatch.group(9))


		parameterStr = functionImplementationMatch.group(10)
		if parameterStr != None and parameterStr != "":
			for funcParameter in functionParameters(parameterStr, allowReferences or state.currentFunctionImplementation.operatorStr != None):
				state.currentFunctionImplementation.parameters.append(funcParameter)

		state.currentFunctionImplementation.hasVarargs = functionImplementationMatch.group(11) != None
		state.currentFunctionImplementation.isConst = functionImplementationMatch.group(12) != None
		state.currentFunctionImplementation.noBody = functionImplementationMatch.group(13) != None


	if state.currentFunctionImplementation != None:

		if state.currentFunctionImplementation.noBody:
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


	variableMatch: Match = re.match(variablePatternGlobal if isGlobal else variablePatternLocal, line)
	if variableMatch != None:

		variableField = VariableField(group)
		state.lineGroupFlags.applyTo(variableField.lineGroupFlags)

		if keywordMatch := variableMatch.group(1):
			for keyword in keywordMatch.strip().split(" "):
				if keyword == "nobinding":
					assert not variableField.lineGroupFlags.isExplicitlyFlagged("noBindings"), f"nobinding already defined for {group.name}::{variableMatch.group(3)}"
					variableField.lineGroupFlags.setFlag("noBindings", FlagSource.EXPLICIT)
				elif keyword == "static":
					assert not variableField.static, "static already defined"
					variableField.static = True
				elif keyword == "nopointer":
					assert not variableField.nopointer, "nopointer already defined"
					variableField.nopointer = True

		variableField.variableType = defineTypeRef(mainState, group, variableMatch.group(2), TypeRefSourceType.VARIABLE, variableMatch.group(4), debugLine=f"processCommonGroupLines()-3 {line}")
		variableField.variableType.bitFieldPart = variableMatch.group(5)

		variableField.variableName = variableMatch.group(3)

		group.addField(variableField)


	# Define function fields
	functionVariableMatch: Match = re.match("^\\s*(?!typedef\\s+)((?:(?:nopointer)\\s+)*)([, _a-zA-Z0-9*:<>]+?)\\s*\\(\\s*(?:([_a-zA-Z]+?)\\s*){0,1}(\\*+)\\s*([_a-zA-Z0-9~]+)\\s*\\)\\s*\\((?:\\s*([, _a-zA-Z0-9*:<>]+?)\\s+\\*\\s*this(?:\\s*,\\s+){0,1}){0,1}(?:([, _a-zA-Z0-9*:<>]+?)\\s+\\*\\s*result(?:\\s*,\\s+){0,1}){0,1}\\s*((?:[ _a-zA-Z0-9*:<>][, _a-zA-Z0-9*:<>]*?){0,1}(?:\\.\\.\\.(?=\\s*\\))){0,1}){0,1}\\s*\\)\\;$", line)
	if functionVariableMatch != None:

		functionField = FunctionField()
		state.lineGroupFlags.applyTo(functionField.lineGroupFlags)

		if keywordMatch := functionVariableMatch.group(1):
			for keyword in keywordMatch.strip().split(" "):
				if keyword == "nopointer":
					assert not functionField.nopointer, "nopointer already defined"
					functionField.nopointer = True

		functionField.returnType = defineTypeRef(mainState, group, functionVariableMatch.group(2), TypeRefSourceType.FUNCTION_RETURN, debugLine=f"processLinesFillTypes()-2 {line}")
		functionField.callConvention = functionVariableMatch.group(3)
		functionField.pointerLevel = len(functionVariableMatch.group(4))

		functionField.functionName = functionVariableMatch.group(5)
		if functionField.functionName.startswith("~"):
			functionField.functionName = "Destruct"

		if thisTypeNoPtrMatch := functionVariableMatch.group(6):
			functionField.thisType = defineTypeRef(mainState, group, f"{thisTypeNoPtrMatch}*", TypeRefSourceType.FUNCTION_PARAMETER, debugLine=f"processLinesFillTypes()-3 {line}")

		if resultTypeNoPtrMatch := functionVariableMatch.group(7):
			functionField.resultType = defineTypeRef(mainState, group, f"{resultTypeNoPtrMatch}*", TypeRefSourceType.FUNCTION_PARAMETER, debugLine=f"processLinesFillTypes()-4 {line}")

		parameterStr = functionVariableMatch.group(8)
		if parameterStr != None and parameterStr != "":
			for funcParameter in functionParameters(parameterStr):
				functionField.parameters.append(funcParameter)

		group.addField(functionField)



class TemplateUse:

	__slots__ = ("tup", "maxPointerLevel")
	def __init__(self, templateUse: tuple[TypeReference], maxPointerLevel: int) -> None:
		self.tup: tuple[TypeReference] = templateUse
		self.maxPointerLevel = maxPointerLevel


class UniqueTemplateUsesByHeaderName(UniqueList[TemplateUse]):

	def pHash(templateUse: TemplateUse):
		toReturn = 0
		for ref in templateUse.tup:
			toReturn += 3 * hash(ref.getHeaderName())
		return toReturn

	def pEq(a: TemplateUse, b: TemplateUse):
		if len(a.tup) != len(b.tup):
			return False
		for i in range(len(a.tup)):
			if a.tup[i].getHeaderName() != b.tup[i].getHeaderName():
				return False
		return True

	def __init__(self) -> None:
		super().__init__(pHash=UniqueTemplateUsesByHeaderName.pHash, pEq=UniqueTemplateUsesByHeaderName.pEq)


class GroupLineCollection:
	__slots__ = ("lineGroupFlags", "lines")
	def __init__(self):
		self.lineGroupFlags: LineGroupFlags = LineGroupFlags()
		self.lines: list[str] = []


class Group:

	def __init__(self):

		self.template: str = None  # String filled with the template definition as found in the input file. Example: template<class T, int size>
		self.groupType: str = None # "struct" / "class" / "enum" / "union" / (possibly "undefined").

		self.name: str = None # String filled with the name of the group, as defined in the input file. Examples:
							  # "CPtrList" / "CPtrList::CNode"

		self.singleName: str = None # String filled with the name of the group. If group is a sub-group, contains only the last group name. Example:
									# self.name = "CPtrList::CNode" => self.singleName = "CNode"

		self.defined: bool = False                            # True if the group was defined in a header file
		self.lineCollections: list[GroupLineCollection] = []  # List of all lines in the group's definition.
		self.linesProcessed = False                           # True if the group's lines have already been processed.

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
		self.hadVfptrField: bool = False
		self.numOriginalVFuncs: int = None
		self.isVGroup: bool = False

		self.lineGroupFlags: LineGroupFlags = LineGroupFlags()
		self.allowDefaultConstruction: bool = False
		self.abstract: bool = False


	def definedFields(self):

		for item in self.fields:

			if item.getName().startswith("_"):
				continue

			if item.type == FieldType.VARIABLE:
				variableField: VariableField = item
				if variableField.variableType.getName().startswith("undefined"):
					continue

			yield item


	def addInwardTypeRef(self, typeRef: TypeReference):
		self.inwardTypeRefs.addUnique(typeRef)


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


	def getTopGroup(self):
		topGroup = self
		while temp := topGroup.superGroup:
			topGroup = temp

		return topGroup


	def hasDefinedTop(self):
		return self.getTopGroup().groupType != "undefined"


	def getField(self, fieldName) -> Field | None:
		return self.fieldsMap.get(fieldName)


	def hasField(self, fieldName) -> bool:
		return self.fieldsMap.get(fieldName) != None


	def retypeExtendsIndex(self, mainState: MainState, extendsIndex: int, newTypeStr: str):

		existingRef: TypeReference = self.extends[extendsIndex]

		for ref in existingRef.getAllTypeReferences(mainState):
			ref.removeFromGroupRefs()

		self.extends[extendsIndex] = defineTypeRef(mainState, self, newTypeStr, TypeRefSourceType.EXTENDS, debugLine="retypeExtendsIndex()")


	def retypeField(self, mainState: MainState, fieldName: str, newTypeStr: str):

		field = self.fieldsMap[fieldName]
		assert field.type == FieldType.VARIABLE, "Unhandled field.type in Group.retypeField()"

		varField: VariableField = field

		for ref in varField.variableType.getAllTypeReferences(mainState):
			ref.removeFromGroupRefs()

		varField.variableType = defineTypeRef(mainState, self, newTypeStr, TypeRefSourceType.VARIABLE, debugLine="retypeField()")


	def retypeFunctionFieldRet(self, mainState: MainState, fieldName: str, newTypeStr: str):

		field = self.fieldsMap[fieldName]
		assert field.type == FieldType.FUNCTION, "Unhandled field.type in Group.retypeField()"

		functionField: FunctionField = field

		for ref in functionField.returnType.getAllTypeReferences(mainState):
			ref.removeFromGroupRefs()

		functionField.returnType = defineTypeRef(mainState, self, newTypeStr, TypeRefSourceType.FUNCTION_RETURN, debugLine="retypeFunctionFieldRet()")


	def addFunctionFieldParameter(self, mainState: MainState, fieldName: str, newTypeStr: str):
		field = self.fieldsMap[fieldName]
		assert field.type == FieldType.FUNCTION, "Unhandled field.type in Group.retypeField()"
		functionField: FunctionField = field
		funcParam = FunctionParameter()
		funcParam.type = defineTypeRef(mainState, self, newTypeStr, TypeRefSourceType.FUNCTION_PARAMETER, debugLine="addFunctionFieldParameter()")
		funcParam.name = ""
		functionField.parameters.append(funcParam)


	def removeField(self, mainState: MainState, field: Field) -> None:

		for ref in field.getAllTypeReferences(mainState):
			ref.removeFromGroupRefs()

		del self.fieldsMap[field.getName()]
		del self.fields[field.listI]
		for i in range(field.listI, len(self.fields)):
			self.fields[i].listI -= 1


	def removeFieldByIndex(self, mainState: MainState, fieldI: int) -> None:
		self.removeField(mainState, self.fields[fieldI])


	def removeFieldByName(self, mainState: MainState, fieldName: str) -> None:
		self.removeField(mainState, self.fieldsMap[fieldName])


	def renameField(self, field: Field, newName: str):
		del self.fieldsMap[field.getName()]
		self.fieldsMap[newName] = field
		field.setName(newName)


	def addField(self, field: Field, insertI: int=None):

		assert field.type in (FieldType.VARIABLE, FieldType.FUNCTION), "Unhandled field.type in Group.addField()"

		name: str = field.getName()

		if self.fieldsMap.get(name):
			i: int = 2
			while True:
				newName: str = f"{name}_{i}"
				if not self.fieldsMap.get(newName):
					field.setName(newName)
					name = newName
					break
				i += 1

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
		field = VariableField(self)
		field.variableName = fieldName
		field.variableType = defineTypeRef(mainState, self, typeStr, TypeRefSourceType.VARIABLE, debugLine="addVariableField()")
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

		for lineCollection in self.lineCollections:

			state.lineGroupFlags = lineCollection.lineGroupFlags
			unnamedStructsState.lineGroupFlags = lineCollection.lineGroupFlags

			for line in lineCollection.lines:

				checkUnnamedStructs(mainState, unnamedStructsState, self, line)

				# Define extends types
				declMatch: Match = re.match("^(?:(?:\\$pack_(\\d+)|\\$allow_default_construction\\((true|false)\\))\\s+)*(?:const\\s+){0,1}(?:struct|class|enum|union)\\s+(?:\\/\\*VFT\\*\\/\\s+){0,1}(?:__cppobj\\s+){0,1}(?:__unaligned\\s+){0,1}(?:__declspec\\(align\\(\\d+\\)\\)\\s+){0,1}[^;]*?(?:\\s+\\:\\s+(.*?)){0,1}\\s*$", line)
				if declMatch != None:
					if packGroup := declMatch.group(1):
						self.pack = int(packGroup)
					if allowDefaultConstructionGroup := declMatch.group(2):
						self.allowDefaultConstruction = allowDefaultConstructionGroup == "true"
					extendsStr = declMatch.group(3)
					if extendsStr != None:
						for extendsType in splitKeepBrackets(extendsStr, [","]):
							self.extends.append(defineTypeRef(mainState, self, extendsType, TypeRefSourceType.EXTENDS, debugLine=f"processLinesFillTypes()-1 {line}"))

				processCommonGroupLines(mainState, state, line, self)

				# Define certain enum values in group.enumTuples, else print to console
				if self.groupType == "enum":
					enumLineMatch: Match = re.match("^\\s*([_a-zA-Z0-9]+)\\s*=\\s*(.+?)\\s*,\\s*(?:\\/\\/.*){0,1}$", line)
					if enumLineMatch:
						firstExtendName = self.extends[0].getName() if len(self.extends) > 0 else "__int32"
						if firstExtendName == "__int8":
							value = int(enumLineMatch.group(2), 0)
							if value & 0x80 != 0: value = -1 - (0xFF - value)
							self.enumTuples.append((enumLineMatch.group(1), value))
						elif firstExtendName == "__int32":
							value = int(enumLineMatch.group(2), 0)
							if value & 0x80000000 != 0: value = -1 - (0xFFFFFFFF - value)
							self.enumTuples.append((enumLineMatch.group(1), value))
						elif firstExtendName == "__int64":
							value = int(enumLineMatch.group(2), 0)
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
				#print(f"templateTypeNameMapping[{templateTypeName}] = {group.name}")
				self.templateTypeNameMapping[templateTypeName] = group

		process(self)


	def addTemplateUse(self, useTup: tuple[TypeReference], pointerLevel: int) -> bool:

		templateUse = TemplateUse(useTup, pointerLevel)
		if existing := self.templateUses.getUnique(templateUse):
			if pointerLevel > existing.maxPointerLevel:
				existing.maxPointerLevel = pointerLevel
		else:
			self.templateUses.addUnique(templateUse)
			return True

		return False


	def scanInwardTypeRefs(self, mainState: MainState):

		"""
		Fills:
			templateUses \n
			uniqueUseRepresentations

		Scans inwardTypeRefs for uses of this Group's template definition and adds tuples representing these
		template uses to templateUses, (duplicate entries are discarded).\n\n
		Also fills uniqueUseRepresentations, which is a series of TypeRefs representing every unique way this group has been used.
		"""

		#print(f"scanInwardTypeRefs() - Group: {self.name}")

		for typeRef in self.inwardTypeRefs:

			# The Group that generated this TypeReference must be in-view
			if not typeRef.isDirectlyWanted and (not typeRef.sourceGroup or not typeRef.sourceGroup.isUsed(mainState)):
				continue

			# Reference templates must be parameterized and non-generic
			if typeRef.isTemplateIncomplete(mainState, askingGroup=self):
				continue

			if (templates := typeRef.getTemplates(mainState, askingGroup=self)) and len(templates) > 0:
				self.addTemplateUse(tuple(templates), typeRef.getUserTypePointerLevel())

			#print(f"  Group: {self.name}, appliedHeaderName: {typeRef.getHeaderName()}")
			self.uniqueUseRepresentations[typeRef.getHeaderName()] = typeRef


	def resolveTemplateUseRepresentations(self, mainState: MainState, pending: set[str], templateMappingTracker: TemplateMappingTracker) -> bool:

		"""
		Fills:
			templateUses \n
			uniqueUseRepresentations

		Scans templateUses to iterate all unique instances of this Group's template uses, and applies these templates to
		each TypeReference held by this Group (fetched via `getAllTypeReferences`) to fill `uniqueUseRepresentations`
		with the resolved templated representations.
		"""

		for templateUse in self.templateUses:

			#print(f"resolveTemplateUseRepresentations() - Group: {self.name}, templateUse.tup: {templateUse.tup}")

			templateMappingTracker.registerMapping(self.name, templateUse.tup)

			for typeRef in self.getAllTypeReferences(mainState, noGroups=True):
				if (replacedType := typeRef.resolveTemplateTypes(mainState, typeRef.sourceGroup, templateMappingTracker)) and (group := replacedType.getGroup()):

					if (templates := replacedType.getTemplates(mainState, askingGroup=group)) and len(templates) > 0:
						if group.addTemplateUse(tuple(templates), typeRef.getUserTypePointerLevel()):
							pending.add(group.getTopGroup().name) # TODO: Overzealous

					appliedHeaderName: str = replacedType.getAppliedHeaderName(mainState, typeRef.sourceGroup, templateMappingTracker)
					#print(f"  Group: {group.name}, appliedHeaderName: {appliedHeaderName}")
					group.uniqueUseRepresentations[appliedHeaderName] = replacedType

			for subGroup in self.subGroups:
				subGroup.resolveTemplateUseRepresentations(mainState, pending, templateMappingTracker)

			templateMappingTracker.deregisterMapping(self.name)


	def getAllTypeReferences(self, mainState: MainState, noGroups: bool=False):

		"""
		Returns all TypeReference instances held by this Group. This includes:
		1) If noGroup=False, a newly-created TypeReference to the Group itself. This reference is NOT added to `inwardTypeRefs`.
		2) If noGroup=False, all TypeReference instances held by `subGroups` (groups that this group immediately contains).
		3) All TypeReference instances held by `extends` (subclasses).
		4) All TypeReference instances held by `fields` (variables, including function pointers).
		5) All TypeReference instances held by `functionImplementations` (functions).
		"""

		parts: list[TypeReference] = []

		if not noGroups:
			myself = TypeReference()
			myself.name = self.name
			myself.group = self
			parts.append(myself)

		if not noGroups:
			for subgroup in self.subGroups:
				for ref in subgroup.getAllTypeReferences(mainState, noGroups=noGroups):
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

			if typeRef.isGenericTemplate() or (typeRef.group and (typeRef.group is self or typeRef.group.isSubgroupOf(self))):
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
				self.lineGroupFlags.applyTo(newGroup.lineGroupFlags)
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

				lastRef: TypeReference = defineTypeRefPart(mainState, None, topRef.sourceGroup, parts[0], TypeRefSourceType.INTERMEDIATE, isDirectlyWanted=topRef.isDirectlyWanted, allowReference=topRef.reference)
				for i in range(1, partsLen - 1):
					lastRef = defineTypeRefPart(mainState, lastRef, topRef.sourceGroup, parts[i], TypeRefSourceType.INTERMEDIATE, isDirectlyWanted=topRef.isDirectlyWanted, allowReference=topRef.reference)

				inRef.sourceGroup = lastRef.group
				lastRef.subRef = inRef
				inRef.superRef = lastRef


	def relocate(self: Group, mainState: MainState, newStructPath):
		mainState.updateGroupNameMapping(self, newStructPath)
		self.updateNesting(mainState)
		self.broadcastName(mainState)
		self.rebuildInwardTypeRefs(mainState)


	def appendTemplates(self, mainState: MainState, templateMappingTracker: TemplateMappingTracker, parts: list[str], useUsertypeOverride=False,
		templateTypeMode: TemplateTypeMode=None, typeManipulator: Callable[[str], str]=None):

		if templateMappingTracker != None and (v := templateMappingTracker.getMapping(self.name)) != None:

			parts.append("<")

			if templateTypeMode == TemplateTypeMode.USER_TYPE:
				for typeRef in v:
					parts.append(typeRef.checkReplaceTemplateType(mainState, typeRef.sourceGroup, templateMappingTracker).getAppliedUserTypeName(mainState, typeRef.sourceGroup,
						templateMappingTracker, useUsertypeOverride=useUsertypeOverride, typeManipulator=typeManipulator))
					parts.append(",")
			elif templateTypeMode == TemplateTypeMode.HEADER:
				for typeRef in v:
					parts.append(typeRef.checkReplaceTemplateType(mainState, typeRef.sourceGroup, templateMappingTracker).getAppliedHeaderName(mainState, typeRef.sourceGroup,
						templateMappingTracker, useUsertypeOverride=useUsertypeOverride, typeManipulator=typeManipulator))
					parts.append(",")

			parts.pop()
			parts.append(">")


	def getAppliedName(self, mainState: MainState, templateMappingTracker: TemplateMappingTracker, useUsertypeOverride=False, noTemplate=False,
		singleName=False, noName=False, templateTypeMode: TemplateTypeMode=None, typeManipulator: Callable[[str], str]=None):

		"""
		Given a Group in which the caller wants to express an arbitrary series of template uses, returns a
		string representation of the current Group name as if its template types were filled with the information
		held by templateMappingTracker.
		"""

		assert templateTypeMode, "templateTypeMode must be defined in Group.getAppliedName()!"

		groupNameParts = []

		if not noName:

			if not singleName and self.superGroup:

				nameNoTemplates, success = attemptManipulate(typeManipulator, self.superGroup.getAppliedName(mainState, templateMappingTracker,
					templateTypeMode=templateTypeMode, noTemplate=True))

				if success:
					groupNameParts.append(nameNoTemplates)
				else:
					groupNameParts.append(self.superGroup.getAppliedName(mainState, templateMappingTracker, templateTypeMode=templateTypeMode,
						typeManipulator=typeManipulator))
					groupNameParts.append("::")

			groupNameParts.append(manipulate(typeManipulator, self.overrideUsertypeSingleName if useUsertypeOverride
				and self.overrideUsertypeSingleName != None else self.singleName))

		if not noTemplate:
			self.appendTemplates(mainState, templateMappingTracker, groupNameParts, useUsertypeOverride=useUsertypeOverride,
				templateTypeMode=templateTypeMode, typeManipulator=typeManipulator)

		return "".join(groupNameParts)


	def checkForVGroup(self, mainState: MainState, ignoreGhidraVFTables: bool = False) -> Group:

		"""
		Fills:
			vGroup

		Fills vGroup and removes __vftable field if present.
		"""

		if vtblStruct := mainState.tryGetGroup(f"{self.name}::vtbl"):
			# vtbl already processed
			finalSuperVGroup: Group = vtblStruct
			while True:
				if len(finalSuperVGroup.extends) > 0:
					extendRef: TypeReference = finalSuperVGroup.extends[0]
					finalSuperVGroup = extendRef.group
				else:
					break

			return vtblStruct, finalSuperVGroup

		vtblStruct = mainState.tryGetGroup(f"{self.name}_vtbl")
		ghidraVtblStruct: bool = False

		if vtblStruct is None and not ignoreGhidraVFTables:
			vtblStruct = mainState.tryGetGroup(f"{self.name}_VFTable")
			if vtblStruct is not None:
				ghidraVtblStruct = True

		if vtblStruct is None:

			# Get super vtbl struct if it exists
			superVGroup: Group = None
			for extendRef in self.extends:
				superVGroupTemp, _ = extendRef.group.checkForVGroup(mainState, ignoreGhidraVFTables=ignoreGhidraVFTables)
				if superVGroupTemp:
					if superVGroup == None:
						superVGroup = superVGroupTemp
					else:
						# print(f"[!] Failed to fully create vtbl struct for {self.name}. Code can only handle one superclass having a vftable.")
						superVGroup = None
						break

			if superVGroup:
				# If I didn't have a vtbl struct, and yet my super struct did, copy the super vtbl struct
				# This is useful for manual structs that extend a struct with a vtbl - this code generates the
				# new struct's vtbl automatically.
				vtblStruct = Group()
				vtblStruct.groupType = "struct"
				vtblStruct.defined = True
				superVGroup.lineGroupFlags.applyTo(vtblStruct.lineGroupFlags)
				vtblStruct.updateSingleName(mainState, f"{self.name}_vtbl")

				def copyVtblStructFields(toCopyVtblGroup: Group):
					nonlocal vtblStruct
					# Copy the vtbl fields higher in the hierarchy first
					# len(toCopyVtblGroup.extends) is either 1 or 0 (when the hierarchy failed to build)
					for extendRef in toCopyVtblGroup.extends:
						copyVtblStructFields(extendRef.group)

					for field in toCopyVtblGroup.fields:
						vtblStruct.addField(field.shallowCopy())

				copyVtblStructFields(superVGroup)
				mainState.addGroup(vtblStruct)
			else:
				# vtbl struct doesn't exist, and didn't generate one
				return None, None

		vtblStruct.isVGroup = True
		self.vGroup = vtblStruct
		# Relocate vtbl struct so that it nests under its parent Group
		vtblStruct.relocate(mainState, f"{self.name}::vtbl")

		# Remove __vftable field if it exists
		# (they are hidden and should never be explicitly defined in C++)
		vfptrField = self.getField("__vftable")
		if vfptrField != None:
			self.hadVfptrField = True
			self.removeFieldByName(mainState, "__vftable")

		# Keep track of some hierarchy Groups, (immediate parent and upper-most parent)
		superVGroup: Group = None
		finalSuperVGroup: Group = None

		# Build vtbl struct hierarchy
		for extendRef in self.extends:

			assert extendRef.group, "checkForVGroup() - extendRef has no group assigned"
			# Recursively handle all vtbl structs in the hierarchy chain
			superVGroupTemp, finalSuperVGroupTemp = extendRef.group.checkForVGroup(mainState, ignoreGhidraVFTables=ignoreGhidraVFTables)

			if superVGroupTemp != None:

				if superVGroup == None:

					# Add the parent vtbl struct to this struct's extends list
					superVGroup = superVGroupTemp
					finalSuperVGroup = finalSuperVGroupTemp

					if not ghidraVtblStruct:
						extendTemplateTypes: list[TypeReference] = extendRef.getTemplates(mainState, askingGroup=extendRef.group)
						if len(extendTemplateTypes) == 0:
							superVGroupRefStr = superVGroup.name
						else:
							# Resolve super vtbl struct's templates
							templateMappingTracker: TemplateMappingTracker = TemplateMappingTracker()
							templateMappingTracker.registerMapping(extendRef.group.name, tuple(extendTemplateTypes))
							superVGroupRefStr = superVGroup.getAppliedName(mainState, templateMappingTracker, templateTypeMode=TemplateTypeMode.HEADER)

						vtblStruct.extends.append(defineTypeRef(mainState, vtblStruct, superVGroupRefStr, TypeRefSourceType.EXTENDS, debugLine=f"checkForVGroup()"))
				else:
					# print(f"[!] Failed to fully create vtbl struct for {self.name}. Code can only handle one superclass having a vftable.")

					# Clear everything since building the hierarchy failed
					superVGroup = None
					finalSuperVGroup = None

					for extendRef in vtblStruct.extends:
						extendRef.removeFromGroupRefs()

					vtblStruct.extends.clear()


		if ghidraVtblStruct:
			superCount: int = superVGroup.numOriginalVFuncs if superVGroup != None else 0
			vtblStruct.numOriginalVFuncs = len(vtblStruct.fields) + superCount
		else:
			vtblStruct.numOriginalVFuncs = len(vtblStruct.fields)

		if not ghidraVtblStruct and superVGroup != None:
			# Remove vtbl fields that were inherited
			for _ in range(superVGroup.numOriginalVFuncs):
				vtblStruct.removeFieldByIndex(mainState, 0)

		for field in vtblStruct.fields:

			if field.type == FieldType.VARIABLE:

				if not vtblStruct.superGroup.name.startswith("cricket::Port"):
					print(f"[!] Variable field detected in vtbl struct {vtblStruct.name}")

			elif field.type == FieldType.FUNCTION:

				functionField: FunctionField = field

				thisType = functionField.thisType
				if (
					thisType and thisType.getGroup() != self
					and not vtblStruct.superGroup.name.startswith("buzz::Xmpp")
					and not vtblStruct.superGroup.name.startswith("cricket")
					and not vtblStruct.superGroup.name.startswith("Microsoft::WRL::Wrappers")
					and not vtblStruct.superGroup.name.startswith("talk_base")
					and not vtblStruct.superGroup.name.startswith("XmppHandler")
					and not vtblStruct.superGroup.name.startswith("XmppPump")
					and not vtblStruct.superGroup.name.startswith("XmppThread")
				):
					print(f"[!] Function field {functionField.functionName} detected in vtbl struct {vtblStruct.name} with a `this` parameter mismatch")
					continue

				impl: FunctionImplementation = functionField.toImplementation(self, fromVFTable=True)
				impl.name = f"virtual_{functionField.functionName}"
				impl.virtual = True

				if ghidraVtblStruct and functionField.functionName.startswith("_"):
					impl.lineGroupFlags.setFlag("noBindings", FlagSource.DEFAULT)

				self.functionImplementations.append(impl)
			else:
				assert False, f"Unexpected field type in vtbl struct {vtblStruct.name}"

		return vtblStruct, finalSuperVGroup if finalSuperVGroup != None else vtblStruct


	def writeHeader(self, mainState, internalPointersOut, internalPointersListOut: list[tuple[str,str]], headerType: HeaderType, indent="") -> str:

		parts = [indent]

		def writeGroupInternalFunctionPointers(group: Group, indent: str = ""):

			isNormal: bool = group != mainState.globalGroup
			wroteSomething = False

			for functionImp in group.functionImplementations:

				if functionImp.noBody and not functionImp.externalImplementation:

					patternName: str = None
					if not functionImp.patternName:
						if not functionImp.bindingName:
							patternName = functionImp.name
							if functionImp.operatorStr:
								patternName = f"{functionImp.operatorStr}{patternName}"
						else:
							patternName = functionImp.bindingName
					else:
						patternName = functionImp.patternName

					patternName = f"{group.name}::{patternName}" if isNormal else patternName
					pointerVariableName: str = f"{group.name}::p_{functionImp.funcPtrName}" if isNormal else f"p_{functionImp.funcPtrName}"

					pointerVariableTypeName: str = f"type_{functionImp.funcPtrName}"
					pointerVariableFullTypeName: str = f"{group.name}::{pointerVariableTypeName}" if isNormal else pointerVariableTypeName

					internalPointersOut.write(f"{pointerVariableFullTypeName} {pointerVariableName};\n")
					internalPointersListOut.append((patternName, f"{pointerVariableName}"))

					if not functionImp.noDeclaration:

						conventionStr: str = f"{functionImp.callingConvention} " if functionImp.callingConvention != None else ""
						if conventionStr == "" and isNormal and not functionImp.isStatic:
							conventionStr = "__thiscall "

						parts.append(f"{indent}typedef {functionImp.returnType.getHeaderName()} ({conventionStr}*{pointerVariableTypeName})(")

						if isNormal and not functionImp.isStatic:
							constStr: str = "const " if functionImp.isConst else ""
							parts.append(f"{constStr}{group.name}* pThis")
							parts.append(", ")

						for param in functionImp.parameters:
							parts.append(f"{param.type.getHeaderName()} {param.name}")
							parts.append(", ")

						if functionImp.hasVarargs:
							parts.append("...")
						elif (isNormal and not functionImp.isStatic) or len(functionImp.parameters) > 0:
							del parts[-1]

						parts.append(");\n")
						modifierStr: str = "static" if isNormal else "extern"
						parts.append(f"{indent}{modifierStr} {pointerVariableTypeName} p_{functionImp.funcPtrName};")
						parts.append("\n\n")
						wroteSomething = True

			if isNormal:
				if group.groupType == "namespace":
					for field in group.fields:
						if field.type == FieldType.VARIABLE:
							internalPointersOut.write(f"{field.toString(mainState, includeNamespace=True)}\n")
				else:
					for field in group.fields:
						if field.type == FieldType.VARIABLE:
							varField: VariableField = field
							if varField.static:
								varName = f"{self.name}::{'' if varField.nopointer else 'p_'}{varField.variableName}"
								pointerLevelAdjust: int = 0 if varField.nopointer else 1
								internalPointersOut.write(f"{varField.variableType.getHeaderName(pointerLevelAdjust=pointerLevelAdjust)} {varName};\n")
								internalPointersListOut.append((f"{self.name}::{varField.variableName}", varName))
			else:
				for field in group.fields:
					if field.type == FieldType.VARIABLE:
						varField: VariableField = field
						pointerLevelAdjust: int = 0 if varField.nopointer else 1
						varStr = f"{varField.variableType.getHeaderName(pointerLevelAdjust=pointerLevelAdjust)} {'' if varField.nopointer else 'p_'}{varField.variableName};"
						internalPointersOut.write(f"{varStr}\n")
						internalPointersListOut.append((varField.variableName, f"{'' if varField.nopointer else 'p_'}{varField.variableName}"))
						parts.append(f"extern {varStr}")
						parts.append("\n")
						wroteSomething = True
					elif field.type == FieldType.FUNCTION:
						funcField: FunctionField = field
						pointerLevelAdjust: int = 0 if funcField.nopointer else 1
						varStr = f"{funcField.toString(mainState, pointerLevelAdjust=pointerLevelAdjust, addPointerPrefixToName=not funcField.nopointer)}"
						internalPointersOut.write(f"{varStr}\n")
						internalPointersListOut.append((funcField.getName(), f"{'' if funcField.nopointer else 'p_'}{funcField.getName()}"))
						parts.append(f"extern {varStr}")
						parts.append("\n")
						wroteSomething = True
					else:
						assert "BAD FIELD TYPE"

			return wroteSomething


		wroteSomething = False
		isNormal: bool = self != mainState.globalGroup

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
			needExtraNewlineBeforeFuncImps = False

			for subgroup in self.subGroups:
				if not subgroup.isUsed(mainState): continue
				parts.append(subgroup.writeHeader(mainState, internalPointersOut, internalPointersListOut, headerType, nextIndent))
				parts.append("\n")

			for enumTuple in self.enumTuples:
				parts.append(nextIndent)
				parts.append(enumTuple[0])
				parts.append(" = ")
				parts.append(str(enumTuple[1]))
				parts.append(",\n")
				needExtraNewlineBeforeFuncImps = True

			for field in self.fields:
				parts.append(nextIndent)
				if self.groupType == "namespace":
					parts.append("extern ")
				parts.append(field.toString(mainState))
				parts.append("\n")
				needExtraNewlineBeforeFuncImps = True

			if not mainState.noCustomTypes and not self.allowDefaultConstruction and self.groupType not in ("enum", "namespace") and self.name not in ("Array", "ConstArray"):

				deleteDefault: bool = True
				for funcImp in self.functionImplementations:
					if funcImp.isConstructor and len(funcImp.parameters) == 0:
						deleteDefault = False
						break

				if deleteDefault:
					if needExtraNewlineBeforeFuncImps:
						parts.append("\n")
					parts.append(f"{nextIndent}{self.singleName}() = delete;\n")
					needExtraNewlineBeforeFuncImps = True

			if needExtraNewlineBeforeFuncImps and len(self.functionImplementations) > 0:
				parts.append("\n")

		if isNormal:

			lastWasExternalImplementation = False
			writeGroupInternalFunctionPointers(self, nextIndent)

			for functionImplementation in self.functionImplementations:

				if functionImplementation.externalImplementation:
					parts.append(functionImplementation.toString(mainState, indent))
					lastWasExternalImplementation = True
				else:
					if lastWasExternalImplementation:
						parts.append("\n")
					parts.append(functionImplementation.toString(mainState, indent))
					parts.append("\n")
					lastWasExternalImplementation = False

				wroteSomething = True

			if lastWasExternalImplementation:
				parts.append("\n")
		else:

			writeGroupInternalFunctionPointers(self)

			globalLineBetweenPointers = True
			for functionImplementation in self.functionImplementations:
				if not functionImplementation.noBody or functionImplementation.externalImplementation:
					if globalLineBetweenPointers and wroteSomething:
						globalLineBetweenPointers = False
						parts.append("\n")
					parts.append(functionImplementation.toString(mainState))
					parts.append("\n")
					wroteSomething = True

		if wroteSomething:
			parts.pop()

		if isNormal:
			parts.append(indent)
			parts.append("};\n")
			if self.pack:
				parts.append("#pragma pack(pop)\n")

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

		# Check if I am requested when my superGroup is being used, (isSoftWanted).
		return not dontCheckSuper and self.isSoftWanted and self.superGroup and self.superGroup.isUsed(mainState, dontCheckSuper=True, processed=processed)



def checkUnnamedStructs(mainState: MainState, state: CheckUnnamedStructsState, superGroup: Group, line: str):

	unnamedStructStart: Match = re.match("^\\s*(struct|class|enum|union)(?:\\s+__declspec\\(align\\(\\d+\\)\\)){0,1}\\s*$", line)
	if unnamedStructStart != None and state.preBracketLevel == None:
		state.groupType = unnamedStructStart.group(1)
		state.preBracketLevel = state.bracketLevel

	bracketLevelBeforeChange = state.bracketLevel
	state.bracketLevel += line.count("{")
	state.bracketLevel -= line.count("}")

	unnamedStructEnd: Match = re.match("^\\s*}\\s*([_a-zA-Z0-9]+)\\s*;\\s*$", line)
	if unnamedStructEnd != None and state.bracketLevel == state.preBracketLevel:

		myName = unnamedStructEnd.group(1)

		myTypeName = f"<unnamed_type_{myName}>" if mainState.idaUnnamedScheme else f"{myName}_t"
		myFullName = f"{superGroup.name}::{myTypeName}"

		subGroup = Group()
		subGroup.groupType = state.groupType
		subGroup.defined = True
		state.lineGroupFlags.applyTo(subGroup.lineGroupFlags)

		subGroupLineCollection = GroupLineCollection()
		subGroupLineCollection.lines = state.lines
		state.lineGroupFlags.applyTo(subGroupLineCollection.lineGroupFlags)

		subGroup.lineCollections.append(subGroupLineCollection)
		subGroup.superGroup = superGroup

		subGroup.updateSingleName(mainState, myTypeName)
		superGroup.subGroups.addUnique(subGroup)

		mainState.addGroup(subGroup)
		subGroup.processLinesFillTypes(mainState)

		newSuperField = VariableField(superGroup)
		newSuperField.variableType = defineTypeRef(mainState, superGroup, myFullName, TypeRefSourceType.VARIABLE, debugLine=f"checkUnnamedStructs() {line}")
		newSuperField.variableName = myName
		state.lineGroupFlags.applyTo(newSuperField.lineGroupFlags)
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
		self.lineGroupFlags: LineGroupFlags = LineGroupFlags()

	def shallowCopy(self, copy=None):
		copy = copy if copy != None else Field()
		copy.type = self.type
		copy.listI = self.listI
		self.lineGroupFlags.applyTo(copy.lineGroupFlags)
		return copy

	def getName(self) -> str:
		assert False, "Field.getName() intentionally unimplemented"

	def setName(self, newName: str) -> None:
		assert False, "Field.setName() intentionally unimplemented"

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
		self.pointerLevel: int = None
		self.functionName: str = None
		self.thisType: TypeReference = None
		self.resultType: TypeReference = None
		self.parameters: list[FunctionParameter] = []
		self.nopointer: bool = False


	def shallowCopy(self, copy=None):
		copy: FunctionField = copy if copy != None else FunctionField()
		super().shallowCopy(copy)
		copy.type = self.type
		copy.returnType = self.returnType.shallowCopy()
		copy.callConvention = self.callConvention
		copy.pointerLevel = self.pointerLevel
		copy.functionName = self.functionName
		copy.thisType = self.thisType.shallowCopy() if self.thisType != None else None
		copy.resultType = self.resultType.shallowCopy() if self.resultType != None else None
		for parameter in self.parameters:
			copy.parameters.append(parameter.shallowCopy())
		return copy


	def toImplementation(self, group: Group, fromVFTable: bool = False, isFunctionPointer: bool = False) -> FunctionImplementation:

		impl = FunctionImplementation()

		impl.isFunctionPointer = isFunctionPointer
		impl.returnType = self.returnType
		impl.callingConvention = self.callConvention
		impl.name = self.functionName
		self.lineGroupFlags.applyTo(impl.lineGroupFlags)

		enumerateStartI = 0

		if fromVFTable and self.callConvention == "__thiscall":
			impl.removedThisType = self.parameters[0].type
			enumerateStartI = 1

		for i in range(enumerateStartI, len(self.parameters)):
			funcParam: FunctionParameter = self.parameters[i]
			implParam = FunctionParameter()
			implParam.name = funcParam.name if funcParam.name != "" else f"_{i - enumerateStartI}"
			implParam.type = funcParam.type
			impl.parameters.append(implParam)

		impl.customReturnCount = None
		impl.group = group

		return impl


	def getName(self):
		return self.functionName


	def setName(self, newName: str) -> None:
		self.functionName = newName


	def toString(self, mainState: MainState, typeManipulator: Callable[[str], str]=None, indent="", addPointerPrefixToName: bool=False, pointerLevelAdjust: int=0) -> str:

		parts = [indent, self.returnType.getHeaderName(typeManipulator=typeManipulator), " ("]

		if self.callConvention:
			parts.append(self.callConvention)
			parts.append(" ")

		parts.append("*" * (self.pointerLevel + pointerLevelAdjust))
		if addPointerPrefixToName:
			parts.append("p_")
		parts.append(self.functionName)
		parts.append(")(")

		hadParam = False

		if self.thisType:
			parts.append(self.thisType.getHeaderName(typeManipulator=typeManipulator))
			parts.append(", ")
			hadParam = True

		if self.resultType:
			parts.append(self.resultType.getHeaderName(typeManipulator=typeManipulator))
			parts.append(", ")
			hadParam = True

		for parameter in self.parameters:

			parts.append(parameter.type.getHeaderName(typeManipulator=typeManipulator))

			if parameter.name != "":
				parts.append(" ")
				parts.append(parameter.name)

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

		for parameter in self.parameters:
			for v in parameter.type.getAllTypeReferences(mainState):
				parts.append(v)

		return parts


class VariableField(Field):

	def __init__(self, group: Group):
		super().__init__()
		self.type = FieldType.VARIABLE
		self.group = group
		self.variableType: TypeReference = None
		self.variableName: str = None
		self.static: bool = False
		self.nopointer: bool = False


	def shallowCopy(self, copy=None):
		copy: VariableField = copy if copy != None else VariableField(self.group)
		super().shallowCopy(copy)
		copy.type = self.type
		copy.variableType = self.variableType.shallowCopy()
		copy.variableName = self.variableName
		copy.static = self.static
		copy.nopointer = self.nopointer
		return copy


	def getName(self):
		return self.variableName


	def setName(self, newName: str) -> None:
		self.variableName = newName


	def toString(self, mainState: MainState, indent="", includeNamespace=False) -> str:

		parts = [indent]

		if self.static:
			parts.append("static ")

		#TODO: Handle nested Arrays
		if (not mainState.noCustomTypes) or self.variableType.getName() not in ("Array", "ConstArray"):
			pointerLevelAdjust: int = 1 if self.static and not self.nopointer else 0
			parts.append(f"{self.variableType.getHeaderName(pointerLevelAdjust)}")
			parts.append(" ")
			namespaceStr = f"{self.group.name}::" if includeNamespace else ""
			parts.append(f"{'p_' if self.static and not self.nopointer else ''}{namespaceStr}{self.variableName}")
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
	EXTENDS = 1
	FUNCTION_PARAMETER = 2
	FUNCTION_RETURN = 3
	INTERMEDIATE = 4
	TEMPLATE = 5
	VARIABLE = 6
	WANTED = 7


def defineTypeRefPart(mainState: MainState, superRef: TypeReference, sourceGroup: Group, inStr: str, src: TypeRefSourceType, arrayStr: str=None, isDirectlyWanted: bool=False, allowReference: bool=False, debugLine: str=""):

	assert inStr != None
	str = inStr

	primitive = False
	noconst = False
	while True:
		if primitiveMatch := re.fullmatch("primitive\\s+(.*)", str):
			primitive = True
			str = primitiveMatch.group(1)
		elif noconstMatch := re.fullmatch("noconst\\s+(.*)", str):
			noconst = True
			str = noconstMatch.group(1)
		else:
			break

	needArrayPart = False
	# Transform arrays into Array types
	if arrayStr != None:
		if sourceGroup == None or sourceGroup.name not in ("Array", "ConstArray"):
			allMatches = [x for x in re.finditer("\\[(\\d+)\\]", arrayStr)]
			all = [x.group(0) for x in allMatches]
			nextArrayStr = "".join(all[:-1]) if len(all) > 1 else None
			if constMatch := re.fullmatch("const\\s+(.*)", str):
				str = constMatch.group(1)
				return defineTypeRef(mainState, sourceGroup, f"ConstArray<{str},{allMatches[-1].group(1)}>", src, nextArrayStr, isDirectlyWanted, debugLine=debugLine)
			else:
				return defineTypeRef(mainState, sourceGroup, f"Array<{str},{allMatches[-1].group(1)}>", src, nextArrayStr, isDirectlyWanted, debugLine=debugLine)
		else:
			needArrayPart = True

	splits = splitKeepBrackets(stripUnnecessaryTypeSpaces(str), ["*", "&"], includeToSplit=True)
	typeRef = TypeReference()
	typeRef.sourceGroup = sourceGroup
	typeRef.sourceType = src
	typeRef.sourceString = inStr
	typeRef.isDirectlyWanted = isDirectlyWanted

	hitName = False

	def doBaseProcess(name: str):

		nonlocal hitName

		name, unsignedCount = removeRegexCount(name, "unsigned\\s+")
		if unsignedCount == 1:
			typeRef.unsigned = True
		else:
			assert unsignedCount == 0, "Invalid number of 'unsigned' keywords"

		if hitName:
			name, constCount = removeRegexCount(name, "const")
		else:
			name, constCount = removeRegexCount(name, "const\\s+")

		if volatileMatch := re.match("^volatile\\s+(.*)", name):
			typeRef.volatile = True
			name = volatileMatch.group(1)

		if longMatch := re.match("^long\\s+(.*)", name):
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
		if structMatch := re.match("^struct\\s+(.*)", name):
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
				if sourceGroup:
					sourceGroup.lineGroupFlags.applyTo(typeGroup.lineGroupFlags)
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
					typeRef.templateTypes.append(defineTypeRef(mainState, sourceGroup, templateType, TypeRefSourceType.TEMPLATE, isDirectlyWanted=isDirectlyWanted, debugLine=debugLine))

		elif split in ("*", "&"):

			# HACK: Array's operator[] needs to return a reference
			# even though I usually convert them to pointers
			if split == "&" and (allowReference or sourceGroup.name in ("Array", "ConstArray", "EEex")):
				assert not typeRef.reference, "Cannot handle rvalue reference"
				typeRef.reference = True

			typeRef.pointerLevel += 1
		else:
			doBaseProcess(split)

	if needArrayPart:
		for arrayPartMatch in re.finditer("\\[([a-zA-Z0-9_]+)\\]", arrayStr):
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
	elif typeRef.isPrimitiveString():
		mode = CharReferenceMode.PRIMITIVE_ONLY if primitive else CharReferenceMode.MORPHING
		return CharReference.create(mainState, typeRef, mode)

	# Transform pointers into PointerReference
	else:
		assert groupName not in ("Array", "ConstArray") or len(typeRef.templateTypes) == 2, "defineTypeRefPart() created invalid Array"
		return PointerReference.create(mainState, typeRef, debugLine=debugLine)



def defineTypeRef(mainState: MainState, sourceGroup: Group, str: str, src: TypeRefSourceType, arrayStr: str=None, isDirectlyWanted: bool=False, allowReference: bool=False, debugLine: str=""):

	if str == None:
		return

	splits = splitKeepBrackets(stripUnnecessaryTypeSpaces(str), ["::"])
	lastSplitIndex: int = len(splits) - 1

	if lastSplitIndex < 0:
		return

	lastRef: TypeReference = None

	# First type part
	if lastSplitIndex > 0:
		lastRef = defineTypeRefPart(mainState, None, sourceGroup, splits[0], TypeRefSourceType.INTERMEDIATE, arrayStr, isDirectlyWanted, allowReference=allowReference, debugLine=debugLine)
		arrayStr = None

	# Intermediate type parts
	for i in range(1, lastSplitIndex):
		lastRef = defineTypeRefPart(mainState, lastRef, sourceGroup, splits[i], TypeRefSourceType.INTERMEDIATE, None, isDirectlyWanted, allowReference=allowReference, debugLine=debugLine)

	# Last type part
	lastRef = defineTypeRefPart(mainState, lastRef, sourceGroup, splits[lastSplitIndex], src, arrayStr, isDirectlyWanted, allowReference=allowReference, debugLine=debugLine)

	#print(f"Created ref {lastRef.getHeaderName()} with sourceGroup: {lastRef.sourceGroup.name if lastRef.sourceGroup != None else "None"}")
	return lastRef



def relocateGroup(mainState: MainState, existingPath: str, newPath: str):
	mainState.getGroup(existingPath).relocate(mainState, newPath)



def moveElementAfter(list: list, originalIndex, afterIndex):
	temp = list[originalIndex]
	del list[originalIndex]
	list.insert(afterIndex if originalIndex <= afterIndex else afterIndex + 1, temp)



def tryResolveDependencyOrder(groups: UniqueList[Group]):

	"""
	Brute force dependency order, moving groups when needed. \n
	OH the time complexity!
	"""

	def alphabetically(a: Group, b: Group) -> int:
		if a.name < b.name:
			return -1
		elif a.name == b.name:
			return 0
		else:
			return 1

	# Sort groups alphabetically based on name
	groups.insertionSort(alphabetically)

	curCheckNode: UniqueListNode[Group] = groups.head.next
	curCheckNodeI: int = 0
	while curCheckNode != groups.tail:

		curCheckGroup: Group = curCheckNode.value

		if len(curCheckGroup.dependsOn) > 0:

			maxDependNode: UniqueListNode[Group] = None
			maxDependIndex: int = 0
			for dependName in curCheckGroup.dependsOn:
				i: int = 0
				for checkDependNode in groups.nodes():
					checkDependGroup: Group = checkDependNode.value
					if checkDependGroup.name == dependName and i > maxDependIndex:
						assert curCheckGroup.name not in checkDependGroup.dependsOn, f"Circular dependency: {curCheckGroup.name} and {dependName}"
						maxDependNode = checkDependNode
						maxDependIndex = i
					i += 1

			if curCheckNodeI < maxDependIndex:
				curCheckNode = curCheckNode.next
				groups.moveNodeAfter(curCheckNode.previous, maxDependNode)
				assert curCheckGroup != curCheckNode.value, f"Duplicate group in list: {curCheckGroup.name} and {curCheckNode.value.name}"
				continue

		curCheckNode = curCheckNode.next
		curCheckNodeI += 1

	for group in groups:
		tryResolveDependencyOrder(group.subGroups)


def resolveTemplateUseRepresentations(mainState: MainState):

	pending: set[str] = set()
	for group in mainState.filteredGroups:
		if group.isSubgroup(): continue
		pending.add(group.name)

	while len(pending) > 0:
		group: Group = mainState.getGroup(pending.pop())
		group.resolveTemplateUseRepresentations(mainState, pending, TemplateMappingTracker())


def writeBindings(mainState: MainState, outputFileName: str, groups: UniqueList[Group], out: TextIOWrapper, baseclassOut: TextIOWrapper) -> None:

	baseclassOut.write(f"\n#include \"{pathToFileNameNoExt(outputFileName)}.h\"\n\n")

	baseclassOut.write("template<typename Derived, typename Base>\n")
	baseclassOut.write("constexpr uintptr_t offsetofbase() {\n")
	baseclassOut.write("\treturn reinterpret_cast<uintptr_t>(static_cast<Base*>(reinterpret_cast<Derived*>(1))) - 1;\n")
	baseclassOut.write("}\n\n")

	baseclassOut.write("void registerBaseclasses() {\n")
	baseclassOut.write("\tRegisterBaseclassOffsets({\n")

	class OpenFieldData:
		def __init__(self) -> None:
			self.fieldBindingName: str = None
			self.getBindingName: str = None
			self.setBindingName: str = None


	class OpenConstantType(Enum):
		INTEGER = 1
		STRING = 2

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
			self.hasReasonForOutput: bool = False


	class OpenFunctionData:

		def __init__(self) -> None:
			self.functionName: str = None
			self.functionBindingName: str = None


	openDataGroups: list[OpenGroupData] = []
	usedIdentifiers: set[str] = set()

	def resolveIdentifier(identifer):

		attempt = identifer
		attemptI: int = 1
		while True:
			if attempt in usedIdentifiers:
				attempt = f"{identifer}_clashing{attemptI}"
				attemptI = attemptI + 1
			else:
				break

		usedIdentifiers.add(attempt)
		return attempt


	def writeGroupWithTemplateUse(group: Group, templateMappingTracker: TemplateMappingTracker, currentTemplate: TemplateUse=None):

		groupOpenData = OpenGroupData()
		groupOpenData.group = group
		openDataGroups.append(groupOpenData)

		if currentTemplate != None:
			templateMappingTracker.registerMapping(group.name, currentTemplate.tup)

		groupOpenData.appliedNameUsertypeNoOverride = group.getAppliedName(mainState, templateMappingTracker, templateTypeMode=TemplateTypeMode.HEADER)
		groupOpenData.appliedNameUsertype = group.getAppliedName(mainState, templateMappingTracker, useUsertypeOverride=True, templateTypeMode=TemplateTypeMode.HEADER)
		groupOpenData.appliedNameUsertypeFunc = group.getAppliedName(mainState, templateMappingTracker, templateTypeMode=TemplateTypeMode.HEADER)
		groupOpenData.appliedHeaderName = group.getAppliedName(mainState, templateMappingTracker, templateTypeMode=TemplateTypeMode.HEADER)
		groupNameStrIden, _ = re.subn("[^a-zA-Z0-9_]", "_", groupOpenData.appliedNameUsertypeNoOverride)

		# Writing sizeof variable which returns the value of the sizeof operator when run on the usertype
		if group != mainState.globalGroup and group.groupType not in ("enum", "namespace") and group.name != "void" and not group.lineGroupFlags.isFlagged("noHardcodedBindings"):
			sizeofConstant = OpenConstantData()
			sizeofConstant.name = "sizeof"
			sizeofConstant.valueType = OpenConstantType.STRING
			sizeofConstant.value = f"sizeof({groupOpenData.appliedHeaderName})"
			groupOpenData.constantBindings.append(sizeofConstant)

		# Writing size variable which returns the size of the array
		if group.name in ("Array", "ConstArray") and not group.lineGroupFlags.isFlagged("noHardcodedBindings"):

			sizeConstant = OpenConstantData()
			sizeConstant.name = "size"
			sizeConstant.valueType = OpenConstantType.INTEGER
			sizeConstant.value = int(currentTemplate.tup[1].getHeaderName())
			groupOpenData.constantBindings.append(sizeConstant)

			lastIndexConstant = OpenConstantData()
			lastIndexConstant.name = "lastIndex"
			lastIndexConstant.valueType = OpenConstantType.INTEGER
			lastIndexConstant.value = int(currentTemplate.tup[1].getHeaderName()) - 1
			groupOpenData.constantBindings.append(lastIndexConstant)


		def writeAccessSelf(errorMsg: str):
			out.write(f"\t{groupOpenData.appliedHeaderName}* self = ({groupOpenData.appliedHeaderName}*)tolua_tousertype_dynamic(L, 1, 0, \"{groupOpenData.appliedNameUsertype}\");\n")
			out.write(f"\tif (!self) tolua_error(L, \"{errorMsg}\", NULL);\n")


		funcPointerFieldImplementations: list[FunctionImplementation] = []


		def handleField(field: Field, isPointerCast=False):

			"""
			Writes getter function for given field, (and an reference_ function that returns a pointer to the field).
			"""

			fieldNameStr = None
			writeFieldBindings: bool = False

			assert field.type in (FieldType.VARIABLE, FieldType.FUNCTION), "field.type unhandled in writeGroupWithTemplateUse()"
			if field.type == FieldType.VARIABLE:
				variableField: VariableField = field
				if variableField.lineGroupFlags.isFlagged("noBindings"): return
				if len(variableField.variableType.arrayParts) > 0: return # These use GenericArray functions
				fieldNameStr = variableField.variableName
				writeFieldBindings = True
			elif field.type == FieldType.FUNCTION:
				functionField: FunctionField = field
				if functionField.lineGroupFlags.isFlagged("noBindings"): return
				if group.isVGroup:
					fieldNameStr = functionField.functionName
					writeFieldBindings = True
				else:
					funcPointerFieldImplementations.append(functionField.toImplementation(group, isFunctionPointer=True))

			if writeFieldBindings:

				fieldOpenData = OpenFieldData()
				isNormal: bool = group != mainState.globalGroup
				shouldWritePointerCast = not isPointerCast and not group.name in ("Pointer", "VoidPointer")

				addressPrefix = "reference_" if isPointerCast else ""

				groupOpenData.fieldBindings.append(fieldOpenData)
				groupOpenData.hasReasonForOutput = True

				fieldOpenData.fieldBindingName = f"{addressPrefix}{fieldNameStr}"

				if isNormal:
					fieldOpenData.getBindingName = resolveIdentifier(f"tolua_get_{groupNameStrIden}_{addressPrefix}{fieldNameStr}")
				else:
					fieldOpenData.getBindingName = resolveIdentifier(f"tolua_get_{addressPrefix}{fieldNameStr}")

				# GETTER START

				out.write(f"static int {fieldOpenData.getBindingName}(lua_State* L)\n")
				out.write("{\n")

				if field.type == FieldType.VARIABLE:

					variableField: VariableField = field
					varType: TypeReference = variableField.variableType.checkReplaceTemplateType(mainState, group, templateMappingTracker)

					if isNormal and group.groupType != "namespace" and not variableField.static:
						out.write(f"\t{groupOpenData.appliedNameUsertypeFunc}* self = ({groupOpenData.appliedNameUsertypeFunc}*)tolua_tousertype_dynamic(L, 1, 0, \"{groupOpenData.appliedNameUsertype}\");\n")
						out.write(f"\tif (!self) tolua_error(L, \"invalid 'self' in accessing variable '{variableField.variableName}'\", NULL);\n")

					varNameHeader = variableField.variableName if (isNormal and not variableField.static) else f"p_{variableField.variableName}"
					selfStr: str = None
					if isNormal:
						if group.groupType == "namespace" or variableField.static:
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
						if varType.isEnum():
							checkType = varType.getPrimitiveEnumType(mainState)

						checkTypeName = checkType.getName()

						if checkType.isPrimitiveNumber():
							if checkType.getUserTypePointerLevel() == 0:
								if checkTypeName in ("float", "double"):
									out.write(f"\ttolua_pushnumber(L, (lua_Number){'*'*effectivePtrLevel}{selfStr}{varNameHeader});\n")
								else:
									out.write(f"\tlua_pushinteger(L, (lua_Integer){'*'*effectivePtrLevel}{selfStr}{varNameHeader});\n")
								return True
						elif checkTypeName == "bool":
							if checkType.getUserTypePointerLevel() == 0:
								out.write(f"\ttolua_pushboolean(L, (bool){'*'*effectivePtrLevel}{selfStr}{varNameHeader});\n")
								return True
						elif checkType.isPrimitiveString():
							if checkType.getUserTypePointerLevel() == 1:
								out.write(f"\ttolua_pushstring(L, (const char*){'*'*(effectivePtrLevel - 1)}{selfStr}{varNameHeader});\n")
								return True
							elif checkType.getUserTypePointerLevel() == 0:
								out.write(f"\tlua_pushlstring(L, (const char*){'*'*(effectivePtrLevel - 1)}{selfStr}{varNameHeader}, 1);\n")
								return True

						return False


					if not checkPrimitiveHandling(varType):

						extraDeref: bool = not isNormal or variableField.static
						primitiveLike: bool = varType.isPrimitive() or varType.isEnum()

						if isPointerCast:
							assert varType.getUserTypePointerLevel() != 0 or primitiveLike, f"pointer cast cannot be written for type {varType.getHeaderName()}"
							out.write(f"\ttolua_pushusertype(L, (void*){'&' if not extraDeref else ''}")
						else:
							out.write(f"\ttolua_pushusertype(L, (void*){'&' if not extraDeref and varType.getUserTypePointerLevel() == 0 else ''}")

						out.write(f"{'*' if not isPointerCast and extraDeref and varType.getUserTypePointerLevel() != 0 else ''}{selfStr}{varNameHeader}")

						if isPointerCast:
							pointerTypeName = varType.getAppliedUserTypeName(mainState, group, templateMappingTracker, useUsertypeOverride=True, forcePointer=True)
							out.write(f", \"{pointerTypeName}\"")
						else:
							if varType.getUserTypePointerLevel() == 0 and not primitiveLike:
								# It is useless to write a reference to a non-pointer, non-primitive field
								# since the default behavior is to bind it using a pointer (reference)
								shouldWritePointerCast = False

							pointerRef = varType
							forcePointer: bool = False

							if varType.getUserTypePointerLevel() > (0 if primitiveLike else 1):
								# UserData objects are initialized with the value of the pointer
								# which essentially removes one pointer level from the type
								# (TODO: this should probably be templated somewhere)
								pointerRef = varType.shallowCopy()
								pointerRef.adjustUserTypePointerLevel(mainState, -1)
								forcePointer = not primitiveLike

							typeStr = pointerRef.getAppliedUserTypeName(mainState, group, templateMappingTracker, useUsertypeOverride=True, forcePointer=forcePointer)
							out.write(f", \"{typeStr}\"")

						out.write(");\n")


					out.write("\treturn 1;\n")

					if varType.bitFieldPart != None:
						shouldWritePointerCast = False

				elif field.type == FieldType.FUNCTION:
					# TODO: Not implemented
					functionField: FunctionField = field
					out.write("\treturn 1;\n")

				out.write("}\n\n")

				# GETTER END

				# SETTER START

				allowSetter = not isPointerCast

				if allowSetter and field.type == FieldType.VARIABLE:
					variableField: VariableField = field
					varType: TypeReference = variableField.variableType.checkReplaceTemplateType(mainState, group, templateMappingTracker)

					# Enums are fancy primitives!
					if varType.isEnum():
						varType = varType.getPrimitiveEnumType(mainState)

					allowSetter = varType.isPrimitive() or varType.getUserTypePointerLevel() > 0

				if allowSetter:

					if isNormal:
						fieldOpenData.setBindingName = resolveIdentifier(f"tolua_set_{groupNameStrIden}_{addressPrefix}{fieldNameStr}")
					else:
						fieldOpenData.setBindingName = resolveIdentifier(f"tolua_set_{addressPrefix}{fieldNameStr}")

					out.write(f"static int {fieldOpenData.setBindingName}(lua_State* L)\n")
					out.write("{\n")

					if field.type == FieldType.VARIABLE:

						variableField: VariableField = field
						varType: TypeReference = variableField.variableType.checkReplaceTemplateType(mainState, group, templateMappingTracker)

						if isNormal and group.groupType != "namespace" and not variableField.static:
							out.write(f"\t{groupOpenData.appliedNameUsertypeFunc}* self = ({groupOpenData.appliedNameUsertypeFunc}*)tolua_tousertype_dynamic(L, 1, 0, \"{groupOpenData.appliedNameUsertype}\");\n")
							out.write(f"\tif (!self) tolua_error(L, \"invalid 'self' in accessing variable '{variableField.variableName}'\", NULL);\n")

						varNameHeader = variableField.variableName if (isNormal and not variableField.static) else f"p_{variableField.variableName}"

						def checkPrimitiveHandling(varType: TypeReference):

							varTypeName = varType.getName()
							if isNormal and ((varTypeName != "char" and varType.getUserTypePointerLevel() > 0) or (varTypeName == "char" and varType.getUserTypePointerLevel() > 1)): return False

							enumCastStr = ""
							checkType = varType

							# Enums are fancy primitives!
							if varType.isEnum():
								enumCastStr = f"({varType.getEnumName()})"
								checkType = varType.getPrimitiveEnumType(mainState)

							checkTypeName: str = checkType.getName()
							checkTypeCastName = checkType.getCastName()

							selfStr: str = None
							if isNormal:
								if group.groupType == "namespace":
									selfStr = f"{groupOpenData.appliedHeaderName}::"
								elif variableField.static:
									selfStr = f"*{groupOpenData.appliedHeaderName}::"
								else:
									selfStr = "self->"
							else:
								selfStr = "*"*(varType.getUserTypePointerLevel() + 1)

							if checkType.isPrimitiveNumber():

								out.write(f"\t{selfStr}{varNameHeader} = ")

								if checkTypeName in ("float", "double"):
									out.write(f"{enumCastStr}tolua_setter_tonumber<{checkTypeCastName}>(L, \"{variableField.variableName}\");\n")
								else:
									out.write(f"{enumCastStr}tolua_setter_tointeger<{checkTypeCastName}>(L, \"{variableField.variableName}\");\n")

								return True

							elif checkTypeName == "bool":
								out.write(f"\t{selfStr}{varNameHeader} = {enumCastStr}tolua_setter_toboolean(L, \"{variableField.variableName}\");\n")
								return True
							elif checkTypeName == "char":
								if not checkType.unsigned and checkType.getUserTypePointerLevel() == 0:
									out.write(f"\t{selfStr}{varNameHeader} = {enumCastStr}tolua_setter_tochar(L, \"{variableField.variableName}\");\n")
									return True

							return False


						if not checkPrimitiveHandling(varType):

							selfStr: str = None
							if isNormal:
								if group.groupType == "namespace":
									selfStr = f"{groupOpenData.appliedHeaderName}::"
								elif variableField.static:
									selfStr = f"*{groupOpenData.appliedHeaderName}::"
								else:
									selfStr = "self->"
							else:
								selfStr = "*"

							pointerRef = varType
							forcePointer: bool = False
							primitiveLike: bool = varType.isPrimitive() or varType.isEnum()

							if varType.getUserTypePointerLevel() > (0 if primitiveLike else 1):
								# UserData objects are initialized with the value of the pointer
								# which essentially removes one pointer level from the type
								# (TODO: this should probably be templated somewhere)
								pointerRef = varType.shallowCopy()
								pointerRef.adjustUserTypePointerLevel(mainState, -1)
								forcePointer = not primitiveLike

							out.write(f"\t{selfStr}{varNameHeader} = ({varType.getAppliedHeaderName(mainState, group, templateMappingTracker)})tolua_tousertype_dynamic(L, 2, 0, \"{pointerRef.getAppliedUserTypeName(mainState, group, templateMappingTracker, useUsertypeOverride=True, forcePointer=forcePointer)}\");\n")

						out.write("\treturn 0;\n")

					elif field.type == FieldType.FUNCTION:
						# TODO: Not implemented
						functionField: FunctionField = field
						out.write("\treturn 0;\n")

					out.write("}\n\n")

				# SETTER END

				if shouldWritePointerCast:
					handleField(field, isPointerCast=True)


		def handleFunctionImplementation(functionImplementation: FunctionImplementation):

			# TODO: I can't return / pass non-pointer, non-primitives to functions yet

			returnType: TypeReference = functionImplementation.returnType.checkReplaceTemplateType(mainState, group, templateMappingTracker)

			# Must be void, enum, primitive, or pointer
			if not returnType.isNonPointerVoid() and not returnType.isEnum() and not returnType.isPrimitive() and returnType.getUserTypePointerLevel() == 0:
				return

			for param in functionImplementation.parameters:

				paramType = param.type.checkReplaceTemplateType(mainState, group, templateMappingTracker)

				# Can't have conflicting const requirements (the noconst directive prevents the function binding from generating for const types)
				if paramType.isNonPointerVoid() or paramType.isAbstractValue() or (paramType.const and paramType.noconst):
					return


			isNormal: bool = group != mainState.globalGroup
			functionOpenData = OpenFunctionData()

			funcImpBindingName: str = None
			if not functionImplementation.bindingName:
				funcImpBindingName = f"{functionImplementation.operatorStr}{functionImplementation.name}" if functionImplementation.operatorStr != None else functionImplementation.name
			else:
				funcImpBindingName = functionImplementation.bindingName

			functionOpenData.functionName = funcImpBindingName
			groupIden = f"{groupNameStrIden}_" if isNormal else ""
			functionOpenData.functionBindingName = resolveIdentifier(f"tolua_function_{groupIden}{funcImpBindingName}")

			groupOpenData.functionBindings.append(functionOpenData)
			groupOpenData.hasReasonForOutput = True

			out.write(f"static int {functionOpenData.functionBindingName}(lua_State* L)\n")
			out.write("{\n")

			if isNormal and group.groupType != "namespace" and not functionImplementation.isStatic:
				writeAccessSelf(f"invalid 'self' in calling function '{funcImpBindingName}'")

			callArgParts: list[str] = []
			def checkPrimitiveHandling(paramType: TypeReference, luaVarIndex: int):

				checkType: TypeReference = paramType
				enumCastString = ""

				# Enums are fancy primitives!
				if paramType.isEnum():
					enumCastString = f"({paramType.getEnumName()})"
					checkType = paramType.getPrimitiveEnumType(mainState)

				checkTypeName = checkType.getName()
				checkTypeCastName = checkType.getCastName()

				if checkType.isPrimitiveNumber() and checkType.getUserTypePointerLevel() == 0:
					if checkTypeName in ("float", "double"):
						callArgParts.append(f"{enumCastString}tolua_function_tonumber<{checkTypeCastName}>(L, {luaVarIndex}, \"{funcImpBindingName}\")")
					else:
						callArgParts.append(f"{enumCastString}tolua_function_tointeger<{checkTypeCastName}>(L, {luaVarIndex}, \"{funcImpBindingName}\")")
					callArgParts.append(", ")
					return True
				elif checkTypeName == "bool" and checkType.getUserTypePointerLevel() == 0:
					callArgParts.append(f"tolua_function_toboolean(L, {luaVarIndex}, \"{funcImpBindingName}\")")
					callArgParts.append(", ")
					return True
				elif checkType.isPrimitiveString() and not checkType.unsigned:
					if checkType.getUserTypePointerLevel() == 1:
						nonConstCast = "(char*)" if not checkType.const else ""
						callArgParts.append(f"{nonConstCast}tolua_function_tostring(L, {luaVarIndex}, \"{funcImpBindingName}\")")
						callArgParts.append(", ")
						return True
					elif checkType.getUserTypePointerLevel() == 0:
						callArgParts.append(f"tolua_function_tochar(L, {luaVarIndex}, \"{funcImpBindingName}\")")
						callArgParts.append(", ")
						return True

				return False

			out.write("\t")

			parameterIMod: int = None
			functionNameHeader = f"p_{functionImplementation.funcPtrName}" \
				if (not isNormal and functionImplementation.noBody and not functionImplementation.externalImplementation) \
				else functionImplementation.name

			functionNameHeader = f"{functionImplementation.operatorStr}{functionNameHeader}" if functionImplementation.operatorStr != None else functionNameHeader

			if isNormal and group.groupType != "namespace" and not functionImplementation.isStatic:
				parameterIMod = 2
			else:
				parameterIMod = 1

			if not returnType.isNonPointerVoid():
				returnTypeStr = returnType.getAppliedHeaderName(mainState, group, templateMappingTracker)
				out.write(f"{returnTypeStr} returnVal = ")

			if functionImplementation.isConstructor:
				out.write(f"new (self) {groupOpenData.appliedHeaderName}(")
			elif functionImplementation.isFakeConstructor:
				out.write(f"self->Construct(")
			elif functionImplementation.isDestructor:
				out.write(f"self->~{groupOpenData.appliedHeaderName}(")
			elif isNormal and group.groupType != "namespace" and not functionImplementation.isStatic:
				out.write(f"self->{functionNameHeader}(")
			else:
				classStr = f"{groupOpenData.appliedHeaderName}::" if isNormal else ""
				funcNameStr: str = f"(*p_{functionNameHeader})" if functionImplementation.isFunctionPointer else functionNameHeader
				out.write(f"{classStr}{funcNameStr}(")

			if functionImplementation.customReturnCount or functionImplementation.passLuaState:
				out.write("L")
				callArgParts.append(", ")

			for i, parameter in enumerate(functionImplementation.parameters):
				i += parameterIMod
				paramType = parameter.type.checkReplaceTemplateType(mainState, group, templateMappingTracker)
				if not checkPrimitiveHandling(paramType, i):
					# if paramType.getName() == "VoidPointer" and paramType.getUserTypePointerLevel() == 0:
					# 	callArgParts.append(f"tolua_tousertype(L, {i}, 0)")
					# 	callArgParts.append(", ")
					# else:
						callArgParts.append(paramType.getDereferenceStr(mainState, group, templateMappingTracker, i))
						callArgParts.append(", ")

			if functionImplementation.customReturnCount or functionImplementation.passLuaState or len(functionImplementation.parameters) > 0:
				callArgParts.pop()

			callArgParts.append(");\n")
			out.write("".join(callArgParts))


			if not returnType.isNonPointerVoid():

				out.write("\t")

				def checkPrimitiveHandling(varType: TypeReference):

					# Enums are fancy primitives!
					if varType.isEnum():
						varType = varType.getPrimitiveEnumType(mainState)

					varTypeName = varType.getName()

					if varType.isPrimitiveNumber() and varType.getUserTypePointerLevel() == 0:
						if varTypeName in ("float", "double"):
							out.write("tolua_pushnumber(L, (lua_Number)returnVal);\n")
						else:
							out.write(f"lua_pushinteger(L, (lua_Integer)returnVal);\n")
						return True
					elif varTypeName == "bool" and varType.getUserTypePointerLevel() == 0:
						out.write("tolua_pushboolean(L, (bool)returnVal);\n")
						return True
					elif varType.isPrimitiveString():
						if varType.getUserTypePointerLevel() == 1:
							out.write("tolua_pushstring(L, (const char*)returnVal);\n")
							return True
						elif varType.getUserTypePointerLevel() == 0:
							out.write("lua_pushlstring(L, (const char*)&returnVal, 1);\n")
							return True

					return False


				if not checkPrimitiveHandling(returnType):

					adjustedReturnType = returnType
					forcePointer: bool = False
					primitiveLike: bool = returnType.isPrimitive() or returnType.isEnum()

					if returnType.getUserTypePointerLevel() > (0 if primitiveLike else 1):
						# UserData objects are initialized with the value of the pointer
						# which essentially removes one pointer level from the type
						# (TODO: this should probably be templated somewhere)
						adjustedReturnType = returnType.shallowCopy()
						adjustedReturnType.adjustUserTypePointerLevel(mainState, -1)
						forcePointer = not primitiveLike

					out.write(f"tolua_pushusertype(L, (void*)returnVal, \"")
					if mainState.tryGetGroup(adjustedReturnType.getName()) != None:
						returnUserTypeStr = adjustedReturnType.getAppliedUserTypeName(mainState, group, templateMappingTracker, useUsertypeOverride=True, forcePointer=forcePointer)
						out.write(returnUserTypeStr)
					else:
						out.write("UnmappedUserType")

					out.write("\");\n")


			if functionImplementation.customReturnCount:
				out.write(f"\treturn {functionImplementation.customReturnCount};\n")
			elif not returnType.isNonPointerVoid():
				out.write("\treturn 1;\n")
			else:
				out.write("\treturn 0;\n")

			out.write("}\n\n")

			# reference_ functions for internal function implementations
			if (not isNormal) or functionImplementation.isStatic:

				addressVar = OpenFieldData()
				addressVar.fieldBindingName = f"reference_{functionImplementation.name}"
				addressVar.getBindingName = resolveIdentifier(f"tolua_get_reference_{groupIden}{functionImplementation.name}")

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


		for field in group.definedFields():
			handleField(field)

		for functionImplementation in group.functionImplementations:
			if functionImplementation.lineGroupFlags.isFlagged("noBindings"): continue
			handleFunctionImplementation(functionImplementation)

		for functionImplementation in funcPointerFieldImplementations:
			handleFunctionImplementation(functionImplementation)

		for enumTuple in group.enumTuples:
			handleEnumTuple(enumTuple)

		# Empty structs (those that simply derive from a superclass) should
		# be outputted if they were defined when bindings were enabled.
		if len(group.fields) == 0 and len(group.functionImplementations) == 0 and not group.lineGroupFlags.isFlagged("noBindings"):
			groupOpenData.hasReasonForOutput = True

		#handleHardcodedBindings()

		for subGroup in group.subGroups:
			if writeGroup(subGroup, templateMappingTracker):
				groupOpenData.hasReasonForOutput = True

		if currentTemplate != None:
			templateMappingTracker.deregisterMapping(group.name)



	def writeGroup(group: Group, templateMappingTracker: TemplateMappingTracker):

		if group.name == "void" or group.isPrimitive() or not group.isUsed(mainState):
			return False

		if group.template != None:
			for templateUse in group.templateUses:
				writeGroupWithTemplateUse(group, templateMappingTracker, templateUse)
		else:
			writeGroupWithTemplateUse(group, templateMappingTracker)

		return True



	out.write("\n")

	templateMappingTracker = TemplateMappingTracker()
	for group in groups:
		if group.isSubgroup(): continue
		writeGroup(group, templateMappingTracker)


	out.write("static void tolua_reg_types(lua_State* L)\n")
	out.write("{\n")

	for openData in openDataGroups:

		if not openData.hasReasonForOutput:
			continue

		out.write(f"\ttolua_usertype(L, \"{openData.appliedNameUsertype}\");\n")

	out.write("}\n\n")

	out.write("void registerBaseclasses();\n")
	out.write("int OpenBindingsInternal(lua_State* L)\n")
	out.write("{\n")
	out.write("\tregisterBaseclasses();\n")
	out.write("\ttolua_open(L);\n")
	out.write("\ttolua_reg_types(L);\n")
	out.write("\ttolua_module(L, NULL, 0);\n")
	out.write("\ttolua_beginmodule(L, NULL);\n")
	for openData in openDataGroups:

		if not openData.hasReasonForOutput:
			continue

		# Write global mappings
		if openData.group == mainState.globalGroup:

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
			baseclassOut.write(f"\t\t{{\"{openData.appliedNameUsertype}\", {{")

		if len(openData.group.extends) > 0:

			if hasNonPrimitiveBase:
				baseclassOut.write("\n")

			parts: list[str] = []

			for extendRef in openData.group.extends:

				extendRefUT = extendRef.getHeaderName(useUsertypeOverride=True)

				parts.append(f"\"{extendRefUT}\"")
				parts.append(",")

				if extendRef.isPrimitive():
					continue

				if hasNonPrimitiveBase:
					baseclassOut.write(f"\t\t\t{{\"{extendRefUT}\", ")
					baseclassOut.write(f"offsetofbase<{openData.appliedHeaderName}, {extendRef.getHeaderName()}>()")
					baseclassOut.write("},\n")

			parts.pop()
			out.write("".join(parts))

			if hasNonPrimitiveBase:
				baseclassOut.write("\t\t")

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

	baseclassOut.write("\t});\n")
	baseclassOut.write("}\n\n")




def fileAsString(fileName: str):
	with open(fileName) as file:
		return file.read()


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
	constarray = mainState.getGroup("ConstArray")
	pointer = mainState.getGroup("Pointer")
	voidPointer = mainState.getGroup("VoidPointer")


	def registerPointerTypesForGroup(group: Group):
		for uniqueRepresentation in group.uniqueUseRepresentations.values():
			if uniqueRepresentation.isNonPointerVoid(): continue
			specialRef: TypeReference = uniqueRepresentation.shallowCopy()
			pointer.addTemplateUse( (specialRef,), 0 )


	registerPointerTypesForGroup(pointer)

	for group in mainState.filteredGroups:

		if group in (mainState.globalGroup, array, constarray, pointer, voidPointer) or group.groupType == "namespace":
			continue

		registerPointerTypesForGroup(group)


def registerVariableArrayTypes(mainState: MainState):

	"""
	Registers VariableArray types for every Group (and every pointer level > 0). Since pointer-as-array fixups
	are difficult to establish without a massive review, provide all possible VariableArray specializations
	for Lua code to be able to cast to.
	"""

	array = mainState.getGroup("Array")
	constarray = mainState.getGroup("ConstArray")
	pointer = mainState.getGroup("Pointer")
	variableArray = mainState.getGroup("VariableArray")
	voidPointer = mainState.getGroup("VoidPointer")

	def registerVariableArrayTypesForGroup(group: Group):
		for uniqueRepresentation in group.uniqueUseRepresentations.values():
			if uniqueRepresentation.getUserTypePointerLevel() == 0: continue
			if uniqueRepresentation.getName() == "void" and uniqueRepresentation.getUserTypePointerLevel() == 1: continue
			if uniqueRepresentation.sourceType not in (TypeRefSourceType.FUNCTION_RETURN, TypeRefSourceType.VARIABLE): continue

			specialRef: TypeReference = uniqueRepresentation.shallowCopy()
			specialRef.adjustUserTypePointerLevel(mainState, -1)
			variableArray.addTemplateUse( (specialRef,), 0 )

	for group in mainState.filteredGroups:

		if group in (mainState.globalGroup, array, constarray, pointer, variableArray, voidPointer) or group.groupType == "namespace":
			continue

		registerVariableArrayTypesForGroup(group)


def fileAsSet(filePath):
	s = set()
	if filePath != None:
		with open(filePath) as fileIn:
			for line in fileIn:
				s.add(line.strip())
	return s


def filesAsSet(filePaths):
	s = set()
	for filePath in filePaths:
		with open(filePath) as fileIn:
			for line in fileIn:
				s.add(line.strip())
	return s


def outputFile(filePath, out: TextIOWrapper):
	if filePath != None:
		with open(filePath) as fileIn:
			for line in fileIn:
				out.write(line)


def filterGroups(mainState: MainState, wantedFiles: list[str], abstractTypesFile: str, ignoreHeaderFile: str, packingFile: str):

	"""
	Filter groups down to what is requested in wanted_types.txt and their subclasses / referenced types.
	"""

	wantedNames = filesAsSet(wantedFiles)
	wantedNames.add("EngineGlobals")
	wantedNames.add("Pointer") # WORKAROUND
	wantedNames.add("VoidPointer") # WORKAROUND
	wantedNames.add("UnmappedUserType")

	for primitive in handledPrimitives:
		wantedNames.add(f"Primitive<{primitive}>")

	if mainState.noCustomTypes:
		mainState.getGroup("Pointer").ignoreHeader = True
		mainState.getGroup("Array").ignoreHeader = True
		mainState.getGroup("ConstArray").ignoreHeader = True
		mainState.getGroup("CharString").ignoreHeader = True
		mainState.getGroup("ConstCharString").ignoreHeader = True
		mainState.getGroup("VoidPointer").ignoreHeader = True
		mainState.getGroup("Primitive").ignoreHeader = True
		mainState.getGroup("UnmappedUserType").ignoreHeader = True

	pendingProcessed: list[str] = []
	for wantedName in wantedNames:
		wantedRef: TypeReference = defineTypeRef(mainState, None, wantedName, TypeRefSourceType.WANTED, isDirectlyWanted=True)
		wantedGroup: Group = wantedRef.getGroup()
		wantedGroup.isDirectlyWanted = True
		pendingProcessed.append(wantedGroup.name)

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

	primitiveGroup: Group = mainState.getGroup("Primitive")
	for groupNode in mainState.filteredGroups.nodes():
		group: Group = groupNode.value
		if group.isUsed(mainState):
			# Add primitive template for every used enum
			if group.groupType == "enum":
				primitiveGroup.addTemplateUse((defineTypeRef(mainState, None, group.name, TypeRefSourceType.TEMPLATE),), 0)
		else:
			mainState.filteredGroups.remove(groupNode)

	if abstractTypesFile:
		with open(abstractTypesFile) as fileIn:
			for line in fileIn:
				if group := mainState.tryGetGroup(line.strip()):
					group.abstract = True

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


def checkRename(mainState: MainState, alreadyDefinedUsertypesFile: str):

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
			unnamedTypeMatch = re.fullmatch("<unnamed_(?:type|enum)_(\\S+)>", newName)
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
				if group := mainState.tryGetGroup(groupName):
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

		if group.isSubgroup() or group.ignoreHeader: continue

		for lightDependency in group.lightDependsOn:

			lightDepend = mainState.tryGetGroup(lightDependency)

			if (not lightDepend or lightDepend == mainState.globalGroup
				or lightDepend.isPrimitive() or lightDepend.name == "void"
				or lightDepend.isSubgroup() or lightDepend.ignoreHeader or not lightDepend.isUsed(mainState)
				or (lightDepend.defined and lightDepend.sortedPosition <= group.sortedPosition)
			):
				continue

			forwardDeclarations.add(lightDependency)

		# Non-static internal member functions need a forward def for the 'this' pointer.
		if group != mainState.globalGroup and group.groupType != "namespace":
			for funcImp in group.functionImplementations:
				if not funcImp.isStatic and funcImp.noBody:
					forwardDeclarations.add(group.name)
					break

	# Output forward declarations
	for forwardDeclaration in sorted(forwardDeclarations):
		group = mainState.getGroup(forwardDeclaration)
		if group.template != None: out.write(group.template + "\n")
		out.write(group.groupType + " " + group.name + ";\n")

	out.write("\n")


def outputHeader(mainState: MainState, outputFileName: str, dllName: str, out: TextIOWrapper):

	def doOutput(internalPointersOut: TextIOWrapper):

		internalPointersList = []

		if internalPointersOut:
			internalPointersOut.write(f"\n#include \"{pathToFileName(outputFileName)}\"\n\n")

		newline: str = ""

		# Output groups
		for group in mainState.filteredGroups:
			if group.isSubgroup() or group.ignoreHeader or group.groupType == "undefined": continue
			out.write(newline)
			groupStr = group.writeHeader(mainState, internalPointersOut, internalPointersList, HeaderType.NORMAL)
			if groupStr != "":
				out.write(groupStr)
				newline = "\n"

		def doEOFFuncOutput(group: Group):

			for subgroup in group.subGroups:
				doEOFFuncOutput(subgroup)

			for functionImp in group.functionImplementations:
				if functionImp.eofBody:
					out.write("\n")
					out.write(functionImp.toString(mainState, eof=True))

		# Output eof body functions
		for group in mainState.filteredGroups:
			if group.isSubgroup() or group.ignoreHeader or group.groupType == "undefined": continue
			doEOFFuncOutput(group)

		if internalPointersOut:

			if mainState.manualPatternHandling:
				out.write("\ntypedef std::function<uintptr_t(const char*)> type_attemptFillPointerCallback;\n")
				out.write("void InitBindingsInternal(type_attemptFillPointerCallback);\n")

			printFunc: str = mainState.printFuncWideString if not mainState.forceByteStrings else mainState.printFuncByteString
			strStart: str = "TEXT(\"" if not mainState.forceByteStrings else "\""
			strNewline: str = "\\n" if not mainState.printFuncOmitNewline else ""
			strEnd: str = "\")" if not mainState.forceByteStrings else "\""

			if not mainState.manualPatternHandling:

				internalPointersOut.write(f"""
template<typename OutType>
static void attemptFillPointer(const String& patternName, OutType& pointerOut) {{
	PatternValueHandle patternHandle;
	switch (sharedState().GetPatternValue(patternName, patternHandle)) {{
		case PatternValueType::SINGLE: {{
			pointerOut = reinterpret_cast<OutType>(sharedState().GetSinglePatternValue(patternHandle));
			break;
		}}
		case PatternValueType::INVALID: {{
			{printFunc}({strStart}[!][{dllName}] attemptFillPointer() - Binding pattern [%s] missing; using this binding will crash the game{strNewline}{strEnd}, patternName.c_str());
			break;
		}}
		default: {{
			{printFunc}({strStart}[!][{dllName}] attemptFillPointer() - Binding pattern [%s].Type not SINGLE; using this binding will crash the game{strNewline}{strEnd}, patternName.c_str());
			break;
		}}
	}}
}}

void InitBindingsInternal() {{
"""
				)
			else:
				internalPointersOut.write(f"""
template<typename OutType>
static void attemptFillPointer(const char *const patternName, OutType& pointerOut, type_attemptFillPointerCallback callback) {{
	const uintptr_t patternValue = callback(patternName);
	if (patternValue == 0x0) {{
		{printFunc}({strStart}[!][{dllName}] attemptFillPointer() - Binding pattern [%s] missing; using this binding will crash the game{strNewline}{strEnd}, patternName);
		return;
	}}
	pointerOut = reinterpret_cast<OutType>(patternValue);
}}

void InitBindingsInternal(type_attemptFillPointerCallback callback) {{
"""
				)

			callbackArgument: str = "" if not mainState.manualPatternHandling else ", callback"
			for internalPointerNameTup in internalPointersList:
				internalPointersOut.write(f"\tattemptFillPointer({strStart}{internalPointerNameTup[0]}{strEnd}, {internalPointerNameTup[1]}{callbackArgument});\n")

			internalPointersOut.write("}\n")


	if not mainState.noCustomTypes:
		outputInternalPointersFile = outputFileName[0:outputFileName.rindex('.')] + "_internal_pointers.cpp"
		with open(outputInternalPointersFile, "w") as internalPointersOut:
			doOutput(internalPointersOut)
	else:
		doOutput(None)


def processInputHeader(mainState: MainState, filePath: str=None, blob: str=None) -> None:
	"""
	Processes the given header file and registers all of the top-level `Group`s (struct/class/enum/union/namespace)
	Note that Group lines are not processed past associating them with the Group.
	The "global" Group (that contains lines not found in a Group) is fully processed by this function.
	"""

	state: CheckLinesState = CheckLinesState()
	mainState.lineGroupFlags.applyTo(state.lineGroupFlags)

	currentGroup = None
	currentLineCollection = None
	groupLevel = 0
	hitFirstBracket = False
	previousTemplate: str = None
	alreadyExisted = False
	ignoreGroup = False

	def checkGroupLine(line: str) -> Tuple[bool,bool]:
		nonlocal groupLevel
		nonlocal hitFirstBracket
		nonlocal alreadyExisted
		openBracketCount: int = line.count("{")
		groupLevel += openBracketCount
		groupLevel -= line.count("}")
		appendLine: bool = not alreadyExisted or (groupLevel > 0 and hitFirstBracket)
		if openBracketCount > 0: hitFirstBracket = True
		groupDone: bool = hitFirstBracket and groupLevel == 0
		return (appendLine, groupDone)


	def clearGroupState():
		nonlocal currentGroup
		nonlocal currentLineCollection
		nonlocal hitFirstBracket
		nonlocal alreadyExisted
		nonlocal ignoreGroup
		currentGroup = None
		currentLineCollection = None
		hitFirstBracket = False
		alreadyExisted = False
		ignoreGroup = False


	def processLine(line: str):

		nonlocal state
		nonlocal currentGroup
		nonlocal currentLineCollection
		nonlocal groupLevel
		nonlocal hitFirstBracket
		nonlocal previousTemplate
		nonlocal alreadyExisted
		nonlocal ignoreGroup
		line = line.rstrip()

		if not ignoreGroup:

			leftOfExtends = None
			try:
				colonIndex = line.index(":")
				leftOfExtends = line[:colonIndex].strip()
			except ValueError:
				leftOfExtends = line

			split = splitKeepBrackets(leftOfExtends, [" "])
			declMatch: Match = re.match("^(?:(?:\\$pack_\\d+|\\$allow_default_construction\\((?:true|false)\\))\\s+)*(?:const\\s+){0,1}(struct|class|enum|union|namespace)\\s+(?:\\/\\*VFT\\*\\/\\s+){0,1}(?:__cppobj\\s+){0,1}(?:__unaligned\\s+){0,1}(?:__declspec\\(align\\(\\d+\\)\\)\\s+){0,1}([^;]*?)(?:\\s+\\:\\s+(.*?)){0,1}\\s*$", line)

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
					for namePart in nameParts:
						if namePart.startswith("<"): continue
						if namePart.find("<") != -1:
							ignoreGroup = True
							break

					if not ignoreGroup:
						currentGroup = Group()
						currentGroup.template = previousTemplate
						currentGroup.groupType = declMatch.group(1)
						currentGroup.defined = True
						mainState.lineGroupFlags.applyTo(currentGroup.lineGroupFlags)
						currentGroup.updateSingleName(mainState, nameStr)

				if not ignoreGroup:
					currentLineCollection = GroupLineCollection()
					mainState.lineGroupFlags.applyTo(currentLineCollection.lineGroupFlags)
					currentGroup.lineCollections.append(currentLineCollection)


		# Track template lines, (previousTemplate is only set if the previous line was a template declaration outside of a Group)
		if not ignoreGroup and currentGroup == None and len(split) >= 1 and stripTypeBrackets(split[0]) == "template":
			previousTemplate = line
		else:
			previousTemplate = None

		if not ignoreGroup:

			# Track Group lines
			if currentGroup != None:

				appendLine, groupDone = checkGroupLine(line)

				# TODO: Store struct declaration separately so separately definitions can override the previous ones
				if appendLine:
					currentLineCollection.lines.append(line)

				if groupDone:
					if not alreadyExisted:
						# Register Group
						mainState.addGroup(currentGroup)

					clearGroupState()
			else:
				# Process the global group's lines
				processCommonGroupLines(mainState, state, line, mainState.globalGroup)
		else:
			_, groupDone = checkGroupLine(line)
			if groupDone:
				clearGroupState()


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


def runModule(mainState: MainState, modulePath: str, functionName: str):
	_, moduleName = separatePathNoExt(modulePath)
	spec = importlib.util.spec_from_file_location(moduleName, modulePath)
	module = importlib.util.module_from_spec(spec)
	sys.modules[spec.name] = module
	spec.loader.exec_module(module)
	getattr(module, functionName)(mainState)


def loadMaximumMainState(
	mainState: MainState = None,
	abstractTypesFile: str = None,
	alreadyDefinedUsertypesFile: str = None,
	fixupFileName: str = None,
	ignoreGhidraVFTables: bool = False,
	ignoreHeaderFile: str = None,
	inputFileNames: str = None,
	manualTypesFile: str = None,
	packingFile: str = None,
	wantedFiles: str = ""
) -> MainState:

	mainState = mainState or MainState()

	mainState.globalGroup = Group()
	mainState.globalGroup.defined = True
	mainState.lineGroupFlags.applyTo(mainState.globalGroup.lineGroupFlags)
	mainState.globalGroup.updateSingleName(mainState, "EngineGlobals")
	mainState.addGroup(mainState.globalGroup)

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

template<typename T>
struct Primitive
{
};

struct UnmappedUserType
{
};
		""")

	if manualTypesFile != None:
		processInputHeader(mainState, manualTypesFile)

	for inputFileName in inputFileNames.split(","):

		parts = inputFileName.split(":")
		numParts = len(parts)
		if numParts not in (1, 2):
			assert False, "inFiles malformed"

		flags = parts[0] if numParts == 2 else ""
		fileName = parts[1] if numParts == 2 else parts[0]

		oldFlagValues = []
		for flag in flags.split(";"):
			if flag == "NO_BINDINGS":
				oldFlagValues.append(("noBindings", mainState.lineGroupFlags.getFlag("noBindings")))
				mainState.lineGroupFlags.setFlag("noBindings", FlagSource.DEFAULT)
			elif flag == "NO_HARDCODED_BINDINGS":
				oldFlagValues.append(("noHardcodedBindings", mainState.lineGroupFlags.getFlag("noHardcodedBindings")))
				mainState.lineGroupFlags.setFlag("noHardcodedBindings", FlagSource.DEFAULT)

		processInputHeader(mainState, fileName)

		for flagName, oldFlagValue in oldFlagValues:
			mainState.lineGroupFlags.setFlag(flagName, oldFlagValue)


	# Process Group lines to derive types
	for group in mainState.groups:
		if group.linesProcessed: continue
		group.processLinesFillTypes(mainState)

	# Move multi-layer structs so that they nest properly
	for group in mainState.groups:
		group.updateNesting(mainState)

	# Run fixup file to make some necessary changes
	if fixupFileName != None:
		runModule(mainState, fixupFileName, "fixup")

	for group in mainState.groups:
		group.checkForVGroup(mainState, ignoreGhidraVFTables=ignoreGhidraVFTables) # Fills vGroup and removes __vftable field if present.
		group.mapTemplateTypeNames()                                               # Maps the template names that appear in this Group's inheritance hierarchy to their originating Group.
		group.mapDependsOn(mainState)                                              # Attempts to derive type dependencies and light dependencies (those that need forward declarations).

	# Filter groups down to what is requested in wanted_types.txt and their subclasses / referenced types.
	filterGroups(mainState, wantedFiles.split(","), abstractTypesFile, ignoreHeaderFile, packingFile)

	# Fill templateUses and uniqueUseRepresentations
	for group in mainState.filteredGroups:
		group.scanInwardTypeRefs(mainState)

	resolveTemplateUseRepresentations(mainState)

	# Try to fix dependency order (SLOW)
	tryResolveDependencyOrder(mainState.filteredGroups)

	# Rename groups to remove invalid characters / improve autogenerated names, fix clashing function fields, and fix clashing usertype names.
	checkRename(mainState, alreadyDefinedUsertypesFile)

	# Registers Pointer types for every group, (for reference_ functions)
	registerPointerTypes(mainState)

	# Registers VariableArray types for every Group (and every pointer level > 0). Since pointer-as-array fixups
	# are difficult to establish without a massive review, provide all possible VariableArray specializations
	# for Lua code to be able to cast to.
	registerVariableArrayTypes(mainState)

	return mainState


def doGenerateHeader():

	mainState = MainState()

	abstractTypesFile: str = None
	alreadyDefinedUsertypesFile: str = None
	bindingsFileName: str = None
	bindingsPreludeFile: str = None
	dllName: str = None
	fixupFileName: str = None
	ignoreGhidraVFTables: bool = False
	ignoreHeaderFile: str = None
	inputFileNames: str = None
	manualTypesFile: str = None
	outputFileName: str = None
	packingFile: str = None
	preludeFile: str = None
	suffixFile: str = None
	wantedFiles: str = ""

	for k in islice(sys.argv, 1, None):
		if   (v := re.search("-abstractTypesFile=(.+)",           k)) != None: abstractTypesFile               = v.group(1)
		elif (v := re.search("-alreadyDefinedUsertypesFile=(.+)", k)) != None: alreadyDefinedUsertypesFile     = v.group(1)
		elif (v := re.search("-bindingsOutFile=(.+)",             k)) != None: bindingsFileName                = v.group(1)
		elif (v := re.search("-bindingsPreludeFile=(.+)",         k)) != None: bindingsPreludeFile             = v.group(1)
		elif (v := re.search("-dllName=(.+)",                     k)) != None: dllName                         = v.group(1)
		elif (v := re.search("-fixupFile=(.+)",                   k)) != None: fixupFileName                   = v.group(1)
		elif (v := re.search("-forceByteStrings",                 k)) != None: mainState.forceByteStrings      = True
		elif (v := re.search("-ignoreGhidraVFTables",             k)) != None: ignoreGhidraVFTables            = True
		elif (v := re.search("-ignoreHeaderFile=(.+)",            k)) != None: ignoreHeaderFile                = v.group(1)
		elif (v := re.search("-inFiles=(.+)",                     k)) != None: inputFileNames                  = v.group(1)
		elif (v := re.search("-manualPatternHandling",            k)) != None: mainState.manualPatternHandling = True
		elif (v := re.search("-manualTypesFile=(.+)",             k)) != None: manualTypesFile                 = v.group(1)
		elif (v := re.search("-noCustomTypes",                    k)) != None: mainState.noCustomTypes         = True
		elif (v := re.search("-outFile=(.+)",                     k)) != None: outputFileName                  = v.group(1)
		elif (v := re.search("-packingFile=(.+)",                 k)) != None: packingFile                     = v.group(1)
		elif (v := re.search("-preludeFile=(.+)",                 k)) != None: preludeFile                     = v.group(1)
		elif (v := re.search("-printFuncByteString=(.+)",         k)) != None: mainState.printFuncByteString   = v.group(1)
		elif (v := re.search("-printFuncOmitNewline",             k)) != None: mainState.printFuncOmitNewline  = True
		elif (v := re.search("-printFuncWideString=(.+)",         k)) != None: mainState.printFuncWideString   = v.group(1)
		elif (v := re.search("-suffixFile=(.+)",                  k)) != None: suffixFile                      = v.group(1)
		elif (v := re.search("-wantedFiles=(.+)",                 k)) != None: wantedFiles                     = v.group(1)

	loadMaximumMainState(
		mainState = mainState,
		abstractTypesFile = abstractTypesFile,
		alreadyDefinedUsertypesFile = alreadyDefinedUsertypesFile,
		fixupFileName = fixupFileName,
		ignoreGhidraVFTables = ignoreGhidraVFTables,
		ignoreHeaderFile = ignoreHeaderFile,
		inputFileNames = inputFileNames,
		manualTypesFile = manualTypesFile,
		packingFile = packingFile,
		wantedFiles = wantedFiles
	)

	with open(outputFileName, "w") as out:

		# Write bindings file
		if bindingsFileName:
			outBindingsPath, outBindingsBase = separatePathNoExt(bindingsFileName)
			with \
			open(bindingsFileName, "w") as bindingsOut, \
			open(f"{outBindingsPath}{outBindingsBase}_baseclass_offsets.cpp", "w") as baseclassOut:
				outputFile(bindingsPreludeFile, bindingsOut)
				writeBindings(mainState, outputFileName, mainState.filteredGroups, bindingsOut, baseclassOut)

		# Write header prelude
		outputFile(preludeFile, out)

		# Write forward declarations
		outputForwardDeclarations(mainState, out)

		# Write header
		outputHeader(mainState, outputFileName, dllName, out)

		# Write header suffix
		outputFile(suffixFile, out)


def loadMinimumMainState(inputFileName: str, fixupFileName: str=None, manualTypesFile: str=None, checkRename=True, idaUnnamedScheme=False) -> MainState:

	mainState = MainState()
	mainState.noCustomTypes = True
	mainState.idaUnnamedScheme = idaUnnamedScheme

	mainState.globalGroup = Group()
	mainState.globalGroup.defined = True
	mainState.lineGroupFlags.applyTo(mainState.globalGroup.lineGroupFlags)
	mainState.globalGroup.updateSingleName(mainState, "EngineGlobals")
	mainState.addGroup(mainState.globalGroup)

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

template<typename T>
struct Primitive
{
};

struct UnmappedUserType
{
};
		""")

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
		runModule(mainState, fixupFileName, "fixup")

	for group in mainState.groups:
		group.checkForVGroup(mainState) # Fills vGroup and removes __vftable field if present.

	if checkRename:
		# Rename groups to remove invalid characters / improve autogenerated names, fix clashing function fields, and fix clashing usertype names.
		checkRename(mainState, None)

	return mainState



def doCompare(compare1: str, compare2: str):

	mainStateOld = loadMinimumMainState(compare1)
	mainStateNew = loadMinimumMainState(compare2)

	for newGroup in mainStateNew.groups:

		if (oldGroup := mainStateOld.tryGetGroup(newGroup.name)) != None:

			for field in newGroup.fields:
				if oldGroup.fieldsMap.get(field.getName()) == None:
					print(f"{newGroup.name} added field: {field.getName()}")

			for oldField in oldGroup.fields:
				if newGroup.fieldsMap.get(oldField.getName()) == None:
					print(f"{newGroup.name} removed field: {oldField.getName()}")



class IDAStructFields:

	__slots__ = ("size", "fieldOffsets", "baseclassOffsets")
	def __init__(self, size: int) -> None:
		self.size: int = size
		self.fieldOffsets: list[tuple[str,int]] = []
		self.baseclassOffsets: list[int] = []


idaStructFieldPattern: Pattern = re.compile('(?<=\n)([0-9a-fA-F]{8})(?:(?: ([^;\\s]+)\\s+(?!ends\n)\\S+\\s+[^;\\s]+.*)|(\\s+db \\? ; undefined))\n')

def readIdaStructFieldOffsets(idaStructsPath: str) -> dict[str,int]:

	toReturn: dict[str,IDAStructFields] = {}
	fileContents: str = fileAsString(idaStructsPath)

	for startMatch in re.finditer("(?<=\n)00000000 (.+) (?:struc|union) .*sizeof=0x([0-9a-fA-F]+).*\n", fileContents):

		structNameOriginal: str = startMatch.group(1).strip()

		idaStructFields: IDAStructFields = IDAStructFields(int(startMatch.group(2), 16))
		toReturn[structNameOriginal] = idaStructFields

		idaEndStructPattern = re.compile("(?<=\n)[0-9a-fA-F]{8} (" + re.escape(structNameOriginal) + ") \\s*ends\n")
		endMatch = idaEndStructPattern.search(fileContents, startMatch.span(0)[1])
		if not endMatch:
			raise Exception("PARSE ERROR")

		structContents: str = fileContents[startMatch.span(1)[0]:endMatch.span(0)[1]]

		hitNonBaseclass = False
		for fieldMatch in idaStructFieldPattern.finditer(structContents):

			fieldOffset: int = int(fieldMatch.group(1), 16)

			if fieldMatch.group(3):

				idaStructFields.fieldOffsets.append((":padding", fieldOffset))

			else:

				fieldName: str = fieldMatch.group(2)

				if not hitNonBaseclass and fieldName.startswith("baseclass_"):
					idaStructFields.baseclassOffsets.append(fieldOffset)
				elif fieldName != "__vftable":
					hitNonBaseclass = True
					idaStructFields.fieldOffsets.append((fieldName, fieldOffset))

	return toReturn


def doRequestFieldTypes(requestHeaderPath: str, requestTypesPath: str, idaStructsPath: str, fixupFileName: str, manualTypesFile: str, noRefify: bool):

	idaStructFieldOffsets: dict[str,IDAStructFields] = readIdaStructFieldOffsets(idaStructsPath)
	mainState = loadMinimumMainState(requestHeaderPath, fixupFileName=fixupFileName, manualTypesFile=manualTypesFile, checkRename=False, idaUnnamedScheme=True)

	with open("./out/requested_types.txt", "w") as out:

		taggedTypes = fileAsSet(requestTypesPath)

		if noRefify:
			def refify(typeName: str) -> str:
				typeNameDisplay = re.sub("<unnamed_type_(.+?)>", "\\1_t", typeName)
				return typeNameDisplay, False
		else:
			def refify(typeName: str) -> str:
				typeNameDisplay = re.sub("<unnamed_type_(.+?)>", "\\1_t", typeName)
				if typeName in taggedTypes:
					typeNameDisplay = re.sub("([<>])", "\\\\\\1", typeNameDisplay)
					typeName = re.sub("([<>])", "\\\\\\1", typeName)
					return f":ref:`{typeNameDisplay}<{typeName}>`", True
				else:
					if typeNameDisplay not in ("Array", "ConstArray", "void") and typeNameDisplay not in primitives and not typeNameDisplay.isnumeric():
						print(f"Unable to refify: \"{typeNameDisplay}\"")
					return typeNameDisplay, False


		for typeName in taggedTypes:

			if group := mainState.tryGetGroup(typeName):

				if not (idaFieldOffsets := idaStructFieldOffsets.get(typeName)):
					print(f"** Failed to find field offsets for group with name: \"{typeName}\" **")
					continue

				out.write(f":{typeName}|{idaFieldOffsets.size}\n")

				if group.hadVfptrField:
					if noRefify:
						out.write(f"<vfptr>|0|qword\n")
					else:
						out.write(f"vfptr|0|qword\n")

				for i, extendRef in enumerate(group.extends):
					if noRefify:
						fieldName = f"<baseclass>"
					else:
						fieldName = f"baseclass_{i}"
					offsetHex = str.format("{:X}", idaFieldOffsets.baseclassOffsets[i])
					typeDisplayName = extendRef.getHeaderName(typeManipulator=refify)
					typeDisplayName = re.sub(",:ref:", ", :ref:", typeDisplayName)
					typeDisplayName = re.sub("(:ref:`[^`]*?`)(?=[^\\s.,:;!?\\\\\\/'\")\\]}>])", "\\1\\\\", typeDisplayName)
					out.write(f"{fieldName}|{offsetHex}|{typeDisplayName}\n")

				fieldOffsetsLen = len(idaFieldOffsets.fieldOffsets)
				idaIndex = 0

				for field in group.fields:

					offsetTup: tuple[str,int] = None

					firstPaddingOffset: int = None
					while True:

						offsetTup = idaFieldOffsets.fieldOffsets[idaIndex] if idaIndex < fieldOffsetsLen else None

						if not offsetTup or not offsetTup[0].startswith(":padding"):

							if firstPaddingOffset:
								offsetHex = str.format("{:X}", firstPaddingOffset)
								if noRefify:
									out.write(f"<padding>|{offsetHex}|<blank>\n")
								else:
									out.write(f"``<padding>``|{offsetHex}|<blank>\n")

							break

						if not firstPaddingOffset:
							firstPaddingOffset = offsetTup[1]

						idaIndex += 1


					fieldName = field.getName()

					if not offsetTup or offsetTup[0] != fieldName:

						tupName = offsetTup[0] if offsetTup else ""
						print(f"** IDA expected \"{typeName}.{tupName}\", header has \"{fieldName}\" **")

						for backIndex in range(idaIndex, -1, -1):

							if backIndex >= fieldOffsetsLen:
								continue

							previousOffsetTup = idaFieldOffsets.fieldOffsets[backIndex]
							print(f"** \"{typeName}.{fieldName}\" falling back to \"{previousOffsetTup[0]}\" offset **")
							offsetTup = previousOffsetTup
							break


					if not offsetTup:
						raise Exception("** Failed to get offsetTup in group with name \"{typeName}\" **")

					offsetHex = str.format("{:X}", offsetTup[1])
					typeDisplayName = field.variableType.getHeaderName(typeManipulator=refify) if field.type == FieldType.VARIABLE \
						else field.toString(mainState, typeManipulator=refify).replace("*", "\\*")
					typeDisplayName = re.sub(",:ref:", ", :ref:", typeDisplayName)
					typeDisplayName = re.sub("(:ref:`[^`]*?`)(?=[^\\s.,:;!?\\\\/'\")\\]}>])", "\\1\\\\", typeDisplayName)

					out.write(f"{fieldName}|{offsetHex}|{typeDisplayName}\n")
					idaIndex += 1


				firstPaddingOffset: int = None
				while idaIndex < fieldOffsetsLen:

					offsetTup = idaFieldOffsets.fieldOffsets[idaIndex]

					if not offsetTup[0].startswith(":padding"):
						raise Exception(f"** \"{typeName}\" field index:{idaIndex}, name:\"{offsetTup[0]}\" should have been padding **")

					if not firstPaddingOffset:
						firstPaddingOffset = offsetTup[1]

					idaIndex += 1


				if firstPaddingOffset:
					offsetHex = str.format("{:X}", firstPaddingOffset)
					if noRefify:
						out.write(f"<padding>|{offsetHex}|<blank>\n")
					else:
						out.write(f"``<padding>``|{offsetHex}|<blank>\n")

				out.write(":end\n")

			else:
				print(f"* Failed to find group with name: \"{typeName}\" *")


def doCustomModule():

	mainState = MainState()

	abstractTypesFile: str = None
	alreadyDefinedUsertypesFile: str = None
	customModuleFile: str = None
	fixupFileName: str = None
	ignoreHeaderFile: str = None
	inputFileNames: str = None
	manualTypesFile: str = None
	packingFile: str = None
	wantedFiles: str = ""

	for k in islice(sys.argv, 1, None):
		if   (v := re.search("-abstractTypesFile=(.+)",           k)) != None: abstractTypesFile             = v.group(1)
		elif (v := re.search("-alreadyDefinedUsertypesFile=(.+)", k)) != None: alreadyDefinedUsertypesFile   = v.group(1)
		elif (v := re.search("-customModuleFile=(.+)",            k)) != None: customModuleFile              = v.group(1)
		elif (v := re.search("-fixupFile=(.+)",                   k)) != None: fixupFileName                 = v.group(1)
		elif (v := re.search("-ignoreHeaderFile=(.+)",            k)) != None: ignoreHeaderFile              = v.group(1)
		elif (v := re.search("-inFiles=(.+)",                     k)) != None: inputFileNames                = v.group(1)
		elif (v := re.search("-manualTypesFile=(.+)",             k)) != None: manualTypesFile               = v.group(1)
		elif (v := re.search("-noCustomTypes",                    k)) != None: mainState.noCustomTypes       = True
		elif (v := re.search("-packingFile=(.+)",                 k)) != None: packingFile                   = v.group(1)
		elif (v := re.search("-wantedFiles=(.+)",                 k)) != None: wantedFiles                   = v.group(1)

	loadMaximumMainState(
		mainState = mainState,
		abstractTypesFile = abstractTypesFile,
		alreadyDefinedUsertypesFile = alreadyDefinedUsertypesFile,
		fixupFileName = fixupFileName,
		ignoreHeaderFile = ignoreHeaderFile,
		inputFileNames = inputFileNames,
		manualTypesFile = manualTypesFile,
		packingFile = packingFile,
		wantedFiles = wantedFiles
	)

	runModule(mainState, customModuleFile, "run")


def mainSwitch():

	mode: str = None
	allowDebug: bool = False

	for k in islice(sys.argv, 1, None):
		if   (v := re.search("-mode=(.+)",  k)) != None: mode       = v.group(1)
		elif (v := re.search("-allowDebug", k)) != None: allowDebug = True

	if allowDebug and os.environ.get("DEBUGGING") == "1":
		input("Press any key to continue . . .\n")

	assert mode is not None, "-mode must be specified"

	if mode == "RequestTypes":

		fixupFileName: str = None
		idaStructs: str = None
		manualTypesFile: str = None
		noRefify: bool = False
		requestHeader: str = None
		requestTypes: str = None

		for k in islice(sys.argv, 1, None):
			if   (v := re.search("-fixupFile=(.+)",         k)) != None: fixupFileName   = v.group(1)
			elif (v := re.search("-idaStructsFile=(.+)",    k)) != None: idaStructs      = v.group(1)
			elif (v := re.search("-manualTypesFile=(.+)",   k)) != None: manualTypesFile = v.group(1)
			elif (v := re.search("-noRefify",               k)) != None: noRefify        = True
			elif (v := re.search("-requestHeaderFile=(.+)", k)) != None: requestHeader   = v.group(1)
			elif (v := re.search("-requestTypesFile=(.+)",  k)) != None: requestTypes    = v.group(1)

		doRequestFieldTypes(requestHeader, requestTypes, idaStructs, fixupFileName, manualTypesFile, noRefify)

	elif mode == "Compare":

		compare1: str = None
		compare2: str = None

		for k in islice(sys.argv, 1, None):
			if   (v := re.search("-compare1=(.+)", k)) != None: compare1 = v.group(1)
			elif (v := re.search("-compare2=(.+)", k)) != None: compare2 = v.group(1)

		doCompare(compare1, compare2)

	elif mode == "GenerateHeader":

		doGenerateHeader()

	elif mode == "CustomModule":

		doCustomModule()

	else:
		assert False, "Bad -mode"


if __name__ == "__main__":
	assert False, "generate_bindings.py cannot be invoked directly - import it and call mainSwitch()"
