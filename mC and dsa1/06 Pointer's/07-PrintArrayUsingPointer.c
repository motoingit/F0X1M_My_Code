//Write a C program to accept and store N real numbers into an array. Find their mean(avg) and standard deviation using pointers and 
//display the same(Answers) to output;
//HINT :- Formula for std deviation undertoot{sigma(x^2)/n -[sigma(x)/n]^2} where n = length and x = num
//or
#include <stdio.h>
#include <math.h>
int main(){
    int n;
    printf("Enter the Amount of Numbers:");
    scanf("%d",&n);
    int arr[n];
    int *ptr1;
    ptr1 = arr;

    float sum = 0;
    for(int i = 0; i < n; i++){
        printf("Enter the {%d} Number :",i+1);
        scanf("%d",(ptr1+i));
        sum += *(ptr1+i);
    }
    float mean = (float)sum/n;
    float std;
    for(int i = 0; i < n; i++){
        std += ((*(ptr1+i) - mean) * (*(ptr1+i) - mean));
    }
    std = sqrt(std/n);
    printf("Mean and Stdeviation is (%f) (%f)",mean,std);
return 0;}