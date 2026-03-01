#include <stdio.h>
int main(){
    char str[10];
    printf("Enter : ");
    scanf("%[^x]",str); // x is the barrier
    printf("%s",str);
return 0;}