#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Structure to represent a directed edge
struct Edge {
    int u, v, weight;
};

int main() {
    int V;
    
    // 1. Read number of vertices
    cin >> V;

    vector<Edge> edges;
    
    // 2. Parse the adjacency matrix
    // Using 1-based indexing as the sample output suggests nodes 1 to V
    for (int i = 1; i <= V; ++i) {
        for (int j = 1; j <= V; ++j) {
            int weight;
            cin >> weight;
            // A non-zero value indicates a directed edge from i to j
            if (weight != 0) {
                edges.push_back({i, j, weight});
            }
        }
    }

    int src;
    // 3. Read the source vertex
    cin >> src;

    // 4. Initialize distance and parent arrays
    vector<int> dist(V + 1, INT_MAX);
    vector<int> parent(V + 1, -1);
    
    dist[src] = 0;

    // 5. Core Bellman-Ford Algorithm
    // Relax all edges (V - 1) times to find the shortest paths
    for (int i = 1; i <= V - 1; ++i) {
        for (const auto& edge : edges) {
            if (dist[edge.u] != INT_MAX && dist[edge.u] + edge.weight < dist[edge.v]) {
                dist[edge.v] = dist[edge.u] + edge.weight;
                // Track the predecessor to reconstruct the path later
                parent[edge.v] = edge.u;
            }
        }
    }

    // 6. Output formatting
    // Print the reverse path (destination to source) and the minimum path weight
    for (int i = 1; i <= V; ++i) {
        if (dist[i] != INT_MAX) {
            int curr = i;
            // Backtrack using the parent array
            while (curr != -1) {
                cout << curr;
                if (curr != src) {
                    cout << " ";
                }
                curr = parent[curr];
            }
            cout << " : " << dist[i] << "\n";
        }
    }

    return 0;
}
