// Question : Build a Graph
/*

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
#include <queue>
using namespace std;

class GRAPH{
    int nV;
    int nE;
    list<int> *nodeList;  // int *arr

    public:
        GRAPH(){ //! this is undefined
            this->nV = 0;
            this->nE = 0;
            nodeList = nullptr; //! this is good
        }
        GRAPH(int n){
            this->nV = n;
            this->nE = 0;
            nodeList = new list<int> [nV]; // vertices dubly_ll
        }
        ~GRAPH() {
            delete[] nodeList;
        }


        void addEdge(int u, int v){
            nE++;
            nodeList[u].push_back(v);
            nodeList[v].push_back(u); //todo:  for undirected
        }

        void bfs_trav(int src){
            queue<int> Q;
            vector<bool> Vis_arr(nV, false); //* nV size and falseINITIATED

            Q.push(src); //* in our case 0 is subjected node;
            Vis_arr[src] = true;

            while(Q.size() > 0){
                int u = Q.front();
                Q.pop();
                cout << u << " ";

                for(int v : nodeList[u]){
                    if(!Vis_arr[v]){
                        Q.push(v);
                        Vis_arr[v] = true;
                    }
                }
            }
            cout << endl;
        }
};

int main() {
cout << endl;
    int nVertices = 5;
    // printf("dd");
    // cin >> nVertices;
    GRAPH g1(nVertices);
    g1.addEdge(0,1); //todo:       why not . instead of ->
    g1.addEdge(1,3);
    g1.addEdge(1,2);
    g1.addEdge(2,3);
    g1.addEdge(2,4);

    g1.bfs_trav(0); //? src is 0




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

    g2.bfs_trav(0);
cout << endl;
return 0;}
