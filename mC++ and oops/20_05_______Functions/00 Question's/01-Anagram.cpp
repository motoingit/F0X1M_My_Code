#include <stdio.h>
#include <string.h>

int main() {
    int n;
    
    // Read the size of character arrays
    scanf("%d", &n);
    
    // Declare character arrays
    char str1[n+1], str2[n+1];
    
    // Read first string
    scanf("%s", str1);
    
    // Read second string  
    scanf("%s", str2);
    
    // Frequency arrays to count occurrences of each letter
    int freq1[26] = {0}; // for string 1
    int freq2[26] = {0}; // for string 2
    
    // Count frequency of each character in first string
    for(int i = 0; i < strlen(str1); i++) {
        freq1[str1[i] - 'A']++;
    }
    
    // Count frequency of each character in second string
    for(int i = 0; i < strlen(str2); i++) {
        freq2[str2[i] - 'A']++;
    }
    
    // Compare frequency arrays
    int isAnagram = 1; // assume they are anagrams
    for(int i = 0; i < 26; i++) {
        if(freq1[i] != freq2[i]) {
            isAnagram = 0; // not anagrams
            break;
        }
    }
    
    // Output result
    printf("%d\n", isAnagram);
    
    return 0;
}