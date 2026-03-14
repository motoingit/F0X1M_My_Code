#include <stdio.h>

int binarySearch(int arr[], int size, int key) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        // printf("Yes\n");
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;  // element not found
}

int binarySearchReverse(int arr[], int size, int key) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            high = mid - 1;
        else
            low = mid + 1;
    }

    return -1;  // element not found
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13,86,90,97,99};  // SORTED ARRAY
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 86;

    int index = binarySearch(arr, size, key);

    if (index != -1)
        printf("Element found at index %d\n", index);
    else
        printf("Element not found\n");

    return 0;
}
