import os
from PIL import Image, ImageOps

def permanent_rotate_and_clean(folder_path):
    valid_extensions = ('.jpg', '.jpeg', '.png', '.webp', '.tiff')
    
    if not os.path.exists(folder_path):
        print(f"Error: The folder '{folder_path}' does not exist.")
        return

    print(f"Fixing orientation and stripping metadata in: {folder_path}\n" + "-"*40)
    
    success_count = 0
    error_count = 0

    for filename in os.listdir(folder_path):
        if filename.lower().endswith(valid_extensions):
            file_path = os.path.join(folder_path, filename)
            
            try:
                # 1. Open original image
                img = Image.open(file_path)
                img_format = img.format
                
                # 2. Read the EXIF orientation and physically rotate the pixels upright
                img_upright = ImageOps.exif_transpose(img)
                
                # 3. Strip metadata by copying only raw pixel data into a brand new image
                if hasattr(img_upright, 'get_flattened_data'):
                    data = list(img_upright.get_flattened_data())
                else:
                    data = list(img_upright.getdata())
                    
                clean_img = Image.new(img_upright.mode, img_upright.size)
                clean_img.putdata(data)
                
                # Close original file pointer before overwriting
                img.close()
                
                # 4. Overwrite original file
                clean_img.save(file_path, format=img_format)
                
                print(f"✓ Fixed & Cleared: {filename}")
                success_count += 1
                
            except Exception as e:
                print(f"✗ Failed to process {filename}. Error: {e}")
                error_count += 1

    print("-"*40)
    print(f"Done! Successfully fixed {success_count} images.")

if __name__ == "__main__":
    # Your target folder path
    target_folder = r"C:\Users\mohit\My Drive\101 Do not Delete Folder's @@\Rent\Room"
    
    permanent_rotate_and_clean(target_folder)
