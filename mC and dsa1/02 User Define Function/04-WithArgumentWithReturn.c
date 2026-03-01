#include <stdio.h>
int sum(int, int);
int main(){
    int a, b, result;
    printf("Enter a and b: ");
    scanf("%d %d", &a, &b);
    result = sum(a, b);
    printf("Sum = %d\n", result);
return 0;}

int sum(int a, int b) {
    return a + b;
}
