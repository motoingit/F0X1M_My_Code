

# cd "E:\My_Code\.vscode\extentionRestore"; if ($?) { powershell -ExecutionPolicy ByPass -File export-extensions.ps1 };


# Create .vscode folder if missing
New-Item -ItemType Directory -Force -Path "E:\My_Code\.vscode" | Out-Null

#* ["esbenp.prettier-vscode", "dbaeumer.vscode-eslint", ...]
$extensions = code.cmd --list-extensions

$json = @{ recommendations = $extensions } | ConvertTo-Json -Depth 3

Set-Content -Path "E:\My_Code\.vscode\extensions.json" -Value $json
Write-Host "✅ Saved $($extensions.Count) extensions to .vscode/extensions.json"


