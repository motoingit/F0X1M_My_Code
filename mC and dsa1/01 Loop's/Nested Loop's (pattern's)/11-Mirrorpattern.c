#include <stdio.h>
int main(){
    int n;
    printf("Enter the no of rows : ");
    scanf("%d", &n); 

    int i, s, j;
    for(i = 1; i <= n; i++){  
        for(j = 1; j <= i; j++)
            printf("%d ",j);
        for(s = 2*(n-i)*2 + 2; s > 0; s -=2)  // Print spaces
            printf("  ");
        for(j--;j > 0; j--) // Print stars
            printf("%d ",j);

        printf("\n"); // Move to the next line after a row
    }

    return 0;
}
