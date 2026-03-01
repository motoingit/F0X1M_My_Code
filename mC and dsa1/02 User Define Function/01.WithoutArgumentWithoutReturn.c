#include <stdio.h>
void add(void);
int main(){
    add();  
return 0;}

void add(void) {
    int a, b, sum;
    printf("Enter a and b: ");
    scanf("%d %d", &a, &b);
    sum = a + b;
    printf("Sum = %d\n", sum);
}
