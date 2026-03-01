// Write a C program to calculate the compound interest by reading the principal ‘p’, rate 
// ‘r’ and time ‘n’ as input by the user. (HINT: p*(1+r/100) raised to power n ) 

#include <stdio.h>
#include <math.h>
int main(){
    int p,r,t,ci;
    printf("Enter the principle Amount : ");
    scanf("%d",&p);
    printf("Enter the rate :");
    scanf("%d",&r);
    printf("Enter the time :");
    scanf("%d",&t);
    ci = p*pow((1+r/100),t);
    printf("Your Compount intrest in %d",ci);
return 0;
}

// Input: 1000, 10, 2
// Output: 1210