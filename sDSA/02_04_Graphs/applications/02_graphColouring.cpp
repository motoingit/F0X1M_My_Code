// Question : Colour Graph

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int findColor(vector<int> &visColor, vector<vector<int>> &adjList, int src){
    int color = -1;
    for(auto x : adjList[src]){
        for (auto x)
        {
            visColor[x]
        }
        
    }
    return color;
}

//* Invert Color
void canColor(vector <vector<int>> &adjList, int src){
    vector <int> visColor(adjList.size(), -1);
    queue <int> qq;

    qq.push(src);
    visColor[src] = 0;

    while (!visColor.empty())
    {
        int current = qq.front();
        qq.pop();

        if(visColor[current] )
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

    canColor(adjMat, 0);

return 0;}
