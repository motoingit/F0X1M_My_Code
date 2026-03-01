////INput n string and only print palindrome
#include <stdio.h>
#include <string.h>
void main(){
    int n;
    printf("Enter the No of String's : "); //assuming each has 9 + 1 bytes
    scanf("%d",&n);
    char str[n][10];

    int i,j,k;
    for(i = 0; i < n; i++){
        printf("Enter the String %d - ",i+1);
        scanf(" %[^\n]",str[i]);
    }

    char temp[10];
    for(i = 0; i < n; i++){
        int len = strlen(str[i]);
        strcpy(temp,str[i]);
        int signal = 0;

        for(j = 0, k = len - 1; j < k; j++, k--){
            if(temp[j] != temp[k]){
                signal = -1;
                break;
            }
        }
        if(signal == 0)
            printf("%s\n",str[i]);
    }
}