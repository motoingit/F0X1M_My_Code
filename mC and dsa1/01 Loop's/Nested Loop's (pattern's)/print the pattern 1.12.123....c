// Wap to print the following pattern 
// 1
// 1 2

// .....n

#include <stdio.h>
int main(){
    int n;
    printf("Enter the number of rows : ");
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            printf(" %d ",j);
        }
        printf("\n");
    }
    return 0;
}

// Output:
// Enter the number of rows : 5
//  1
//  1  2
//  1  2  3
//  1  2  3  4
//  1  2  3  4  5