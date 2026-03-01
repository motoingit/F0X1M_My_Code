// Ques: Write a C program to calculate the compound interest by reading the principal ‘p’, rate ‘r’ 
// and time ‘n’ as input by the user. (HINT: compound intrest = p*(1+r/100) raised to power n )
//////////////////////////// MY //////////////////////////////
#include <stdio.h>
#include <math.h>
int main(){
    float p,r,n,ci;
    printf("Enter the principal, rate and time respectively : ");
    scanf("%f %f %f",&p,&r,&n);
    ci = p*pow((1+r/100),n);
    printf("The compound interest is %.2f", ci);
return 0;
}
//////////////////////////// I-O //////////////////////////////
// Input: 1000 10 2
// Output: The compound interest is 1210.00




//////////////////////////// AI //////////////////////////////
