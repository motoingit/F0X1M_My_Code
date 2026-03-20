#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Edge {
    int weight, child, parent; // Added parent to track the MST structure
};

struct Compare {
    bool operator()(Edge& a, Edge& b) {
        return a.weight > b.weight;  // min-heap behavior
    }
};

int primsAlgo(vector<vector<Edge>> &adjList, vector<Edge> &mstResult, int startNode) {
    int totalWeight = 0;
    int nV = adjList.size();
    
    priority_queue<Edge, vector<Edge>, Compare> pq;
    vector<bool> visitedArr(nV, false);

    // Initial "dummy" edge to start the process: weight 0, target is startNode, no parent (-1)
    pq.push({0, startNode, -1});

    while (!pq.empty()) {
        Edge curr = pq.top();
        pq.pop();

        int u = curr.child;

        // Skip if we've already included this node in the MST
        if (visitedArr[u]) continue;

        // Mark as visited and add to MST weight
        visitedArr[u] = true;
        totalWeight += curr.weight;
        
        // If it's not the first dummy node, add to our MST result list
        if (curr.parent != -1) {
            mstResult.push_back(curr);
        }

        // Check all neighbors of the newly added node 'u'
        for (auto& edge : adjList[u]) {
            if (!visitedArr[edge.child]) {
                pq.push(edge);
            }
        }
    }
    
    return totalWeight;
}

int main() {
    int nV, nE;
    cout << "Enter number of vertices: ";
    cin >> nV;
    cout << "Enter number of edges: ";
    cin >> nE;

    vector<vector<Edge>> adjList(nV);

    cout << "Enter edges (source, weight, destination):" << endl;
    for (int i = 0; i < nE; i++) {
        int u, w, v;
        cin >> u >> w >> v;
        // Since it's undirected, add edges for both directions
        adjList[u].push_back({w, v, u});
        adjList[v].push_back({w, u, v});
    }

    vector<Edge> mstResult;
    int totalWeight = primsAlgo(adjList, mstResult, 0);

    // Print MST results
    cout << "\n--- Final MST ---" << endl;
    cout << "Total MST Weight: " << totalWeight << endl;
    cout << "Edges in MST (Parent -> Child [Weight]):" << endl;
    for (auto& edge : mstResult) {
        cout << edge.parent << " - " << edge.child << " [" << edge.weight << "]" << endl;
    }

    return 0;
}
