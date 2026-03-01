#include <stdio.h>
int main(){
    int M[4][4];
    int i, j;
    int flag0 = 0, flag1 = 0;

    printf("Enter the elements of the 4x4 matrix row-wise: ");
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            scanf("%d", &M[i][j]);

            if (i == j && M[i][j] != 1)
                flag1 = 1;
            if (i != j && M[i][j] != 0)
                flag0 = 1;
        }
    }
    
    if (flag1 == 1 || flag0 == 1) {
        printf("The matrix is NOT an identity matrix.\n");
    } else {
        printf("The matrix is an identity matrix.\n");
    }

    return 0;
}