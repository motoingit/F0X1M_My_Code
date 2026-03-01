#include <stdio.h>
int main(){
    FILE *fp;
    fp = fopen ("test.txt","a");
    char data[20] = "Mohit Singh";

    if(fp == NULL){
        printf("Error");
    }
    else{
        printf("Sucess");
        fputs(data,fp);
        fclose(fp);  
    }
return 0;}