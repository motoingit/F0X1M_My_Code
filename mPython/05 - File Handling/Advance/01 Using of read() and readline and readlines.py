import os

def clear_screen(): #fuction to clear the privious stuff
    os.system('cls' if os.name == 'nt' else 'clear')

clear_screen()

f = open("File1.txt","w")
f.write("Hello It's mohit singh\nHow Are You")
f.close() # if you forgot () then ouptus is unbehaviour

with open("File1.txt", "r") as file: 
    content = file.read()
    content1 = content[8]
    print(content)
    
with open("File1.txt", "r") as file: 
    content = file.readline() #it also stores \n in the content at last
    print(content)
    content = file.readline()
    print(content)

with open("File1.txt", "r") as file: # its equal to the file = open() but more clear and handles f.close automaticaly
    content = file.readlines()
    print(content)