// Question : 

//! for only single graph and p-0 c-0

#include <iostream>
#include <vector>

using namespace std;

bool dfs(vector <vector<int>> &adjList, vector<bool> &visitedArr, int currEle, int parent){
    visitedArr[currEle] = true;

    for(auto xNeighbor : adjList[currEle]){
        if(visitedArr[xNeighbor] == false){
            if(dfs(adjList, visitedArr, xNeighbor, currEle) == true){
                return true;
            }
        }else if(xNeighbor != parent){
            cout << "Cycle Found " << endl;
            return true;
        }
    }

    return false;
}

bool isCycle(vector <vector <int>> &adjList){
    vector<bool> visitedArr(adjList.size(), false);
    return dfs(adjList, visitedArr, 0, 0); //todo : starting from 0
}

int main(){
vector<vector<int>> adjList = {
    {1,2,3},
    {0,2,3},
    {0,1,3},
    {0,1,2}
};

    int src = 0; //todo: any node
    cout << isCycle(adjList);
return 0;}
