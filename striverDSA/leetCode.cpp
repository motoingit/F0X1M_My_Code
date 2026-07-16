#include <iostream>
#include <vector>

using namespace std;

class Solution{
  public:
    int subArraySum(vector<int>& nums){
      int n = nums.size();
      long long int maxSum = LLONG_MIN;
      long long int currSum = 0;

      for (int i = 0; i < n; i++){
        currSum += nums[i];
        maxSum = max(currSum, maxSum);

        // hearth of kadans
        if (currSum < 0) {
            currSum = 0; 
        }
      }

      return maxSum;
    }
};
