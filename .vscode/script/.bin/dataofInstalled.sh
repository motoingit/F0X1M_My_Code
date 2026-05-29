#!/bin/bash

# ============================================================
#   installedApp.sh  —  Git Bash on Windows 11
#   No PowerShell needed — uses reg.exe only
# ============================================================

OUTPUT="$(cd "$USERPROFILE" && pwd)/Desktop/my_installed_apps_$(date +%Y-%m-%d_%H-%M).txt"

EXCLUDE=(
    "Microsoft" "Windows" "Xbox" "Visual C++" ".NET"
    "Redistributable" "Runtime" "DirectX" "WebView2"
    "Update" "Driver" "OneDrive" "Edge" "Skype"
    "Intel" "NVIDIA" "Realtek" "AMD " "Vulkan"
    "Dell " "HP Inc" "Lenovo" "Synaptics" "Qualcomm"
    "WDF" "Hotfix" "WIC" "Connection Manager"
)

should_exclude() {
    local str="$1 $2"
    for kw in "${EXCLUDE[@]}"; do
        [[ "$str" == *"$kw"* ]] && return 0
    done
    return 1
}

# Parse a named value from a pre-fetched reg.exe output block
parse_val() {
    echo "$1" | grep -i "^    $2 " | grep -i "REG_SZ" | sed 's/.*REG_SZ[[:space:]]*//' | head -1
}

echo "🔍 Scanning registry... please wait."

TMPFILE=$(mktemp /tmp/apps_XXXXXX.txt)

REG_PATHS=(
    "HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Uninstall"
    "HKEY_LOCAL_MACHINE\\SOFTWARE\\Wow6432Node\\Microsoft\\Windows\\CurrentVersion\\Uninstall"
    "HKEY_CURRENT_USER\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Uninstall"
)

for reg_path in "${REG_PATHS[@]}"; do
    parent_depth=$(echo "$reg_path" | tr -cd '\\' | wc -c)
    expected_depth=$(( parent_depth + 1 ))

    KEYS_TMP=$(mktemp /tmp/keys_XXXXXX.txt)
    reg.exe query "$reg_path" 2>/dev/null | tr -d '\r' | grep -v '^$' > "$KEYS_TMP"

    while IFS= read -r subkey; do
        depth=$(echo "$subkey" | tr -cd '\\' | wc -c)
        [[ "$depth" -ne "$expected_depth" ]] && continue

        # Query entire key at once — /v flag is broken in Git Bash
        raw=$(reg.exe query "$subkey" 2>/dev/null | tr -d '\r')
        [[ -z "$raw" ]] && continue

        name=$(parse_val "$raw" "DisplayName")
        [[ -z "$name" ]] && continue

        pub=$(parse_val "$raw" "Publisher")
        should_exclude "$name" "$pub" && continue

        grep -qF "NAME=$name|" "$TMPFILE" 2>/dev/null && continue

        ver=$(parse_val   "$raw" "DisplayVersion")
        idate=$(parse_val "$raw" "InstallDate")
        loc=$(parse_val   "$raw" "InstallLocation")

        [[ "$idate" =~ ^[0-9]{8}$ ]] && idate="${idate:0:4}-${idate:4:2}-${idate:6:2}"
        [[ -z "$ver" ]]   && ver="N/A"
        [[ -z "$pub" ]]   && pub="Unknown"
        [[ -z "$idate" ]] && idate="Unknown"
        [[ -z "$loc" ]]   && loc="N/A"

        echo "NAME=$name|VER=$ver|PUB=$pub|DATE=$idate|LOC=$loc" >> "$TMPFILE"
        echo "  + Found: $name"

    done < "$KEYS_TMP"
    rm -f "$KEYS_TMP"
done

SORTED_TMP=$(mktemp /tmp/sorted_XXXXXX.txt)
sort -f "$TMPFILE" > "$SORTED_TMP"
total=$(grep -c '.' "$SORTED_TMP" || echo 0)

SEP="======================================================================"
{
echo "$SEP"
echo "   MY INSTALLED APPS — Windows 11"
echo "   Generated : $(date '+%A, %B %d %Y  %H:%M:%S')"
echo "   Computer  : $COMPUTERNAME"
echo "   User      : $USERNAME"
echo "$SEP"
echo ""
echo "$SEP"
printf "  INSTALLED APPS  (%d found)\n" "$total"
echo "$SEP"
echo ""

i=1
while IFS= read -r entry; do
    [[ -z "$entry" ]] && continue
    n=$(echo "$entry" | sed 's/NAME=\([^|]*\).*/\1/')
    v=$(echo "$entry" | sed 's/.*|VER=\([^|]*\).*/\1/')
    p=$(echo "$entry" | sed 's/.*|PUB=\([^|]*\).*/\1/')
    d=$(echo "$entry" | sed 's/.*|DATE=\([^|]*\).*/\1/')
    l=$(echo "$entry" | sed 's/.*|LOC=\(.*\)/\1/')
    printf "  [%d] %s\n"        "$i" "$n"
    printf "       %-16s: %s\n" "Version"      "$v"
    printf "       %-16s: %s\n" "Publisher"    "$p"
    printf "       %-16s: %s\n" "Install Date" "$d"
    printf "       %-16s: %s\n" "Location"     "$l"
    echo ""
    (( i++ ))
done < "$SORTED_TMP"

echo "$SEP"
printf "  TOTAL: %d apps  |  End of Report — %s\n" "$total" "$(date '+%H:%M:%S')"
echo "$SEP"
} > "$OUTPUT"

rm -f "$TMPFILE" "$SORTED_TMP"

echo ""
echo "✅  Done! Report saved to:"
echo "    $OUTPUT"
echo "    Total apps found: $total"
echo ""
