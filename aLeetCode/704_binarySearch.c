int search(int* nums, int numsSize, int target) {
         int low = 0, high = numsSize - 1;

        int idxFound = -1;
        while (low <= high) {
          int mid = low + (high - low) / 2; //this is stable mid

            if (nums[mid] == target) {
                idxFound = mid;
                break;

            }else if (nums[mid] < target) {
                low = mid + 1;

            }else if (nums[mid] > target) {
                high = mid - 1;
            }
        }

    return idxFound;
}
