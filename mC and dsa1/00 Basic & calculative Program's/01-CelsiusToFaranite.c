//Write a C program to convert temperature from degree Celsius to Degree Fahrenheit. 
//Formula: F = C * 9/5 + 32

#include <stdio.h>
int main(){
    float celsius, faranite;
    printf("Enter the temperature in celsius: ");
    scanf("%f", &celsius);
    faranite = (celsius * 9/5.0) + 32;
    printf("The temperature in faranite is: %f", faranite);
    return 0;
}

/*

Input: 37

Output: 98.600006

*/