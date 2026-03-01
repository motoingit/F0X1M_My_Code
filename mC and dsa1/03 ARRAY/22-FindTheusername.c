#include <stdio.h>
#include <string.h>
int main(){

    char a[10] = "priyanka",b[10] = "alok" ,c[10] = "mohit";
    char o[10];

    char x[10] = "1234",y[10] = "alok90",z[10] = "MOTIg7";
    char w[10];

    int flag1;

    printf("Enter the username :");
    gets(o);
    printf("Enter the Password :");
    gets(w);

    if(strcmp(o,a) && strcmp(x,w) || strcmp(o,b) && strcmp(y,w) || strcmp(o,c) && strcmp(z,w))
        printf("Match Found :");
    else    
        printf("Not found");

return 0;}