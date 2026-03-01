
//Pass pointer in udf
#include <stdio.h>
int add(int ,int *);
int main(){
    int a,temp;
    int *x;
    a = 10;
    x = &a;
    
    temp = add(a,x);
    printf("Sum = %d\n",temp);

return 0;}

int add(int a, int *x){
    int temp = *x + *x;
    return temp;
}