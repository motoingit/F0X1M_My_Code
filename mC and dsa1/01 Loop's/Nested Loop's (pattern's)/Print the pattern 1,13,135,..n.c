// Wap to print the following pattern 
// 1
// 1 3
// 1 3 5

// .....n

#include <stdio.h>
int main(){
    int n;
    printf("Enter the number of rows : ");
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i*2;j++){
            if(j%2!=0)
                printf(" %d ",j);
        }
        printf("\n");
    }
    return 0;
}

// Output:
// Enter the number of rows : 5
//  1
//  1  3
//  1  3  5
//  1  3  5  7
//  1  3  5  7  9









/*
alternatively

1>
#include <stdio.h>
int main(){
    int n;
    printf("Enter the number of rows : ");
    scanf("%d",&n);
    for(int i=1;i<=n*2;i++){
        for(int j=1; j<= i ;j++){
            if(i%2!=0)
                continue;
            if(j%2!=0)
                printf(" %d ",j);
        }
        printf("\n");                
    }
    return 0;
}




2>
#include <stdio.h>
int main(){
    int n;
    printf("Enter the number of rows : ");
    scanf("%d",&n);
    for(int i=1;i<=n*2;i++){
        for(int j=1; j<= i ;j++){
            if(i%2!=0)
                continue;
            if(j%2!=0)
                printf(" %d ",j);
        }
        printf("\n");                
    }
    return 0;
}
*/