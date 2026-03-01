#include <stdio.h>
#include "mylove.h" // this is used when the header file is on the same directory as program
#include "C:\\Users\\mohit\\OneDrive\\Documents\\02 CODES\\C\\0 Basic & calculative Program's\\myfile.h" //this is used when header file is in some loction
int main(){
    int n;
    printf("Enter the order of Square matrix :");
    scanf("%d",&n);
    int arr[n][n];

    in(&arr[0][0],n);  //in my.h
    out(&arr[0][0],n);//in myfile.h

return 0;}
