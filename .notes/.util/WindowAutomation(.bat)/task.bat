@echo off
title Simple Task Manager
color 0A
set "TASK_FILE=tasks.txt"

:MENU
cls
echo ================================
echo       📋 TASK MANAGER
echo ================================
echo.
echo 1. View Tasks
echo 2. Add Task
echo 3. Delete Task
echo 4. Exit
echo.
set /p choice="Enter your choice: "

if "%choice%"=="1" goto VIEW
if "%choice%"=="2" goto ADD
if "%choice%"=="3" goto DELETE
if "%choice%"=="4" exit
goto MENU

:VIEW
cls
echo ================================
echo       ✅ Current Tasks
echo ================================
if not exist "%TASK_FILE%" (
    echo (No tasks found)
) else (
    type "%TASK_FILE%"
)
echo.
pause
goto MENU

:ADD
cls
set /p newtask="Enter new task: "
if "%newtask%"=="" goto MENU
echo %newtask%>>"%TASK_FILE%"
echo Task added successfully!
timeout /t 1 >nul
goto MENU

:DELETE
cls
if not exist "%TASK_FILE%" (
    echo No tasks to delete.
    pause
    goto MENU
)

echo ================================
echo       ❌ Delete a Task
echo ================================
echo.
setlocal enabledelayedexpansion
set i=0
for /f "tokens=*" %%a in (%TASK_FILE%) do (
    set /a i+=1
    echo !i!. %%a
)
echo.
set /p dnum="Enter task number to delete: "

if "%dnum%"=="" goto MENU

set i=0
>temp.txt (
    for /f "tokens=*" %%a in (%TASK_FILE%) do (
        set /a i+=1
        if not "!i!"=="%dnum%" echo %%a
    )
)
move /y temp.txt "%TASK_FILE%" >nul
echo Task deleted successfully!
timeout /t 1 >nul
goto MENU
