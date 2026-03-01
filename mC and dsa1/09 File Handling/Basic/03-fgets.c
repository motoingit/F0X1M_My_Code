#include <stdio.h>

int main() {
    FILE* fp = fopen("create.txt", "r");
    char data[10];

    if (fp == NULL)
        printf("Error: Could not open file.\n");
    else {
        printf("Success: File opened.\n");

        while (fgets(data, sizeof(data), fp)) {
            printf("read - %s", data);
        }

        fclose(fp);
    }

    return 0;
}
