
// Wap to print the following pattern 
// .....n
// .....n-1
//
// *
#include <stdio.h>
int main(){
    int n;
    printf("Enter the number of rows : ");
    scanf("%d",&n);
    for(int i=1; i<=n; i++){
        for(int j=1; j<= (n - i + 1); j++){
            printf(" * ");
        }
        printf("\n");
    }
    return 0;
}
// Output:
// Enter the number of rows : 5
//  *  *  *  *  *
//  *  *  *  *
//  *  *  *
//  *  *
//  *
