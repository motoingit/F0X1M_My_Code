//check the panildrom by only inbuild fuction
#include <stdio.h>
#include <string.h>
int main(){
    char a[10];
    char temp[10];
    int flag;

    printf("Enter the array : ");
    scanf("%[^\n]",a);
    
    strcpy(temp,a);
    strrev(temp);
    flag = strcmp(temp,a);

    if(flag == 0)
        printf("yes");
    else
        printf("no");

return 0;}