#include <stdio.h>
#include <stdbool.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}


void bubbleSort(int arr[], int size){
    if(size == 0){
        printf("Empty Array !\n");
    }else if(size == 1){
        printf("Sorted Array (101) !\n");
    }

    for(int i = 0; i <= size - 2; i++){
        int j = 0; 
        bool isSwap = false;
        for(int j = 1; j <= size-1-i; j++){
            if(arr[j-1] > arr[j]){
                swap(&arr[j], &arr[j-1]);
                isSwap = true;
            }
        }
        if(isSwap == false){ //optimisation
            break;
        }
    }
}
void printArr(int arr[], int size){
    if(size == 0){
        printf("Empty Array !\n");
    }

    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){
    // int arr[] = {-10, -3, 0, 2, 5, 9};      //*already sorted
    // int arr3[] = {7, 0, 1, -6, 4};           //* avg case
    // int arr[] = {9, 5, 2, 0, -3, -10};          //* sorted reverse
    int arr[] = {};

    //todo: empty array not handeled     //! if sizeof(arr) == 0

    int size = sizeof(arr)/sizeof(arr[0]);

    printArr(arr, size);
    bubbleSort(arr, size);
    printArr(arr, size);
return 0;}
