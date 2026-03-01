//wap in c to print the inverse odd triangle pattern
#include <stdio.h>
int main(){
    int n;
    printf("Enter the number of rows : ");
    scanf("%d",&n);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= (n-i+1)*2; j++){
            if(j%2!=0)
                printf(" %d ",j);
        }  
        printf("\n"); 
    }
    return 0;
}

// Output:
// Enter the number of rows : 5
// 1 3 5 7 9
// 1 3 5 7
// 1 3 5
// 1 3
// 1 









/*
Alternatively

#include <stdio.h>
int main(){
    int n;
    printf("Enter the number of rows : ");
    scanf("%d",&n);
    for(int i = 1; i <= n; i++){
        int a = 1;
        for(int j = 1; j <= i; j++){
            printf(" %d ",a);
            a = a + 2;
        }   
        printf("\n");
    }
    return 0;
}
*/