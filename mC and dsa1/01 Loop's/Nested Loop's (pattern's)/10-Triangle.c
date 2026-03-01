#include <stdio.h>
int main(){
    int n;
    printf("Enter the no of rows : ");
    scanf("%d", &n); 

    int i, s, p;
    for(i = 0; i < n; i++){  
        for(s = 0 ; s < n - i - 1; s++)  // Print spaces
            printf(" ");

        for(p = 0; p < 2 * i + 1; p++) // Print stars
            printf("*");

        printf("\n"); // Move to the next line after a row
    }

    return 0;
}
