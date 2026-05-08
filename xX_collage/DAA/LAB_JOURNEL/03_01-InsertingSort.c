#include <stdio.h>
#include <stdbool.h>

bool insertionSort(int arr[], int size, int *nComp, int *nShift){
    if(size == 1){
        return true;
    }

    for(int i = 1; i < size; i++){
        int key = arr[i];
        int j = i -1;

        while(j >= 0){
            (*nComp)++;
            if(arr[j] > key){
                arr[j+1] = arr[j];
                (*nShift)++;
            }else if (arr[j] <= key){
                break;
            }
            j--;
        }
        arr[j+1] = key;
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
    int arr[] = {2, 3, 4, 5, 6};

    int size = sizeof(arr) / sizeof(arr[0]);

    int nComp = 0, nShift = 0;

    // printArr(arr, size);

    if(selectionSort(arr, size, &nComp, &nShift)){
        printArr(arr, size);
        // printf("Sucessfully Done !");
    }else{
        printf("Error occurs !");
    }
return 0;}
