// Write A C program to read length in centimeters and then convert it into meters and 
// kilometers. Display the converted length to the Screen.

#include <stdio.h>
int main(){
    float cm, m, km;
    printf("Enter the length in centimeters: ");
    scanf("%f", &cm);
    m = cm / 100.0;
    km = cm / 100000.0;
    printf("Length in meters = %.2f m\n", m);
    printf("Length in kilometers = %.2f km\n", km);
    return 0;
}

// Output: Enter the length in centimeters: 100
//         Length in meters = 1.00 m
//         Length in kilometers = 0.00 km