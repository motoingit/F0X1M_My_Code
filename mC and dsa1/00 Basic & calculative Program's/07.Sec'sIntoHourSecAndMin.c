// Write a C program to convert a given number of seconds into Hours, minutes and seconds.

#include <stdio.h>
int main(){
    int sec, h, m, s;
    printf("Enter the number of seconds: ");
    scanf("%d", &sec);
    h = sec / 3600;  //power of int :)
    m = (sec % 3600) / 60;
    s = (sec % 3600) % 60;
    printf("The number of seconds in hours, minutes and seconds respectively is : %d : %d : %d", h, m, s);
    return 0;
}

/*
Input: 5000
Output: 1 : 23 : 20
*/