#include <stdio.h>
int main(){
    int a,b;
    int *x, *y;
    a = 10; b = 29;
    x = &a; y = &b;
    printf("Sum = %d\n",*x + *y);

    a = 20;
    b = 25;
    x = &a;
    y = &b;
    printf("Sub = %d\n",*x - *y);

    a = 5;
    b = 9;
    x = &a;
    y = &b;
    printf("Mul = %d\n",*x * *y);

    a = 11;
    b = 9;
    x = &a;
    y = &b;
    printf("Div = %d\n",*x / *y);

return 0;}