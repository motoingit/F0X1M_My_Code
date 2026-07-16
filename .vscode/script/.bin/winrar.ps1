# ===========================================================================
#  WinRAR / 7-Zip Backup Script
#  Author : Mohit
#  Version: 1.0
# ===========================================================================

# ---------------------------------------------------------------------------
# CONFIGURATION SECTION
# ---------------------------------------------------------------------------

# Path to 7-Zip executable
$SevenZip = "C:\Program Files\7-Zip\7z.exe"

# Backup destination folder
$BackupDestination = "D:\Backups"

# Archive file name (date/time stamp will be appended automatically)
$ArchiveName = "ProjectsBackup"

# Compression level:
#   0 = Store (no compression)
#   1 = Fastest
#   5 = Normal
#   7 = Maximum
#   9 = Ultra
$CompressionLevel = 5

# ---------------------------------------------------------------------------
# SOURCE FOLDERS
# Add as many folders as you want inside the @( ... ) block
# ---------------------------------------------------------------------------

$SourceFolders = @(
    "E:\GIT-HUB",
    "E:\JavaProjects",
    "E:\Documents"
)

# ---------------------------------------------------------------------------
# FOLDERS TO EXCLUDE
# These folder names are excluded recursively from every source path
# ---------------------------------------------------------------------------

$ExcludeFolders = @(
    "node_modules",
    ".next",
    "dist",
    "build",
    ".git",
    ".cache",
    ".gradle",
    "target",
    "coverage",
    ".pnpm-store",
    ".turbo",
    ".nuxt",
    ".svelte-kit"
)

# ---------------------------------------------------------------------------
# CREATE BACKUP FOLDER IF IT DOES NOT EXIST
# ---------------------------------------------------------------------------

if (!(Test-Path $BackupDestination)) {
    New-Item -ItemType Directory -Path $BackupDestination | Out-Null
    Write-Host "Created backup folder: $BackupDestination" -ForegroundColor Yellow
}

# ---------------------------------------------------------------------------
# GENERATE ARCHIVE NAME WITH DATE/TIME STAMP
# ---------------------------------------------------------------------------

$DateStamp   = Get-Date -Format "yyyy-MM-dd_HH-mm-ss"
$ArchivePath = Join-Path $BackupDestination "$ArchiveName-$DateStamp.7z"

# ---------------------------------------------------------------------------
# BUILD 7-ZIP ARGUMENT LIST
# ---------------------------------------------------------------------------

$Arguments = @()

# Add command  (a = add/create archive)
$Arguments += "a"

# Add archive output path
$Arguments += $ArchivePath

# Add all source folders
$Arguments += $SourceFolders

# Add exclusion rules (recursive wildcard)
foreach ($Folder in $ExcludeFolders) {
    $Arguments += "-xr!$Folder"
}

# Set compression level
$Arguments += "-mx=$CompressionLevel"

# ---------------------------------------------------------------------------
# START BACKUP
# ---------------------------------------------------------------------------

Write-Host ""
Write-Host "===================================" -ForegroundColor Cyan
Write-Host "        Starting Backup ...        " -ForegroundColor Green
Write-Host "===================================" -ForegroundColor Cyan
Write-Host ""
Write-Host "  Archive : $ArchivePath"
Write-Host "  Sources : $($SourceFolders -join ', ')"
Write-Host "  Level   : $CompressionLevel"
Write-Host ""

# Execute 7-Zip
& $SevenZip @Arguments
$ExitCode = $LASTEXITCODE

# ---------------------------------------------------------------------------
# RESULT
# ---------------------------------------------------------------------------

Write-Host ""

if ($ExitCode -eq 0) {
    Write-Host "===================================" -ForegroundColor Cyan
    Write-Host "   Backup Completed Successfully!  " -ForegroundColor Green
    Write-Host "===================================" -ForegroundColor Cyan
} else {
    Write-Host "===================================" -ForegroundColor Red
    Write-Host "  Backup finished with errors!     " -ForegroundColor Red
    Write-Host "  7-Zip exit code: $ExitCode        " -ForegroundColor Red
    Write-Host "===================================" -ForegroundColor Red
}

Write-Host ""
