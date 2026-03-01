
#include <stdio.h>
#include <stdbool.h>
/*
bool isFound = false;
        unsigned int counter = 0;
        //
        unsigned int left = 0, right = size-1;
        unsigned int mid;
        while(left <= right){
            mid = left + (right-left)/2;

            counter++;
            if(arr[mid] == key){
                isFound = true;
                break;
            }else if(arr[mid] > key){
                right = mid-1;
            }else{
                left = mid+1;
            }
        }
*/
bool binarySearch(int arr[], int size, int key, int *counter, int left, int right, int* mid){
    if(left > right){
        *mid = -1;
        return false;
    }

    (*counter)++; //now the compari st
    *mid = left + (right - left)/2;
    if(arr[*mid] == key){
        return true;
    }else if(arr[*mid] > key){
        right = (*mid) - 1;
    }else{
        left = (*mid) + 1;
    }

    return binarySearch(arr, size, key, counter, left, right, mid);
}

int main() {
    int size;
    scanf("%d",&size);

    int arr[size];
    for (int i = 0; i < size; i++) {
        scanf("%d",&arr[i]);
    }

    int key;
    scanf("%d",&key);
    
    unsigned int counter = 0;
    unsigned int left = 0, right = size-1;
    unsigned int mid;
    if(binarySearch(arr, size, key, &counter, left, right, &mid)){ //call
        printf("Found it !\n");
    }else{
        printf("Faild to Found !\n");
    }
    printf("Comparisons: ");
    printf("%d\n",counter);
return 0;}
