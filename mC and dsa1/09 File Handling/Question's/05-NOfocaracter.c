// Write a C program to Count the Number of Word's, Character's & Lines in a File.
#include <stdio.h>
int main(){
    FILE* fp = fopen("test.txt","r");

    int cc = 0, cs = 0, cl = 0;
    while(!feof(fp)){
        char ch = fgetc(fp);
        if(ch == ' ')
            cs++;
        else if(ch == '\n')
            cl++;
        else
            cc++;
    }
    printf("Character's -> %d\nSpace's -> %d\nNext Line Character's -> %d",cc,cs,cl);
    fclose(fp);
return 0;}