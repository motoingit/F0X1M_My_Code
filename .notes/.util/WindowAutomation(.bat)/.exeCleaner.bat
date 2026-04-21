@echo off
setlocal enabledelayedexpansion

:: Define the target folder (No user input needed)
set "dirPath=C:\Users\mohit\OneDrive\Documents\00_CODE"

:: Verify if the folder exists
if not exist "%dirPath%" (
    echo The directory does not exist: %dirPath%
    pause
    exit
)

:: Delete all .exe files in the folder and its subfolders
echo Deleting all .exe files in "%dirPath%" and its subdirectories...
for /r "%dirPath%" %%f in (*.exe) do (
    echo Deleting: "%%f"
    del /f /q "%%f"
)

echo All .exe files have been deleted!
pause
