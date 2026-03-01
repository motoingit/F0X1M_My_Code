// Input 3x3 matrix in main and print the matrix elements by sending the base location for the arr and input the brr to arr
#include <stdio.h>

void x(int *p, int *q) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            *(q + i * 3 + j) = *(p + (3 - 1 - j) * 3 + (3 - 1 - i)); 
            // &arr[i][j] = base_address + (i * total_columns + j) in 2D
            // *(q + i * 3 + j) == brr[i][j]
            // *(p + (3 - 1 - j) * 3 + (3 - 1 - i)) == arr[N-1-j][N-1-i]
        }
    }
}

int main() {
    int arr[3][3], brr[3][3];
    int a, b;

    printf("Enter the element's: ");
    for (a = 0; a < 3; a++) {
        for (b = 0; b < 3; b++)
            scanf("%d", &arr[a][b]);
    }

    int *p = &arr[0][0], *q = &brr[0][0];
    x(p, q);

    for (a = 0; a < 3; a++) {
        for (b = 0; b < 3; b++)
            printf(" %d ", brr[a][b]);
        printf("\n\n");
    }

    return 0;
}
