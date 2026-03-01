#include <stdio.h>
#include <string.h>
int main(){
    char str[100];
    char vtr[100];

    int flag;

    printf("Enter the string : ");
    scanf("%[^\n]",str);
    printf("Enter the String : ");
    scanf("%[^\n]",vtr);


    strcpy(vtr,str); // to copy 
    printf("\n{%s} {%s}",str,vtr);



    flag = strcmp(str,vtr); // to compare
    printf("\n%d",flag);



    strcat(vtr,str); //
    printf("\n{%s}",str); //AS



    strrev(str);
    printf("\n%s",&str);



return 0;}