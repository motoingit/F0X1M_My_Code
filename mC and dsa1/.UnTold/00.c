#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    if (argc < 4) {
        printf("Not enough arguments\n");
        return 1;
    }

    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    int c = atoi(argv[3]);

    printf("%d %d %d\n", a, b, c);
    printf("%d\n", argc);
    printf("%d\n", atoi(argv[0]));

    return 0;
}

/*
    
    on : 
        if ($?) { gcc 00.c -o 00 }
        if ($?) { .\00 1 2 3 }

    argv = {
        "00",   // program name
        "1",
        "2",
        "3"
    };

    argc = 4 = argumentLength;

*/
