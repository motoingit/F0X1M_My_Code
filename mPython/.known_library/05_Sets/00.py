# Set is un-ordered and has represented with the {curlybraces}

s = {1,2,3,4,4,0} # only unique element stored and ignore if duplicates
print(s)

n = {4,5,0,1,3,6}

# intersecction will only include the commn elements n both but the union will only get all elemnts 
print(s.union(n))
print(s.intersection(n))


#! set element is imutable but not as a whole


# Initial set
s = {1, 2, 3, 4}
print("Original set:", s)

# add()
s.add(5)
print("After add:", s)

# remove()
s.remove(2) #! error if not present
print("After remove:", s)

# discard()
s.discard(10)   # no error if element not found
print("After discard:", s)

# pop()
s.pop()
print("After pop:", s)

# copy()
s2 = s.copy()
print("Copied set:", s2)

# clear()
s2.clear()
print("After clear:", s2)
