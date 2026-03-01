#include <stdio.h>
#include <string.h>
// #include <conio.h>
int main(){
    FILE *fp;
    fp = fopen ("test.txt","a");
    char data[20] = "Mohit Singh";
    int len = strlen(data);

    if(fp == NULL){
        printf("Error");
    }
    else{
        printf("Sucess");
        for(int i = 0; i < len; i++){
            fputc(data[i],fp);
        }
        fclose(fp);  
    }
return 0;}