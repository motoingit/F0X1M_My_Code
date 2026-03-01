#include <vector>
#include <iostream>
#include <set>
#include <unordered_map>

using namespace std;

class Solution {
    public:
        long long maximumSubarraySum(vector<int>& nums, int k) {
            if(nums.size() < k){
                return 0; //todo: not Possible
            }

            long long sum = 0;

            //
            int flag = true;
            set<int> mySet;

            int counter = 0;
            while(flag == true && k+counter <= nums.size()){

                int localSum = 0;
                for(int i = counter; i < k+counter; i++){
                    if(false == mySet.insert(nums.at(i)).second){
                        flag = false;
                        break; //todo: duplicate in subArr
                    }
                    localSum += nums[i];
                }

                if(flag == true){
                    if( localSum >= sum){
                        sum = localSum;
                    }
                }else{
                    //todo: Not Considered to sum
                }

                flag = true; //todo reseting flag
                mySet.clear();
                counter++;
            };
            
            //
            
            return sum;
        }

        //!GPT
        long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        long long currentSum = 0;
        long long maxSum = 0;
        int left = 0;

        for (int right = 0; right < nums.size(); right++) {
            freq[nums[right]]++;
            currentSum += nums[right];

            // If window size > k, shrink it
            if (right - left + 1 > k) {
                freq[nums[left]]--;
                if (freq[nums[left]] == 0)
                    freq.erase(nums[left]);
                currentSum -= nums[left];
                left++;
            }

            // Check if window size == k and all elements distinct
            if (right - left + 1 == k && freq.size() == k) {
                maxSum = max(maxSum, currentSum);
            }
        }

        return maxSum;
    }
};

int main(){
    vector <int> nums = {1,5,4,2,9,9,9};
    int k = 3;

    Solution sc;

    cout << sc.maximumSubarraySum(nums, k);

    return 0;
}
