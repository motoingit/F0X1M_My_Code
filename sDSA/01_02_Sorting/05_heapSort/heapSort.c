#include <stdio.h>

// Global heap size (as in CLRS)
int heap_size;

// Utility function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Max-Heapify function
void maxHeapify(int A[], int i) {
    int largest;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= heap_size && A[left] > A[i])
        largest = left;
    else
        largest = i;

    if (right <= heap_size && A[right] > A[largest])
        largest = right;

    if (largest != i) {
        swap(&A[i], &A[largest]);
        maxHeapify(A, largest);
    }
}

// Heap-Sort function
void heapSort(int A[], int n) {
    heap_size = n;
    for (int i = n / 2; i >= 1; i--) { // build heapStructure
        maxHeapify(A, i);
    }
    
    for (int i = n; i >= 2; i--) {
        swap(&A[1], &A[i]);
        heap_size--;
        maxHeapify(A, 1);
    }
}

//! zero is always empty
// Main function
int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Array size n+1 to use 1-based indexing
    int A[n + 1];

    printf("Enter elements:\n");
    for (int i = 1; i <= n; i++) {
        scanf("%d", &A[i]);
    }

    heapSort(A, n);

    printf("Sorted array:\n");
    for (int i = 1; i <= n; i++) {
        printf("%d ", A[i]);
    }

    return 0;
}
