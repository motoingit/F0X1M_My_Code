//wap in c to count the frequency of each character in a string. assume onluy alphabets are present in string.
#include <stdio.h>
#include <string.h>
int main(){
    char str[100];
    printf("enter :");
    scanf("%[^\n]s",str);

    int i;
    int arr[26];
    for(i = 0; i < 26; i++)
        arr[i] = 0;

    int len = strlen(str);
    for(i = 0; i < len; i++){
        if(str[i] >= 'a' && str[i] <= 'z')
            arr[str[i] - 'a']++;
        else if(str[i] >= 'A' && str[i] <= 'Z')
            arr[str[i] - 'A']++;
    }

    for(int i = 0; i < 26; i++){
        if(arr[i] != 0)
            printf("%c -> %d\n",i + 'A',arr[i]);
    }

return 0;}