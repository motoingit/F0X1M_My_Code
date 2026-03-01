#include <stdio.h>

void main() {
    FILE *fp1 = NULL;
    FILE *fp2 = NULL;
    FILE *fp0 = NULL;

    fp1 = fopen("f1.txt", "r");
    fp2 = fopen("f2.txt", "w+");
    fp0 = fopen("f0.txt", "w+");

    char str[100];
    int ch;  // Use int to store fgetc() return value

    printf("File 01 is Already inputed!\n");
    printf("Enter the content of File 02: ");
    scanf(" %[^\n]", str);
    fputs(str, fp2);

    printf("Filling the File 00 by File 01\n");
    while ((ch = fgetc(fp1)) != EOF) {
        fputc(ch, fp0);
    }

    printf("Filling the File 00 by File 02\n");
    rewind(fp2);
    while ((ch = fgetc(fp2)) != EOF) {
        fputc(ch, fp0);
    }

    printf("Contents in File 00: ");
    rewind(fp0);
    while ((ch = fgetc(fp0)) != EOF) {
        printf("%c", ch);
    }

    fclose(fp1);
    fclose(fp2);
    fclose(fp0);
}
