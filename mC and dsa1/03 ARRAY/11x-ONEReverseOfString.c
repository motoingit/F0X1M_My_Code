//Develope a c program to Insert a reverse of array in the second array

#include <stdio.h>
#include <string.h>
int main(){
    char a[10];
    int i,j;
    int l;
    printf("Enter the string: ");
    gets(a);

    l = sizeof(a) -;
    char b[6];     //asuming the string of 6 character

    for(i = 0,j = 5; i <= l-1 && j >=0 ; i++,j--){ 
        b[j] += a[i]; //x = x + y                         
        a[i] = b[j] - a[i]; //y = x - y
        b[j] -= a[i]; //x = x - y 
    }
    printf("The Reverse string is {%s}",b);
return 0;}