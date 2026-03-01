//write a program in c to print the no of 1's and 0's in a binary form of a decino
#include <stdio.h>
#include <stdbool.h>
int main(){
    int num, binary[10];
    printf("Enter the Number : ");
    scanf("%d", &num);
    
    int i = 0;
    while(num > 0){
        binary[i] = num % 2;
        num = num/2;
        i++;
    }

    int count_1 = 0, count_0 = 0;
    int j = i - 1;
    while(j  >= 0){
        printf("%d",binary[j]);
        if(binary[j] == 1){
            count_1++;
        } else {
            count_0++;
        }
    j--;}
    printf("\nCount of 1's = %d\n", count_1);
    printf("Count of 0's = %d\n", count_0);
return 0;}