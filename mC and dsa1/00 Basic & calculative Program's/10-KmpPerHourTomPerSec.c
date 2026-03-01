// Ques: Write a C program to calculate the speed of a bike in m/sec when the bike travels ‘d’ km of distance in ‘h’ hours.
//////////////////////////// MY //////////////////////////////
#include <stdio.h>
int main(){
    float d, t, speed;
    printf("Enter the distance and time in km and sec respectively : ");
    scanf("%f %f",&d,&t);
    speed = (d/t)*(1000.0/3600.0);
    printf("The speed of the bike is %.2f m/sec", speed);
return 0;
}
//////////////////////////// I-O //////////////////////////////
// Input: 10 3600
// Output: The speed of the bike is 2.78 m/sec




//////////////////////////// AI //////////////////////////////
