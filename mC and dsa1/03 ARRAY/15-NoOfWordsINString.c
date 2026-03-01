//write a code in c to find the nuber of words
#include <stdio.h>
int main(){
    int c,i;
    char str[100];
    printf("Enter the String : "); //asuming only one space after each word
    gets(str);
    
    for(i = 0; str[i] != '\0'; i++){
        if(str[i] == ' ')
            c++;
    }
    c++;
    printf("The No of words is/are %d",c);
return 0;}
