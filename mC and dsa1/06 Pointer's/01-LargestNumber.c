#include <stdio.h>
int main(){
    int a,b,c,max;
    int *x,*y,*z;

    max = (a > b) ? ((a > c) ? a : c) : (b > c) ? b : c ;
    printf("Max = %d",max);
return 0;}