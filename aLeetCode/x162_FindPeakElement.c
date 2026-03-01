#include <stdio.h>

int fuc(int* nums, int low, int high) {
    if (low == high) return low;

    int mid = low + (high - low) / 2;

    if (nums[mid] > nums[mid + 1]) {
        return fuc(nums, low, mid);
    } else { //equal is cannot hapen
        return fuc(nums, mid + 1, high);
    }
}

int findPeakElement(int* nums, int numsSize) {
    return fuc(nums, 0, numsSize - 1);
}

int main(){
    int arr[] = {100,10,20,1,2,3,4,5,6,0};
    int size = sizeof(arr)/sizeof(arr[0]);

    int res = findPeakElement(arr, size);
    printf("%d",res);
}
