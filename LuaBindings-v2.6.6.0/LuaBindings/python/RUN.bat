
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
 -bindingsOutFile=./out/EEexLua_generated.cpp^
 -outFile=./out/Baldur-v2.6.6.0_generated.h^
 > log.txt
 
copy /Y .\out\Baldur-v2.6.6.0_generated.h ..\..\include\LuaBindings\
copy /Y .\out\EEexLua_generated_baseclass_offsets.h ..\..\include\LuaBindings\

copy /Y .\out\Baldur-v2.6.6.0_generated_internal_pointers.cpp ..\..\
copy /Y .\out\EEexLua_generated_baseclass_offsets.cpp ..\..\
copy /Y .\out\EEexLua_generated.cpp ..\..\
 
pause
