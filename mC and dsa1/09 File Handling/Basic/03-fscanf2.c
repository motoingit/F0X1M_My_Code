#include <stdio.h>
int main(){
    FILE* fp = fopen("create.txt","r");
    char name[10];
    int age;

    if (fp == NULL) {  // can give error if text in not in format
        printf("Error: Could not open the file.\n");
        return 1;
    } else {
        printf("Success: File opened.\n");

        // Using flexible format specifier to handle whitespace
        if (fscanf(fp, "%s %d", name, &age) == 2) {
            printf("Name: %s\nAge: %d\n", name, age);
        } else {
            printf("Error reading data from file.\n");
        }

        fclose(fp);
    }
return 0;}
