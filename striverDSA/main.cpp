#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using myPair = pair<int, int>;
const int INF = 1e9;

class Solution {
  public:
    vector<int> dijkstra(int nNode, vector<vector<int>> &edgeList, int srcNode) {

      //convert
      vector<vector<int>> adjList = edges_to_adjList(edgeList, nNode);

      priority_queue <myPair, vector<myPair>, greater<myPair>> pq;
      pq.push({0, srcNode});

      vector<int> distanceArray(nNode, INF);
      distanceArray[srcNode] = 0;

      while (pq.empty() != true){
        pair<int, int> currTop = pq.top();
        int bufferParentWeight_u = currTop.first;
        int bufferParent_u = currTop.second;
        pq.pop();

        //^ not sure
        // if(distanceArray[bufferChild_v] < bufferWeight_u_v) continue;

        for (pair<int, int> edge : adjList[bufferParent_u]){
         //Your Code
        }
      }
      
    }

    vector<vector<int>> edges_to_adjList(vector<vector<int>> edgeList, int nNode){
      vector<vector<int>> adjList(nNode);

      //insert
      for (vector<int> edge : edgeList){
        adjList[edge[0]] = {edge[2], edge[1]};
      }

      return adjList;
    }
};

int main(){
  
return 0;}
