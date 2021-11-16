
if not exist "./out" mkdir "./out"

python generate_bindings.py^
 -normal^
 -alreadyDefinedUsertypesFile=./in/already_defined_usertypes.txt^
 -bindingsPreludeFile=./in/bindings_prelude.txt^
 -excludedFile=./in/excluded_types.txt^
 -fixupFile=in.fixup^
 -inFile=./in/Baldur-v2.6.6.0.h^
 -manualTypesFile=./in/manual_types.txt^
 -preludeFile=./in/prelude.txt^
 -wantedFile=./in/wanted_types.txt^
 -bindingsOutFile=./out/bindings.cpp^
 -outFile=./out/Baldur-v2.6.6.0_generated.h^
 > log.txt
 
copy /Y .\out\Baldur-v2.6.6.0_generated.h ..\..\include\LuaBindings\
copy /Y .\out\Baldur-v2.6.6.0_generated_internal_pointers.cpp ..\..\
copy /Y .\out\bindings.cpp ..\..\EEexLua_generated.cpp
 
pause
