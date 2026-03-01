// Question 16 : Design a function that returns 1 if the two strings are Anagrams of each other otherwise 0, So
// Develop a C program to read the two strings from the user in the main program and 
// display appropriate message by calling the function to the console. Ignore the case of 
// each of the strings. 

//Sample  Input ::  Enter the first string: Rescue 
//                  Enter the second string: secure  
//
//Sample  Output :: Strings are anagrams of each other  
////////////////////////////////////////////////////////////// MY //////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <string.h>
int main(){
     char atr[]={"lisent"};
     char btr[10];
    printf("Enter the string :");
    scanf("%[^\n]s",btr);
    
    if( strlen(atr) != strlen(btr) ){
        printf("Not Anagram error 1");
        return 0;
    }
    int len = strlen(atr);
    int flag = 0;
    int i,j;
    for(i = 0; i < len; i++){
        for(j = 0; j < len; j++){
            if(atr[i] == btr[j]){
                atr[i] = '@';
                btr[j] = '#';
                flag = 0;
                break;
            }
            else
                flag++;
        }
        if(flag > 0){
            printf("Not Anagram error 2");
            return 0;
        }
    }
    printf("It is !!");
return 0;}

////////////////////////////////////////////////////////////// I-O ///////////////////////////////////////////////////////////////
/* 
     
*/
//////////////////////////// AI //////////////////////////////

