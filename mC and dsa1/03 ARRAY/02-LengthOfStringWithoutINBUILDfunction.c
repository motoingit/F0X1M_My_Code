#include <stdio.h>
int count(char str[]){
    int i = 0;
    while(str[i] != '\0'){
        i++;
    }
    return i;
}
int main(){
    char str[20], ch;
    int i = 0;

    printf("Enter the String: ");
    scanf(" %[^\n]",str);
    int len = count(str);
    printf("\n And Length of the String is: %d",len);
return 0;}