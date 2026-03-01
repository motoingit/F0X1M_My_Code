# upperce case count / lowercase count / sace
def vovel(sentence):
    u,l,s = 0,0,0
    for c in sentence:
        if c.isupper():
            u += 1
        elif c.islower():
            l += 1
        elif c == ' ':
            s += 1
    return u,l,s
      
name = 'Graphic Era Hill University'
data1,data2,data3 = vovel(name) # mulltiple return
data = vovel(name) # tuple hai ye

print(data1,data2,data3)
print(data[0],data[1],data[2])
print(data)

'''
4 20 3
4 20 3
(4, 20, 3)
'''