#include <stdio.h>
int main (){
    int num = 23498;
    int big = 0;
    int temp = 1;
    for( int i = 0;  11111  ; i++){
        if( temp == 0)
            break;
        temp = num % 10;
        num /= 10;
        if(temp > big)
            big = temp; 
    }
    printf("%d",big);
return 0;}