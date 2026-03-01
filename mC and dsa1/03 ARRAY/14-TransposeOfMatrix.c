#include <stdio.h>
int main(){
    int M[4][4],T[4][4];
    int i, j;

    printf("Enter the elements of the 4x4 matrix row-wise: ");
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++)
            scanf("%d", &M[i][j]);
    }
    
    printf("Transpose is :\n");
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++){
            T[i][j] = M[j][i];
            printf(" %d ",T[i][j]);
        }
        printf("\n");
    }

    return 0;
}