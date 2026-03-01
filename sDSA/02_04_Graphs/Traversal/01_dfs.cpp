
#include <iostream>
#include <vector>
#include <stack>

using namespace std;


                //! RECURSIVE DFS
void dfsHelper_01(vector <vector <int>> &adjList, vector <bool> &visitedArr, int src)
{
    visitedArr[src] = true;
    cout << src << " ";

    for(auto xSrc : adjList[src])
    {
        if(visitedArr[xSrc] == false)
        {
            dfsHelper_01(adjList, visitedArr, xSrc);
        }

        //* else look for anoter
    }

    //* else i have to head back
}

void dfs_01(vector <vector <int>> &adjList, int src)
{
    vector <bool> visitedArr(adjList.size(), false);
    dfsHelper_01(adjList, visitedArr, src);
}

                //! STACK DFS
void dfs_02(vector <vector <int>> &adjList, int src){
    vector <bool> visitedArr(adjList.size(), false);
    stack <int> myStack;

    visitedArr[src] = true;
    myStack.push(src);
    
    while(!myStack.empty()){
        int currEle = myStack.top();
        myStack.pop();
        cout << currEle << " ";

        //* this is also fine but just to get some travesing as Recrusive
        // for(auto xSrc : adjList[currEle]) {
        //     if(!visitedArr[xSrc]) {
        //         myStack.push(xSrc);
        //         visitedArr[xSrc] = true;
        //     }
        // }


        //* Im using this (pushing in rev)
        for (int i = adjList[currEle].size()-1; i >= 0; i--) {
            if(visitedArr[adjList[currEle][i]] == false){
                myStack.push(adjList[currEle][i]);
                visitedArr[adjList[currEle][i]] = true;
            }
        }
    }
}

int main()
{
    vector <vector <int>> adjList = {
        {4}, //0
        {3}, //1
        {3,4}, //2
        {1,2}, //3
        {0,2,5}, //4
        {4}, //5
    };

    dfs_02(adjList, 4);
    return 0;
}
