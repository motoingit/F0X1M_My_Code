#include <stdio.h>
#include <string.h>

int main(){

//     Situation 01
    for ( int i = 1; i <= 100; i++ )
        for( int j = 1; j <= 100000; j++ )
            int x = 100000;

//     Situation 02
    for ( int i = 1; i <= 100000; i++ )
        for( int j = 1; j <= 100; j++ )
            int x = 100000;
    
//     Question : 
    printf("Which of the situation is more Power Friendly\n");
    printf("Which of the situation is cache memory traveller\n");
return 0;}