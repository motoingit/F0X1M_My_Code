/* Question : Belmenford
*/

#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int weight;
    int child;
    int parent;
};

class Graph{
   public:
      int nV;
      int nE;
      vector<vector<Node>> adjList;

      Graph(){
         this->nV = 0;
         this->nE = 0;
         // adjList.resize(nV);
      }
      Graph(int nV, int nE){
         this->nV = nV;
         this->nE = nE;
         adjList.resize(nV);
      }

      /* Inputing Edge's
         - 
      */
      void edgeInput(){
         for (int i = 0; i < nE; i++) {
            int u, w, v;
            cin >> u >> w >> v;
            this->adjList[u].push_back({w, u, v});
            this->adjList[u].push_back({w, v, u});
         }
      }

      /*  
      
      */
      void bellManFord(){
         
      }
   };

int main(){
   int nV, nE;
   cin >> nV;
   cin >> nE;

   Graph g(nV, nE);
   g.edgeInput();

   g.bellManFord();

return 0;}

/*

7 8
0 4 1
0 4 2
1 2 2
2 3 3
2 6 5
2 1 4
3 2 5
4 3 5
0

*/
