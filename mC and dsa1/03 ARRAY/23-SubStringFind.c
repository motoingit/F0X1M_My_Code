// Question 16 : Design a UDF that searches for a sub-string in the main string and returns 1 if found else 
// returns 0. Write a C program to read the main string and the substring to be searched from 
// the user and then display appropriate message if found by calling this UDF. Ignore case, **of uper and lower character**.
////////////////////////////////////////////////////////////// MY //////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <string.h>
int main(){
    char str[100];  //substring                     //limitaion (.|,|?|NULL)
    printf("Enter the main string : ");
    scanf("%[^\n]",str);
    int l = strlen(str);
    str[l+1] = ' ';
    str[l+2] = '\0';

    getchar(); //////////////THIS is used to consume the \n character as the first one left in buffer

    char s[10];
    printf("Enter the word : ");
    scanf("%[^\n]",s);

    l = strlen(s);
    s[l+1] = ' ';
    s[l+2] = '\0';
    l = strlen(s);

    int i = 0,j = 0;
    for(i = 0; i < strlen(str); i++){
        if(str[i] == s[j] || str[i] == s[j] + 32 || str[i] == s[j] - 32)
            j++;
        else if(j == l)
            break;
        else
            j = 0;
    }

    if(j != 0)
        printf("The sub-string [%s] is present in the main string.",s);
    else   
        printf("The sub-string [%s] is NOT present in the main string.",s);
return 0;
}

////////////////////////////////////////////////////////////// I-O ///////////////////////////////////////////////////////////////
/* 
    Input: Enter the main string : My name is Mohit
           Enter the word : MOHIT 

    Output: The sub-string MOHIT is present in the main string. 



*/
//////////////////////////// AI //////////////////////////////

