// for the acending order
#include <stdio.h>
#include <stdbool.h>
void swap(int*,int*);
int main (){
    int arr[] = {5,4,3,2,1,0};
    int n = 6;
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