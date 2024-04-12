
pushd "%~dp0"

start cmd.exe /c "call ../../EEex-v2.6.6.0/scripts/generate_bindings/RUN_GENERATE_HEADER.bat"
start cmd.exe /c "call ../../LuaBindings-PSTEE/scripts/generate_bindings/RUN_GENERATE_HEADER.bat"
start cmd.exe /c "call ../../LuaBindings-v2.6.6.0/scripts/generate_bindings/RUN_GENERATE_HEADER.bat"

popd
