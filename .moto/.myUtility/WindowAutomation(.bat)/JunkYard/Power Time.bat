@echo off
title System Power Manager
color 0A
echo ===================================
echo   System Power Manager - Automate  
echo ===================================
echo.
echo Choose an option:
echo 1. Shutdown
echo 2. Restart
echo 3. Sleep
echo 4. Cancel
echo.
set /p choice="Enter your choice (1/2/3/4): "

if "%choice%"=="4" (
    echo Cancelled.
    exit
)

set /p time="Enter time in seconds: "
set /a time=%time%

echo Task scheduled. Waiting for %time% seconds...
timeout /t %time% /nobreak >nul

if "%choice%"=="1" shutdown /s /f /t 0
if "%choice%"=="2" shutdown /r /f /t 0
if "%choice%"=="3" rundll32.exe powrprof.dll,SetSuspendState Sleep

exit
