#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    printf("[%d]",n);
    
    char c[10];
    scanf(" %[^\n]s", &c); // this space (just before the %) consume that \n

    scanf("%[^\n]s", &c); // if no space then it also not take \n as input
    //!  %[^\n]   meaning read until \n , so the string still remain empty due the buffer \n.


    printf("[%s]",c);
return 0;}
