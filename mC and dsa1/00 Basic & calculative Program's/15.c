#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
    
    int temp1;
    srand(time(0));
    int temp = rand() % 10;

    printf("%dEnter number b/w 1 to 10 : ",temp);
    scanf("%d",&temp1);
    
    if(temp == temp1)
        printf("You have woned the lottery");
    else
        printf("You have losted");

return 0;}