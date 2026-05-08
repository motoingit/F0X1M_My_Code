
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

struct Edge {
    int u, v, w;
};

void bellmanFord(int n, vector<Edge>& edges, int src) {
    vector<int> dist(n, INT_MAX);
    vector<int> parent(n, -1);
    dist[src] = 0;

    // try to relax every node n-1 time
    for (int i = 0; i < n - 1; i++) {
        for (auto &e : edges) {
            if (dist[e.u] != INT_MAX && dist[e.u] + e.w < dist[e.v]) {
                dist[e.v] = dist[e.u] + e.w;
                parent[e.v] = e.u;
            }
        }
    }

    //! one more for negative cycle 
    for (auto &e : edges) {
        if (dist[e.u] != INT_MAX && dist[e.u] + e.w < dist[e.v]) {
            cout << "Negative cycle detected\n";
            return;
        }
    }

    //* print
    for (int i = 0; i < n; i++) {
        if (dist[i] == INT_MAX) {
            cout << i << ":INF\n";
            continue;
        }

        vector<int> path;
        for (int cur = i; cur != -1; cur = parent[cur]){
            path.push_back(cur);
        }

        reverse(path.begin(), path.end());

        for (int j = 0; j < path.size(); j++) {
            cout << path[j] << (j+1<path.size()?" ":"");
        }
        cout << ":" << dist[i] << "\n";
    }
}

int main() {
    int n;
    cin >> n;

    vector<Edge> edges;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int w; cin >> w;
            if (w != 0)
                edges.push_back({i, j, w});
        }
    }

    int src;
    cin >> src;

    bellmanFord(n, edges, src);

    return 0;
}

/*
4
0 1 4 0
1 0 2 6
4 2 0 3
0 6 3 0
0
0:0
0 1:1
0 1 2:3
0 1 2 3:6
PS E:\My_Code\xX_collage\DAA\LAB_JOURNEL> cd "e:\My_Code\xX_collage\DAA\LAB_JOURNEL\" ; if ($?) { g++ 07_02-.cpp -o 07_02- } ; if ($?) { .\07_02- }
3
0 4 5
0 0 -2
0 0 0
0
0:0
0 1:4
0 1 2:2
PS E:\My_Code\xX_collage\DAA\LAB_JOURNEL> cd "e:\My_Code\xX_collage\DAA\LAB_JOURNEL\" ; if ($?) { g++ 07_02-.cpp -o 07_02- } ; if ($?) { .\07_02- }
3
0 1 0
0 0 -1
-1 0 0
0
Negative cycle detected
*/
