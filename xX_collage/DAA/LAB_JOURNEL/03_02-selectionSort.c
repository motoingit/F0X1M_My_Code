#include <stdio.h>
#include <stdbool.h>

bool swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;

    return true;
}

bool selectionSort(int arr[], int size, int *nComp, int *nSwap){
    if(size == 1){
        return true;
    }

    for(int i = 0; i <= size - 2; i++){
        int minIdx = i;
        for(int j = i + 1; j <= size - 1; j++){
            (*nComp)++;
            if(arr[j] < arr[minIdx]){
                minIdx = j;
            }
        }
        if( minIdx != i ){
            swap(&arr[i], &arr[minIdx]);
            (*nSwap)++;
        }
    }

    return true;
}

void printArr(int arr[], int size){
    for(int i = 0; i < size;i++){
        printf("%d ",arr[i]);
    }
    printf("\n\n");
}

int main() {
    int arr[] = {7,11,8,0,10,1};

    int size = sizeof(arr)/ sizeof(arr[0]);

    int nComp = 0, nSwaps = 0;

    // printArr(arr, size);

    if(selectionSort(arr, size, &nComp, &nSwaps)){
        printArr(arr, size);
        // printf("Sucessfully Done !");
    }else{
        printf("Error occurs !");
    }
return 0;}
