@echo off
title EXE Installer Menu
color 0A
setlocal enabledelayedexpansion

:MENU
cls
echo ======================================
echo      🚀 Automatic EXE Installer
echo ======================================
echo.
echo 1. Install ALL .exe files
echo 2. Install a specific .exe file
echo 3. Exit
echo.
set /p choice="Enter your choice (1-3): "

if "%choice%"=="1" goto INSTALL_ALL
if "%choice%"=="2" goto INSTALL_ONE
if "%choice%"=="3" exit
goto MENU

:INSTALL_ALL
cls
set count=0
for %%f in (*.exe) do (
    set /a count+=1
    echo [!count!] Installing: %%f
    start /wait "" "%%f"
    echo.
)
if %count%==0 (
    echo ⚠ No .exe files found in this directory.
) else (
    echo ✅ Finished installing all %count% executables.
)
pause
goto MENU

:INSTALL_ONE
cls
set i=0
for %%f in (*.exe) do (
    set /a i+=1
    echo !i!. %%f
    set "file[!i!]=%%f"
)
if %i%==0 (
    echo ⚠ No .exe files found in this directory.
    pause
    goto MENU
)

echo.
set /p num="Enter the number of the .exe to install: "

if "%num%"=="" goto MENU
if %num% gtr %i% (
    echo Invalid choice.
    pause
    goto MENU
)

echo Installing: !file[%num%]!
start /wait "" "!file[%num%]!"
echo ✅ Installation completed.
pause
goto MENU
