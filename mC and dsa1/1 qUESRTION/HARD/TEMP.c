#include <stdio.h>

void genBinary(char *s, int i, int N) {
    // Base case: if we've filled all positions
    if (i == N) {
        // Null terminate the string and print it
        s[i] = '\0';
        printf("%s\n", s);
        return;
    }
    
    // First, try placing '0' at position i
    s[i] = '0';
    genBinary(s, i + 1, N);
    
    // Then, try placing '1' at position i
    s[i] = '1';
    genBinary(s, i + 1, N);
}

int main() {
    int N;
    scanf("%d", &N);
    
    // Create a character array to store the binary string
    // Size N+1 to accommodate null terminator
    char binaryString[N + 1];
    
    // Start the recursive generation
    genBinary(binaryString, 0, N);
    
    return 0;
}