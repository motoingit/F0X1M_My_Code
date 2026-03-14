// Question : 
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> fun1(vector<vector<int>>& graph){
    vector<int> count(graph.size(), 0);
    
    int i = 0;
    for (auto& ele1 : graph) {
        int countNum = 0;
        for (auto& ele2 : ele1) {
            countNum++;
        }
        count[i] = countNum;
        i++;
    }

    return count;
}

void khanAlgo(vector<vector<int>>& graph){
    vector<int> degreeNode = fun1(graph);
    queue<int> qq;
    qq.push(0);

    while (!qq.empty()){
        /* code */
    }
    
}

int main(){
    vector<vector<int>> graph = {
        {1, 2},    // Node 0 -> 1, 2
        {3},       // Node 1 -> 3
        {3, 4, 5}, // Node 2 -> 3, 4, 5
        {6},       // Node 3 -> 6
        {6, 7},    // Node 4 -> 6, 7
        {7},       // Node 5 -> 7
        {8, 9},    // Node 6 -> 8, 9
        {9},       // Node 7 -> 9
        {},        // Node 8 (Leaf)
        {}         // Node 9 (Leaf)
    };

    khanAlgo(graph);

return 0;}
