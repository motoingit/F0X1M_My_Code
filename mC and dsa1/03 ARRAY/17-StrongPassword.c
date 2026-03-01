#include <stdio.h>
#include <string.h>

int main(){
    int i, len;
    int lcase = 0, ucase = 0, num = 0, spe = 0;
    char str[50];

    printf("Enter Password : ");
    scanf("%[^\n]", str);

    len = strlen(str);

    if (len < 8)
        printf("Weak Password (too short)\n");

    for (i = 0; i < len; i++){
        if(str[i] >= 'a' && str[i] <= 'z')
            lcase++;
        if(str[i] >= 'A' && str[i] <= 'Z')
            ucase++;
        if(str[i] >= '0' && str[i] <= '9')
            num++;
        if(str[i] == '?' || str[i] == '!' || str[i] == '$' || str[i] == '#')
            spe++;
    }
    if(lcase > 0 && ucase > 0 && num > 0 && spe > 0)
        printf("Strong Passoword");
    else
        printf("Week Password (Incude shit)");
    return 0;
}