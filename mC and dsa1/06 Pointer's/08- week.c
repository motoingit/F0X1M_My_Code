//Write a C program to accept N integers from the user into an array. If any integer is positive then subtract 2 from it, 
//if integer is negetive add 1 to it and if zero then do nothing
#include <stdio.h>
int main(){
    int n;
    printf("Enter the Number of element's : ");
    scanf("%d",&n);
    int num[n];
    int *ptr;
    ptr = num;

    for(int i = 0; i < n; i++){
        printf("Enter [%d] element : ",i + 1);
        scanf("%d",(ptr+i));
    }

    for(int i = 0; i < n; i++){
        if(*(ptr + i) > 0)
            *(ptr + i) -= 2;
        else if(*(ptr + i) < 0)
            *(ptr + i) += 1;
    }

    for(int i = 0; i < n; i++)
        printf("%d ",*(ptr+i));

return 0;}