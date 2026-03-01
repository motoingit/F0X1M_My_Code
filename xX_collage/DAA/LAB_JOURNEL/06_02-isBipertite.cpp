// Question : Graph is bipertite or not

/*
///todo: only for undirected and sigle comoponent
*/
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

bool fun1(vector<vector<int>> &adjList, int src){

    queue<int> myQueue;
    vector <int> colourArr(adjList.size(), -1); //* also visited array

    myQueue.push(src);
    colourArr[src] = 0;

    while (!myQueue.empty()){
        int curr = myQueue.front();
        myQueue.pop();

        for(auto xNeighbour : adjList[curr]){
            if(colourArr[xNeighbour] == -1){
                colourArr[xNeighbour] = !colourArr[curr]; //! opposite color (!)
                myQueue.push(xNeighbour);
            }else if(colourArr[xNeighbour] == colourArr [curr]){ 
                cout << curr << " and " << xNeighbour << " is same color"<< endl;
                return false; //! found the critical point
            }
        }
    }
    
    return true;
}

int main(){
vector<vector<int>> adjList = {
    {1},
    {0,2},
    {1,3},
    {2,4},
    {3,1}
};



    int src = 0; //todo: any node
    cout << fun1(adjList, src);
return 0;}
