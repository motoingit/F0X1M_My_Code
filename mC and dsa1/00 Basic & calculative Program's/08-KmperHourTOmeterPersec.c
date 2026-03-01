//Write a C program to calculate the speed of a bike in m/sec when the bike travels ‘d’ km of distance in ‘h’ hours.
#include <stdio.h>
int main(){
    float d, h, mps;
    printf("Enter the distance travelled by the bike in km: ");
    scanf("%f", &d);
    printf("Enter the time taken by the bike in hours: ");
    scanf("%f", &h);
    mps = (d * 1000) / (h * 3600);
    printf("The speed of the bike in m/sec is: %f", mps);
    return 0;
}