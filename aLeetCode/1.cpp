#include <algorithm>
#include <vector>
#include <iostream>

class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            if(nums.size() < 2){
                return {-1,-1};
            }

            sort(nums.begin(), nums.end());

            int i = 0, j = nums.size() - 1;
            while (i < j){
                int sum = nums[i] + nums[j];
                if(sum < target){
                    i++;
                }else if(sum > target){
                    j--;
                }else if(sum == target){
                    return {i,j};
                }
            }
            
            return {-1, -1};
        }
};
