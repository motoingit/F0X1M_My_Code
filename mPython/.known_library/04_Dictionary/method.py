sample_Person = {
    'name1' : "Mohit",
    'name2' : "Mohit",
    'name3' : "Mohit",
    'name4' : "Mohit",
}

#keys() return all values
print(sample_Person.keys())

#values()
print(sample_Person.values())

# items()
print(sample_Person.items())

#Acessing 
x1 = sample_Person['name1']
x2 = sample_Person.get('name2') # name or Not Found

print(x1, x2)

sample_Person["name5"] = "Mohit"


#removing
sample_Person.pop("name1")
sample_Person.popitem() # revoes the last inserted element

sample_Person.clear() # clear everyting

#! this will crash if not present 
del sample_Person["name3"]


#* get()
print("Using get():", sample_Person.get("name"))

#* update() method
sample_Person.update({"age": 21})
print("\nAfter update:", student)
