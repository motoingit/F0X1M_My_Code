// Question : Heapsort
/**
 * Only Distinct Element
 * 
 */

#include <iostream>
#include <vector>
#include <algorithm>
// #include <utility>       both algo and util provide swap

using namespace std;
int heapSize = -1;

void maxHeapify(vector<int> &arr, int currentIdx){
    int leftIdx = currentIdx*2 + 1, rightIdx = currentIdx*2 + 2;
    int larValIdx = currentIdx;

    if(leftIdx <= heapSize && arr[leftIdx] > arr[larValIdx]){
        larValIdx = leftIdx;
    }

    if(rightIdx <= heapSize && arr[rightIdx] > arr[larValIdx]){
        larValIdx = rightIdx;
    }

    if(larValIdx != currentIdx){
        swap(arr[larValIdx], arr[currentIdx]);
        maxHeapify(arr, larValIdx);
    }
}

void buildHeap(vector<int> &arr){
    if(arr.size() <= 1){
        cout<<"Array is empty or not exist";
        return;
    }

    heapSize = arr.size() - 1;

    for(int i = arr.size()/2 -1; i >= 0; i--) {
        maxHeapify(arr, i);
    }
}

void heapSort(vector<int> &arr){
    heapSize = arr.size() - 1;
    buildHeap(arr); 
    for(int i = arr.size() - 1; i >= 1; i--) {
        swap(arr[0], arr[i]);
        heapSize--;
        maxHeapify(arr, 0);
    }
}

int main() {
    int n; cout << "Enter n :"; cin >> n;

    vector<int> arr(n);

    cout << "Enter elements: ";
    for (int i = 0; i < arr.size(); i++) {
        cin >> arr[i];
    }

    heapSort(arr);

    printf("Sorted array:\n");
    for (int i = 0; i < arr.size(); i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
