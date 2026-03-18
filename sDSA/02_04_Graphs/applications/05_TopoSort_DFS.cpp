// Question : Topological Sort using DFS

#include <iostream>
#include <vector>

using namespace std;

void dfsTopoSort(vector<vector<int>> &adjMat, vector<bool> &visitedArr, int currNode){

    if(visitedArr[currNode] == true){
        return;
    }

    visitedArr[currNode] = true;
    for (int i = 0; i < adjMat.size(); i++) {
        if(adjMat[currNode][i] == 1 && visitedArr[i] == false)
            dfsTopoSort(adjMat,visitedArr, i);
    }
    cout << currNode << " ";
}

int main(){
    vector<vector<int>> adjMat = {
        // wat if self loop ? (ignore this)
        {0,0,0,0,0,1,0,0,0,0},
        {1,0,1,0,0,0,0,0,0,0},
        {0,0,0,0,1,0,0,0,0,0},
        {0,0,1,0,0,0,1,1,0,0},
        {0,0,0,1,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,1,0,0,1},
        {0,0,0,0,0,0,0,1,0,0}
    };

    vector<bool> visitedArr(adjMat.size(), false);

    for (int src = 0; src < adjMat.size(); src++) {
        dfsTopoSort(adjMat, visitedArr, src);
    }

return 0;}
