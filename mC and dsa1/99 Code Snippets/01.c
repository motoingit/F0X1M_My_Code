#include <stdio.h>
#include <string.h>

struct car{
    char str[10];
    struct engine e;
};

struct engine{
    // int oil = 10; this gives error
    int oil;
};

int main(){
    struct car bmw;
    strcpy(bmw.str,"10xz");
    bmw.e.oil = 5;

    printf("Version of BMW : %s, Oil present in it %d",bmw.str,bmw.e.oil);

return 0;}