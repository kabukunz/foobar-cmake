del /S /Q build

cmake -S . -B build -G Ninja ^
-DCMAKE_BUILD_TYPE=Release ^
-DCMAKE_INSTALL_PREFIX=install ^
-DCMAKE_WINDOWS_EXPORT_ALL_SYMBOLS=TRUE

cmake --build build

cmake --install build

.\install\bin\foo.exe

@REM with NSIS
cmake --build build --target package
