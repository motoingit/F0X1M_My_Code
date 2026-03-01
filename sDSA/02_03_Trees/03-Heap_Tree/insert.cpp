// Question : heap Sort
#include <iostream>
#include <queue>
using namespace std;

void swap(int *a, int *b) {
    int t = *a; *a = *b; *b = t;
}

void heapify(int arr[], int n, int i) { // O(n)
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < n && arr[l] > arr[largest]) largest = l;
    if (r < n && arr[r] > arr[largest]) largest = r;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) { // O(nlogn)
    // Build max heap
    for (int i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extract elements
    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

void printArr(int arr[], int size){
    for (int i = 0; i < size; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main(){
    int arr[] = {1,6,3,4,0,9};
    int size = sizeof(arr)/sizeof(arr[0]);

    printArr(arr, size);
    heapSort(arr, size);
    printArr(arr, size);
return 0;}
