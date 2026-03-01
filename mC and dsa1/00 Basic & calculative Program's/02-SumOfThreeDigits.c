// Write a C program to display the sum of individual digits of a given three digit number. 

#include <stdio.h>
int main(){
    int num,sum,pro,d1,d2,d3;
    printf("Enter the three digit number : ");
    scanf("%d",&num);
    d1 = num/100;
    d2 = (num%100)/10;
    d3 = num%10;
    sum = d1 + d2 + d3;
    pro =  d1 * d2 *d3;
    printf("The sum of the digits of the number is : %d\n",sum);
    printf("The product of the digits of the number is : %d\n",pro);   
return 0;
}