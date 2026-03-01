#include <stdio.h>

int heapSize = -1;

void swap(int arr[], int a, int b){
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void min_heapify(int arr[], int target){
    int smallest = target;
    int leftChild = target*2;
    int rightChild = target*2+1;

    if(leftChild <= heapSize && arr[smallest] > arr[leftChild]){
        smallest = leftChild;
    }

    if(rightChild <= heapSize && arr[smallest] > arr[rightChild]){
        smallest = rightChild;
    }

    if(smallest != target){
        swap(arr, smallest, target);
        min_heapify(arr, smallest);
    }   
}

void heapSort(int arr[], int size){
    heapSize = size;

    //buildHeap
    for(int i = size/2; i >= 1; i--){
        min_heapify(arr, i);
    }

    //HeapSort
    for(int i = size; i >= 2; i--){
        swap(arr, 1, i);
        heapSize--;
        min_heapify(arr, 1);
    }
}

int main() {
    int n; scanf("%d",&n);
    int arr[n+1]; //todo: 1 based indexing
    int size = sizeof(arr)/sizeof(arr[0]);

    for (int i = 1; i <= n; i++)
    {
        scanf("%d",&arr[i]);
    }

    heapSort(arr, n); //Decreasing order

    for (int i = 1; i <= n; i++)
    {
        printf("%d ",arr[i]);
    }
    
    
return 0;}
