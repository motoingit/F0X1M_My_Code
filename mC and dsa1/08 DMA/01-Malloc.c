#include <stdio.h>
#include <stdlib.h> // for malloc
struct employ{
    char name[10];
    float price;
    int noOfPages;
};
int main(){
    int n;
    printf("Enter n :");
    scanf("%d", &n);

    struct employ* ptr = (struct employ*)malloc(n*sizeof(struct employ)); // Dynamic memory allocation
    if(ptr == NULL){
        printf("Memory allocation failed\n");
        return 1;
    }
    else{
        printf("Memory allocation succeeded\n");
        
        for(int i = 0; i<n;i++){
            printf("Enter name ");
            scanf(" %[^\n]",(ptr + i)->name);
            printf("Enter price ");
            scanf("%f",&(ptr + i)->price);
            printf("Enter no of pages ");
            scanf("%d",&(ptr + i)->noOfPages);

        }

        for(int i = 0; i<n;i++){
            printf("Name: %s, Price: %.2f, No of Pages: %d\n", (ptr + i)->name, (ptr + i)->price, (ptr + i)->noOfPages);
        }
        free(ptr);
    }
return 0;}