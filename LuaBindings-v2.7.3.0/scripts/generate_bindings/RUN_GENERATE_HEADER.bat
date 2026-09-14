
pushd "%~dp0"
if not exist "./out" mkdir "./out"

set script_path="../../../scripts/generate_bindings/generate_bindings_main.py"
set core_in="../../../Core-Shared-Files/generate_bindings/in"
set lua_in="../../../Core-Shared-Files/generate_bindings/in_lua"

python %PYTHON_OPTIONS% %script_path%^
 -mode=GenerateHeader^
 -allowDebug^
 -abstractTypesFile=%core_in%/abstract_types.txt^
 -aliasFiles=%core_in%/alias_v2.7.txt^
 -alreadyDefinedUsertypesFile=%core_in%/already_defined_usertypes.txt^
 -bindingsOutFile=./out/EEexLua_generated.cpp^
 -bindingsPreludeFile=%core_in%/bindings_prelude.txt^
 -dllName=LuaBindings.dll^
 -fixupFile=%core_in%/fixup.py^
 -ignoreHeaderFile=%core_in%/ignore_header_types.txt^
 -inFiles=%core_in%/manual_types.txt,%core_in%/manual_reimplementations_export.txt,%core_in%/Baldur-v2.7.3.0.h^
 -outFile=./out/Baldur_generated.h^
 -packingFile=%core_in%/packing.txt^
 -preludeFile=%core_in%/prelude_luabindings.txt^
 -printFuncWideString=FPrintT^
 -wantedFiles=%core_in%/wanted_types.txt^
 > log.txt 2>&1

copy /Y .\out\Baldur_generated.h ..\..\headers\LuaBindings-v2.7.3.0_generated\
copy /Y .\out\Baldur_generated_internal_pointers.cpp ..\..\source\LuaBindings-v2.7.3.0\generated
copy /Y .\out\EEexLua_generated.cpp ..\..\source\LuaBindings-v2.7.3.0\generated
copy /Y .\out\EEexLua_generated_baseclass_offsets.cpp ..\..\source\LuaBindings-v2.7.3.0\generated

python %PYTHON_OPTIONS% %script_path%^
 -mode=GenerateHeader^
 -ignoreHeaderFile=%lua_in%/ignore_header_types.txt^
 -inFiles=%lua_in%/manual_types.txt,%core_in%/Baldur-v2.7.3.0.h^
 -noCustomTypes^
 -outFile=./out/Baldur_lua_generated.h^
 -packingFile=%core_in%/packing.txt^
 -preludeFile=%lua_in%/prelude.txt^
 -wantedFiles=%lua_in%/wanted_types.txt^
 > log_lua.txt 2>&1

copy /Y .\out\Baldur_lua_generated.h ..\..\headers\LuaBindings-v2.7.3.0_generated\

popd
