// Question : 

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    public:
        int removeDuplicates(vector<int>& nums) {
            // if (size < 2)

            int left = 0, right = 1;
            int container = nums[left];
            int count = 1;

            while (right < nums.size()){
                if(container != nums[right]){
                    nums[++left] = nums[right];
                    container = nums[right];
                    count++;
                }

                right++;
            }
            return count; //! you can place left here also
        }
};

// int main(){
//     Solution obj;
//     vector <int> arr = {1,2,3,4};
//     // for(auto x : obj.twoSum(arr, 3)){
//     //     cout << x << " ";
//     // }

// return 0;}
