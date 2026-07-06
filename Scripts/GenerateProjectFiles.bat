cd ..
cmake -B build-win
rem Build a second time to fix PCH folder
cmake -B build-win
pause
exit
