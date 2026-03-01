//Develope a c program to compare two strings using UDF and  return 1 if the strings are equal and 
//otherwise without using the built in function strcmp(). Display an appropriate message to the ouput screen.

#include <stdio.h>
int x(char[],char[]);
int main(){
    char a[10],b[10];
    int flag = 0;
    printf("Enter the string 1 : ");
    fgets(a,10,stdin); //could be problem in size
    printf("Enter the string 2 : ");
    fgets(b,10,stdin); //xxxxxxxxxxxxxxxxxxxx

    flag = x(a,b);
    if(flag == 1)
        printf("Not Equal");
    else    
        printf("Equal");
return 0;}

int x(char a[10],char b [10]){\
    int i;
    for(i = 0; i <10; i++){
        if(a[i] != b[i]){        //could be a problem
            return 1;
            break;
        }
    }
}