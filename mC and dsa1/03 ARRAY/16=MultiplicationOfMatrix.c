#include <stdio.h>

int main() {
    int n;

    // Input the order of the matrices
    printf("Enter the order of the matrices (n): ");
    scanf("%d", &n);

    int A[n][n], B[n][n], C[n][n];
    int i, j, k;

    // Input elements of matrix A
    printf("\nEnter the elements of matrix A row-wise:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("Enter element A[%d][%d]: ", i, j);
            scanf("%d", &A[i][j]);
        }
    }

    // Input elements of matrix B
    printf("\nEnter the elements of matrix B row-wise:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("Enter element B[%d][%d]: ", i, j);
            scanf("%d", &B[i][j]);
        }
    }

    // Initialize matrix C to 0
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            C[i][j] = 0;
        }
    }

    // Perform matrix multiplication
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            for (k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    // Display the resulting matrix C
    printf("\nMatrix A x B:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d\t", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}