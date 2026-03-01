#include <stdio.h>
int main(){
     FILE* fp = fopen("create.txt","r");
     char ch;

     if(fp == NULL)
          printf("errpr\n");
     else{
          printf("SUfcess");
          while(!feof(fp)){            // this returns 1 if EOF meets
            ch = fgetc(fp);
            printf("%c",ch);
          }
          fclose(fp);
     }
     
return 0;}