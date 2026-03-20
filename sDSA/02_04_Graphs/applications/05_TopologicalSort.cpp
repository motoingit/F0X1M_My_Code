// Question : Khans Algorithm

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void khansAlgo(vector<vector<int>> adjList){
    queue<int> myQueue;
    vector<int> inDegreeArr(adjList.size(), 0);

    //doubt? should i check Directed-Acylic or not ?

    // Step 1: Calculate in-degrees
    for (auto& ele1 : adjList) {
        for (auto& ele2 : ele1) {
            inDegreeArr[ele2]++;
        }
    }

    // Step 2: Push all 0 in-degree nodes at start
    for (int i = 0; i < adjList.size(); i++) {
        if (inDegreeArr[i] == 0) {
            myQueue.push(i);
        }
    }

    //* to store the dependency order
    vector<int> topoOrder;

    // Step 3: Process queue
    while (!myQueue.empty()) {
        int xEle = myQueue.front();
        myQueue.pop();

        topoOrder.push_back(xEle);

        // Reduce indegree of neighbors
        for (auto neighbor : adjList[xEle]) {
            inDegreeArr[neighbor]--;
            if (inDegreeArr[neighbor] == 0) {
                myQueue.push(neighbor);
            }
        }
    }

    //! still this cycle detection is not in my mind fully
    // Step 4: Cycle detection
    if (topoOrder.size() != adjList.size()) {
        cout << "Cycle detected ! Topological sort not possible.";
        return;
    }

    // Print result
    for (int node : topoOrder) {
        cout << node << " ";
    }
}

int main(){
    vector<vector<int>> adjList = {
        {5},
        {0,2},
        {4},
        {2,6,7},
        {},
        {},
        {},
        {},
        {6,9},
        {7},
    };

    khansAlgo(adjList);
return 0;}
