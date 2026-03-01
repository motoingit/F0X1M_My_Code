//* Minimum Spanning Tree

#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

class Graph{
    private:
        int nEdges;
        int nVertex;
        vector<vector<int>> adjList;
    public:
        Graph(){
            nEdges = 0;
            nVertex = 0;
        }
        Graph(int n){
            nEdges = 0;
            nVertex = n;

            for(int i = 0; i < n; i++){
                adjList.push_back({});
            }
        }
        int addEdge(int src, int des, int anotherDir = 0){
            if(adjList.size() <= src || adjList.size() <= des){
                cout << "Wrong Arguments, Try again !" <<src<<des<<adjList.size() << endl;
                return -1;
            }else{
                int flag = 0;
                for(auto x : adjList[src]){
                    if(x == des){
                        flag = 1;
                    }
                }
                if(flag == 1){
                    cout << "Already Aded, Try again !";
                    return -1;
                }
            }

            adjList[src].push_back(des);
            nEdges++;
            
            if(anotherDir == 1){
                adjList[des].push_back(src);
                nEdges++;
            }

            return 0;
        }
        int addVertex(){
            adjList.push_back({}); 
            nVertex++;
            cout << nVertex << " is Added";

            return 0;
        }
        int dfs(int src){
            if(adjList.size() <= src){
                cout << "Incorrect node";
                return -1;
            }

            stack<int> myStack;
            vector<int> visArray(nVertex);
            myStack.push(src);
            visArray[src] = true;

            cout << "Dfs : ";
            while(!myStack.empty()){
                int currNode = myStack.top();
                myStack.pop();
                cout << currNode << " ";

                for(int i = adjList[currNode].size()-1; i >= 0; i--){ //! wonder why you do revverse
                    int nbr = adjList[currNode][i];
                    if(visArray[nbr] == false){
                        myStack.push(nbr);
                        visArray[nbr] = true;
                    }
                }
            }
            cout << endl;

            return 0;
        }
        int bfs(int src){
            if(adjList.size() <= src){
                cout << "Incorrect node";
                return -1;
            }

            queue<int> myQueue;
            vector<int> visArray(nVertex);
            myQueue.push(src);
            visArray[src] = true;

            cout << "Bfs : ";
            while(!myQueue.empty()){
                int currNode = myQueue.front();
                myQueue.pop();
                cout << currNode << " ";

                for(auto &nbr : adjList[currNode]){
                    if(visArray[nbr] == false){
                        myQueue.push(nbr);
                        visArray[nbr] = true;
                    }
                }
            }
            cout << endl;
            return 0;
        }
};

int main()
{
    vector<vector<int>> adjMatrix = {
        //0 1 2 3 4 5 6 7 8
        {0,1,0,0,0,0,0,1,0}, // 0
        {1,0,1,0,0,0,0,1,0}, // 1
        {0,1,0,1,0,1,0,0,1}, // 2
        {0,0,1,0,1,1,0,0,0}, // 3
        {0,0,0,1,0,1,0,0,0}, // 4
        {0,0,1,1,1,0,1,0,0}, // 5
        {0,0,0,0,0,1,0,1,1}, // 6
        {1,1,0,0,0,0,1,0,1}, // 7
        {0,0,1,0,0,0,1,1,0}  // 8
    };

    return 0;
}
