// Question : Khans Algorithm

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void khansAlgo(vector<vector<int>> adjList){
    queue<int> myQueue;
    vector<int> inDegreeArr(adjList.size(), 0);

    // Step 1: Calculate in-degrees
    for (auto& ele1 : adjList) {
        for (auto& ele2 : ele1) {
            inDegreeArr[ele2]++;
        }
    }

    // Step 2: Push all 0 in-degree nodes
    for (int i = 0; i < adjList.size(); i++) {
        if (inDegreeArr[i] == 0) {
            myQueue.push(i);
        }
    }

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

    // Step 4: Cycle detection
    if (topoOrder.size() != adjList.size()) {
        cout << "Cycle detected! Topological sort not possible.";
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
    // cout << adjList[7].size();
return 0;}
