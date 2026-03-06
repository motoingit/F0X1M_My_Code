#include <stdio.h>

int main() {
    
int a=20,b=90;
char str[100];

//* f3f -> skiips %D
scanf("%d", &a);
scanf("%s", str); // The space before %c skips the \n
    
printf("{%d} {%s}", a, str);

//! getchar(); // Consumes the '\n'
return 0;}
