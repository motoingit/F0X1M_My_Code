#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using myPair = pair<int, int>;

class Solution {
  public:
  int fun1(vector<vector<int>> &adjMat, int initNode){
    int nNode = adjMat.size();
    int minMstWeight = 0;
    vector<bool> visArray(nNode, false);
    priority_queue<myPair, vector<myPair>, greater<myPair>> sortedContainer;
    sortedContainer.push({0, initNode});

    while(sortedContainer.empty() == false){
      myPair currNode = sortedContainer.top();
      sortedContainer.pop();
      int w = currNode.first, v = currNode.second;

      if(visArray[v] == true) continue;
      visArray[v] = true;
      minMstWeight += w;

      for (int i = 0; i < nNode; i++){
        int weightChild = adjMat[v][i];

        //^ -1 means no edge
        if(weightChild == 0) continue;
      
        sortedContainer.push({weightChild, i});
      }
    }

    return minMstWeight;
  }
};

// MAIN
int main(){
  Solution sol;
  vector<vector<int>> graph = {
    {0, 2, 0, 6, 0},
    {2, 0, 3, 8, 5},
    {0, 3, 0, 0, 7},
    {6, 8, 0, 0, 9},
    {0, 5, 7, 9, 0}
  };

  cout << "MST weight " << sol.fun1(graph, 0);
return 0;}
