# ─────────────────────────────────────────
#  Auto-elevate to Administrator
# ─────────────────────────────────────────
if (-not ([Security.Principal.WindowsPrincipal] [Security.Principal.WindowsIdentity]::GetCurrent()).IsInRole([Security.Principal.WindowsBuiltInRole]::Administrator)) {
    Start-Process powershell.exe -Verb RunAs -ArgumentList "-NoExit -ExecutionPolicy Bypass -File `"$PSCommandPath`""
    exit
}

# ─────────────────────────────────────────
#  Build CMD command chain
# ─────────────────────────────────────────
$cmds = @(
    "cls",
    "echo.",
    "echo ===================================================",
    "echo          DISM Full Auto Runner",
    "echo ===================================================",
    "echo.",

    "echo [1/3] CheckHealth...",
    "DISM /Online /Cleanup-Image /CheckHealth",
    "echo.",

    "echo [2/3] ScanHealth  (may take a few minutes)...",
    "DISM /Online /Cleanup-Image /ScanHealth",
    "echo.",

    "echo [3/3] RestoreHealth  (may take 10-20 mins - do NOT close)...",
    "DISM /Online /Cleanup-Image /RestoreHealth",
    "echo.",

    "echo ===================================================",
    "echo   ALL DISM OPERATIONS COMPLETED",
    "echo ===================================================",
    "echo.",
    "pause"
) -join " & "

# ─────────────────────────────────────────
#  Open single elevated CMD window and run
# ─────────────────────────────────────────
Start-Process cmd.exe -ArgumentList "/k $cmds" -Verb RunAs -Wait
