#include <stdio.h>

int linearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key)
            return i;   // element found
    }
    return -1;          // element not found
}

int main() {
    int arr[] = {5, 2, 9, 1, 7, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 7;

    int index = linearSearch(arr, size, key);

    if (index != -1)
        printf("Element found at index %d\n", index);
    else
        printf("Element not found\n");

    return 0;
}
