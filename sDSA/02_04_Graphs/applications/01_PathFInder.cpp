

#include <iostream>
#include <vector>

using namespace std;

                //! RECURSIVE DFS
void dfsHelper_01(vector <vector <int>> &adjList, vector <bool> &visitedArr, vector<int> &pathArr, int src, int& des)
{
    visitedArr[src] = true;
    pathArr.push_back(src);

    if(src == des){
        cout << "Path : ";
        for(auto step : pathArr){
            cout << step << " ";
        }
        cout << "\n\n";
    }

    for(auto xSrc : adjList[src])
    {
        if(visitedArr[xSrc] == false)
        {
            dfsHelper_01(adjList, visitedArr, pathArr, xSrc, des);
        }
    }

    visitedArr[src] = false;
    pathArr.pop_back();
}

void AllPathFinder_01(vector <vector <int>> &adjList, int src, int des)
{
    vector <bool> visitedArr(adjList.size(), false);
    vector <int> pathArr;

    dfsHelper_01(adjList, visitedArr, pathArr, src, des);
}

int main()
{
    vector <vector <int>> adjList = {
        {1,2,3,5}, //0
        {0,4}, //1
        {0,5}, //2
        {0,4}, //3
        {1,3}, //4
        {0,2,8,9}, //5
        {8,9}, //6
        {9}, //7
        {5,6}, //8
        {5,6,7}, //9
    };


    AllPathFinder_01(adjList, 4, 7);
    return 0;
}
