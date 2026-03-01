//Write a C program to create a file ThreePara.txt and Write any three paragraph of text to it. Display the content of the file and the the count of frequency of consonant and vowels present in it to the console.
// You may assume a single paragraph in the input streame until you encounter a new line caracter (\n)

#include <stdio.h>
int main(){
    FILE *fp = fopen("ThreePara.txt","w");
    
    if(fp == NULL){
        printf("File Does'nt Open !!");
    return 0;}
    
    else{
        printf("File Open Sucessfully.\n");
        char str[100];   //limition
        printf("Enter the Paragraph : ");
        scanf(" %[^\t]",str);
        fputs(str,fp);
        fclose(fp);


//read
        fp = fopen("ThreePara.txt","r");
        char ch;
        while ((ch = fgetc(fp)) != EOF) {
            putchar(ch);
        }
        fclose(fp);
    }
return 0;}