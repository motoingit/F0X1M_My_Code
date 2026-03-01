#include <stdio.h>

void fmcopy(FILE*, FILE*);

int main() {
    FILE* fp1 = fopen("data.txt", "r");
    FILE* fp2 = fopen("store.txt", "w");
    char ch;

    if (fp1 == NULL || fp2 == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    fmcopy(fp2, fp1);

    fclose(fp1);
    fclose(fp2);

    // Reopen store.txt in read mode
    fp2 = fopen("store.txt", "r");

    if (fp2 == NULL) {
        printf("Error reopening store.txt.\n");
        return 1;
    }

    while ((ch = fgetc(fp2)) != EOF) {
        printf("%c", ch);
    }

    fclose(fp2);
    return 0;
}

void fmcopy(FILE* dest, FILE* src) {
    char ch;
    while ((ch = fgetc(src)) != EOF) {
        fputc(ch, dest);
    }
}
