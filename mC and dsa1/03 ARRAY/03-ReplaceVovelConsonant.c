//Wap in c to input a string and replace all the vovels ,consonant and spaces by @,$ and % respectively
#include <stdio.h>
int main(){
    char str[100];
    int i = 0;
    printf("Enter the String :");
    fgets(str, sizeof(str), stdin);   //strlen(arr)==sizeof(arr) 
    
    for(i = 0; i < 100; i++){
        if (str[i] == 'a' || str[i] == 'e' ||  str[i] == 'i' || str[i] == 'o' ||  str[i] == 'u' ||
             str[i] == 'A' || str[i] == 'E' ||  str[i] == 'I' || str[i] == 'O' ||  str[i] == 'U' )
            str[i] = '#';
        else if(str[i] > 'a' &&  str[i] > 'z' || str[i] > 'A' &&  str[i] > 'Z')
            str[i] = '@';
        else if(str[i] == ' ')
            str[i] = '$';
    }
    printf("The updated string is : %s",str);
return 0;}