@echo off
title Windows Cleanup Script
echo Cleaning Temporary Files...
echo.

:: Delete Windows Temp files
echo Deleting Windows Temp files...
del /s /f /q "C:\Windows\Temp\*.*"

:: Delete User Temp files
echo Deleting User Temp files...
del /s /f /q "%TEMP%\*.*"

echo.
echo Cleanup Completed Successfully!
pause
exit
