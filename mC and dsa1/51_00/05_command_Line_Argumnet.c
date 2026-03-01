
/* 
in terminal move to the directory of this file by :
    cd "directory(C:\Users\mohit\OneDrive\Documents\00_CODE\90_01_____Temp_Files)"
then write run command's :
    gcc name.c -o xyz.exe
    .\a.exe MOHIT || ./a.out MOHIT ||

    here MOHIT is input
*/



#include <stdio.h>

int main(int argc, char *argv[]) {
    printf("Program name: %s\n", argv[0]);  // program itself
    if (argc > 1) {
        printf("First argument: %s\n", argv[1]);
    }
    return 0;
}

/*

                        Command Line Arguments

👉 Think of this like giving inputs to your program from outside (terminal) instead of typing them 
    inside scanf.

Syntax
    int main(int argc, char *argv[])


argc → Argument count (number of inputs passed including program name).

argv → Argument vector (array of strings containing each argument).


*/
