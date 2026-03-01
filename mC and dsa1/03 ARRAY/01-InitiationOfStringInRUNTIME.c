#include <stdio.h>
int main(){
    char a[20];  //limition of 20 characters
    char ch;
    int i = 0;

    printf("Enter a string: ");
    ch = getchar();  //scan and store the first character
    while (ch != '\n' && i < 19) { // this Ensure we don't exceed array bounds But still we can see the input infinite
        a[i] = ch;
        i++;
        ch = getchar();
    }
    a[i] = '\0';
    
    printf("You entered: ");
    i = 0;
    while (a[i] != '\0'){
        putchar(a[i]);
        i++;
    }

return 0;}