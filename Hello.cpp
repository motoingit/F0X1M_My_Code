/* Question : longest common Subsequence
*/

#include <iostream>
#include <vector>

using namespace std;

string lse1(string &s1, string &s2){
  
  return "defulat";
}

int lse2HELPER(string &s1, string &s2, int idx1, int idx2, vector<vector<int>> &dp){
  // base
  if(s1.size() >= idx1 || s2.size() >= idx2)
    return 0;

    //dp
  if(dp[idx1][idx2] != -1){
    return dp[idx1][idx2];
  }

  // start
  if(s1[idx1] == s2[idx2]){
    return 1 + lse2HELPER(s1, s2, idx1+1, idx2+1, dp);
  }

  int r1 = 0 + lse2HELPER(s1, s2, idx1+1, idx2, dp);
  int r2 = 0 + lse2HELPER(s1, s2, idx1, idx2+1, dp);

  return dp[idx1][idx2] = max(r1, r2);
}

/**
 * TC : O(s1.size + s2.size)
 * wi
 */
int lse2(string &s1, string &s2){
  int n1 = s1.size(), n2 = s2.size();
  vector<vector<int>> dp(n2, vector<int>(n1,-1));
  return lse2HELPER(s1, s2,0,0, dp);
}

int main(){
  string s1 = "dca";
  string s2 = "dec";

  cout << lse2(s1,s2) << endl;

cout << "ProgramTerminated";
return 0;}
