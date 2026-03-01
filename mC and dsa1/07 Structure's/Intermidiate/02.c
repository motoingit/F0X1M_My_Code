// understanding the behaviour of typedef struct in C
#include <stdio.h>
#include <string.h>

struct date{ int day; int month; int year;} D[20];

int main(){
    struct date *ptr = D;
    ptr[0].day = 10;
    printf("%d\n", ptr[0].day);
    return 0;
}


 // seee ptr == D