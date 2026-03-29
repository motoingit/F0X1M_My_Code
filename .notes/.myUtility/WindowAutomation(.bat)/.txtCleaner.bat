@echo off
setlocal enabledelayedexpansion

:: Set your folder path here
set "targetDir=C:\Users\mohit\OneDrive\Documents\02 CODE FILE'S"

:: Check if the directory exists
if not exist "%targetDir%" (
    echo Folder does not exist: %targetDir%
    pause
    exit
)

echo Searching and deleting all .txt files in:
echo %targetDir%
echo.

:: Delete all .txt files in target folder and subfolders
for /R "%targetDir%" %%f in (*.txt) do (
    echo Deleting: "%%f"
    del /f /q "%%f"
)

echo.
echo All .txt files deleted successfully.
pause
