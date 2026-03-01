// Question : Build a Graph
/*

       (2) -------- (4)
       |  
       |   
       |    
       |     
(0)----(1)----(3)

*/
#include <iostream>
#include <vector>
#include <list>
using namespace std;

class GRAPH{
    int nV;
    list<int> *nodeList;  // int *arr

    public:
        GRAPH(){ //! this is undefined
            this->nV = 0;
            nodeList =nullptr;
        }
        GRAPH(int n){
            this->nV = n;
            nodeList = new list<int> [nV]; // vertices dubly_ll
        }

        void addEdge(int u, int v){
            nodeList[u].push_back(v);
            nodeList[v].push_back(u); //todo:  for undirected
        }

        void dfsHelper(int u, vector<bool> &vis){ //!    O(V+E)     worst case
            cout << u << " ";
            vis[u] = true;
            
            for(int v : nodeList[u]){
                if(!vis[v]){
                    dfsHelper(v, vis);
                }
            }
        }

        void dfs(){
            int src = 0;
            vector<bool> vis(nV, false);
            dfsHelper(src, vis);
            cout << endl;
        }
};

int main() {
cout << endl;

//? exaple 1
    int nVertices = 5;
    // printf("dd");
    // cin >> nVertices;
    GRAPH g(nVertices);

    g.addEdge(0,1); //todo:       why not . instead of ->
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,4);

    g.dfs();


//? exaple 2
    GRAPH g2(11);
    g2.addEdge(0,1);
    g2.addEdge(0,3);
    g2.addEdge(0,4);
    g2.addEdge(0,8);
    g2.addEdge(1,2);
    g2.addEdge(1,4);
    g2.addEdge(5,6);
    g2.addEdge(5,4);
    g2.addEdge(7,8);
    g2.addEdge(8,9);
    g2.addEdge(8,10);

    g2.dfs();

cout << endl;
return 0;}
