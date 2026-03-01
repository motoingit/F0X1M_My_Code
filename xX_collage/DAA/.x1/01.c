#include <stdio.h>
#include <stdlib.h>

int main() {
    int *num1 = (int*) malloc(sizeof(int));
    int *num2 = (void*)malloc(sizeof(int));

    printf("%d %d\n", num1, num2);
    printf("%d %d", num1+1, num2+1);
return 0;}
