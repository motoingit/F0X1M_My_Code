// Wap in c to print the pattern of rectangle using nested loop's

#include <stdio.h>
int main(){
    int i,j,r,c;
    printf("Enter the number of rows and columns: ");
    scanf("%d %d",&r,&c); //row = no of lines.. column = no of stars in each line
    for(i=1;i<=r;i++){
        for(j=1;j<=c;j++){
            printf("*");
        }
        printf("\n");
    }
    return 0;
}

// Output:
// Enter the number of rows and columns: 4 5
// *****
// *****
// *****
// ***** 