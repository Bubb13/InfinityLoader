
pushd "%~dp0"
if not exist "./out" mkdir "./out"

set script_path="../../../scripts/generate_bindings/generate_bindings.py"

python %script_path%^
 -alreadyDefinedUsertypesFile=./in/already_defined_usertypes.txt^
 -bindingsOutFile=./out/EEexLua_generated.cpp^
 -bindingsPreludeFile=./in/bindings_prelude.txt^
 -fixupFile=./in/fixup.py^
 -ignoreHeaderFile=./in/ignore_header_types.txt^
 -inFiles=./in/manual_types.txt,./in/engine_structs.h^
 -outFile=./out/engine_structs_generated.h^
 -preludeFile=./in/prelude.txt^
 -suffixFile=./in/suffix.txt^
 -wantedFile=./in/wanted_types.txt^
 > log.txt 2>&1

copy /Y .\out\engine_structs_generated.h ..\..\headers\LuaBindings-PSTEE_generated
copy /Y .\out\engine_structs_generated_internal_pointers.cpp ..\..\source\generated
copy /Y .\out\EEexLua_generated.cpp ..\..\source\generated
copy /Y .\out\EEexLua_generated_baseclass_offsets.cpp ..\..\source\generated

python %script_path%^
 -inFiles=./in_lua/manual_types.txt,./in_lua/Baldur-v2.5.17.0.h^
 -noCustomTypes^
 -outFile=./out/Baldur-v2.5.17.0_lua_generated.h^
 -preludeFile=./in_lua/prelude.txt^
 -wantedFile=./in_lua/wanted_types.txt^
 > log_lua.txt 2>&1

copy /Y .\out\Baldur-v2.5.17.0_lua_generated.h ..\..\headers\LuaBindings-PSTEE_generated

popd
