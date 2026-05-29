@echo off
title Hyper-V Master Toggle
color 0A

:: Check for Admin Rights
net session >nul 2>&1
if %errorlevel% neq 0 (
    echo.
    echo =====================================
    echo   RUN THIS SCRIPT AS ADMINISTRATOR
    echo =====================================
    echo.
    pause
    exit
)

:menu
cls
echo =====================================
echo        HYPER-V CONTROL PANEL
echo =====================================
echo.
echo 1. Enable Full Hyper-V
echo 2. Disable Full Hyper-V
echo 3. Quick Enable (Boot Only)
echo 4. Quick Disable (Boot Only)
echo 5. Check Hyper-V Status
echo 6. Exit
echo.
set /p choice=Select option: 

if "%choice%"=="1" goto enablefull
if "%choice%"=="2" goto disablefull
if "%choice%"=="3" goto quickenable
if "%choice%"=="4" goto quickdisable
if "%choice%"=="5" goto status
if "%choice%"=="6" exit

echo Invalid option.
pause
goto menu

:enablefull
cls
echo Enabling Hyper-V Features...

dism /online /enable-feature /featurename:Microsoft-Hyper-V-All /all /norestart
dism /online /enable-feature /featurename:VirtualMachinePlatform /all /norestart
dism /online /enable-feature /featurename:HypervisorPlatform /all /norestart

bcdedit /set hypervisorlaunchtype auto

echo.
echo =====================================
echo      HYPER-V FULLY ENABLED
echo =====================================
echo Restart required.
pause
goto menu

:disablefull
cls
echo Disabling Hyper-V Features...

dism /online /disable-feature /featurename:Microsoft-Hyper-V-All /norestart
dism /online /disable-feature /featurename:VirtualMachinePlatform /norestart
dism /online /disable-feature /featurename:HypervisorPlatform /norestart

bcdedit /set hypervisorlaunchtype off

echo.
echo =====================================
echo      HYPER-V FULLY DISABLED
echo =====================================
echo Restart required.
pause
goto menu

:quickenable
cls
echo Enabling Hypervisor Boot...

bcdedit /set hypervisorlaunchtype auto

echo.
echo =====================================
echo      HYPERVISOR ENABLED
echo =====================================
echo Restart required.
pause
goto menu

:quickdisable
cls
echo Disabling Hypervisor Boot...

bcdedit /set hypervisorlaunchtype off

echo.
echo =====================================
echo      HYPERVISOR DISABLED
echo =====================================
echo Restart required.
pause
goto menu

:status
cls
echo =====================================
echo          SYSTEM STATUS
echo =====================================
echo.

systeminfo | findstr /i "Hyper-V"
echo.
bcdedit | findstr /i hypervisorlaunchtype

echo.
pause
goto menu
