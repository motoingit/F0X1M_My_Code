

#include <iostream>
#include <vector>

using namespace std;

                //! RECURSIVE DFS
bool dfsHelper_01(vector <vector <int>> &adjList, vector <bool> &visitedArr, vector<bool> &recPathArr, int curr)
{
    visitedArr[curr] = true;
    recPathArr[curr] = true;

    for(auto xSrc : adjList[curr])
    {
        if(!visitedArr[xSrc])
        {
            if(dfsHelper_01(adjList, visitedArr, recPathArr, xSrc))
                return true;
        }
        else if(recPathArr[xSrc])
        {
            return true;
        }
    }

    recPathArr[curr] = false;
    return false;
}

bool cycleDir(vector <vector <int>> &adjList)
{
    vector <bool> visitedArr(adjList.size(), false);
    vector <bool> recPathArr(adjList.size(), false);

    for (int i = 0; i < adjList.size(); i++) {
        if(visitedArr[i] == false 
        && dfsHelper_01(adjList, visitedArr,recPathArr, i) ){
            return true;
        }
    }
    return false;
}

int main()
{
vector<vector<int>> adjList = {
    {2},
    {},
    
    {}
};




    cout << endl << cycleDir(adjList);
    return 0;
}
