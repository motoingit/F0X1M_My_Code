// Write a C program to read three test scores of a student and find the average of the 
// best two scores. Assume a test score of MM 25 each. 
#include <stdio.h>
int main(){
    int a,b,c;
    printf("Enter the score 1 :");
    scanf("%d",&a);

    printf("Enter the score 2 :");
    scanf("%d",&b);

    printf("Enter the score 3 :");
    scanf("%d",&c);

    float avg = (a+b+c)/(1.0*3);
    printf("Average is %f",avg);


return 0;}