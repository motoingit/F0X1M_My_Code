//Write a C program to compute the gross salary of an employee by Reading his basic pay 
//from the keyboard.
//Where Gross Salary =BP+DA+HRATA, where HRA = 10% of BP, TA = 5% of BP, DA=15% of BP

#include <stdio.h>
int main(){
    float BP, DA, HRA, TA, Gross;
    printf("Enter the basic pay of the employee : ");
    scanf("%f", &BP);
    DA = 0.15 * BP;
    HRA = 0.10 * BP;
    TA = 0.05 * BP;
    Gross = BP + DA + HRA + TA;
    printf("The gross salary of the employee is: %.2f", Gross);
    return 0;
}