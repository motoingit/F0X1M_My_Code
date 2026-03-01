#include <stdio.h>
#include <string.h>
int main(){
    char a[100];
    int i, j, len;
    
    printf("Enter the string: ");
    // fgets(a,sizeof(a), stdin); //let graphic - graphic\n\0 -
    
    // len = strlen(a);
    // if (a[len - 1] == '\n'){
    //     a[len - 1] = '\0';
    //     len--;
    // }
    gets(a);
    len = strlen(a);
    char b[len];
    for (i = 0, j = len - 1; i < len; i++, j--)
        b[i] = a[j];
    b[len] = '\0';

    printf("The Reverse string is: {%s}", b);
return 0;}
