#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    printf("[%d]",n);
    
    char c;
    scanf("%c", &c);
    printf("[%c]",c);
return 0;}

/*
    by this code you can see the output
    "\n" which is still in the buffer after the input from the int type
    char type scan imidiately take it and off

///todo: Input
1000

///todo: Output
1000
[1000][   <- this is where we got the \n exposed
]

*/

