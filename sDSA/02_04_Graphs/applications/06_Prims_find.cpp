/*
        ///! Prims Algorithms
1- find the edge with min weight (0)
2- now select those edge this time which is not selected earlier and which is connected to the already visited vertex
3- repeat step 2 untill all nodes are visited
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Edge {
    int weight;
    int child;
    int parent;
};

struct Compare {
    bool operator()(Edge& a, Edge& b) {
        //* a is the inserted and b is the relative
        return a.weight > b.weight;  // min-heap behavior
        //! if false then go up
    }
};

int primsAlgo(vector<vector<Edge>> &adjList, vector<Edge> &mstResult, int startNode) {
    int totalWeight = 0;
    int nV = adjList.size();
    
    vector<bool> visitedArr(nV, false);
    priority_queue<Edge, vector<Edge>, Compare> pq;

    //! Initially dummy edge is pushed (parent -1, weight 0)
    pq.push({0, startNode, -1});

    while (!pq.empty()) {
        Edge curr = pq.top();
        pq.pop();

        int u = curr.child;

        if (visitedArr[u]) continue; //* avoid cycle and revisiting
        //todo: can we put a nV == count to go out on done

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
        adjList[v].push_back({w, u, v});
        adjList[u].push_back({w, v, u});
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
