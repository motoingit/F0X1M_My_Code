//Develop a C program to create a file and copy its contents to another file such that there is no space b/w any of the words in the copied file display the conteents of the newly copied file to the output screen 

//file1.txt    Helloc Cse
//new.txt      hellocCse


#include <stdio.h>
int main(){
    FILE *fp1 = fopen("old.txt","w");
    FILE *fp2 = fopen("new.txt");
    if(fp1 == NULL && fp2 == NULL){
        printf("File's Doesn't Open !!");
    return 0;}
    
    else{
        printf("File Open Sucessfully.\n");
        char str[100];   //limition
        printf("Enter the Paragraph : ");
        scanf(" %[^\n]",str);
        fputs(str,fp1);
        fclose(fp1);

        fputs(fp1,str);

        fp2 = fopen("ThreePara.txt","r");
        char ch;
        while ((ch = fgetc(fp)) != EOF) {
            putchar(ch);
        }
        fclose(fp);
    }
return 0;}