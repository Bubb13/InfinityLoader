call "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars64.bat"
cd src
call msvcbuild.bat
move "lua51.dll" "..\..\x64\Release\LuaJITProvider\"
move "lua51.pdb" "..\..\x64\Release\LuaJITProvider\"
pause