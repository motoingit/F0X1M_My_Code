// nospace coount ok.
#include <stdio.h>
int main(){
    char str[100];
    printf("enter : ");
    scanf("%[^\n]s",str);

    int c=0,i = 0;
    while(str[i] != '\0'){
        if(' ' != str[i])
            c++;
        i++;
    }
    printf("No of character %d",c);
return 0;}