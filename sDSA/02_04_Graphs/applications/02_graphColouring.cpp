#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool canColor(vector<vector<int>> &adjList, int src){

    vector<int> visColor(adjList.size(), -1);
    queue<int> qq;

    qq.push(src);
    visColor[src] = 0;

    while(!qq.empty()){

        int current = qq.front();
        qq.pop();

        for(auto neighbor : adjList[current]){

            if(visColor[neighbor] == -1){

                visColor[neighbor] = 1 - visColor[current];
                qq.push(neighbor);

            }
            else if(visColor[neighbor] == visColor[current]){

                cout << "Graph cannot be colored (Not Bipartite)" << endl;
                return false;

            }

        }

    }

    cout << "Graph can be colored (Bipartite)" << endl;
    return true;
}

int main(){

    vector<vector<int>> adjList = {
        {1,2},
        {0,3},
        {0,3,4},
        {1,2,5},
        {2,5},
        {3,4}
    };

    canColor(adjList,0);

    return 0;
}
