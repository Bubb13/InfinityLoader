
if not exist "./out" mkdir "./out"

python generate_bindings.py^
 -alreadyDefinedUsertypesFile=./in/already_defined_usertypes.txt^
 -bindingsPreludeFile=./in/bindings_prelude.txt^
 -ignoreHeaderFile=./in/ignore_header_types.txt^
 -fixupFile=in.fixup^
 -inFile=./in/Baldur-v2.6.6.0.h^
 -manualTypesFile=./in/manual_types.txt^
 -preludeFile=./in/prelude.txt^
 -wantedFile=./in/wanted_types.txt^
 -packingFile=./in/packing.txt^
 -bindingsOutFile=./out/EEexLua_generated.cpp^
 -outFile=./out/Baldur-v2.6.6.0_generated.h^
 > log.txt 2>&1
 
copy /Y .\out\Baldur-v2.6.6.0_generated.h ..\..\headers\LuaBindings-v2.6.6.0\
copy /Y .\out\EEexLua_generated_baseclass_offsets.h ..\..\headers\LuaBindings-v2.6.6.0\

copy /Y .\out\Baldur-v2.6.6.0_generated_internal_pointers.cpp ..\..\source\LuaBindings-v2.6.6.0\Generated
copy /Y .\out\EEexLua_generated_baseclass_offsets.cpp ..\..\source\LuaBindings-v2.6.6.0\Generated
copy /Y .\out\EEexLua_generated.cpp ..\..\source\LuaBindings-v2.6.6.0\Generated

python generate_bindings.py^
 -inFile=./in/Baldur-v2.6.6.0.h^
 -noCustomTypes^
 -wantedFile=./in_lua/wanted_types.txt^
 -preludeFile=./in_lua/prelude.txt^
 -packingFile=./in/packing.txt^
 -outFile=./out/Baldur-v2.6.6.0_lua_generated.h^
 > log_lua.txt

copy /Y .\out\Baldur-v2.6.6.0_lua_generated.h ..\..\headers\LuaBindings-v2.6.6.0\

pause
