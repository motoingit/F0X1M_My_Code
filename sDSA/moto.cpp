/* Question : 0/1 knapSack

Imagine you are a thief with a knapsack that has a fixed weight capacity. You are faced with a set of items, each having a specific weight and value. Your goal is to fill the knapsack to maximize the total value without exceeding the weight limit.

The "0/1" constraint is the most important rule:

   * 0 (Exclude): You leave the item behind.

   * 1 (Include): You take the entire item.

   * No Fractions: Unlike the Greedy-based "Fractional Knapsack," you cannot take half of an item to fill remaining space.

   url = https://gemini.google.com/share/38cc83341b89
*/

#include <iostream>
#include <vector>

using namespace std;

int fun2(vector<int> &weight, vector<int> &value, int idx, int cap, vector<vector<int>> &dp) {
   if(idx == value.size() || cap == 0 )
      return 0;
   if(dp[idx][cap] != -1)
      return dp[idx][cap]; 

   //* take
   int take = 0;
   if(cap >= weight[idx]){
      return take + fun2(weight, value, idx+1, cap - weight[idx], dp);
   }

   //* not take
   int notTake = 0 + fun2(weight, value, idx+1, cap, dp);

   return dp[idx][cap] = max(take, notTake);
}

int fun1(vector<int> &weight, vector<int> &value, int cap){
   int n = value.size();
   vector<vector<int>> dp(n,vector<int>(cap+1, 0));

   for (auto& elem : dp) {
      for (auto& hele : elem) {
         printf("[%2d] ", hele);
      }
      cout << endl;
   }
   return fun2(weight, value, 1, cap, dp);
}

int main(){

   vector<int> weight = {2,3,3,4,6};
   vector<int> value = {1,2,5,9,4};
   int cap = 10;

   cout << fun1(weight, value, cap) << endl;

cout << "programTerminated";
return 0;}

/*
Complexity AnalysisTime Complexity: $O(N \times W)$, where $N$ is the number of items and $W$ is the maximum capacity.Space Complexity: $O(N \times W)$ to store the table, though this can be optimized to $O(W)$ by only keeping track of the previous row.
*/
