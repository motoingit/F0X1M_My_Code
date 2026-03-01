//## Playing With Pointer's.

#include <stdio.h>
int main(){
    int x = 10;
    int *y = &x;

    printf("%p\n",&x);// address of x

    printf("%p\n",&y); // adress of y

    printf("%d\n",x);  // value in x

    printf("%d\n",y);  //value of y

    printf("%d",*y);// y  pointing the x value

return 0;}