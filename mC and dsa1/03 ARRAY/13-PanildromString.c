//write a program in c to check wheather a string is panildrome or not 

#include <stdio.h>
#include <string.h>
int main(){
    char a[10]; // limited to 10
    int i, j;
    int flag = 0,l;
    
    printf("Enter the string: ");
    gets(a);
    l = strlen(a);

    for (i = 0, j = l-1; i < j; i++, j--){  // 9 is ocupide by '\0'
        if(a[j] != a[i]){
            flag = 1;
            break;
        }
    }

    if(flag == 0)
        printf("00 The given string is panildrome");
    else
        printf("XX The given string is not panildrome");
return 0;}
