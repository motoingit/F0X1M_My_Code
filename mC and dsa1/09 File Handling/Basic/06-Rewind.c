#include <stdio.h>

int main() {
    FILE* fp = fopen("create.txt", "r+");
    char str[100], ch;

    if (fp == NULL) {
        printf("Error: Could not open the file.\n");
        return 1;
    } else {
        printf("Success: File opened.\n");
        rewind(fp);  // to painter at start
        while(!feof(fp)){
            char ch = fgetc(fp);
            printf("%c",ch);
        }

        fclose(fp);
    }
    return 0;
}
