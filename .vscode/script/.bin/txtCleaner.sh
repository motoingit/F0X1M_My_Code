#!/bin/bash

# Set your folder path here
TARGET_DIR="/mnt/c/Users/mohit/OneDrive/Documents/02 CODE FILE'S"

# Check if the directory exists
if [[ ! -d "$TARGET_DIR" ]]; then
    echo "Folder does not exist: $TARGET_DIR"
    read -r -p "Press Enter to exit..."
    exit 1
fi

echo "Searching and deleting all .txt files in:"
echo "$TARGET_DIR"
echo

# Delete all .txt files in target folder and subfolders
find "$TARGET_DIR" -type f -name "*.txt" | while read -r file; do
    echo "Deleting: \"$file\""
    rm -f "$file"
done

echo
echo "All .txt files deleted successfully."
read -r -p "Press Enter to exit..."
