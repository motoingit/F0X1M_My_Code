with open("File1.txt", "x") as file:
    print('Creating File.1.txt')

with open("File1.txt", "w") as file: # rt == t (default) (read text)
    file.write('No one')

with open("File1.txt", "r") as file:
    content = file.read()
    print(content)

with open("File1.txt", "a") as file:
    file.write('\nIs ever')

with open("File1.txt", "rb") as file: # rb is for reading bin file
    binary_data = file.read()
    print(type(binary_data)) # to find the variable type or class