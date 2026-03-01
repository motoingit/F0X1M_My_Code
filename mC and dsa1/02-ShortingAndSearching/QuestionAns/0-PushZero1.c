// Push all the xero to the left and maintian the relative position of the non zero element , Space complexity should be O(1)
#include <stdio.h>
#include <stdbool.h>
void swap(int*,int*);
int main (){
    int arr[] = {0,5,4,0,0,0,3,2,1,0,5,5,2,0,0,1};
    int n = 16;
    int i,j;
    bool flag = true;
    printf("\nBefore : ");
    for(i = 0; i < n; i++){
        printf("%d ",arr[i]);
    }

    for(i = 0; i < n - 1; i++){
        for(j = 0; j < n - 1 - i; j++){
            if(arr[j] == 0){
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