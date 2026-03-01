/*

    Question : Build a Graph

        (2) -------- (4)
        |  \
        |   \
        |    \
        |     \
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
            nodeList = NULL;
        }
        GRAPH(int n){
            this->nV = n;
            nodeList = new list<int> [nV]; // vertices dubly_ll
        }

        void addEdge(int u, int v){
            nodeList[u].push_back(v);
            nodeList[v].push_back(u); //todo:  for undirected
        }

        void printAL(){
            for (int i = 0; i < nV; i++)
            {
                cout << i << " : ";
                for(int x : nodeList[i]){
                    cout << x << " ";
                }
                cout << endl;
            }
            
        }
};

int main() {
cout << endl;
    int nVertices = 5;
    GRAPH g(nVertices);

    g.addEdge(0,1); //todo:       why not . instead of ->
    g.addEdge(1,3);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(2,4);

    g.printAL();
cout << endl;
return 0;}
