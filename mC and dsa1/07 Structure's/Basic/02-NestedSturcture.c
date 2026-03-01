#include <stdio.h>
struct employ{
    char name[10];
    float price;
    int noOfPages;
};

struct book{
    char name[10];
    float price;
    struct employ X; // Nested structure
};
int main(){
    printf("Use karna ni ata");
return 0;}