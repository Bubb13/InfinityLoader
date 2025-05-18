
pushd "%~dp0"

set PYTHON_OPTIONS=-Xfrozen_modules=off
set DEBUGGING=1
call RUN_GENERATE_HEADER.bat

popd
