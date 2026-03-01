#include <stdio.h>

// Function to calculate factorial
long long fact(int num) {
    long long factorial = 1;
    for (int i = 1; i <= num; i++) {
        factorial *= i;
    }
    return factorial;
}

// Function to print Pascal's Triangle with spacing
void pascalTriangle(int n) {
    for (int i = 0; i < n; i++) {
        // Print spaces for formatting
        for (int s = 0; s < n - i; s++) {
            printf("  ");  // Two spaces for better alignment
        }
        
        // Compute and print Pascal Triangle values
        for (int j = 0; j <= i; j++) {
            printf("%4lld ", fact(i) / (fact(j) * fact(i - j))); 
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter number of rows: ");
    scanf("%d", &n);
    pascalTriangle(n);
    return 0;
}
