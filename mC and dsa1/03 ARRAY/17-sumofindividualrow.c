#include <stdio.h>
int main(){
    int r,c;
    printf("Enter the No of rows and column : ");
    scanf("%d %d",&r,&c);

    int i,j;
    int arr[r][c];
    for(i = 0; i < r; i++){
        for(j = 0; j < c; j++){
            printf("Enter the [%d][%d] elemnte :",i+1,j+1);
            scanf("%d",&arr[i][j]);
        }
    }

    int sum = 0;
    for(i = 0; i < r; i++){
        for(j = 0; j < c; j++){
            sum += arr[i][j]; 
        }
        printf("Sum of %d row is %d\n",i+1,sum);
        sum = 0;
    }
    
return 0;}