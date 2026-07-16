#include <bits/stdc++.h>

using namespace std;

class Solution{
  public:
    //find the nextPermutation
    void nextPermutation(vector<int> &nums){
      int nSize = nums.size();
      int breakIdx = -1;

      // finding break point
      for (int i = nSize-1; i > 0; i--){
        if(nums[i] > nums[i-1]){
          breakIdx = i-1;
          break;
        }
      }

      if(breakIdx == -1){
        return;
      }

      //finding element just littile bigger
      for (int i = breakIdx+1; i < nSize; i++){
        if(nums[i] > nums[breakIdx]){
          swap(nums[i], nums[breakIdx]);
          break;;
        }
      }

      //sorting with beest case;

    }
    void mySort(vector<int> &arr){
      int n = arr.size();

      for (int i = n-1; i > 0; i--){
        if(arr[i] < arr[i-1]){
          swap(arr[i], arr[i-1]);
        }
      }
    }
};

int main(){
printf("Code is Started Succesfully !\n.\n.\n");

  Solution obj;

  int n;
  cin >> n;

  vector<int> arr(n);

  for (auto &x : arr){
    cin >> x;
  }

  obj.nextPermutation(arr);

  //Next Permutation of arr
  for (auto &x : arr){
    cout << x << " ";
  }

printf("\n.\n.\nCode is Terminated Successfully !\n\n");
return 0;}

/*
7
2 1 5 4 3 0 0

3
1 2 3
*/
