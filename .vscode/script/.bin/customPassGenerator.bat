@echo off
:: Clear screen and simulate loading
cls
echo Initializing Company Code Generator...
ping -n 2 127.0.0.1 > nul
echo Loading modules...
ping -n 2 127.0.0.1 > nul
echo Preparing environment...
ping -n 2 127.0.0.1 > nul
cls

:: Show menu
echo ===============================
echo     COMPANY CODE GENERATOR
echo ===============================
echo.
echo Select an option:
echo [1] Generate Simple String (length + name + @2444)
echo [2] Run Full Custom Code Generator
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

:: Extract first word and get length using PowerShell
for /f "tokens=1" %%a in ("%name%") do set name=%%a
for /f %%L in ('powershell -nologo -command "('{0:D2}' -f ('%name%'.Length))"') do set len=%%L

:: Display custom string
echo.
echo Generated String: %len%%name%@2444
echo.
goto end

:full_code
cls
set /p company=Enter company name: 
echo.
python -c "company=r'''%company%''';fw=company.strip().split()[0].capitalize();fc=fw[0].lower();lc=fw[-1].lower();fv=ord(fc)-96;lv=ord(lc)-96;cc=f'{fv:02d}{lv:02d}';s1='@' if sum(map(int,cc))%%2==0 else '#';l=len(fw);hl=l//2;fd=f'{l:02d}{hl:02d}';s2='@' if sum(map(int,fd))%%2==0 else '#';print('Generated Code:',f'{cc}{s1}{fw}{s2}{fd}')"
goto end

:invalid_option
echo Invalid choice. Please run the script again.
goto end

:end
echo.
pause
