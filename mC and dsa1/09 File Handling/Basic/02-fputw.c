#include <stdio.h>
#include <string.h>
// #include <conio.h>
int main(){
    FILE *fp;
    fp = fopen ("test.txt","w");
    int len = 12;

    if(fp == NULL){
        printf("Error");
    }
        fputw(len,fp);
        fclose(fp);  
return 0;}