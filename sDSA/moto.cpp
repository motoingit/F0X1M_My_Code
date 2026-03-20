// Question : Topological Sort using dfs

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void topoSort(vector<vector<int>>&adjList){

   //Counting Degree
   vector<int> degreeArr(adjList.size(), 0);

   for (int i = 0; i < adjList.size(); i++) {
      for (auto& elem : adjList[i]) {
         degreeArr[elem]++;
      }
   }

   queue <int> qq;

   // pushing all 0 incomming vertedx
   for (int i = 0; i < degreeArr.size(); i++) {
      if(degreeArr[i] == 0){
         qq.push(i);
      }
   }

   //now adding front elements
   vector<int> topoOrder;
   while (!qq.empty()) {
      int currNode = qq.front();
      qq.pop();

      topoOrder.push_back(currNode);

      for (auto& elem : adjList[currNode]) {
         degreeArr[elem]--;
         //? can degreeArr[x] -> -1 possible
         if(degreeArr[elem] == 0){
            qq.push(elem);
         }
      }
   }

   //seeing if cycle present
   if(topoOrder.size() != adjList.size()){
      cout << "Cycle !" << endl;
      return;
   }

   //print
   for (auto& elem : topoOrder) {
      cout << " " << elem;
   }
}

int main(){
   vector<vector<int>> adjList = {
        {5},
        {0,2},
        {4},
        {2,6,7},
        {},
        {},
        {},
        {},
        {6,9},
        {7},
    };

    topoSort(adjList);
return 0;}
