/*
Develop a program to check the size of integer, character and a float pointer. print The following:
i.	Print the size of original data
ii.	Print the size of data pointed by pointers
iii.	Print the size of pointer variables
*/
#include <stdio.h>
int main(){
    int a = 10, b = 20;
    int *ptr1 = &a, *ptr2 = &b;
    
    printf("size of orrignal data : %d",sizeof(a));
    printf("\nsize of orrignal data by pointer : %d",sizeof(*ptr1));
    printf("\nsize of ponter : %d",sizeof(ptr1));
return 0;}