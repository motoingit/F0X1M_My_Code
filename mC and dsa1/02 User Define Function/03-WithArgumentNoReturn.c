#include <stdio.h>
void sum(int a, int b);
int main(){
    int x, y;
    printf("Enter x and y : ");
    scanf("%d %d", &x, &y);
    sum(x, y);
return 0;}

void sum(int a, int b){ 
    printf("Sum = %d\n", a + b);
}
