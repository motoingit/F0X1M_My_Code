// Question : 
#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;

// DFS helper to check if a path already exists between 'curr' and 'target'
bool hasPathDFS(const vector<vector<int>>& currentMST, int curr, int target, vector<bool>& visited) {
    // Base case: If we reached the target, a path exists!
    if (curr == target) return true;
    
    visited[curr] = true;
    
    // Check all neighbors of the current node
    for (int neighbor = 0; neighbor < currentMST.size(); neighbor++) {
        // If there is an edge in our currenSt MST AND we haven't visited the neighbor
        if (currentMST[curr][neighbor] != 0 && !visited[neighbor]) {
            if (hasPathDFS(currentMST, neighbor, target, visited)) {
                return true;
            }
        }
    }
    
    return false;
}

vector<vector<int>> MinSpanTree(vector<vector<int>> &adjMat){
    vector <pair <int, pair<int,int>>> edges;

    for (int i = 0; i < adjMat.size(); i++) {
        for (int j = 0; j < adjMat.size(); j++) {
            if(adjMat[i][j] != 0){
                int weight = adjMat[i][j];
                int src = i;
                int des = j;

                /*
                    5 (1,2);
                    5 (2,1);
                */
                edges.push_back({weight,{src,des}}); //! twice ?
            }
        }
    }

    // 2. Sort edges by weight in ascending order
    sort(edges.begin(), edges.end());

    // 3. Create an empty adjacency matrix for our resulting MST
    vector<vector<int>> mstMat(adjMat.size(), vector<int>(adjMat.size(), 0));

    for (auto& edge : edges) {
        int weight = edge.first;
        int src = edge.second.first;
        int des = edge.second.second;

        // Reset visited array for the new DFS search
        vector<bool> visited(adjMat.size(), false);

        // CYCLE DETECTION: If there is NO existing path between src and des in mstMat...
        if (!hasPathDFS(mstMat, src, des, visited)) {
            // ...it's safe to add this edge to our MST!
            mstMat[src][des] = weight;
            mstMat[des][src] = weight; // Graph is undirected
        } else {
            // Uncomment the line below to see DFS actively rejecting cycles
            cout << "Cycle detected! Rejecting edge between " << src << " and " << des << " (Weight: " << weight << ")\n";
        }
    }

    return mstMat; // Return the final MST graph
}

int main(){
    vector<vector<int>> adjMat_1 = {
        //A B C D E F
        {0, 2, 4, 0, 0, 0}, // A
        {2, 0, 2, 4, 2, 0}, // B
        {4, 2, 0, 0, 3, 0}, // C
        {0, 4, 0, 0, 3, 2}, // D
        {0, 2, 3, 3, 0, 2}, // E
        {0, 0, 0, 2, 2, 0} // F
    };
    
    vector<vector<int>> newMat = MinSpanTree(adjMat_1);

     // Print the output matrix
    cout << "Minimum Spanning Tree Adjacency Matrix:\n";
    cout << "  A B C D E F\n";
    for(int i = 0; i < newMat.size(); i++) {
        char nodeLabel = 'A' + i;
        cout << nodeLabel << " ";
        for(int j = 0; j < newMat[i].size(); j++) {
            cout << newMat[i][j] << " ";
        }
        cout << "\n";
    }

    int n;
    cin >> n;

return 1;}
