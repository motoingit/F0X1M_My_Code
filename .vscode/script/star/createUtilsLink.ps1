# ============================================================
# Create-Notes.ps1
#
# Creates:
#
# <Project>
# │
# ├── .notes
# │   ├── MYCODE  ---------> E:\code\F0X1M_My_Code
# │   └── NOTES   ---------> E:\code\F0X1M_My_Code\.notes
#
# Automatically requests Administrator privileges if needed.
# Safe to run multiple times.
# ============================================================




$ErrorActionPreference = "Stop"

# -----------------------------
# CONFIGURATION
# -----------------------------

$Links = @(
    @{
        Name   = "Full_Workshop"
        Target = "E:\code\F0X1M_My_Code"
    },
    @{
        Name   = "shortNotes"
        Target = "E:\code\F0X1M_My_Code\.notes"
    },
    @{
        Name   = "User_vscode_GlobalConfig"
        Target = "C:\Users\mohit\AppData\Roaming\Code\User"
    }
)

$NotesFolderName = ".myNotes"

# Adding Data
Write-Host "========== DEBUG =========="
Write-Host "PWD: $(Get-Location)"
Write-Host "Script: $PSCommandPath"
Write-Host "User: $env:USERNAME"
Write-Host "==========================="

# # -----------------------------
# # Auto Elevate (Run as Admin)
# # -----------------------------

# $currentUser = New-Object Security.Principal.WindowsPrincipal(
#     [Security.Principal.WindowsIdentity]::GetCurrent()
# )

# if (-not $currentUser.IsInRole([Security.Principal.WindowsBuiltInRole]::Administrator)) {

#     Write-Host "Requesting Administrator permission..." -ForegroundColor Yellow

#     Start-Process powershell `
#         -ArgumentList "-ExecutionPolicy Bypass -NoProfile -File `"$PSCommandPath`"" `
#         -Verb RunAs

#     exit
# }

# -----------------------------
# Detect Current Project Folder
# -----------------------------

$ProjectFolder = (Get-Location).Path

$NotesFolder = Join-Path $ProjectFolder $NotesFolderName

Write-Host ""
Write-Host "===================================="
Write-Host " Project : $ProjectFolder"
Write-Host "===================================="
Write-Host ""

Write-Host "Links to create:" -ForegroundColor Cyan

foreach ($Link in $Links) {
    Write-Host " - $($Link.Name) -> $($Link.Target)"
}

Write-Host ""

# -----------------------------
# Create .notes Folder
# -----------------------------

if (!(Test-Path $NotesFolder)) {

    New-Item `
        -ItemType Directory `
        -Path $NotesFolder | Out-Null

    Write-Host "Created .notes folder." -ForegroundColor Green

}

# -----------------------------
# Create Junctions
# -----------------------------

foreach ($Link in $Links) {
    Write-Host ""
    Write-Host "Creating:"
    Write-Host "  Link   : $LinkPath"
    Write-Host "  Target : $($Link.Target)"

    $LinkPath = Join-Path $NotesFolder $Link.Name

    if (!(Test-Path $Link.Target)) {

        Write-Host ""
        Write-Host "Target does not exist:" -ForegroundColor Red
        Write-Host $Link.Target
        continue

    }

    if (Test-Path $LinkPath) {

        Write-Host "[EXISTS] $($Link.Name)" -ForegroundColor Yellow
        continue

    }

    try {

        New-Item `
            -ItemType Junction `
            -Path $LinkPath `
            -Target $Link.Target | Out-Null

        Write-Host "[OK] $($Link.Name)" -ForegroundColor Green

    }
    catch {

      Write-Host ""
      Write-Host "===================================" -ForegroundColor Red
      Write-Host "FAILED : $($Link.Name)" -ForegroundColor Red
      Write-Host "===================================" -ForegroundColor Red

      Write-Host $_ | Format-List * -Force

  }

}

# Pause

Write-Host ""
Write-Host "=========================================" -ForegroundColor Cyan
Write-Host " Script finished." -ForegroundColor Green
Write-Host " Press ENTER to close this window..."
Write-Host "=========================================" -ForegroundColor Cyan

Read-Host


#* Run like this

# @echo off
# powershell -ExecutionPolicy Bypass -NoProfile -File "E:\Scripts\Create-Notes.ps1"
# pause

#*or this
Set-ExecutionPolicy -Scope Process Bypass; & "E:\code\F0X1M_My_Code\.vscode\script\star\createUtilsLink.ps1"

#todo: Or even Better (from project fodler)
# New-Item `
#     -ItemType Junction `
#     -Path ".\.notes\Full_Workshop" `
#     -Target "E:\code\F0X1M_My_Code"
