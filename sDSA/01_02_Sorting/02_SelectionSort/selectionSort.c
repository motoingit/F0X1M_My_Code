/*
    Time complexity = O(n square)
*/

#include <stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int arr[], int size){
    for(int i = 0; i < size-1; i++){
        int sIdx = i;
        for(int j = i+1; j < size; j++){
            if(arr[sIdx] > arr[j]){
                sIdx = j;
            }
        }
        if(sIdx != i){
            swap(&arr[sIdx],&arr[i]);
        }
    }
}


int main(){
    int arr[] = {4,1,5,2,3};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Before Sorting: ");
    for(int i = 0; i < size; i++)
        printf("%d ", arr[i]);

    selectionSort(arr, size);

    printf("\nAfter Sorting: ");
    for(int i = 0; i < size; i++)
    printf("%d ", arr[i]);

return 0;}

/*
| Case       | Time Complexity | Reason                       |
| ---------- | --------------- | ---------------------------- |
| Best Case  | **O(n²)**       | Always scans remaining array |
| Average    | **O(n²)**       | No early stopping            |
| Worst Case | **O(n²)**       | Full comparisons             |



Space Complexity
    Uses only a few extra variables (i, j, sIdx, temp)
    Space Complexity: O(1) (In-place sorting)

Stability
    ❌ Unstable

Recursion
    no

comparitive
    yes

adaptive
    no
*/