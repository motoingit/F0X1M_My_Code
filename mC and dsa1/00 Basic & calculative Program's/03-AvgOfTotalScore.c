//Write a C program to enter marks of a student in four subjects, Find the average of total 
//marks of a student (accurately up to 2 Decimal places). 

#include <stdio.h>
int main(){
    int sub1, sub2, sub3, sub4;
    float avg;
    printf("Enter the marks of subject 1: ");
    scanf("%d", &sub1);
    printf("Enter the marks of subject 2: ");
    scanf("%d", &sub2);
    printf("Enter the marks of subject 3: ");
    scanf("%d", &sub3);
    printf("Enter the marks of subject 4: ");
    scanf("%d", &sub4);
    avg = (sub1 + sub2 + sub3 + sub4) / 4.0;
    printf("The average of total marks of a student is: %.2f", avg);
    return 0;
}

/*
Input: 50, 60, 70, 80
Output: 65.00
*/