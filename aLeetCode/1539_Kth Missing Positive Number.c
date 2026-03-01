#include <stdio.h>

int findKthPositive(int* arr, int arrSize, int k) {
    int k = 0;

    for(int i = 1; i < arr[0]; i++){
        k++;
    }

    for(int i = 0; i < arrSize - 1; i++){ // size -1 as arr[i+1 is acessing]
        if(arr[i]+1 != arr[i+1]){ //as said stricty increasing
            for(int j = arr[i]+1; j < arr[i+1]; j++){
                k++;
            }
        }
    }

    return k;
}

int main() {
    int k = 0;
    int arr[] = {2,3,4,7,11};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("%d",findKthPositive(arr, n, k));
return 0;}
