// Write a program in C to Create a book structure to store title, Author and price, INput details for three books, store them in a file, read the file to find the most expensive and lowest priced boooks and display their information
#include <stdio.h>
struct book{ char title[10]; char author[10]; float price; } B[2];
int main(){
    FILE* fp = fopen("book.txt","w");
    if(fp == NULL){
        printf("Error !\n");
    }
    else{
        printf("Success fully file opend !\n");

        int i;
        for(i = 0; i < 2; i++){
            printf("Enter The Detail's Of Book %d.\n\n",i+1);
            printf("Title : ");
            scanf(" %[^\n]",B[i].title);
            printf("Author : ");
            scanf(" %[^\n]",B[i].author);
            printf("Price : ");
            scanf("%f",&B[i].price);
        }

        for(i = 0; i < 2; i++){
            printf("Entering Book %d. ",i+1);
            fprintf(fp,"%s|%s|%f\n",B[i].title, B[i].author, B[i].price);
        }

        printf("Succesfully Sturctured coppied !!\n");
        fclose(fp);

        fp = fopen("book.txt","r");
        char t[10], a[10]; float p;
        printf("Reading the Data form file !!\n");
        for(i = 0; i < 2; i++){
            fscanf(fp,"%[^|]|%[^|]|%f\n",t,a,&p);
            printf("Book %d: Title = %s, Author = %s, Price = %.2f\n", i+1, t, a, p);
        }
        fclose(fp);
    }
return 0;}