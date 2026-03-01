@echo off
title Windows Cleanup Script
color 0A
echo Cleaning Temporary Files...
echo.

:: Delete Windows Temp files
echo Deleting Windows Temp files...
rd /s /q C:\Windows\Temp
md C:\Windows\Temp

:: Delete User Temp files
echo Deleting User Temp files...
rd /s /q "%TEMP%"
md "%TEMP%"

:: Delete Prefetch files
echo Deleting Prefetch files...
rd /s /q C:\Windows\Prefetch
md C:\Windows\Prefetch

:: Display completion message
echo.
echo Cleanup Completed Successfully!
pause
exit
