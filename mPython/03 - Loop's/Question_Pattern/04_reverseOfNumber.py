

#todo: Unable to do :  easy
# num = 102344
# strMy = str(num)
# print(strMy.)

# j = len(strMy) - 1
# while 0 <= j:
#     print(str[j], end=" ")


# BASIC : aproach

num = 10234
numTemp = num
i = 1
while numTemp > 0: # should run 5 times
    numTemp = numTemp//10 #todo: / for float is a fatal blow
    # print("%d")
    print(numTemp)
    i+=1

print(i-1)
i = i-1

while numTemp > 0:
    print(num%)
