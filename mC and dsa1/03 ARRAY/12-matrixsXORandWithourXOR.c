//program 01 : write a c program to read two square binary matrices of order n*n 
//and perform the xor on the elements of the matrices and print the resultant matrix on the output.

/////////////////mycode///////////////////
#include <stdio.h>
int main(){
    int n;
    printf("Enter the order of the matrix: ");
    scanf("%d",&n);
    int a[n][n],b[n][n],c[n][n];
    printf("Enter the elements of the matrix A :");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            scanf("%d",&a[i][j]);
    }
    printf("Enter the elements of the matrix B :");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            scanf("%d",&b[i][j]);
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) {       // 1 + 0 = 1 and 0 + 0 = 0 so we can use xor operation
            if(b[i][j]==a[i][j])          //just put the line instead of these
                c[i][j] = 0;             //  
            else                         //     c[i][j] = a[i][j] ^ b[i][j];  //xor operation
                c[i][j] = 1;             //
        }                               //
     }
    printf("Elements of the matrix C : \n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            printf(" %d ",c[i][j]);
        printf("\n");
    }
    return 0;
}
// Input: Enter the order of the matrix: 2
//        Enter the elements of the matrix A : 1 0 1 0
//        Enter the elements of the matrix B : 0 1 0 1
// Output: Elements of the matrix C : 
//         1 1 
//         1 1