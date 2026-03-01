
void swap(int arr[], int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void sortColors(int* nums, int numsSize) {
    int st = 0, ptr = 0, end = numsSize - 1;

    while (ptr <= end) {
        if (nums[ptr] == 0) {
            swap(nums, ptr, st);
            st++;
            ptr++;
        } 
        else if (nums[ptr] == 2) {
            swap(nums, ptr, end);
            end--;
            // DO NOT increment ptr here
        } 
        else { // nums[ptr] == 1
            ptr++;
        }
    }
}

