// Question : BFS

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs_02(vector <vector <int>> &adjList, int src){
    vector <bool> visitedArr(adjList.size(), false);
    queue <int> myQueue;

    myQueue.push(src);
    visitedArr[src] = true;

    while (!myQueue.empty())
    {
        int currEle = myQueue.front();
        myQueue.pop();
        cout << currEle << " ";

        for(auto xSrc : adjList[currEle]){
            if(visitedArr[xSrc] == false){
                myQueue.push(xSrc);
                visitedArr[xSrc] = true;
            }
        }
    }
}

int main(){
    vector <vector <int>> adjMat = {
        {1,2},
        {0,3},
        {0,3,4},
        {0,3,4},
        {2,5},
        {3,4},
    };

    bfs_02(adjMat, 0);
    return 0;
}

/*

0: 1,2
1: 0,3
2: 0,3,4
3: 0,3,4
4: 2,5
5: 3,4

*/
