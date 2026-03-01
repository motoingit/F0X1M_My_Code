@echo off
:: Clear the screen
cls

:: Simulated loading screen
echo Initializing Company Code Generator...
ping -n 2 127.0.0.1 > nul
echo Loading modules...
ping -n 2 127.0.0.1 > nul
echo Preparing environment...
ping -n 2 127.0.0.1 > nul
cls

:: Display menu
echo ===============================
echo     COMPANY CODE GENERATOR
echo ===============================
echo.
echo Select an option:
echo [1] Generate Simple String
echo [2] Run Full Code Generator (Python)
echo.

set /p choice=Enter your choice (1 or 2): 
if "%choice%"=="1" goto simple_string
if "%choice%"=="2" goto full_code
goto invalid_option

:simple_string
cls
set /p company=Enter company name: 
setlocal EnableDelayedExpansion
set name=%company%
set len=00

:: Get length of company name (first word)
for /f "tokens=1" %%a in ("%name%") do set name=%%a

:: Use PowerShell to get string length and pad
for /f %%L in ('powershell -nologo -command "('{0:D2}' -f ('%name%'.Length))"') do set len=%%L

:: Display custom string
echo.
echo Generated String: %len%%name%@2444
echo.
goto end

:full_code
cls
:: Run Python code
python code.py
goto end

:invalid_option
echo Invalid choice. Please run the script again.
goto end

:end
echo.
pause