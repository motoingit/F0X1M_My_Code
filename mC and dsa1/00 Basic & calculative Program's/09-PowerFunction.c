//Write a C program to find x raised to the power y using pow () function.
#include <stdio.h>
#include <math.h>
int main(){
    int x,y,power;
    printf("Enter the value of x and y : ");
    scanf("%d %d",&x,&y);
    power = pow(x,y);
    printf("The value of %d raised to the power %d is : %.2f\n",x,y,power);
    return 0;
}