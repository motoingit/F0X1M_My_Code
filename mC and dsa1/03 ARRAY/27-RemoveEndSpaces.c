#include <stdio.h>
#include <string.h>
int main(){
    char str[100],rtr[100];
    printf("enter : ");
    scanf("%[^\n]s",str);

    int i,j;
    int flag1 = -1,flag2 = -2;
    int len = strlen(str);
    for(i = 0, j = len - 1; i < len; i++,j--){
        if(flag1 == -1){
            if(str[i] != ' '){
                flag1 = i;
            }
        }
        if(flag2 == -2){
            if(str[j] != ' ')
                flag2 = j;
        }
    }

    for(i = 0,j = flag1; j <= flag2; i++,j++){
        str[i] = str[j];
    }

return 0;}