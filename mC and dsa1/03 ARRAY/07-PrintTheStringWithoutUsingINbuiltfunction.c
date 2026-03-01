#include <stdio.h>
int main(){
    char a[10],b[10];
    char ch;
    int i = 0;
    
    printf("Enter the first string : ");
    do{
        ch = getchar();
        a[i] = ch;
        i++;
    }while(ch != '\n');
    a[i] = '\0';
    
    i = 0;
    
    printf("Enter the second string : "); ///output is wrong
    do{
        ch = getchar();
        b[i] = ch;
    }while(ch != '\n');
    b[i] = '\0';
    
    printf("Your Required String combination is : %s %s",a,b);
    return 0;}