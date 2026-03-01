#include <stdio.h>
#include <string.h>          // Required for strlen()
int main(){
    char str[100];
    char ch;
    int i = 0;
    printf("Enter the String: ");
    ch = getchar();
    while(ch != '\n' && i < 100){
        str[i]=ch;
        i++;
        ch = getchar();
    }
    str[i] = '\0' ;   //option when the strlen() is used
    int length = strlen(str);
    
    printf("Length of the string: %d\n", length);
    return 0;
}
