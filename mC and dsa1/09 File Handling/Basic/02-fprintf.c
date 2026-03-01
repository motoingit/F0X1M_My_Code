#include <stdio.h>
int main(){
     FILE* fp = fopen("create.txt","w");
     char name[] = "mohit";
     int age = 18;

     if(fp == NULL)
          printf("errpr");
     else{
          printf("SUfcess");
          fprintf(fp,"%s\t%d",name,age);

          fclose(fp);
     }
     // FILE* ptr = fopen("file.txt","r");
     // char str[100];
     // if( fgets(str,100,ptr) != NULL){ //   to write just a line
     //    printf("%s",str);
     // }
     // fclose(ptr);

     // printf("\n\n");


     // ptr = fopen("file.txt","r");
     // str[100];
     // while( fgets(str,100,ptr) != NULL){  //to write whole
     //      printf("%s",str);
     // }
   
     // fclose(ptr);
return 0;}