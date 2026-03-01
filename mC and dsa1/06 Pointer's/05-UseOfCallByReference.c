//write a program in c to validate if a number given by user is panildrome number or not ,the process of checking shoud be done
//using the UDF and pointer,as you have to print in the main function and return the value from the function

#include <stdio.h>
void ispanil(int*);
int main(){
    int num,temp;
    printf("Enter the Number : ");
    scanf("%d",&num);
    temp = num;

    ispanil(&temp);
    if(temp == num)
        printf("Yes");
    else    
        printf("No");
return 0;}
void ispanil(int *temp){
    int y = 0, x = *temp;
        while(x > 0){
            y = y*10 + x%10;
            x /= 10; 
        }
        *temp = y;
}