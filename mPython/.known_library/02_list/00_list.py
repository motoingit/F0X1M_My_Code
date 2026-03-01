
myList1 = [10,20,30]
myList2 = [10,20,10]
myList = [10,20,30]

flag = True
st, end = 0, len(myList1) - 1
while st < end :
    if( myList[st] != myList[end]):
        flag = False
        break

if flag == False :
    print('Palindrome is not')
else :
    print('Palindrome is not')


# fuction
if myList == list(reversed(myList)) :
    print('Palindrome')
else :
    print("not")
