#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int findPairs(int* nums, int numsSize, int k) {
    if (k < 0 || numsSize < 2)
        return 0;

    qsort(nums, numsSize, sizeof(int), cmp);

    int left = 0, right = 1;
    int pairs = 0;

    while (right < numsSize) {
        if (left == right) {
            right++;
            continue;
        }

        int diff = nums[right] - nums[left];

        if (diff == k) {
            pairs++;

            // Skip duplicates for uniqueness
            int leftVal = nums[left];
            int rightVal = nums[right];

            while (left < numsSize && nums[left] == leftVal)
                left++;
            while (right < numsSize && nums[right] == rightVal)
                right++;
        }
        else if (diff < k) {
            right++;
        }
        else {
            left++;
        }
    }

    return pairs;
}
