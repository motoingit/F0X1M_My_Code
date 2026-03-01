// for the acending order
#include <stdio.h>
#include <stdbool.h>
void swap(int*,int*);
int main (){
    int arr[] = {5,6,8,0,5,23,33,6,745,900,34,2,2,0,7,65,2,2};
    int n = 18;
    int i,j;
    bool flag = true;
    printf("\nBefore : ");
    for(i = 0; i < n; i++){
        printf("%d ",arr[i]);
    }

    for(i = 0; i < n - 1; i++){
        for(j = 0; j < n - 1 - i; j++){
            if(arr[j] > arr[j + 1]){
                swap(&arr[j],&arr[j + 1]);
                flag = false;
            }
        }
        if(flag == true)
            break;
    }

    printf("\nAfter : ");
    for(i = 0; i < n; i++){
        printf("%d ",arr[i]);
    }
    
    return 0;}

    void swap(int* x, int * y){
        int temp = *x;
        *x = *y;
        *y = temp;
    }