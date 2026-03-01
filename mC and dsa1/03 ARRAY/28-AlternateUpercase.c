#include <stdio.h>
#include <string.h>
int main(){
    char str[100] = "my name is mohit singh";
    int len = strlen(str);

    int i,flag = -1;
    for(i = 0; i < len; i++){
        if(flag == -1){
            if(str[i-1] == ' '){
                while(str[i] != ' '){
                    str[i] -= 32;
                    i++;
                }
                flag *= -1;
            }
        }
        else if(str[i] == ' '){
            flag *= -1;
        }
    }
    printf("[%s]",str);

return 0;}