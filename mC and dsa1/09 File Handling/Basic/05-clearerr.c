#include <stdio.h>
int main(){
    int status;
    char data[20] = "hello";
    FILE *fp = fopen("create.txt","r");

    if(fp == NULL){
        printf("Errro");
    }
        
    else{
        fprintf(fp,"%s",data);
        status =  ferror(fp);
        printf("%d",status);

       //
            clearerr(fp);
            status = ferror(fp);
       //
        if(status == 0)
            printf("No error");
        else
            printf("Eror");
    }
    
return 0;}