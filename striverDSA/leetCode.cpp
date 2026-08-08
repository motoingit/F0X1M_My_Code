/* Ques: Number of Islands
- leetcode 200

Given:
- m x n 2D binary grid which represent -> map of "1"s (land) and "0"s (water)
- we have to return -> no of island === strongest component
- 

*/

#include <bits/stdc++.h>

using namespace std;

//Solution Class
class Solution {
  public:
    /*
    - uint8_t is 8bit integer
    */
    int noOfIsland(vector<vector<uint8_t>> &mapMatrix){
      int nRow = mapMatrix.size(), nCol = mapMatrix[0].size();
      int countOfIsland = nRow * nCol;
      //! assuming all are island

      for (int rowIdx = 0; rowIdx < nRow; rowIdx++){
        for (int colIdx = 0; colIdx < nCol; colIdx++){
          if(fun1()){
            
          }
        }
      }

    }

};

//Main Function
int main(){
printf("SOF\n◇────◇\n");

  Solution obj;

  int n;
  cin >> n;

  vector<vector<int>> arr(n, vector<int>(n));
    
  //input 2d array
  for (auto &innerArray : arr){
    for (auto &ele : innerArray){
      cin >> ele;
    }
  }

  //* begin
  obj.minimumEffortPath(arr);

  //wrapped 
  for (auto &x : arr){
    for (auto &ele : x){
      cout << ele << " ";
    }
    cout << endl;
  }

printf("\n◇────◇\nEOF\n\n");
return 0;}

/*
7
2 1 5 4 3 0 0

3
1 2 3
*/
