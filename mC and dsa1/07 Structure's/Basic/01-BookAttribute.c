#include <stdio.h>
struct book{
    char name[10];
    float price;
    int noOfPages;
};
int main(){
    struct book b1;
    printf("Enter the Name : ");
    scanf(" %[^\n]",b1.name);
    printf("Enter the Page :");
    scanf("%d",&b1.noOfPages);
}