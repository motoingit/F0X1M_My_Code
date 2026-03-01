/*
    I assumed piviot element will be the last one
*/

/* //todo: spaceComplexity = O(1)

*/
#include <stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partitionFun(int arr[], int srt, int end){
    int idx = srt - 1;
    for(int j = srt; j < end; j++){
        if(arr[j] <= arr[end]){ //!  <= for ascending and >= for decending
            idx++;
            swap(&arr[idx],&arr[j]);
        }
    }
    idx++;
    swap(&arr[idx],&arr[end]);
    return idx; //todo:   if i delete this return then it terminates silently
}

void quickSort(int arr[], int srt, int end){
    if(srt < end){
        int pivIdx = partitionFun(arr, srt, end);
        quickSort(arr, srt, pivIdx-1);
        quickSort(arr, pivIdx+1, end);
    }
}

/*
void quickSort(int arr[], int srt, int end){
    while (srt < end) {
        int pivIdx = partitionFun(arr, srt, end);

        // Left side is smaller
        if (pivIdx - srt < end - pivIdx) {
            quickSort(arr, srt, pivIdx - 1);
            srt = pivIdx + 1;   // tail call eliminated
        }
        // Right side is smaller
        else {
            quickSort(arr, pivIdx + 1, end);
            end = pivIdx - 1;   // tail call eliminated
        }
    }
}
This is manual tail-call elimination.
*/

int main(){
    int arr[] = {1,6,4,8,0,34,55,-45};
    int size = sizeof(arr) / sizeof(arr[0]);

    for(int i = 0; i < size; i++){
        printf("%d ",arr[i]);
    }

    quickSort(arr, 0, size-1);

    for(int i = 0; i < size; i++){
        printf("%d ",arr[i]);
    }
return 0;}


/*
| Scenario                                    | Complexity     | Business Reality             |
| ------------------------------------------- | -------------- | ---------------------------- |
| **Best case** (balanced partitions)         | **O(n log n)** | Optimal throughput           |
| **Average case** (random data)              | **O(n log n)** | What you get 90% of the time |
| **Worst case** (already sorted + bad pivot) | **O(n²)**      | Performance disaster         |

*/