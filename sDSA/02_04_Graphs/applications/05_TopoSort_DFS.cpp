// Question : Topological Sort using DFS

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void dfsTopoSort(vector<vector<int>> &adjMat, vector<bool> &visitedArr, stack <int> &myStack, int currNode){

    visitedArr[currNode] = true;
    for (int i = 0; i < adjMat.size(); i++) {
        if(adjMat[currNode][i] == 1 && visitedArr[i] == false)
            dfsTopoSort(adjMat,visitedArr, myStack, i);
    }
    myStack.push(currNode);
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

    // 0 0 0 0 0 0 0 0 0 0
    vector<bool> visitedArr(adjMat.size(), false);
    stack <int> myStack;

    for (int src = 0; src < adjMat.size(); src++) {
        if(visitedArr[src] == false){
            dfsTopoSort(adjMat, visitedArr, myStack, src);
        }
    }

    while (!myStack.empty()){
       cout << myStack.top() << " ";
       myStack.pop();
    }
    
return 0;}
