
f = open("File1.txt","w")
f.write("Hellow Its mohit singh\nHow Are You")
f.close

with open("File.txt", "r") as file:
    content = file.readlines()  # no of \n used
    length = len(content)
    print(length)