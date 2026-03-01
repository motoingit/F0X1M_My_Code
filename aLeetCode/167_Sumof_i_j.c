/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdlib.h>

int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    
    *returnSize = 2;
    int *ptr = (int*)malloc(sizeof(int) * (*returnSize));

    if(!ptr){
        *returnSize = 0;
        return NULL;
    }

    ptr[0] = -1, ptr[1] = -1; //* even though they said i gerenty

    int i = 0, j = numbersSize -1;
    while(i < j){
        int res = numbers[i] + numbers[j];
        if(res == target){
            ptr[0] = i+1, ptr[1] = j+1;
            return ptr;
        }else if(res > target){
            j--;
        }else{
            i++;
        }
    }
    return ptr;
}
