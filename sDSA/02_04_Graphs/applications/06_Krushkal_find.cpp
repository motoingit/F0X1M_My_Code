// Question : MST using prims

#include <iostream>
#include <queue>

using namespace std;

struct Edge {
   int parent, weight, child;
};

struct Compare {
   bool operator()(Edge& a, Edge& b) {
      return a.weight > b.weight;  // min-heap behavior
   }
};

/*

*/
int primsAlgo(vector<vector<Edge>> &adjList,vector<vector<Edge>> &mstList, Edge& src){
   int totalWeight = 0;

   priority_queue<Edge, vector<Edge>, Compare> pq;
   vector<bool> visitedArr(adjList.size(), false);
   pq.push({src});

   while (!pq.empty()){
      Edge curr = pq.top();
      pq.pop();

      if(visitedArr[curr.child] == true){
         continue;
      }else{
         visitedArr[curr.child] = true;
      }

      //add to mst
      totalWeight += curr.weight;
      for (auto& elem : adjList[curr.parent]) {
         if(visitedArr[elem.child] == false){
            pq.push(elem);
         }
      }
   }
   
   return totalWeight;
}

int main(){
   int nV, nE;
   cout << "Enter nV : ";
   cin >> nV;
   //below is same as == vector<Edge> adjList[nV]; //! this gives error
   vector<vector<Edge>> adjList(nV);

   cout << "Enter nE : ";
   cin >> nE;

   cout << "\t< Enter nE Horizontally >" << endl;
   cout << "\t< parent, weight, child >" << endl;
   //Edge input
   for (int i = 0; i < nE; i++) { 
      int parent, weight, child;
      cin >> parent >> weight >> child;
      adjList[parent].push_back({parent,weight,child});
      adjList[child].push_back({child,weight,parent}); //* undireced
   }

   //Saving MST weight
   vector<vector<Edge>> mstList;
   Edge src = {0,0,-1}; //! parent 0, weg = 0, child = -1
   int mstNum =  primsAlgo(adjList, mstList, src); // 0 for now as src

   //print MST
   cout << "This is the Final Mst" << "<" << mstNum << ">" << endl;
   for (int i = 0 ; i < nV; i++) {
      cout << i << " : ";
      for (auto& elem2 : adjList[i]) {
         cout << elem2.parent << ","<< elem2.parent << ","<< elem2.parent << " | ";
      }
      cout << endl;
   }

return 0;}
