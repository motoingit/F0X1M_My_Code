@echo off
setlocal enabledelayedexpansion
cls
color 0A

:: Define paragraphs
set "p1=The terminal glowed softly as lines of code spilled onto the screen, like digital ink across the canvas of logic."
set "p2=In a quiet room, the only sound was the rhythmic tapping of keys, as the machine obeyed its human."
set "p3=Ideas become code, and code becomes action—each function a whispered spell in the language of logic."
set "p4=As the cursor blinked patiently, the programmer smiled, knowing that even chaos could be structured."
set "p5=Through loops and conditions, the mind spoke to the machine, binding imagination with execution."

:: Pick a random paragraph
set /a rand=%random% %% 5 + 1
call set "para=%%p%rand%%%"

:: Wait for space to start
echo Press SPACE to begin typing...
:waitSpace
choice /c " " /n /t 0 >nul
if errorlevel 1 goto startTyping
goto waitSpace

:startTyping
cls
echo Typing started... [Press ENTER to stop]
echo.

:: Start printing char by char
set i=0
:printLoop
set "char=!para:~%i%,1!"
if "!char!"=="" goto done

<nul set /p=!char!
set /a i+=1
ping -n 1 127.0.0.1 >nul

:: Check if ENTER was pressed
:: Use CHOICE to check without waiting
choice /c "E" /n /t 0 /d E >nul
if errorlevel 1 goto done

goto printLoop

:done
echo.
echo Done!
pause >nul
