//Design a UDF in C to find the product and quotient of two numbers passed to it from the calling program.Display the product
// and quotient in the main program & aslo display their product and quotient .Implement using a pointer.

#include <stdio.h>
void op(int*,int*);
int main(){
    int a,b;
    printf("Enter the two Number respectively : ");
    scanf("%d %d",&a,&b);

    op(&a,&b);
    printf("Your Product(%d) and Quotent(%d)",a,b);

return 0;}
void op(int*x, int*y){
    int temp = *x;
    *x = *x * *y;
    *y = temp / *y;
}