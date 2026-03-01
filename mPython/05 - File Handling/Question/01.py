# Write to the file
f = open("File.txt", "w")
f.write(".hel.no\n.flow.")
f.close()  # Use parentheses to close the file

# Count the number of '.' characters
ch = 0
with open("File.txt", "r") as file:
    while True:
        char = file.read(1)  # Read one character
        if not char:         # End of file
            break
        if char == '.':
            ch += 1
        print(char, end='')  # Print each character
print("\nNumber of '.' characters:", ch)

# Use the paranthysis to make the south the dessert for the the now the 