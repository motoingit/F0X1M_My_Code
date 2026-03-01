import string # its basicall ythe librari in py

special_count = 0
special_chars = set(string.punctuation)  # string.pu.... is sting contain ["!@#$%^&*()_+-=[]{}|;:'\",.<>/?`~"]
                                         #set is used to do the faster comartision it makes from set("abc") becomes {'a', 'b', 'c'} 
with open("File.txt", "r") as file:
    while True:
        char = file.read(1)
        if not char:
            break
        if char in special_chars:
            special_count += 1
            print(f"Special character found: {char}")

print("Total special characters:", special_count)

# import string # its basicall ythe librari in py

# special_count = 0
# special_chars = '.@!'  # string.pu.... is sting contain ["!@#$%^&*()_+-=[]{}|;:'\",.<>/?`~"]
#                                          #set is used to do the faster comartision it makes from set("abc") becomes {'a', 'b', 'c'} 
# with open("File.txt", "r") as file:
#     while True:
#         char = file.read(1)
#         if not char:
#             break
#         if char in special_chars:
#             special_count += 1
#             print(f"Special character found: {char}")

# print("Total special characters:", special_count)