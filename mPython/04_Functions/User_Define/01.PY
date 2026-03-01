def countVowel(message):
    vowel = 'AEIOUaeiou'
    count = 0
    for c in message: 
        if vowel.find(c) == -1:
            continue
        else:
            count += 1
    return count
        
message = 'aeiou'
res = countVowel(message)
print('The Count of vovel is ',res)
    


