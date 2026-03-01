//wpa in c
#include <stdio.h>
#include <string.h>
int main(){
    int n;
    printf("Enter the no of names : ");
    scanf("%d",&n);

    char str[n][20];
    int i;
    for(i = 0; i < n; i++){
        prinf("Enter the name %d = ", i + 1);
        scanf("%s",str[i][]);
    }

    char ntr[20];
    printf("Enter : ");
    scanf("%[^\n]s",ntr);
    int len = strlen(str);
    
    int flag = 0, i, j = 0;
    


    if(flag > 0)
        printf("found");
    else
        printf("not");
return 0;}
