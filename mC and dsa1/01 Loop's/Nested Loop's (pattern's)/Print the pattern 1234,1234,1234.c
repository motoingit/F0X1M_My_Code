// Wap in c to print the following pattern
// 1 2 3 4...n
// 1 2 3 4...n
// 1 2 3 4...n
// 1 2 3 4...n

#include <stdio.h>
int main(){
    int n;
    printf("Enter the number of rows : ");
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            printf(" %d ",j);
        printf("\n");
    }
    return 0;
}

// Output:
// Enter the number of rows : 4
// 1234
// 1234
// 1234
// 1234