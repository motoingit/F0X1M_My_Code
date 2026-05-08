/*
Maximum Spanning Tree — Greedy Kruskal's (Reversed)Problem (Compact):
Same graph, same N-1 roads constraint — but the greedy person wants to maximize total construction cost. Find the Maximum Spanning Tree weight.Approach:

Identical to Kruskal's MST but sort edges in descending order instead of ascending
Same Union-Find cycle detection applies
Pick the heaviest edge that doesn't form a cycle, repeat until V-1 edges chosen

One-line change from Kruskal's Min: sort descending → Max Spanning Tree. Everything else (DSU, logic) stays identical.
*/

/* Question: Maximum Spanning Tree using Kruskal's (Descending Sort) */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ─── Union-Find (DSU) ────────────────────────────────────────
struct DSU {
    vector<int> parent, rank_;

    DSU(int n) : parent(n), rank_(n, 0) {
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);   // path compression
        return parent[x];
    }

    bool unite(int u, int v) {
        int pu = find(u), pv = find(v);
        if (pu == pv) return false;         // cycle detected
        if (rank_[pu] < rank_[pv]) swap(pu, pv);
        parent[pv] = pu;
        if (rank_[pu] == rank_[pv]) rank_[pu]++;
        return true;
    }
};

// ─── Edge ────────────────────────────────────────────────────
struct Edge {
    int u, v, weight;
    // ↓ ONLY CHANGE from Min ST: sort descending
    bool operator<(const Edge& other) const {
        return weight > other.weight;
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
                if (w != 0 && i < j)        // upper triangle only
                    edges.push_back({i, j, w});
            }
        }
    }

    void maximumSpanningTree() {
        sort(edges.begin(), edges.end());   // descending (heaviest first)

        DSU dsu(V);
        int totalCost   = 0;
        int edgesPicked = 0;

        cout << "\nEdge\t\tWeight\n";
        cout << "------------------------\n";

        for (auto& e : edges) {
            if (dsu.unite(e.u, e.v)) {
                cout << e.u+1 << " - " << e.v+1
                     << "\t\t" << e.weight << "\n";
                totalCost   += e.weight;
                edgesPicked++;
                if (edgesPicked == V - 1) break;
            }
        }

        cout << "------------------------\n";
        if (edgesPicked < V - 1)
            cout << "Graph is disconnected!\n";
        else
            cout << "Maximum Spanning Weight: " << totalCost << "\n";
    }
};

// ─── Main ────────────────────────────────────────────────────
int main() {
    int V;
    cin >> V;

    Graph g(V);
    g.matrixInput();
    g.maximumSpanningTree();

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
4 - 5           15
6 - 7           11
3 - 4           9
5 - 7           9
2 - 3           8
5 - 6           8
------------------------
Maximum Spanning Weight: 59 ✅

Dry Run (Edge selection — heaviest first):
Sorted edges (descending):
(4-5,15)(6-7,11)(3-4,9)(5-7,9)(2-3,8)(5-6,8)(1-3,7)(3-5,7)...

Step 1: Pick 4-5  (w=15) → unite(3,4) ✅  cost=15
Step 2: Pick 6-7  (w=11) → unite(5,6) ✅  cost=26
Step 3: Pick 3-4  (w=9)  → unite(2,3) ✅  cost=35
Step 4: Pick 5-7  (w=9)  → unite(4,6) ✅  cost=44  [joins two components]
Step 5: Pick 2-3  (w=8)  → unite(1,2) ✅  cost=52
Step 6: Skip 5-6  (w=8)  → find(4)==find(5) ❌ cycle
Step 7: Pick 1-3  (w=7)  → unite(0,2) ✅  cost=59

6 edges for 7 vertices → Max ST done!

Min ST vs Max ST — Summary:
Min Spanning TreeMax Spanning TreeGoalCheapest connectionMost expensive connectionSort orderAscending ↑Descending ↓DSU logicSameSameUse caseNetwork infra, cheapest wiringGreedy budget maximizationResult (sample)3959Sonnet 4.6AdaptiveClaude is AI a
*/
