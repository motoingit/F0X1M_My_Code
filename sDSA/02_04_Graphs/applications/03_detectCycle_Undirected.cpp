// Question : Find a Cycle in Graph

#include <iostream>
#include <vector>

using namespace std;

bool dfsHelper(vector <vector <int>> &adjList, vector <bool> &visitedArr, int src, int parent)
{
    visitedArr[src] = true;

    for(auto xSrc : adjList[src])
    {
        if(visitedArr[xSrc] == false)
        {
            if(dfsHelper(adjList, visitedArr, xSrc, src)){
                return true;
            }
        }else{
            if(xSrc != parent){
                return true;
            }
        }
    }

    return false;
}

bool isCycle(vector <vector <int>> &adjList)
{
    vector <bool> visitedArr(adjList.size(), false);

    for (int i = 0; i < adjList.size(); i++) {
        if(visitedArr[i] == false && dfsHelper(adjList, visitedArr, i, i) ){
            return true;
        }
    }
    return false;
}

int main()
{
vector<vector<int>> adjList = {
    {1},        // 0
    {},         // 1

    {2},        // 2
    {},         // 3 (isolated)

    {4},        // 4
    {4}         // 5 -> Self loop at 4? No. Edge 5→4 only. No cycle here.
};


    cout << isCycle(adjList) << "Cycle";
    return 0;
}


/* //! for directed

bool dfsHelper(vector<vector<int>> &adjList,
               vector<bool> &visited,
               vector<bool> &recStack,
               int node)
{
    visited[node] = true;
    recStack[node] = true;

    for (int neighbor : adjList[node])
    {
        if (!visited[neighbor])
        {
            if (dfsHelper(adjList, visited, recStack, neighbor))
                return true;
        }
        else if (recStack[neighbor])   // 🔥 Key condition
        {
            return true;
        }
    }

    recStack[node] = false;  // Backtrack
    return false;
}

bool isCycle(vector<vector<int>> &adjList)
{
    int n = adjList.size();
    vector<bool> visited(n, false);
    vector<bool> recStack(n, false);

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            if (dfsHelper(adjList, visited, recStack, i))
                return true;
        }
    }

    return false;
}


*/
