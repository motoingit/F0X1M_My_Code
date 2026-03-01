import os

def rename_files(directory, add_text, position="front", extension=None, include_subfolders=False):
    """
    Rename files in a given directory by adding text at the front or end of filenames.


    Parameters:
    - directory (str): Target directory path
    - add_text (str): String to add
    - position (str): 'front' or 'end'
    - extension (str): File extension to filter (e.g., '.jpg'), default None (all files)
    - include_subfolders (bool): Process files inside subfolders too
    """


    """
    Enter directory path: ./your_folder
Enter text to add: .
Add at 'front' or 'end'? front
Filter by extension (e.g. .jpg) or leave blank for all: .jpg
Include subfolders? (y/n): n

    """
    # Choose walk method depending on user preference
    if include_subfolders:
        files = [os.path.join(root, f) for root, _, fs in os.walk(directory) for f in fs]
    else:
        files = [os.path.join(directory, f) for f in os.listdir(directory) if os.path.isfile(os.path.join(directory, f))]

    for filepath in files:
        folder, filename = os.path.split(filepath)
        name, ext = os.path.splitext(filename)

        # Skip if extension doesn’t match
        if extension and ext.lower() != extension.lower():
            continue

        if position == "front":
            new_name = f"{add_text}{name}{ext}"
        elif position == "end":
            new_name = f"{name}{add_text}{ext}"
        else:
            raise ValueError("position must be 'front' or 'end'")

        new_path = os.path.join(folder, new_name)
        os.rename(filepath, new_path)
        print(f"Renamed: {filename} → {new_name}")

    print("\n✅ Rename complete!")


if __name__ == "__main__":
    # Example usage
    dir_path = input("Enter directory path: ").strip()
    add_str = input("Enter text to add: ").strip()
    pos = input("Add at 'front' or 'end'? ").strip().lower()
    ext = input("Filter by extension (e.g. .jpg) or leave blank for all: ").strip()
    subfolders = input("Include subfolders? (y/n): ").strip().lower() == "y"

    rename_files(dir_path, add_str, pos, ext if ext else None, subfolders)
