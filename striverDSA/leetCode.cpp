/* Ques:

*/

#include <bits/stdc++.h>

using namespace std;

//Solution Class
class Solution {
  public:
    int minimumEffortPath(vector<vector<int>>& heights) {
      int nRow = heights.size(), nCol = heights[0].size();
      vector<vector<int>> visitedNode(nRow, vector<int>(nCol, 0));
      visitedNode[0][0] = 1;

      int maxDif = 0;
      int idxRow = 0, idxCol = 0;
      while(true){
        if( idxRow == nRow - 1 && idxCol == nCol - 1 ){
          return maxDif;
        }

        //check for which direction
        [idxRow, idxCol] = fun(visitedNode, heights, idxRow, idxCol);

        //found min idx's
        visitedNode[idxRow][idxCol] = 1;
      }
    }

    pair<int, int> fun(){

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
