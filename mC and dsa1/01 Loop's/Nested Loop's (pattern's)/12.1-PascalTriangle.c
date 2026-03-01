#include <stdio.h>

int main() {
    int n = 5;  // Number of rows
    int c;  

    for (int i = 0; i < n; i++) {
        // Print spaces for formatting
        for (int s = 1; s < n - i; s++) {
            printf(" ");
        }

        // Compute Pascal Triangle values
        for (int j = 0; j <= i; j++) {
            if (i == 0 || j == 0)
                c = 1;
            else
                c = (c * (i - j + 1)) / j;  

            printf("%d ", c);
        }
        printf("\n");
    }

    return 0;
}
