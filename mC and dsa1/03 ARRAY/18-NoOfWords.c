#include <stdio.h>
#include <string.h>
int main(){
    char sen[100];
    int i,l;
    int nw = 0;
    printf("Enter sentence : {");
    // scanf("%[\^n]",sen);         //why this is giving bad results;
    gets(sen);
    printf("}");
    l = strlen(sen);

    for(i = 0; i <= l; i++){
        if(' ' == sen[i])
            nw++;
        if('\0' == sen[i]){
            nw++;
            break;
        }    
    }
    printf("No of words in this sentense is : %d",nw);
return 0;}