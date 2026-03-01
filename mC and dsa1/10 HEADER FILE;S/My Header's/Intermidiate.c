#include <stdio.h>
#include "mylove.h" //if the header file is on the same directory
int main(){
    int n;
    printf("Enter the order of Square matrix :");
    scanf("%d",&n);
    int arr[n][n];

    in(&arr[0][0],n);
    out(&arr[0][0],n);
       

return 0;}
