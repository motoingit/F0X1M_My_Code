#include <stdio.h>
#include <string.h>
int main(){
    char str[100], rtr[100];
    printf("enter : ");
    scanf(" %[^\n]s", str); // Fixed: Added space before % to ignore leading newline

    int i, j;
    int flag1 = -1, flag2 = -2;
    int len = strlen(str);

    // Find first and last non-space characters
    for (i = 0, j = len - 1; i < len; i++, j--) {
        if (flag1 == -1 && str[i] != ' ') {
            flag1 = i;
        }
        if (flag2 == -2 && str[j] != ' ') {
            flag2 = j;
        }
    }

    // Trim spaces
    for (i = 0, j = flag1; j <= flag2; i++, j++) {
        str[i] = str[j];
    }
    str[i] = '\0'; // Null-terminate

    // Remove extra spaces between words
    for (i = 0, j = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ' && str[i + 1] == ' ')
            continue;
        rtr[j++] = str[i]; 
    }
    rtr[j] = '\0'; // Null-terminate

    printf("[%s]", rtr);
    return 0;
}
