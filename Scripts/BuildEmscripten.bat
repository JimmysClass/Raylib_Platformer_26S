cd ..
cd Emscripten
call install.bat
cd ..

path=%path%;%~dp0\..\Emscripten\ninja
set EMSCRIPTEN=%~dp0\..\Emscripten\emsdk
call %EMSCRIPTEN%\emsdk_env.bat

echo --------------------------------------------------------------------------
echo ---------------------------- Building Release ----------------------------
echo --------------------------------------------------------------------------
call emcmake cmake -S . -B build-em\release -DCMAKE_BUILD_TYPE=Release
call xcopy Data build-em\release\Data\ /s /d /y
call cmake --build build-em\release
if %ERRORLEVEL% GEQ 1 goto done
call cmd /k npx http-server build-em\release
echo --------------------------------------------------------------------------
echo ----------------------- Finished Building Release ------------------------
echo --------------------------------------------------------------------------

:done
pause