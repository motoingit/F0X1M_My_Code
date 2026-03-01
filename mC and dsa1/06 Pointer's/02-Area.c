#include <stdio.h>
int main(){
    int a,b;
    printf("Enter the Lenght and Breadth : ");
    scanf("%d %d",&a,&b);
    int *x = &a , *y = &b;
    printf("Tjhe area is : %d",*x * *y);
return 0;}