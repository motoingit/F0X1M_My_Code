#include <stdio.h>
int main(){
    char a[100];  //limition of 100 characters
    char ch;
    int i = 0,v = 0,c = 0;
    printf("Enter a string: ");
    while (ch != '\n' && i < 99){
        ch = getchar();
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
            v++;
        else if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
            c++;
        a[i] = ch;
        i++;
    }
    a[i] = '\0';

    printf("the frequency of Vovel and Consonats is %d and %d respectively ",v,c);
return 0;}