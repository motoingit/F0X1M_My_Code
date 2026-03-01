message = 'hello World'
print(message)
print(message.replace('World','Buddy')) #here I see that on finding no world like 'world' it doest give some type of error
print(message) # as assignation is not done so replace doest affect the real value 
message = message.replace('World','Buddy')
print(message)