#include <stdio.h>
#include <string.h>
int main(){
    char str[] = "NAVNEET ALOK MOHIT DHRUV SIDDHARTH ";
    char ntr[20];
    printf("Enter : ");
    scanf("%[^\n]s",ntr);
    int len = strlen(str);
    
    int flag = 0, i, j = 0;
    for(i = 0; i < len; i++){
        if(str[i - 1] == ' '){
        if(str[i] == ntr[0]){
            while(str[i] != ' '){
                if(str[i] != ntr[j]){
                    flag = 0;
                    break;
                }
                else{
                    flag++;
                }
                i++,j++;
            }
        }
        }
    }
    if(flag > 0)
        printf("found");
    else
        printf("not");
return 0;}
