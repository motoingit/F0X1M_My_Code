@echo off
title System Power Manager
color 0A
setlocal enabledelayedexpansion

:MENU
cls
echo ===================================
echo     System Power Manager
echo ===================================
echo.
echo   1. Shutdown
echo   2. Restart
echo   3. Sleep
echo   4. Exit
echo.
set "choice="
set /p choice="Enter choice (1-4): "

if "!choice!"=="" goto MENU
if "!choice!"=="4" exit
if "!choice!"=="1" goto GET_TIME
if "!choice!"=="2" goto GET_TIME
if "!choice!"=="3" goto SLEEP_NOW
echo Invalid choice. Try again.
timeout /t 1 /nobreak >nul
goto MENU

:: ─────────────────────────────────────
::  Sleep has no timer — runs immediately
:: ─────────────────────────────────────
:SLEEP_NOW
echo Sleeping now...
rundll32.exe powrprof.dll,SetSuspendState Sleep
goto MENU

:: ─────────────────────────────────────
::  Get and validate timer input
:: ─────────────────────────────────────
:GET_TIME
echo.
set "secs="
set /p secs="Enter time in seconds: "

if "!secs!"=="" (
    echo No time entered. Cancelled.
    timeout /t 2 /nobreak >nul
    goto MENU
)

set /a secs=!secs! 2>nul
if !secs! leq 0 (
    echo Invalid time. Enter a number greater than 0.
    timeout /t 2 /nobreak >nul
    goto GET_TIME
)

:: ─────────────────────────────────────
::  Confirm before executing
:: ─────────────────────────────────────
echo.
if "!choice!"=="1" echo Action : Shutdown
if "!choice!"=="2" echo Action : Restart
echo Time   : !secs! seconds
echo.
set "confirm="
set /p confirm="Confirm? (y/n): "
if /i "!confirm!" neq "y" goto MENU

:: ─────────────────────────────────────
::  Countdown then execute
:: ─────────────────────────────────────
echo.
echo Scheduled. Waiting !secs! seconds...
timeout /t !secs! /nobreak >nul

if "!choice!"=="1" shutdown /s /f /t 0
if "!choice!"=="2" shutdown /r /f /t 0

exit
