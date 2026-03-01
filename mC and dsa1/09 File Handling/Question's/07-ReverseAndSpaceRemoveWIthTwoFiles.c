#include <stdio.h>

int main(){
    const char *file1 = "data.txt";
    const char *file2 = "information.txt";
    FILE *fp1 = fopen(file1, "w+");
    FILE *fp2 = fopen(file2, "w+");
    if (!fp1 || !fp2) {
        perror("Error : ");
        return 1;
    }

    char buffer[100];
    printf("Enter a Sentence (max len 100): ");
    if (!scanf(" %[^\n]", buffer)) { //gives 0 on no input
        perror("Error : ");
        return 1;
    }
    fputs(buffer, fp1);

    long len;
    fseek(fp1, 0, SEEK_END);
    len = ftell(fp1) - 1;             /* Index of last byte   */

    for (long pos = len; pos >= 0; --pos) {
        fseek(fp1, pos, SEEK_SET);
        int ch = fgetc(fp1);
        if (ch != ' ' && ch != '\n' && ch != '\r')   /* remove spaces & newlines */
            fputc(ch, fp2);
    }

    rewind(fp2);
    printf("\nResult : ");
    int ch;
    while ((ch = fgetc(fp2)) != EOF)
        putchar(ch);

    fclose(fp1); fclose(fp2);

    getchar();
    char x = 'a';
    printf("\nDo you want to delete txt file's (enter or ANY) : ");
    scanf("%c",&x);

    if(x == '\n'){
        if (remove(file1) != 0)
            perror("remove data.txt failed");
        if (remove(file2) != 0)
            perror("remove information.txt failed");
    }

    return 0;
}
