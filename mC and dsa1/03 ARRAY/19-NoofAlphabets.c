#include <stdio.h>
#include <string.h>
int main(){
    char sen[100];
    int i,l;
    int nw = 0;
    printf("Enter sentence : {");
    gets(sen);
    printf("}");
    l = strlen(sen);

    for(i = 0; i <= l; i++){
        if('A' <= sen[i] && 'Z' <= sen[i] || 'a' <= sen[i] && 'z' <= sen[i])
            nw++;
        if('\0' == sen[i]){
            nw++;
            break;
        }    
    }
    printf("No of Alphabets in this sentense is : %d",nw);
return 0;}