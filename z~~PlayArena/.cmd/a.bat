@echo off
setlocal

:: Set your target directory (or pass as argument: script.bat "E:\My_Code")
set "TARGET_DIR=%~1"
if "%TARGET_DIR%"=="" set "TARGET_DIR=E:\My_Code"

echo.
echo =====================================
echo   WARNING: RECURSIVE DELETE OPERATION
echo =====================================
echo Target Directory: %TARGET_DIR%
echo This will DELETE all .exe and .class files recursively.
echo.

:: Validate directory exists
if not exist "%TARGET_DIR%\" (
    echo ERROR: Directory does not exist: %TARGET_DIR%
    exit /b 1
)

set /p "confirm=Press Enter to confirm deletion, or type anything else to cancel: "
if not "%confirm%"=="" (
    echo Operation cancelled.
    exit /b 0
)

echo.
echo Scanning and deleting files...

:: Count before deleting (optional feedback)
set count=0
for /r "%TARGET_DIR%" %%f in (*.exe *.class) do set /a count+=1

if %count%==0 (
    echo No matching files found. Nothing to delete.
    exit /b 0
)

echo Found %count% file(s). Deleting...

del /s /q "%TARGET_DIR%\*.exe"
del /s /q "%TARGET_DIR%\*.class"

echo.
echo Done. %count% file(s) deleted.
