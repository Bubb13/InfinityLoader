call "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvarsamd64_x86.bat"
cd src
call msvcbuild.bat
move "lua51.dll" "..\..\Win32\Release\LuaJITProvider\"
move "lua51.pdb" "..\..\Win32\Release\LuaJITProvider\"
pause