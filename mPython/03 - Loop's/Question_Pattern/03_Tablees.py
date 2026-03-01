
min = 1
max = 10

print(f"Table from {min} to {max}")
for i in range (min, max+1):
    print(f'Table of {i}', end="\n\n")
    for j in range (1, 11):
        print(f"{i} x {j} = {i*j}", end="\n")
    print("-------------------------" ,end="\n\n")
