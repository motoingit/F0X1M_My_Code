//  write a code in c to reverse the file text and output
#include <stdio.h>
int main() {
    char str[1000];
    printf("Enter a sentence: ");
    scanf(" %[^\n]", str);

    FILE *fp = fopen("Data.txt", "w");
    if (fp == NULL) {
        printf("Error opening file for writing.\n");
        return 1;
    }

    fprintf(fp, "%s", str);
    fclose(fp);

    fp = fopen("Data.txt", "rb");
    if (fp == NULL) {
        printf("Error opening file for reading.\n");
        return 1;
    }

    fseek(fp, 0, SEEK_END); // fp at EOF
    long file_size = ftell(fp);

    printf("Reversed content: ");
    for (long i = file_size - 1; i >= 0; i--) { // cant we go from
        fseek(fp, i, SEEK_SET);
        int ch = fgetc(fp);
        putchar(ch);
    }
    printf("\n");

    fclose(fp);
    return 0;
}