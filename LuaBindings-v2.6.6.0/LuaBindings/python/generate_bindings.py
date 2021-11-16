
###############################################################################
# Generates the .h/.cpp files required to build the bindings DLL.             #
# This file has been hacked together under the principle of "It just works!". #
# Good luck - here be dragons.                                                #
###############################################################################

from enum import Enum
from io import TextIOWrapper
from itertools import islice
from typing import Match, Tuple
import builtins
import copy
import importlib
import re
import sys

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

	if bracketLevel == 0: raise ValueError()

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


class MainState:

	groupsDict: dict[str,Group] = {}
	groups: list[Group] = []
	filteredGroups: list[Group] = []

	def addGroup(self, group: Group):

		if existingGroup := self.groupsDict.get(group.name):

			# Note: This merge can be a source of errors if Group is updated to include new variables

			group.listIndex = existingGroup.listIndex
			self.groups[group.listIndex] = group

			if superGroup := existingGroup.superGroup:
				superGroup.subGroups.remove(existingGroup)

			group.isDirectlyWanted = group.isDirectlyWanted or existingGroup.isDirectlyWanted
			group.isWanted = group.isWanted or existingGroup.isWanted
			
			for inRef in existingGroup.inwardTypeRefs:
				inRef.group = group
				group.inwardTypeRefs.append(inRef)

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

	def renameGroup(self, group: Group, oldName: str):
		del self.groupsDict[oldName]
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


primitives = {"intptr_t", "size_t", "int", "__int8", "__int16", "__int32", "__int64", "long", "bool", "char", "float", "wchar_t", "long double"}
primitiveNumbers = {"intptr_t", "size_t", "int", "__int8", "__int16", "__int32", "__int64", "long", "float", "long double"}

class TypeReference:

	def __init__(self):

		self.sourceString: str = None

		self.group: Group = None
		self.sourceGroup: Group = None
		self.pointerLevel: int = 0
		self.arrayParts: list = []
		self.bitFieldPart: str = None
		self.templateTypes: list[TypeReference] = []

		self.noreplace: bool = False
		self.noconst: bool = False

		self.unsigned: bool = False
		self.const: bool = False
		self.long: bool = False

		self.superRef: TypeReference = None
		self.subRef: TypeReference = None


	def shallowCopy(self):
		return copy.copy(self)


	def getName(self):
		return self.group and self.group.name or self.sourceString


	def getSingleName(self):
		return self.group and self.group.singleName or self.sourceString


	def isVoid(self):
		return self.pointerLevel == 0 and self.getName() == "void"


	def getFullNameFromTypeRefChain(self):

		parts: list[str] = []

		if self.superRef:
			parts.append(self.superRef.getFullName())
			parts.append("::")

		parts.append(self.group and self.group.singleName or self.sourceString)
		return "".join(parts)


	def getAllTypeReferences(self):
		parts = [self]
		for templateType in self.templateTypes:
			for v in templateType.getAllTypeReferences():
				parts.append(v)
		return parts


	def isGenericTemplate(self):
		return self.sourceGroup != None and self.sourceGroup.templateTypeNameMapping.get(self.getName()) != None


	def isPrimitive(self):
		return self.getName() in primitives


	def isPrimitiveNumber(self):
		return self.getName() in primitiveNumbers


	def checkReplaceTemplateType(self, mainState: MainState, sourceGroup: Group, templateMappingTracker: TemplateMappingTracker, debug=False):
		
		toReturn = self
		toReturnName = toReturn.getName()

		if sourceGroup and (v := sourceGroup.templateTypeNameMapping.get(toReturnName)) != None:
			index = v.templateTypeNames.index(toReturnName)
			toReturn = templateMappingTracker.getMapping(v.name)[index].shallowCopy()

			if toReturnName == "Pointer":
				toReturn.templateTypes[0].pointerLevel += self.pointerLevel
			else:
				toReturn.pointerLevel += self.pointerLevel

			if not toReturn.noreplace:
				if toReturnName == "char" and toReturn.pointerLevel == 1:
					if toReturn.const:
						toReturn = ConstStringReference(mainState, sourceGroup)
					else:
						toReturn = StringReference(mainState, sourceGroup)

			toReturn.noreplace = self.noreplace
			toReturn.noconst = self.noconst
		
		return toReturn


	def getAppliedName(self, mainState: MainState, sourceGroup: Group, templateMappingTracker: TemplateMappingTracker, pointerLevelAdjust=0, useUsertypeOverride=False, templatesUseHeaderName=False, debug=False):

		"""
		Given a TypeRef in which the caller wants to express an arbritary series of template uses, returns a
		string representation of the current TypeRef's group name as if its template types were filled with the information
		held by templateMappingTracker.

		If the current TypeRef does not have an attached Group, simply returns the TypeRef's name.
		"""

		parts: list[str] = []

		if self.const:
			parts.append("const ")
		
		if self.unsigned:
			parts.append("unsigned ")

		if self.long:
			parts.append("long ")

		if self.superRef:
			parts.append(self.superRef.getAppliedName(mainState, sourceGroup, templateMappingTracker, useUsertypeOverride=useUsertypeOverride, templatesUseHeaderName=templatesUseHeaderName))
			parts.append("::")

		if len(self.templateTypes) > 0:

			parts.append(self.getSingleName())
			parts.append("<")

			if templatesUseHeaderName:
				for templateType in self.templateTypes:
					parts.append(templateType.checkReplaceTemplateType(mainState, sourceGroup, templateMappingTracker).getHeaderName())
					parts.append(",")
			else:
				for templateType in self.templateTypes:
					parts.append(templateType.checkReplaceTemplateType(mainState, sourceGroup, templateMappingTracker).toString())
					parts.append(",")

			parts.pop()
			parts.append(">")

		else:
			parts.append(self.group.getAppliedName(mainState, templateMappingTracker, useUsertypeOverride=useUsertypeOverride, templatesUseHeaderName=templatesUseHeaderName, singleName=True))


		for _ in range(self.pointerLevel + pointerLevelAdjust):
			parts.append("*")

		return "".join(parts)


	def getHeaderName(self):
		return self.toString()


	def getAppliedHeaderName(self, mainState: MainState, sourceGroup: Group, templateMappingTracker: TemplateMappingTracker, pointerLevelAdjust=0, useUsertypeOverride=False, debug=False):
		return self.getAppliedName(mainState, sourceGroup, templateMappingTracker, pointerLevelAdjust=pointerLevelAdjust, useUsertypeOverride=useUsertypeOverride, debug=debug)


	def getAppliedUserTypeName(self, mainState: MainState, sourceGroup: Group, templateMappingTracker: TemplateMappingTracker, useUsertypeOverride=False):
		
		if self.pointerLevel > 1:
			innerStr = self.getAppliedHeaderName(mainState, sourceGroup, templateMappingTracker, pointerLevelAdjust=-1, useUsertypeOverride=useUsertypeOverride)
			return f"Pointer<{innerStr}>"

		pointerAdj = 0 if self.isPrimitive() else -1
		if self.pointerLevel - pointerAdj == 0:
			if self.isPrimitive():
				return self.getName()
			else:
				raise ValueError("Can't adjust non-primitive pointer level to 0")
		elif self.pointerLevel - pointerAdj < 0:
			raise ValueError("Adjusting pointer level would result in negative value")

		return self.getAppliedName(mainState, sourceGroup, templateMappingTracker, pointerLevelAdjust=pointerAdj, useUsertypeOverride=useUsertypeOverride, templatesUseHeaderName=True)


	def toString(self, pointerLevelAdjust=0, useUsertypeOverride=False) -> str:

		parts: list[str] = []
		
		if self.superRef:
			parts.append(self.superRef.toString(useUsertypeOverride=useUsertypeOverride))
			parts.append("::")

		if self.const: parts.append("const ")
		if self.unsigned: parts.append("unsigned ")
		if self.long: parts.append("long ")

		if useUsertypeOverride and self.group != None and self.group.overrideUsertypeSingleName != None:
			parts.append(self.group.overrideUsertypeSingleName)
		else:
			parts.append(self.getSingleName())

		if len(self.templateTypes) > 0:

			parts.append("<")

			for templateType in self.templateTypes:
				parts.append(templateType.toString())
				parts.append(",")

			parts.pop()
			parts.append(">")

		for _ in range(self.pointerLevel + pointerLevelAdjust):
			parts.append("*")

		return "".join(parts)


	# TODO: This is a really bad way of doing this
	def sameTypeAs(self, other: TypeReference):
		return self.toString() == other.toString()



class PointerReference(TypeReference):

	def __init__(self, mainState: MainState, sourceGroup: Group, pointingToType: TypeReference):
		super().__init__()
		self.group = mainState.getGroup("Pointer")
		self.sourceGroup = sourceGroup
		self.templateTypes.append(pointingToType)


	def getHeaderName(self):
		if not self.noreplace:
			return f"{self.templateTypes[0].toString()}*"

		return self.toString()


	def getAppliedHeaderName(self, mainState: MainState, sourceGroup: Group, templateMappingTracker: TemplateMappingTracker, pointerLevelAdjust=0, useUsertypeOverride=False, debug=False):
		if not self.noreplace:
			innerType = self.templateTypes[0].checkReplaceTemplateType(mainState, sourceGroup, templateMappingTracker)
			return f"{innerType.toString()}*"

		return self.getAppliedName(mainState, sourceGroup, templateMappingTracker, pointerLevelAdjust=pointerLevelAdjust, useUsertypeOverride=useUsertypeOverride)


	def getAppliedUserTypeName(self, mainState: MainState, sourceGroup: Group, templateMappingTracker: TemplateMappingTracker, useUsertypeOverride=False):
		innerType = self.templateTypes[0].checkReplaceTemplateType(mainState, sourceGroup, templateMappingTracker)
		innerStr = innerType.getAppliedName(mainState, sourceGroup, templateMappingTracker, pointerLevelAdjust=0, useUsertypeOverride=useUsertypeOverride)
		return f"Pointer<{innerStr}>"


class StringReference(TypeReference):

	def __init__(self, mainState: MainState, sourceGroup: Group):
		super().__init__()
		self.group = mainState.getGroup("CharString")
		self.sourceGroup = sourceGroup


	def getHeaderName(self):
		if not self.noreplace:
			return "char*"

		return self.toString()


	def getAppliedHeaderName(self, mainState: MainState, sourceGroup: Group, templateMappingTracker: TemplateMappingTracker, pointerLevelAdjust=0, useUsertypeOverride=False, debug=False):
		return self.getHeaderName()


	def getAppliedUserTypeName(self, mainState: MainState, sourceGroup: Group, templateMappingTracker: TemplateMappingTracker, pointerLevelAdjust=0, useUsertypeOverride=False):
		return "CharString"


class ConstStringReference(TypeReference):

	def __init__(self, mainState: MainState, sourceGroup: Group):
		super().__init__()
		self.group = mainState.getGroup("ConstCharString")
		self.sourceGroup = sourceGroup


	def getHeaderName(self):
		if not self.noreplace:
			return "const char*"

		return self.toString()


	def getAppliedHeaderName(self, mainState: MainState, sourceGroup: Group, templateMappingTracker: TemplateMappingTracker, pointerLevelAdjust=0, useUsertypeOverride=False, debug=False):
		return self.getHeaderName()


	def getAppliedUserTypeName(self, mainState: MainState, sourceGroup: Group, templateMappingTracker: TemplateMappingTracker, pointerLevelAdjust=0, useUsertypeOverride=False):
		return "ConstCharString"



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


	def getAllTypeReferences(self):
		
		refs = []

		if self.returnType != None:
			refs.append(self.returnType)

		for param in self.parameters:
			for paramRef in param.type.getAllTypeReferences():
				refs.append(paramRef)

		return refs


	def toString(self, indent=""):

		parts: list[str] = [indent, "\t"]

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


variablePatternGlobal = "^(nobinding\s+){0,1}(?!class|enum|struct|typedef|union)(?:__unaligned\s+){0,1}(?:__declspec\(align\(\d+\)\)\s+){0,1}([, _a-zA-Z0-9*:<>\-$]+?)\s*([_a-zA-Z0-9~]+)((?:\[[_a-zA-Z0-9+]+\])+)*(?:\s*:\s*([^\s>]+?)){0,1}(?:\s|(?:\/\*(?:(?!\*\/).)*\*\/))*;(?:\s|(?:\/\/.*)|(?:\/\*(?:(?!\*\/).)*\*\/))*$"
variablePatternLocal = "^\t(nobinding\s+){0,1}(?:__unaligned\s+){0,1}(?:__declspec\(align\(\d+\)\)\s+){0,1}([, _a-zA-Z0-9*:<>\-$]+?)\s*([_a-zA-Z0-9~]+)((?:\[[_a-zA-Z0-9+]+\])+)*(?:\s*:\s*([^\s>]+?)){0,1}(?:\s|(?:\/\*(?:(?!\*\/).)*\*\/))*;(?:\s|(?:\/\/.*)|(?:\/\*(?:(?!\*\/).)*\*\/))*$"	

def checkFunctionImplementation(mainState: MainState, state: CheckLinesState, line: str, group: Group):

	functionImplementationMatch: Match = re.match("^\s*(?!typedef)(\$nobinding\s+){0,1}(?:(static)\s+){0,1}([, _a-zA-Z0-9*:<>$]+?)\s+(?:(__cdecl|__stdcall|__thiscall)\s+){0,1}([_a-zA-Z0-9\[\]]+)\s*\(\s*((?:[, _a-zA-Z0-9*:<>]+?\s+[_a-zA-Z0-9]+(?:\s*,(?!\s*\))){0,1})*)\s*\)(?:(;)){0,1}$", line)
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
			elif retTypeStr != "$constructor":
				raise ValueError("Bad bindings directive")

			retTypeStr = "void"

		state.currentFunctionImplementation.returnType = defineTypeRef(mainState, group, retTypeStr)
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
				funcParameter.type = defineTypeRef(mainState, group, typeStr)
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
		variableField.private = variableMatch.group(1) != None

		variableField.variableType = defineTypeRef(mainState, group, variableMatch.group(2), variableMatch.group(4), debugLineIn = line)
		variableField.variableType.bitFieldPart = variableMatch.group(5)

		variableField.variableName = variableMatch.group(3)
		group.fields[variableField.variableName] = variableField



class Group:

	def __init__(self):

		self.template: str = None  # String filled with the template definition as found in the input file. Example: template<class T, int size>
		self.groupType: str = None # "struct" / "class" / "enum" / "union" / (possibly "undefined").
		self.defined: bool = False # True if the group was defined in a header file

		self.name: str = None # String filled with the name of the group, as defined in the input file. Examples:
							  # "CPtrList" / "CPtrList::CNode"

		self.singleName: str = None # String filled with the name of the group. If group is a sub-group, contains only the last group name. Example:
									# self.name = "CPtrList::CNode" => self.singleName = "CNode"

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
		self.templateUses: list[tuple[TypeReference]] = None # List of all TypeReferences to the group which use templates.

		self.superGroup: Group = None    # Group that this group immediately resides in.
		self.subGroups: list[Group] = [] # Groups that this group immediately contains.
		self.superSubInitialized = False # Internal state for moving groups to properly nest.

		self.isDirectlyWanted: bool = False # True if the group was listed in -wantedFile.
		self.isWanted: bool = False         # True if the group is wanted for output, either manually in -wantedFile, or automatically from some dependency.
		
		self.fields: dict[str, Field] = {}                              # List of fields the group immediately contains.
		self.extends: list[TypeReference] = []                          # List of TypeReferences the group extends.
		self.enumTuples: list[tuple[str,int]] = []                      # List of enum values, (in the case of groupType="enum").
		self.functionImplementations: list[FunctionImplementation] = [] # List of function implementations the group immediately contains.

		self.inwardTypeRefs: list[TypeReference] = []                # List of all TypeReferences to the group.
		self.uniqueUseRepresentations: dict[str, TypeReference] = {} # List of TypeReferences that each represent a unique use of the group.

		self.copyConstructor: FunctionImplementation = None # Specially-defined copy constructor implementation
		self.pack: int = None                               # Specially-defined struct packing



	def isSubgroup(self):

		"""
		True/False depending on whether the group is a sub-group. Examples:\n
		self.name = "CPtrList" => self.isSubgroup() -> False\n
		self.name = "CPtrList::CNode" => self.isSubgroup() -> True
		"""

		return self.superGroup != None


	def isPrimitive(self):
		return self.name in primitives


	def retypeField(self, mainState: MainState, fieldName: str, newTypeStr: str):

		field = self.fields[fieldName]
		if field.type == FieldType.VARIABLE:

			varField: VariableField = field

			fieldGroup = varField.variableType.group
			if fieldGroup != None:
				fieldGroup.inwardTypeRefs.remove(varField.variableType)

			varField.variableType = defineTypeRef(mainState, self, newTypeStr)
		else:
			raise ValueError()


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
						self.extends.append(defineTypeRef(mainState, self, extendsType))


			# Define function fields
			functionVariableMatch: Match = re.match("^\t([, _a-zA-Z0-9*:<>]+?)\s*\(\s*(?:([_a-zA-Z]+?)\s*){0,1}\*\s*([_a-zA-Z0-9~]+)\s*\)\s*\((?:\s*([, _a-zA-Z0-9*:<>]+?)\s+\*\s*this(?:\s*,\s+){0,1}){0,1}(?:([, _a-zA-Z0-9*:<>]+?)\s+\*\s*result(?:\s*,\s+){0,1}){0,1}\s*((?:[ _a-zA-Z0-9*:<>][, _a-zA-Z0-9*:<>]*?){0,1}(?:\.\.\.(?=\s*\))){0,1}){0,1}\s*\)\;$", line)
			if functionVariableMatch != None:

				functionField = FunctionField()
				functionField.returnType = defineTypeRef(mainState, self, functionVariableMatch.group(1))
				functionField.callConvention = functionVariableMatch.group(2)
				functionField.functionName = functionVariableMatch.group(3)

				if functionField.functionName.startswith("~"):
					functionField.functionName = functionField.functionName[1:] + "_Destructor"

				functionField.thisTypeNoPtr = defineTypeRef(mainState, self, functionVariableMatch.group(4))
				functionField.resultTypeNoPtr = defineTypeRef(mainState, self, functionVariableMatch.group(5))

				parameterStr = functionVariableMatch.group(6)
				if parameterStr != None and parameterStr != "":
					for paramType in splitKeepBrackets(parameterStr, [","]):
						functionField.parameterTypes.append(defineTypeRef(mainState, self, paramType))

				self.fields[functionField.functionName] = functionField


			checkFunctionImplementation(mainState, state, line, self)


			# Define certain enum values in group.enumTuples, else print error to console
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
		Maps the template names that appear in this Group to the Group in which they belong to in the hierarchy.\n
		Fills templateTypeNameMapping.
		"""

		def process(group: Group):
			if group.superGroup: process(group.superGroup)
			for templateTypeName in group.templateTypeNames:
				self.templateTypeNameMapping[templateTypeName] = group

		process(self)


	def addTemplateUse(self, useEntry: tuple[TypeReference]):
		# TODO: This is a really bad way to prevent duplicate entries in templateUses
		shouldAdd = True
		for existingEntry in self.templateUses:
			same = True
			for useEntryI in range(len(useEntry)):
				if not useEntry[useEntryI].sameTypeAs(existingEntry[useEntryI]):
					same = False
					break
			if same:
				shouldAdd = False
				break

		if shouldAdd:
			self.templateUses.append(useEntry)


	def scanInwardTypeRefs(self):

		"""
		Scans inwardTypeRefs for uses of this Group's template definition and adds tuples representing these
		template uses to templateUses, (duplicate entries are discarded).\n\n
		Also fills uniqueUseRepresentations, which is a series of TypeRefs representing every unique way this group has been used.
		"""

		self.templateUses: list[tuple[TypeReference]] = []

		for typeRef in self.inwardTypeRefs:

			if typeRef.sourceGroup != None and not typeRef.sourceGroup.isWanted: continue
			self.uniqueUseRepresentations[typeRef.toString()] = typeRef

			if len(typeRef.templateTypes) == 0: continue
			useEntry = tuple(typeRef.templateTypes)
			self.addTemplateUse(useEntry)


	def getAllTypeReferences(self):

		def getExtendsRefs(typeRef: TypeReference):
			parts = [typeRef]
			for templateRef in typeRef.templateTypes:
				for ref in getExtendsRefs(templateRef):
					parts.append(ref)
			return parts

		myself = TypeReference()
		myself.name = self.name
		myself.group = self

		parts: list[TypeReference] = [myself]

		for subgroup in self.subGroups:
			for ref in subgroup.getAllTypeReferences():
				parts.append(ref)

		for extendRef in self.extends:
			for ref in getExtendsRefs(extendRef):
				parts.append(ref)

		for field in self.fields.values():
			for ref in field.getAllTypeReferences():
				parts.append(ref)

		for funcImp in self.functionImplementations:
			for ref in funcImp.getAllTypeReferences():
				parts.append(ref)

		return parts


	def mapDependsOn(self):
		for typeRef in self.getAllTypeReferences():
			if typeRef.getName() == "void" or typeRef.isGenericTemplate(): continue
			typeName = typeRef.getName()
			if typeRef.pointerLevel == 0:
				self.dependsOn[typeName] = True
			elif typeRef.pointerLevel > 0:
				self.lightDependsOn[typeName] = True
			else:
				raise ValueError("Invalid typeRef.pointerLevel")


	def setSingleName(self, newSingleName: str):

		self.singleName = newSingleName

		parts = []
		def processSuperGroups(group: Group):
			if group.superGroup:
				processSuperGroups(group.superGroup)
				parts.append(group.superGroup.singleName)
				parts.append("::")


		processSuperGroups(self)
		parts.append(self.singleName)
		self.name = "".join(parts)

		#for typeRef in self.inwardTypeRefs:
		#	typeRef.name = self.name


	def changeSingleName(self, mainState: MainState, newSingleName: str):
		oldName = self.name
		self.setSingleName(newSingleName)
		mainState.renameGroup(self, oldName)


	def getAppliedName(self, mainState: MainState, templateMappingTracker: TemplateMappingTracker, useUsertypeOverride=False, noTemplate=False, templatesUseHeaderName=False, singleName=False):

		"""
		Given a Group in which the caller wants to express an arbritary series of template uses, returns a
		string representation of the current Group name as if its template types were filled with the information
		held by templateMappingTracker.
		"""

		groupNameParts = []

		if not singleName and self.superGroup:
			groupNameParts.append(self.superGroup.getAppliedName(mainState, templateMappingTracker))
			groupNameParts.append("::")

		groupNameParts.append(self.overrideUsertypeSingleName if useUsertypeOverride and self.overrideUsertypeSingleName != None else self.singleName)

		if not noTemplate and templateMappingTracker != None and (v := templateMappingTracker.getMapping(self.name)) != None:

			groupNameParts.append("<")

			for typeRef in v:

				if templatesUseHeaderName:
					groupNameParts.append(typeRef.checkReplaceTemplateType(mainState, self, templateMappingTracker).getHeaderName())
				else:
					groupNameParts.append(typeRef.checkReplaceTemplateType(mainState, self, templateMappingTracker).toString())
				
				groupNameParts.append(",")

			groupNameParts.pop()
			groupNameParts.append(">")

		return "".join(groupNameParts)


	def writeHeader(self, internalPointersOut, internalPointersListOut: list[tuple[str,str]], headerType: HeaderType, indent="") -> str:

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

			if not isNormal:
				for field in group.fields.values():
					if field.type == FieldType.VARIABLE:
						varField: VariableField = field
						varStr = f"{varField.variableType.toString(pointerLevelAdjust=1)} p_{varField.variableName};"
						internalPointersOut.write(f"{varStr}\n")
						internalPointersListOut.append((varField.variableName, f"p_{varField.variableName}"))
						parts.append(f"extern {varStr}")
						parts.append("\n")
						wroteSomething = True
					else:
						print("BAD FIELD TYPE")


			for subGroup in group.subGroups:
				if writeGroupInternalFunctionPointers(subGroup): wroteSomething = True

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
					parts.append(extendsType.toString())
					parts.append(", ")

				parts.pop()

			parts.append("\n")
			parts.append(indent)
			parts.append("{\n")

			nextIndent = indent + "\t"

			if headerType == HeaderType.CLEANED and self.templateUses != None:
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
				if not subgroup.isUsed(): continue
				parts.append(subgroup.writeHeader(internalPointersOut, internalPointersListOut, headerType, nextIndent))
				parts.append("\n\n")
				wroteSomethingBeforeFuncImps = True

			for enumTuple in self.enumTuples:
				parts.append(nextIndent)
				parts.append(enumTuple[0])
				parts.append(" = ")
				parts.append(str(enumTuple[1]))
				parts.append(",\n")
				wroteSomethingBeforeFuncImps = True

			for field in self.fields.values():
				parts.append(field.toString(nextIndent))
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


	def isUsed(self):
		for subGroup in self.subGroups:
			if subGroup.isUsed(): return True

		return self.isDirectlyWanted or len(self.inwardTypeRefs) > 0


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

		# Needs to be before setSingleName() to include super group in full name
		subGroup.superGroup = superGroup
		superGroup.subGroups.append(subGroup)
		subGroup.superSubInitialized = True

		# subGroup.name = myFullName
		subGroup.setSingleName(myTypeName)
		#print(f"checkUnnamedStructs() connecting {superGroup.name} (super) to {subGroup.name} (sub)")

		subGroup.lines = state.lines
		
		#print(f"unnamed struct {superGroup.name} adding {subGroup.name}")
		mainState.addGroup(subGroup)
		subGroup.processLinesFillTypes(mainState)

		newSuperField = VariableField()
		newSuperField.variableType = defineTypeRef(mainState, superGroup, myFullName)
		newSuperField.variableName = myName
		superGroup.fields[newSuperField.variableName] = newSuperField

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
		self.type = None

	def toString(indent="") -> str:
		pass

	def getAllTypeReferences() -> list[TypeReference]:
		pass


class FunctionField(Field):

	def __init__(self):
		super().__init__()
		self.type = FieldType.FUNCTION
		self.returnType: TypeReference = None
		self.callConvention: str = None
		self.functionName: str = None
		self.thisTypeNoPtr: TypeReference = None
		self.resultTypeNoPtr: TypeReference = None
		self.parameterTypes: list[TypeReference] = []


	def toString(self, indent="") -> str:

		parts = [indent, self.returnType.getHeaderName(), " ("]

		if self.callConvention:
			parts.append(self.callConvention)
			parts.append(" ")

		parts.append("*")
		parts.append(self.functionName)
		parts.append(")(")

		hadParam = False

		if self.thisTypeNoPtr:
			parts.append(self.thisTypeNoPtr.getHeaderName())
			parts.append("*")
			parts.append(", ")
			hadParam = True

		if self.resultTypeNoPtr:
			parts.append(self.resultTypeNoPtr.getHeaderName())
			parts.append("*")
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


	def getAllTypeReferences(self):

		parts = []

		for v in self.returnType.getAllTypeReferences():
			parts.append(v)

		if self.thisTypeNoPtr != None:
			for v in self.thisTypeNoPtr.getAllTypeReferences():
				parts.append(v)

		if self.resultTypeNoPtr != None:
			for v in self.resultTypeNoPtr.getAllTypeReferences():
				parts.append(v)

		for typeReference in self.parameterTypes:
			for v in typeReference.getAllTypeReferences():
				parts.append(v)

		return parts


class VariableField(Field):

	def __init__(self):
		super().__init__()
		self.type = FieldType.VARIABLE
		self.variableType: TypeReference = None
		self.variableName: str = None
		self.private: bool = False


	def toString(self, indent="") -> str:

		parts = [indent, self.variableType.getHeaderName(), " ", self.variableName]
		for arrayPart in self.variableType.arrayParts:
			parts.append("[")
			parts.append(arrayPart)
			parts.append("]")

		if self.variableType.bitFieldPart != None:
			parts.append(" : ")
			parts.append(self.variableType.bitFieldPart)

		parts.append(";")		
		return "".join(parts)


	def getAllTypeReferences(self):
		return self.variableType.getAllTypeReferences()


def defineTypeRefPart(mainState: MainState, superRef: TypeReference, sourceGroup: Group, inStr: str, arrayStr: str=None, debug=False, debugLineIn: str = None):

	if inStr == None: return
	str = inStr

	noreplace = False
	noconst = False
	while True:
		if noreplaceMatch := re.match("^noreplace\s+(.*)", str):
			noreplace = True
			str = noreplaceMatch.group(1)
		elif noconstMatch := re.match("^noconst\s+(.*)", str):
			noconst = True
			str = noconstMatch.group(1)
		else:
			break

	if not noreplace:

		originalPointerLevel, oneLessPtrStr = getPointerLevel(str, removeAmount=1)

		# Transform char* into CharString types
		if str == "CharString" or (oneLessPtrStr == "char" and originalPointerLevel == 1):
			strRef = StringReference(mainState, sourceGroup)
			strRef.sourceString = inStr
			strRef.noreplace = noreplace
			strRef.noconst = noconst
			strRef.group.inwardTypeRefs.append(strRef)
			return strRef

		# Transform const char* into ConstCharString types
		if str == "ConstCharString" or (oneLessPtrStr == "const char" and originalPointerLevel == 1):
			constStrRef = ConstStringReference(mainState, sourceGroup)
			constStrRef.sourceString = inStr
			constStrRef.noreplace = noreplace
			constStrRef.noconst = noconst
			constStrRef.group.inwardTypeRefs.append(constStrRef)
			return constStrRef

	needArrayPart = False
	# Transform arrays into Array types
	if arrayStr != None:
		if sourceGroup == None or sourceGroup.name != "Array":
			allMatches = [x for x in re.finditer("\[(\d+)\]", arrayStr)]
			all = [x.group(0) for x in allMatches]
			nextArrayStr = "".join(all[:-1]) if len(all) > 1 else None
			return defineTypeRef(mainState, sourceGroup, f"Array<{str},{allMatches[-1].group(1)}>", nextArrayStr)
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
		elif unsignedCount != 0:
			raise ValueError("Invalid number of 'unsigned' keywords")

		if hitName:
			name, constCount = removeRegexCount(name, "const")
		else:
			name, constCount = removeRegexCount(name, "const\s+")

		if longMatch := re.match("^long\s+(.*)", name):
			typeRef.long = True
			name = longMatch.group(1)

		if constCount == 1:
			typeRef.const = True
		elif constCount != 0:
			raise ValueError("Invalid number of 'const' keywords")

		if hitName: return
		name = name.strip()
		if name == "": return

		hitName = True

		struct = False
		if structMatch := re.match("^struct\s+(.*)", name):
			struct = True
			name = structMatch.group(1)

		#typeRef.name = name

		# These should never show up in their non-replaced form if replacing
		# if not noreplace and typeRef.name in ("Pointer", "CharString", "ConstCharString"):
		#	errorStr = f"Attempting to define {typeRef.name} from {str}"
		#	raise ValueError(errorStr)

		# Create a Group for the type if it hasn't been found already
		# (varargs type and completely numeric types obviously aren't real, so exclude them)
		if typeRef.sourceString != "..." and not typeRef.sourceString.isnumeric():

			groupNameParts: list[str] = []

			if superRef:
				groupNameParts.append(superRef.group.name)
				groupNameParts.append("::")

			groupNameParts.append(name)
			groupName = "".join(groupNameParts)

			typeGroup = mainState.tryGetGroup(groupName)

			if not typeGroup:
				#print(f"Creating undefined group \"{groupName}\" because of {debugLineIn}")
				typeGroup = Group()
				typeGroup.groupType = "struct" if struct else "undefined"
				typeGroup.setSingleName(groupName)
				mainState.addGroup(typeGroup)

			typeRef.group = typeGroup

			if typeRef.group != None:
				typeRef.group.inwardTypeRefs.append(typeRef)


	for split in splits:

		typeBracketStarts = findTemplateBracketStarts(split)
		if len(typeBracketStarts) > 0:

			for typeStartI in typeBracketStarts:
				name, parts = separateTemplateTypeParts(split, typeStartI)
				doBaseProcess(name)
				for templateType in splitKeepBrackets(parts, [","]):
					typeRef.templateTypes.append(defineTypeRef(mainState, sourceGroup, templateType))

		elif split == "*" or split == "&":
			typeRef.pointerLevel += 1
		else:
			doBaseProcess(split)

	#if typeRef.name == "":
	#	print(f"Failed to get name for \"{str}\"")

	if needArrayPart:
		for arrayPartMatch in re.finditer("\[([a-zA-Z0-9_]+)\]", arrayStr):
			typeRef.arrayParts.append(arrayPartMatch.group(1))

	typeRef.noreplace = noreplace
	typeRef.noconst = noconst

	if superRef:
		superRef.subRef = typeRef
		typeRef.superRef = superRef

	# Transform double pointers into Pointer types
	if typeRef.pointerLevel > 1:
		typeRef.pointerLevel -= 1
		ptrRef = PointerReference(mainState, sourceGroup, typeRef)
		ptrRef.sourceString = inStr
		ptrRef.noreplace = noreplace
		ptrRef.noconst = noconst
		ptrRef.group.inwardTypeRefs.append(ptrRef)
		return ptrRef

	return typeRef



def defineTypeRef(mainState: MainState, sourceGroup: Group, str: str, arrayStr: str=None, debug=False, debugLineIn: str = None):

	if str == None: return

	splits = splitKeepBrackets(stripUnnecessaryTypeSpaces(str), ["::"])
	numSplits = len(splits)
	if numSplits == 0: return

	lastRef = defineTypeRefPart(mainState, None, sourceGroup, splits[0], arrayStr, debug, debugLineIn)
	for i in range(1, numSplits):
		lastRef = defineTypeRefPart(mainState, lastRef, lastRef.group, splits[i], None, debug, debugLineIn)

	return lastRef



def findLastBaseGroup(mainState: MainState, name: str):
	split = splitKeepBrackets(name, ["::"])
	splitLen = len(split)
	firstSubGroupI = 0
	baseName = split[0]
	baseGroup: Group = None
	while True:

		if (v := mainState.tryGetGroup(baseName)) == None:
			break
		
		baseGroup = v
		baseName += "::" + split[firstSubGroupI]

		firstSubGroupI += 1
		if firstSubGroupI >= splitLen: break

	if baseGroup == None or firstSubGroupI == splitLen: return
	return baseGroup, split, firstSubGroupI


def doMove(mainState: MainState, dependsOnName: str):

	#print(f"Checking move for: \"{dependsOnName}\"")

	def tryGetGroup(fullGroupName, finalGroupNamePart):

		existingGroup = mainState.tryGetGroup(fullGroupName)
		if existingGroup != None:
			# print(f"Move found {fullGroupName}, set singleName to {finalGroupNamePart}")
			existingGroup.singleName = finalGroupNamePart
			return existingGroup

		#print(f"Move made {fullGroupName}")
		newGroup = Group()
		newGroup.groupType = "struct"
		newGroup.name = fullGroupName
		newGroup.singleName = finalGroupNamePart

		mainState.addGroup(newGroup)
		return newGroup


	dependGroup = mainState.tryGetGroup(dependsOnName)
	if dependGroup == None: return False
	if dependGroup.isSubgroup(): return False

	split = splitKeepBrackets(dependsOnName, ["::"])
	splitLen = len(split)
	if splitLen <= 1: return False

	lastFullName = split[0]
	firstSubGroup = tryGetGroup(lastFullName, lastFullName)
	firstSubGroup.superSubInitialized = True
	lastSubGroup = firstSubGroup

	for basePartI in range(1, len(split)):

		lastFullName = lastFullName + "::" + split[basePartI]
		newSubSubGroup = tryGetGroup(lastFullName, split[basePartI])

		if not newSubSubGroup.superSubInitialized:
			#print(f"Move connecting {lastSubGroup.name} (super) to {newSubSubGroup.name} (sub)")
			newSubSubGroup.superGroup = lastSubGroup
			lastSubGroup.subGroups.append(newSubSubGroup)
			newSubSubGroup.superSubInitialized = True

		lastSubGroup = newSubSubGroup

	return True


def relocateGroup(mainState: MainState, existingStructPath, newStructPath):

	existingGroup = mainState.getGroup(existingStructPath)

	if superGroup := existingGroup.superGroup:
		superGroup.subGroups.remove(existingGroup)
		existingGroup.superGroup = None
		existingGroup.superSubInitialized = False

	oldName = existingGroup.name
	existingGroup.name = newStructPath
	mainState.renameGroup(existingGroup, oldName)
	doMove(mainState, existingGroup.name)

	# Rebuild reference chains
	# TODO: Handle templates?
	parts = splitKeepBrackets(stripUnnecessaryTypeSpaces(existingGroup.name), ["::"])
	partsLen = len(parts)

	if partsLen > 1:

		for inRef in list(existingGroup.inwardTypeRefs):

			topRef = inRef
			while topRef.superRef: topRef = topRef.superRef

			lastRef: TypeReference = defineTypeRefPart(mainState, None, topRef.sourceGroup, parts[0])
			for i in range(1, partsLen - 1):
				lastRef = defineTypeRefPart(mainState, lastRef, lastRef.group, parts[i])

			inRef.sourceGroup = lastRef.group
			lastRef.subRef = inRef
			inRef.superRef = lastRef


def moveSubstructs(mainState: MainState, group: Group):
	toProcess = group.getAllTypeReferences()
	while len(toProcess) > 0:
		typeRef = toProcess.pop()
		doMove(mainState, typeRef.getName())


def moveElementAfter(list: list, originalIndex, afterIndex):
	temp = list[originalIndex]
	del list[originalIndex]
	list.insert(afterIndex if originalIndex <= afterIndex else afterIndex + 1, temp)


def tryResolveDependencyOrder(groups: list[Group]):

	"""
	Brute force dependency order, moving groups when needed.\n
	OH the time complexity!
	"""

	curCheckI = 0
	while curCheckI < len(groups):

		group = groups[curCheckI]
		if len(group.dependsOn) > 0:

			maxDependIndex = 0
			for dependName in group.dependsOn:
				i = 0
				for group in groups:
					if group.name == dependName:
						maxDependIndex = max(maxDependIndex, i)
					i += 1

			if curCheckI < maxDependIndex:
				moveElementAfter(groups, curCheckI, maxDependIndex)
				continue

		curCheckI += 1


def writeBindings(mainState: MainState, groups: list[Group], out: TextIOWrapper):


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
			self.appliedName: str = None
			self.appliedNameUsertype: str = None
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

		groupOpenData.appliedName = group.getAppliedName(mainState, templateMappingTracker)
		groupOpenData.appliedNameUsertype = group.getAppliedName(mainState, templateMappingTracker, useUsertypeOverride=True, templatesUseHeaderName=False)
		groupOpenData.appliedHeaderName = group.getAppliedName(mainState, templateMappingTracker, templatesUseHeaderName=True)
		groupNameStrIden, _ = re.subn("[^a-zA-Z0-9_]", "_", groupOpenData.appliedName)

		# Writing getReference() function which returns the userdata's internal pointer
		if group != globalGroup and group.groupType != "enum" and group.name not in ("Pointer", "Array"):
	
			getTypeFunc = OpenFunctionData()
			getTypeFunc.functionBindingName = f"tolua_function_{groupNameStrIden}_getReference"
			getTypeFunc.functionName = "getReference"

			out.write(f"static int {getTypeFunc.functionBindingName}(lua_State* L)\n")
			out.write("{\n")
			out.write(f"\tvoid** ptr = (void**)lua_touserdata(L, 1);\n")
			out.write(f"\ttolua_pushusertype(L, ptr, \"Pointer<{groupOpenData.appliedNameUsertype}>\");\n")
			out.write("\treturn 1;\n")
			out.write("}\n\n")

			groupOpenData.functionBindings.append(getTypeFunc)

		# Writing sizeof variable which returns the value of the sizeof operator when run on the usertype
		if group != globalGroup and group.groupType != "enum" and group.name != "void":

			sizeofConstant = OpenConstantData()
			sizeofConstant.name = "sizeof"
			sizeofConstant.valueType = OpenConstantType.STRING
			sizeofConstant.value = f"sizeof({group.getAppliedName(mainState, templateMappingTracker)})"
			groupOpenData.constantBindings.append(sizeofConstant)


		def writeAccessSelf(errorMsg: str):
			out.write(f"\t{groupOpenData.appliedHeaderName}* self = ({groupOpenData.appliedHeaderName}*)tolua_tousertype(L, 1, 0);\n")
			out.write(f"\tif (!self) tolua_error(L, \"{errorMsg}\", NULL);\n")


		def handleField(field: Field, isPointerCast=False):

			"""
			Writes getter function for given field, (and an reference_ function that returns a pointer to the field).
			"""

			fieldNameStr = None

			if field.type == FieldType.VARIABLE:
				variableField: VariableField = field
				if variableField.private: return
				if len(variableField.variableType.arrayParts) > 0: return # These use GenericArray functions
				fieldNameStr = variableField.variableName
			elif field.type == FieldType.FUNCTION:
				functionField: FunctionField = field
				fieldNameStr = functionField.functionName
			else:
				raise ValueError("Unhandled field.type")


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

				if isNormal:
					out.write(f"\t{groupOpenData.appliedName}* self = ({groupOpenData.appliedName}*)tolua_tousertype(L, 1, 0);\n")
					out.write(f"\tif (!self) tolua_error(L, \"invalid 'self' in accessing variable '{variableField.variableName}'\", NULL);\n")

				varNameHeader = variableField.variableName if isNormal else f"p_{variableField.variableName}"

				def checkPrimitiveHandling(varType: TypeReference):

					if isPointerCast: return False

					#if varType.isPrimitive() and varType.pointerLevel > 0:
					#	print(f"Pointer primitive somehow exists: {varType.toString()} for {groupOpenData.appliedName}::{variableField.variableName}")

					selfStr = "self->" if isNormal else ""
					effectivePtrLevel = varType.pointerLevel if isNormal else varType.pointerLevel + 1

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
						if checkType.pointerLevel == 1:
							out.write(f"\ttolua_pushstring(L, (const char*){'*'*(effectivePtrLevel - 1)}{selfStr}{varNameHeader});\n")
							return True
						elif checkType.pointerLevel == 0:
							out.write(f"\tlua_pushlstring(L, (const char*){'*'*(effectivePtrLevel - 1)}{selfStr}{varNameHeader}, 1);\n")
							return True

					return False


				if not checkPrimitiveHandling(varType):

					effectivePtrLevel = varType.pointerLevel if isNormal else varType.pointerLevel + 1

					if isPointerCast:
						out.write("\ttolua_pushusertypepointer(L, (void*)&")
					else:
						out.write("\ttolua_pushusertype(L, (void*)")
						if effectivePtrLevel == 0:
							out.write("&")

					if isNormal:
						out.write(f"self->{varNameHeader}")
					else:
						out.write(f"{'*'*varType.pointerLevel}{varNameHeader}")

					if isPointerCast:
						insideTypeName = varType.getAppliedName(mainState, group, templateMappingTracker, useUsertypeOverride=True)
						out.write(f", \"Pointer<{insideTypeName}>\"")
					else:
						primitiveReturned = varType.pointerLevel > 0
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

				allowSetter = varType.isPrimitive() or varType.pointerLevel > 0

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

					if isNormal:
						out.write(f"\t{groupOpenData.appliedName}* self = ({groupOpenData.appliedName}*)tolua_tousertype(L, 1, 0);\n")
						out.write(f"\tif (!self) tolua_error(L, \"invalid 'self' in accessing variable '{variableField.variableName}'\", NULL);\n")

					varNameHeader = variableField.variableName if isNormal else f"p_{variableField.variableName}"

					def checkPrimitiveHandling(varType: TypeReference):

						varTypeName = varType.getName()
						if isNormal and ((varTypeName != "char" and varType.pointerLevel > 0) or (varTypeName == "char" and varType.pointerLevel > 1)): return False
						selfStr = "self->" if isNormal else "*"*(varType.pointerLevel + 1)

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
						out.write(f"\t{selfStr}{varNameHeader} = ({varType.getAppliedName(mainState, group, templateMappingTracker)})tolua_tousertype(L, 2, 0);\n")

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
			returnTypeName = returnType.getName()

			# Must be void, primitive, or pointer
			if not returnType.isVoid() and (not returnType.isPrimitive() and (returnTypeName not in ("Pointer", "CharString", "ConstCharString") or returnType.noreplace)) and returnType.pointerLevel == 0:
				return

			for param in functionImplementation.parameters:

				paramType = param.type.checkReplaceTemplateType(mainState, group, templateMappingTracker)

				# Can't have conflicting const requirements (the noconst directive prevents the function from generating for const types)
				if paramType.const and paramType.noconst:
					return

				# Must be primitive or pointer
				if (not paramType.isPrimitive() and (paramType.getName() not in ("Pointer", "CharString", "ConstCharString") or paramType.noreplace)) and paramType.pointerLevel == 0:
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

				if paramType.isPrimitiveNumber() and paramType.pointerLevel == 0:
					callArgParts.append(f"tolua_tonumber(L, {luaVarIndex}, NULL)")
					callArgParts.append(", ")
					return True
				elif paramTypeName == "bool" and paramType.pointerLevel == 0:
					callArgParts.append(f"tolua_toboolean(L, {luaVarIndex}, NULL)")
					callArgParts.append(", ")
					return True
				elif paramTypeName == "char" and not paramType.unsigned:
					if paramType.pointerLevel == 1:
						nonConstCast = "(char*)" if not paramType.const else ""
						callArgParts.append(f"{nonConstCast}tolua_tostring(L, {luaVarIndex}, NULL)")
						callArgParts.append(", ")
						return True
					elif paramType.pointerLevel == 0:
						callArgParts.append(f"*tolua_tostring(L, {luaVarIndex}, NULL)")
						callArgParts.append(", ")
						return True

				return False


			out.write("\t")

			parameterIMod: int = None
			functionNameHeader = functionImplementation.name if isNormal else f"p_{functionImplementation.name}"

			if isNormal and not functionImplementation.isStatic:
				parameterIMod = 2
			else:
				parameterIMod = 1

			if not returnType.isVoid():
				debug = functionOpenData.functionBindingName == "tolua_function_Pointer_CAssoc___getValue"
				returnTypeStr = returnType.getAppliedHeaderName(mainState, group, templateMappingTracker, debug=debug)
				out.write(f"{returnTypeStr} returnVal = ")

			if functionImplementation.isConstructor:
				classStr = functionImplementation.group.getAppliedName(mainState, templateMappingTracker)
				out.write(f"new (self) {classStr}(")
			elif isNormal and not functionImplementation.isStatic:
				out.write(f"self->{functionNameHeader}(")
			else:
				classStr = f"{functionImplementation.group.getAppliedName(mainState, templateMappingTracker)}::" if isNormal else ""
				out.write(f"{classStr}{functionNameHeader}(")

			if functionImplementation.customReturnCount:
				out.write("L")
				callArgParts.append(", ")

			for i, parameter in enumerate(functionImplementation.parameters):
				i += parameterIMod
				paramType = parameter.type.checkReplaceTemplateType(mainState, group, templateMappingTracker, debug=True)
				if not checkPrimitiveHandling(paramType, i):
					appliedParamName = paramType.getAppliedHeaderName(mainState, group, templateMappingTracker)
					callArgParts.append(f"({appliedParamName})tolua_tousertype(L, {i}, 0)")
					callArgParts.append(", ")
			
			if functionImplementation.customReturnCount or len(functionImplementation.parameters) > 0:
				callArgParts.pop()

			callArgParts.append(");\n")
			out.write("".join(callArgParts))


			if not returnType.isVoid():

				out.write("\t")

				def checkPrimitiveHandling(varType: TypeReference):

					varTypeName = varType.getName()

					if varType.isPrimitiveNumber() and varType.pointerLevel == 0:
						out.write("tolua_pushnumber(L, (lua_Number)returnVal);\n")
						return True
					elif varTypeName == "bool" and varType.pointerLevel == 0:
						out.write("tolua_pushboolean(L, (bool)returnVal);\n")
						return True
					elif varTypeName == "char":
						if varType.pointerLevel == 1:
							out.write("tolua_pushstring(L, (const char*)returnVal);\n")
							return True
						elif varType.pointerLevel == 0:
							out.write("lua_pushlstring(L, (const char*)&returnVal, 1);\n")
							return True

					return False


				if not checkPrimitiveHandling(returnType):
					out.write("tolua_pushusertype(L, (void*)returnVal, \"")
					if mainState.tryGetGroup(returnTypeName) != None:
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
				out.write(f"\ttolua_pushusertype(L, {f'{groupOpenData.appliedName}::{functionNameHeader}' if isNormal else f'*{functionNameHeader}'}, \"UnmappedUserType\");\n")	
				out.write("\treturn 1;\n")
				out.write("}\n\n")

				groupOpenData.fieldBindings.append(addressVar)


		def handleEnumTuple(enumTuple: Tuple[str, str]):
			openConstantData = OpenConstantData()
			openConstantData.name = enumTuple[0]
			openConstantData.valueType = OpenConstantType.INTEGER
			openConstantData.value = enumTuple[1]
			groupOpenData.constantBindings.append(openConstantData)



		for field in group.fields.values():
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

		if not group.isUsed(): return

		if group.template != None:
			for templateUse in group.templateUses:
				if templateUseHasGeneric(templateUse): continue # Don't treat a use of a generic template as an actual use 
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

			out.write(f"\ttolua_cclass(L, \"EngineGlobals\", \"EngineGlobals\", \"\", NULL);\n")
			out.write("\ttolua_beginmodule(L, \"EngineGlobals\");\n")

			for functionOpenData in openData.functionBindings:
				out.write(f"\t\ttolua_function(L, \"{functionOpenData.functionName}\", {functionOpenData.functionBindingName});\n")

			for fieldOpenData in openData.fieldBindings:
				out.write(f"\t\ttolua_variable(L, \"{fieldOpenData.fieldBindingName}\", {fieldOpenData.getBindingName}, {fieldOpenData.setBindingName or 'NULL'});\n")

			out.write("\ttolua_endmodule(L);\n")
			continue

		out.write(f"\ttolua_cclass(L, \"{openData.appliedNameUsertype}\", \"{openData.appliedNameUsertype}\", \"")

		if len(openData.group.extends) > 0:
			out.write(openData.group.extends[0].toString())

		out.write("\", NULL);\n")
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


def registerPointerTypes(mainState: MainState):

	"""
	Registers pointer types for every group, (for reference_ functions)
	"""

	array = mainState.getGroup("Array")
	pointer = mainState.getGroup("Pointer")
	
	def registerPointerType(group: Group, tracker: TemplateMappingTracker):
		for v in group.uniqueUseRepresentations.values():
			appliedName = v.getAppliedName(mainState, v.group.superGroup, tracker)
			pointerRef = defineTypeRef(mainState, group, appliedName, debug=True)
			pointer.addTemplateUse( (pointerRef,) )

	def registerPointerTypesForGroup(group: Group, tracker: TemplateMappingTracker):
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
		if group == globalGroup or group == pointer or group == array: continue
		if group.isSubgroup(): continue
		registerPointerTypesForGroup(group, TemplateMappingTracker())


def main():

	headerType: HeaderType = HeaderType.NORMAL
	inputFileName: str = None
	outputFileName: str = None
	bindingsFileName: str = None
	fixupFileName: str = None
	preludeFile: str = None
	bindingsPreludeFile: str = None
	excludedFile: str = None
	wantedFile: str = None
	manualTypesFile: str = None
	alreadyDefinedUsertypesFile: str = None

	for k in islice(sys.argv, 1, None):
		if k == "-normal": headerType = HeaderType.NORMAL
		elif k == "-cleaned": headerType = HeaderType.CLEANED
		elif (v := re.search("-inFile=(.+)", k)) != None: inputFileName = v.group(1)
		elif (v := re.search("-outFile=(.+)", k)) != None: outputFileName = v.group(1)
		elif (v := re.search("-bindingsOutFile=(.+)", k)) != None: bindingsFileName = v.group(1)
		elif (v := re.search("-fixupFile=(.+)", k)) != None: fixupFileName = v.group(1)
		elif (v := re.search("-preludeFile=(.+)", k)) != None: preludeFile = v.group(1)
		elif (v := re.search("-bindingsPreludeFile=(.+)", k)) != None: bindingsPreludeFile = v.group(1)
		elif (v := re.search("-excludedFile=(.+)", k)) != None: excludedFile = v.group(1)
		elif (v := re.search("-wantedFile=(.+)", k)) != None: wantedFile = v.group(1)
		elif (v := re.search("-manualTypesFile=(.+)", k)) != None: manualTypesFile = v.group(1)
		elif (v := re.search("-alreadyDefinedUsertypesFile=(.+)", k)) != None: alreadyDefinedUsertypesFile = v.group(1)
		

	with open(outputFileName, "w") as out:

		mainState = MainState()
		wantedNames: dict[str,bool] = {}

		builtins.globalGroup = Group()
		globalGroup.setSingleName("EngineGlobals")
		globalGroup.defined = True
		mainState.addGroup(globalGroup)

		wantedNames["EngineGlobals"] = True
		wantedNames["UnmappedUserType"] = True

		def processLines(lines: list[str]):

			state: CheckLinesState = CheckLinesState()

			currentGroup = None
			groupLevel = 0
			hitFirstBracket = False
			previousTemplate: str = None
			alreadyExisted = False

			i = 1
			for line in lines:

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
							continue

						currentGroup = Group()
						currentGroup.template = previousTemplate
						currentGroup.groupType = declMatch.group(1)
						currentGroup.defined = True
						currentGroup.name = nameStr
						currentGroup.singleName = nameStr
				
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
					checkFunctionImplementation(mainState, state, line, globalGroup)

				i += 1

			# Register last Group
			if (not alreadyExisted) and currentGroup != None:
				mainState.addGroup(currentGroup)


		if manualTypesFile != None:
			processLines(fileAsLines(manualTypesFile))

		processLines(fileAsLines(inputFileName))

		# Process Group lines to derive types
		for group in mainState.groups:
			if group.linesProcessed: continue
			group.processLinesFillTypes(mainState)

		# Move multi-layer structs so that they nest properly
		for group in mainState.groups:
			moveSubstructs(mainState, group)

		# Run fixup file to make some necessary changes
		if fixupFileName != None:
			my_module = importlib.import_module(fixupFileName)
			my_module.fixup(mainState)

		for group in mainState.groups:
			group.mapTemplateTypeNames()

		# Attempt to derive type dependencies and light dependencies (those that need forward declarations)
		for group in mainState.groups:
			group.mapDependsOn()


		if wantedFile != None:
			with open(wantedFile) as file_in:
				for line in file_in:
					wantedNames[line.strip()] = True


		excludedNames = {}
		if excludedFile != None:
			with open(excludedFile) as file_in:
				for line in file_in:
					excludedNames[line.strip()] = True


		pendingProcessed = []
		for wantedName in wantedNames:
			wantedGroup = mainState.tryGetGroup(wantedName)
			if wantedGroup: wantedGroup.isDirectlyWanted = True
			pendingProcessed.append(wantedName)

		while len(pendingProcessed) > 0:
			wantedName = pendingProcessed.pop()
			wantedGroup = mainState.tryGetGroup(wantedName)
			if wantedGroup == None: continue
			for dependsOnName in wantedGroup.dependsOn:
				if dependsOnName in wantedNames: continue
				pendingProcessed.append(dependsOnName)
				wantedNames[dependsOnName] = True
			for dependsOnName in wantedGroup.lightDependsOn:
				if dependsOnName in wantedNames: continue
				pendingProcessed.append(dependsOnName)
				wantedNames[dependsOnName] = True
			for subGroup in wantedGroup.subGroups:
				if subGroup.name in wantedNames: continue
				pendingProcessed.append(subGroup.name)
				wantedNames[subGroup.name] = True

		for wantedName in wantedNames:
			wantedGroup = mainState.tryGetGroup(wantedName)
			if wantedGroup != None:
				wantedGroup.isWanted = True
				mainState.filteredGroups.append(wantedGroup)
				if excludedNames.get(wantedName) != None:
					wantedGroup.ignoreHeader = True
			else:
				# print("Couldn't find Group: \"" + wantedName + "\"")
				pass

		pointer = mainState.getGroup("Pointer")

		# Fill templateUses
		for group in mainState.filteredGroups:
			# if group == pointer: continue
			group.scanInwardTypeRefs()

		# Define primitive pointer types (for reference_ bindings)
		for primitive in primitives:
			pointer.addTemplateUse( (defineTypeRef(mainState, None, primitive),) )

		# Sort groups alphabetically based on name
		mainState.filteredGroups.sort(key=lambda x: x.name)

		# Try to fix dependency order (SLOW)
		tryResolveDependencyOrder(mainState.filteredGroups)


		# Rename groups
		for group in mainState.filteredGroups:

			def doNameCheck(group: Group):
				if group.superGroup: doNameCheck(group.superGroup)

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
					group.changeSingleName(mainState, newName)

			doNameCheck(group)


		# Rename clashing function names in vftables
		# These are overloaded functions, but they can't
		# have the same name in a struct.
		for group in mainState.filteredGroups:
			seenFuncNames: dict[str,int] = {}
			for field in group.fields.values():
				if field.type == FieldType.FUNCTION:
					functionField: FunctionField = field
					seenCount = seenFuncNames.get(functionField.functionName, 0) + 1
					seenFuncNames[functionField.functionName] = seenCount
					if seenCount > 1:
						functionField.functionName += f"_{seenCount}"


		# The engine already defines some usertypes
		# add prefix to prevent clashing with binding names
		if alreadyDefinedUsertypesFile != None:
			with open(alreadyDefinedUsertypesFile) as file_in:
				for line in file_in:
					groupName = line.strip()
					group = mainState.getGroup(groupName)
					group.overrideUsertypeSingleName = "EEex_" + groupName


		# Registers pointer types for every group, (for reference_ functions)
		registerPointerTypes(mainState)


		with open(bindingsFileName, "w") as bindingsOut:

			if bindingsPreludeFile != None:
				with open(bindingsPreludeFile) as bindingsPrelude:
					for line in bindingsPrelude:
						bindingsOut.write(line)

			writeBindings(mainState, mainState.filteredGroups, bindingsOut)


		if preludeFile != None:
			with open(preludeFile) as file_in:
				for line in file_in:
					out.write(line)


		# Store final sorted positions in groups
		i = 0
		for group in mainState.filteredGroups:
			group.sortedPosition = i
			i += 1

		forwardDeclarations: set[str] = set()

		# Attempt to derive needed forward declarations
		for group in mainState.filteredGroups:

			for lightDependency in group.lightDependsOn:
				lightDepend = mainState.tryGetGroup(lightDependency)
				if not lightDepend or lightDepend == globalGroup or lightDepend.isPrimitive() or lightDepend.name == "void": continue
				if not lightDepend.defined or lightDepend.sortedPosition > group.sortedPosition:
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
			if group.isSubgroup() or group.ignoreHeader: continue
			if group.template != None: out.write(group.template + "\n")
			out.write(group.groupType + " " + group.name + ";\n")

		out.write("\n")


		outputInternalPointersFile = outputFileName[0:outputFileName.rindex('.')] + "_internal_pointers.cpp"
		with open(outputInternalPointersFile, "w") as internalPointersOut:

			internalPointersList = []
			internalPointersOut.write(f"\n#include \"{pathToFileName(outputFileName)}\"\n\n")

			# Output groups
			for group in mainState.filteredGroups:
				if group.isSubgroup() or group.ignoreHeader: continue
				if not group.isUsed() or group.groupType == "undefined": continue
				out.write(group.writeHeader(internalPointersOut, internalPointersList, headerType))
				out.write("\n\n")

			out.write("extern std::vector<std::pair<const TCHAR*, void**>> internalPointersMap;\n")

			if len(internalPointersList) > 0:
				internalPointersOut.write("\n")

			internalPointersOut.write("std::vector<std::pair<const TCHAR*, void**>> internalPointersMap {\n")
			for internalPointerNameTup in internalPointersList:
				internalPointersOut.write(f"\tstd::pair{{TEXT(\"{internalPointerNameTup[0]}\"), reinterpret_cast<void**>(&{internalPointerNameTup[1]})}},\n")

			internalPointersOut.write("};\n")



if __name__ == "__main__":
    main()
