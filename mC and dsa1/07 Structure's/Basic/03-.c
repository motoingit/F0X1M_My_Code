// Develop a C program to read the attributes of an item form the user such as Item Code, ItemName, Quantity and Rate. Implement a C program using a Structure to find the total cost of the inventory of storing N item in the stock.
#include <stdio.h> 
#include <string.h>

struct item{
    int itemCode;
    char itemName[10];
    int itemQuantity;
    float itemRate;
};

int main(){
    int n = 10;
    struct item x[3];
//
x[0].itemCode = 101;
strcpy(&x[0].itemName,"Laptop");
x[0].itemRate = 50000;

x[1].itemCode = 102;
strcpy(&x[1].itemName,"Mouse");
x[1].itemRate = 1000;

x[2].itemCode = 103;
strcpy(&x[2].itemName,"Keyboard");
x[2].itemRate = 3000;
//

    int i,total;
    for(i = 0; i < n; i++){

        int tempc, tempq;
        printf("Enter the Code : ");
        scanf("%d",&tempc);
        printf("Enter the Quantity : ");
        scanf("%d",&tempq);

        total = 
        
    }
return 0;}