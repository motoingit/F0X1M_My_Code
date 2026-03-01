import os
folders= os.listdir("data")
print("folder")
print('\n')

for folder in folders:
    print(os.listdir(f"data/{folder}")) # sub folder