#include <stdio.h>
int main (){
    int arr[] = {67,34,87,0,556,33,8,5,34,778,1,56,88};
    int flag = 0,num = 778;
    int i;
    for(i = 0; i < 13; i++){
        if(arr[i] == num){
            flag++;
            break;
        }
    }
    if(flag > 0){
    printf("Your Number is located on the %d position of the array",i+1);
    }
    else{
        printf("Your Nuber is not located amoung any index");
    }
    return 0;}