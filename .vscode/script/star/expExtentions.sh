#! /bin/bash
#? CMD: { wsl bash "/mnt/e/My_Code/.vscode/script/export-Extentions.sh" }

VSCODE_DIR="/mnt/e/My_Code/.vscode"

# Create .vscode folder if missing
mkdir -p "$VSCODE_DIR"
# Get list of installed extensions
mapfile -t extensions < <(code --list-extensions)

# Build JSON with each extension on its own line
{
  echo '{'
  echo '  "recommendations": ['
  for i in "${!extensions[@]}"; do
    if [[ $i -lt $((${#extensions[@]} - 1)) ]]; then
      echo "    \"${extensions[$i]}\","
    else
      echo "    \"${extensions[$i]}\""  # no trailing comma on last
    fi
  done
  echo '  ]'
  echo '}'
} > "$VSCODE_DIR/extensionsBackUp.json"

echo "✅ Saved ${#extensions[@]} extensions to .vscode/extensions.json"
