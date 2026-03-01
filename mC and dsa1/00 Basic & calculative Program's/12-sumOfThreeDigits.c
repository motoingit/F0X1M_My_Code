// Ques: Write a C program to display the sum of individual digits of a given three digit number.
//////////////////////////// MY //////////////////////////////
#include <stdio.h>
int main(){
    int n, sum = 0;
    printf("Enter a three digit number : ");
    scanf("%d",&n);
    sum = n%10 + (n/10)%10 + n/100;
    printf("The sum of individual digits of the number is %d", sum);
return 0;
}
//////////////////////////// I-O //////////////////////////////
// Input: 123
// Output: 6




//////////////////////////// AI //////////////////////////////
