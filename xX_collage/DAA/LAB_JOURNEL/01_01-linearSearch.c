// Linear Search Funtion in Cpp
#include <stdio.h>

int linearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i;  // element found at index i
        }
    }
    return -1;  // element not found
}

//Binary Search Funtion in Cpp
int binarySearch(int arr[], int size, int key) {
    int low = 0, high = size - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2; //this is stable mid
        if (arr[mid] == key) {
            return mid;  // element found at index mid
        } else if (arr[mid] < key) {
            low = mid + 1;  // search in the right half
        } else {
            high = mid - 1; // search in the left half
        }
    }
    return -1;  // element not found
}
