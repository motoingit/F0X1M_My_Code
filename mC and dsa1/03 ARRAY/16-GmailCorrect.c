#include <stdio.h>
#include <string.h>
int main(){
    int i, j, len;
    char str[50];
    char ad[] = "@gmail.com";

    printf("Enter Gmail ID: ");
    scanf("%[^\n]", str);

    len = strlen(str);

    // Step 1: Check if the Gmail ID is at least 10 characters long
    if (len < 11){
        printf("Wrong address (user name is missing)\n");
        return 0;
    }

    // Step 2: Verify "@gmail.com" at the end
    for (i = len - 10, j = 0; ad[j] != '\0'; i++, j++){
        if (str[i] != ad[j]){
            printf("Wrong address (domain mismatch)\n");
            return 0;
        }
    }

    // Step 3: Check username before '@'
    for (i = 0; i < len - 10; i++){
        if (!((str[i] >= 'A' && str[i] <= 'Z') || 
              (str[i] >= 'a' && str[i] <= 'z') || 
              (str[i] >= '0' && str[i] <= '9') || 
              str[i] == '#' || str[i] == '/' || str[i] == '$' || str[i] == '*')){
            printf("Not valid username\n");
            return 0;
        }
    }
    printf("Valid Gmail address\n");
return 0;}