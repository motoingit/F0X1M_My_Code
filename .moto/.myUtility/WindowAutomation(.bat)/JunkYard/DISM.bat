@echo off
color 0A
title DISM Full Auto Runner

echo ===================================================
echo    STEP 1: Running DISM CheckHealth...
echo ===================================================
DISM /Online /Cleanup-Image /CheckHealth
echo.
echo ---------- Done with CheckHealth ----------
echo.

echo ===================================================
echo    STEP 2: Running DISM ScanHealth...
echo ===================================================
DISM /Online /Cleanup-Image /ScanHealth
echo.
echo ---------- Done with ScanHealth ----------
echo.

echo ===================================================
echo    STEP 3: Running DISM RestoreHealth...
echo ===================================================
DISM /Online /Cleanup-Image /RestoreHealth
echo.
echo ---------- Done with RestoreHealth ----------
echo.

echo ===================================================
echo         ALL DISM OPERATIONS COMPLETED
echo ===================================================
pause
