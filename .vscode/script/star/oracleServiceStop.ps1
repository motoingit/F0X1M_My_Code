# ==========================================
# Oracle Service Manager
# ==========================================

# ---------- Run as Administrator ----------
$currentUser = New-Object Security.Principal.WindowsPrincipal(
    [Security.Principal.WindowsIdentity]::GetCurrent()
)

if (-not $currentUser.IsInRole([Security.Principal.WindowsBuiltInRole]::Administrator)) {
    Start-Process powershell.exe `
        -ArgumentList "-ExecutionPolicy Bypass -File `"$PSCommandPath`"" `
        -Verb RunAs
    exit
}

# ---------- Services ----------
$OracleServices = @(
    "OracleJobSchedulerXE"
    "OracleOraDB21Home1MTSRecoveryService"
    "OracleOraDB21Home1TNSListener"
    "OracleServiceXE"
    "OracleVssWriterXE"
)

# ---------- Start ----------
function Start-OracleServices {

    Write-Host ""
    Write-Host "========== Starting Oracle Services ==========" -ForegroundColor Cyan
    Write-Host ""

    foreach ($service in $OracleServices) {

        try {
            $svc = Get-Service -Name $service -ErrorAction Stop

            if ($svc.Status -eq "Running") {
                Write-Host "[SKIP] $service is already running." -ForegroundColor Yellow
            }
            else {
                Write-Host "[START] $service" -ForegroundColor Cyan
                Start-Service -Name $service -ErrorAction Stop
                Write-Host "[ OK ] Started." -ForegroundColor Green
            }
        }
        catch {
            Write-Host "[FAIL] $service" -ForegroundColor Red
            Write-Host $_.Exception.Message -ForegroundColor DarkRed
        }
    }
}

# ---------- Stop ----------
function Stop-OracleServices {

    Write-Host ""
    Write-Host "========== Stopping Oracle Services ==========" -ForegroundColor Cyan
    Write-Host ""

    $StopOrder = @(
        "OracleServiceXE"
        "OracleOraDB21Home1MTSRecoveryService"
        "OracleOraDB21Home1TNSListener"
        "OracleJobSchedulerXE"
        "OracleVssWriterXE"
    )

    foreach ($service in $StopOrder) {

        try {
            $svc = Get-Service -Name $service -ErrorAction Stop

            if ($svc.Status -eq "Stopped") {
                Write-Host "[SKIP] $service is already stopped." -ForegroundColor Yellow
            }
            else {
                Write-Host "[STOP ] $service" -ForegroundColor Cyan
                Stop-Service -Name $service -Force -ErrorAction Stop
                Write-Host "[ OK ] Stopped." -ForegroundColor Green
            }
        }
        catch {
            Write-Host "[FAIL] $service" -ForegroundColor Red
            Write-Host $_.Exception.Message -ForegroundColor DarkRed
        }
    }
}

# ---------- Status ----------
function Show-OracleStatus {

    Write-Host ""
    Write-Host "=============== Oracle Services ===============" -ForegroundColor Cyan
    Write-Host ""

    foreach ($service in $OracleServices) {

        try {

            $svc = Get-Service $service

            switch ($svc.Status) {

                "Running" {
                    Write-Host ("{0,-45} Running" -f $svc.Name) -ForegroundColor Green
                }

                "Stopped" {
                    Write-Host ("{0,-45} Stopped" -f $svc.Name) -ForegroundColor Red
                }

                default {
                    Write-Host ("{0,-45} {1}" -f $svc.Name,$svc.Status) -ForegroundColor Yellow
                }
            }

        }
        catch {
            Write-Host ("{0,-45} Not Found" -f $service) -ForegroundColor DarkGray
        }
    }

    Write-Host ""
}

# ---------- Menu ----------
while ($true) {

    Clear-Host

    Write-Host "==========================================" -ForegroundColor Cyan
    Write-Host "       Oracle Service Manager"
    Write-Host "==========================================" -ForegroundColor Cyan
    Write-Host ""
    Write-Host "[1] Start Oracle Services"
    Write-Host "[0] Stop Oracle Services"
    Write-Host "[2] Show Status"
    Write-Host "[9] Exit"
    Write-Host ""

    $choice = Read-Host "Select option"

    switch ($choice) {

        "1" {
            Start-OracleServices
            Read-Host "`nPress Enter to continue"
        }

        "0" {
            Stop-OracleServices
            Read-Host "`nPress Enter to continue"
        }

        "2" {
            Show-OracleStatus
            Read-Host "`nPress Enter to continue"
        }

        "9" {
            break
        }

        default {
            Write-Host "`nInvalid option." -ForegroundColor Red
            Read-Host "Press Enter to continue"
        }
    }
}