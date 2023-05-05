
pushd "%~dp0"
if not exist "./out" mkdir "./out"

set script_path="../../../scripts/generate_bindings/generate_bindings.py"

python %script_path%^
 -alreadyDefinedUsertypesFile=./in/already_defined_usertypes.txt^
 -bindingsOutFile=./out/EEexLua_generated.cpp^
 -bindingsPreludeFile=./in/bindings_prelude.txt^
 -fixupFile=./in/fixup.py^
 -ignoreHeaderFile=./in/ignore_header_types.txt^
 -inFile=./in/Baldur-v2.6.6.0.h^
 -manualTypesFile=./in/manual_types.txt^
 -outFile=./out/Baldur-v2.6.6.0_generated.h^
 -packingFile=./in/packing.txt^
 -preludeFile=./in/prelude.txt^
 -wantedFile=./in/wanted_types.txt^
 > log.txt 2>&1

copy /Y .\out\Baldur-v2.6.6.0_generated.h ..\..\headers\LuaBindings-v2.6.6.0\
copy /Y .\out\Baldur-v2.6.6.0_generated_internal_pointers.cpp ..\..\source\LuaBindings-v2.6.6.0\Generated
copy /Y .\out\EEexLua_generated.cpp ..\..\source\LuaBindings-v2.6.6.0\Generated
copy /Y .\out\EEexLua_generated_baseclass_offsets.cpp ..\..\source\LuaBindings-v2.6.6.0\Generated
REM copy /Y .\out\EEexLua_generated_baseclass_offsets.h ..\..\headers\LuaBindings-v2.6.6.0\

python %script_path%^
 -ignoreHeaderFile=./in_lua/ignore_header_types.txt^
 -inFile=./in/Baldur-v2.6.6.0.h^
 -noCustomTypes^
 -outFile=./out/Baldur-v2.6.6.0_lua_generated.h^
 -packingFile=./in/packing.txt^
 -preludeFile=./in_lua/prelude.txt^
 -wantedFile=./in_lua/wanted_types.txt^
 > log_lua.txt 2>&1

copy /Y .\out\Baldur-v2.6.6.0_lua_generated.h ..\..\headers\LuaBindings-v2.6.6.0\

popd
