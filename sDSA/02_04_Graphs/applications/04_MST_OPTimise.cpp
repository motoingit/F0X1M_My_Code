#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 1. Manually made Disjoint Set (Union-Find) class
class DisjointSet {
    vector<int> parent;
    vector<int> rank;

public:
    // Constructor to initialize disjoint set
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        
        // Initially, every node is its own parent (its own set)
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    // Find operation with Path Compression
    int find(int node) {
        if (node == parent[node]) {
            return node;
        }
        // Path compression: attach the node directly to the root
        return parent[node] = find(parent[node]);
    }

    // Union operation by Rank
    void unionByRank(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);

        if (rootU != rootV) {
            // Attach the smaller rank tree under the root of the higher rank tree
            if (rank[rootU] < rank[rootV]) {
                parent[rootU] = rootV;
            } else if (rank[rootU] > rank[rootV]) {
                parent[rootV] = rootU;
            } else {
                parent[rootV] = rootU;
                rank[rootU]++; // Increase rank if both had the same rank
            }
        }
    }
};

// 2. Optimized Minimum Spanning Tree Function
vector<vector<int>> MinSpanTree(const vector<vector<int>> &adjMat) {
    int V = adjMat.size();
    vector<pair<int, pair<int, int>>> edges;

    // Extract edges: Optimized to avoid duplicates (i < j)
    for (int i = 0; i < V; i++) {
        for (int j = i + 1; j < V; j++) {
            if (adjMat[i][j] != 0) {
                edges.push_back({adjMat[i][j], {i, j}});
            }
        }
    }

    // Sort edges by weight in ascending order
    sort(edges.begin(), edges.end());

    // Create an empty adjacency matrix for our resulting MST
    vector<vector<int>> mstMat(V, vector<int>(V, 0));
    
    // Initialize our manual Disjoint Set
    DisjointSet ds(V);

    for (auto& edge : edges) {
        int weight = edge.first;
        int src = edge.second.first;
        int des = edge.second.second;

        // CYCLE DETECTION: Check if src and des belong to the same set
        if (ds.find(src) != ds.find(des)) {
            // No cycle! Safe to add to MST
            mstMat[src][des] = weight;
            mstMat[des][src] = weight; // Graph is undirected
            
            // Merge the two sets
            ds.unionByRank(src, des);
        } else {
            // Cycle detected
            cout << "Cycle detected! Rejecting edge between " 
                 << (char)('A' + src) << " and " << (char)('A' + des) 
                 << " (Weight: " << weight << ")\n";
        }
    }

    return mstMat; 
}

int main() {
    vector<vector<int>> adjMat_1 = {
        //A  B  C  D  E  F
        {0, 2, 4, 0, 0, 0}, // A
        {2, 0, 2, 4, 2, 0}, // B
        {4, 2, 0, 0, 3, 0}, // C
        {0, 4, 0, 0, 3, 2}, // D
        {0, 2, 3, 3, 0, 2}, // E
        {0, 0, 0, 2, 2, 0}  // F
    };
    
    vector<vector<int>> newMat = MinSpanTree(adjMat_1);

    // Print the output matrix
    cout << "\nMinimum Spanning Tree Adjacency Matrix:\n";
    cout << "  A B C D E F\n";
    for(int i = 0; i < newMat.size(); i++) {
        char nodeLabel = 'A' + i;
        cout << nodeLabel << " ";
        for(int j = 0; j < newMat[i].size(); j++) {
            cout << newMat[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
