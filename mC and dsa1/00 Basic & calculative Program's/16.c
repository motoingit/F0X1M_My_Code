// understaing the format specifers advance
#include <stdio.h>
int main(){
    float n = 21.4;
    printf("Num - %.1f", n);
    printf("\nNum - %-03.2f", n);
    printf("\nNum - %-3.3f", n);
    printf("\nNum - %07.3f", n);
return 0;}