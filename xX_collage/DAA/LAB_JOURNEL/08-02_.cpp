/*
Minimum Spanning Tree — Kruskal's Algorithm
Problem (Compact):
Same as Prim's — find minimum cost to connect all N cities using N-1 roads. But now use Kruskal's Algorithm (edge-sorted greedy + Union-Find).

Approach — Kruskal's Algorithm:

Extract all edges from adjacency matrix → sort by weight (ascending)
Use Union-Find (DSU) to detect cycles
Greedily pick the smallest edge that doesn't form a cycle
Stop when MST has V-1 edges
Sum of picked edges = minimum spanning weight


Core idea: Always pick globally cheapest safe edge, unlike Prim's which grows from one vertex locally.
*/


/* Question: Minimum Spanning Tree using Kruskal's Algorithm */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ─── Union-Find (DSU) ───────────────────────────────────────
struct DSU {
    vector<int> parent, rank_;

    DSU(int n) : parent(n), rank_(n, 0) {
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);  // path compression
        return parent[x];
    }

    // Returns false if u and v already in same set (cycle!)
    bool unite(int u, int v) {
        int pu = find(u), pv = find(v);
        if (pu == pv) return false;        // would form cycle
        // union by rank
        if (rank_[pu] < rank_[pv]) swap(pu, pv);
        parent[pv] = pu;
        if (rank_[pu] == rank_[pv]) rank_[pu]++;
        return true;
    }
};

// ─── Edge structure ──────────────────────────────────────────
struct Edge {
    int u, v, weight;
    bool operator<(const Edge& other) const {
        return weight < other.weight;      // sort by weight ascending
    }
};

// ─── Graph ───────────────────────────────────────────────────
class Graph {
public:
    int V;
    vector<Edge> edges;

    Graph(int V) : V(V) {}

    void matrixInput() {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                int w; cin >> w;
                // Only upper triangle to avoid duplicate edges
                if (w != 0 && i < j)
                    edges.push_back({i, j, w});
            }
        }
    }

    void kruskalMST() {
        sort(edges.begin(), edges.end());  // sort edges by weight

        DSU dsu(V);
        int totalCost  = 0;
        int edgesPicked = 0;

        cout << "\nEdge\t\tWeight\n";
        cout << "------------------------\n";

        for (auto& e : edges) {
            if (dsu.unite(e.u, e.v)) {    // safe to add (no cycle)
                cout << e.u+1 << " - " << e.v+1
                     << "\t\t" << e.weight << "\n";
                totalCost += e.weight;
                edgesPicked++;
                if (edgesPicked == V - 1) break;  // MST complete
            }
        }

        cout << "------------------------\n";
        if (edgesPicked < V - 1)
            cout << "Graph is disconnected — MST not possible!\n";
        else
            cout << "Minimum Spanning Weight: " << totalCost << "\n";
    }
};

// ─── Main ────────────────────────────────────────────────────
int main() {
    int V;
    cin >> V;

    Graph g(V);
    g.matrixInput();
    g.kruskalMST();

    return 0;
}

/*
Sample Input:
7
0 0 7 5 0 0 0
0 0 8 5 0 0 0
7 8 0 9 7 0 0
5 5 9 0 15 6 0
0 0 7 15 0 8 9
0 0 0 6 8 0 11
0 0 0 0 9 11 0
Expected Output:
Edge            Weight
------------------------
1 - 4           5
2 - 4           5
4 - 6           6
1 - 3           7
3 - 5           7
5 - 7           9
------------------------
Minimum Spanning Weight: 39 ✅

Dry Run (Edge selection order):
Sorted edges:
(1-4,5) (2-4,5) (4-6,6) (1-3,7) (3-5,7) (1-2,8) (5-6,8) (2-3,8)...

Step 1: Pick 1-4 (w=5)  → unite(0,3) ✅  cost=5
Step 2: Pick 2-4 (w=5)  → unite(1,3) ✅  cost=10
Step 3: Pick 4-6 (w=6)  → unite(3,5) ✅  cost=16
Step 4: Pick 1-3 (w=7)  → unite(0,2) ✅  cost=23
Step 5: Pick 3-5 (w=7)  → unite(2,4) ✅  cost=30
Step 6: Skip 1-2 (w=8)  → find(0)==find(1) ❌ cycle
Step 7: Pick 5-7 (w=9)  → unite(4,6) ✅  cost=39

6 edges picked for 7 vertices → MST done!

Prim's vs Kruskal's — Quick Comparison:
Prim'sKruskal'sStrategyGrow from one vertexPick globally cheapest edgeData Structurekey[] + visited[]Sorted edges + DSUBest forDense graphsSparse graphsComplexity (matrix)O(V²)O(E log E)Cycle detectionImplicit (inMST[])Explicit (Union-Find)Same MST cost?✅ Yes✅ Yes
*/
