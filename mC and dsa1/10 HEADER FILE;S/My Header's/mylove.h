#include <stdio.h>
// Function to take input for a matrix
void in(int *p, int n){
    int i, j;
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            printf("Enter the [%d][%d] Element : ", i + 1, j + 1);
            scanf("%d", (p + i*n + j));
        }
    }
}
