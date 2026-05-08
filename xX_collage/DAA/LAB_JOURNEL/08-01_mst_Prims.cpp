/* Ques> Minimum Road Construction Cost — Prim's MST

Given a weighted undirected graph of cities, find the minimum cost to connect all N cities using exactly N-1 roads. Use Prim's Algorithm.
*/

/* //* Approach — Prim's Algorithm:

Start from any vertex (vertex 0)
Maintain key[] = min edge weight to include each vertex in MST
Maintain inMST[] = whether vertex is already included
At each step, pick the vertex not in MST with minimum key value
Update neighbours' key values if a cheaper edge is found
Repeat V times → MST formed, sum of keys = minimum cost


Prim's vs Kruskal's? Prim's grows MST vertex-by-vertex (better for dense graphs), Kruskal's grows edge-by-edge. Both give same MST cost.
*/

#include <iostream>
#include <climits>
#include <queue>
#include <vector>

using namespace std;

void primMST(vector<vector<pair<int,int>>>& adj, int V, int src) {

    vector<bool> inMST(V, false);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;

    int mstCost = 0;

    pq.push({0, src}); // {weight, vertex}

    while(!pq.empty()){
        auto p = pq.top(); pq.pop();
        int wt = p.first;
        int u  = p.second;

        if(inMST[u]) continue;

        inMST[u] = true;
        mstCost += wt;

        for(auto &it : adj[u]){
            int w = it.first;
            int v = it.second;

            if(!inMST[v]){
                pq.push({w, v});
            }
        }
    }

    cout << "MST Cost: " << mstCost << endl;
}

int main() {
    int V;
    cin >> V;

    vector<vector<int>> mat(V, vector<int>(V));
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            cin >> mat[i][j];

    // Convert matrix → adjacency list
    vector<vector<pair<int,int>>> adj(V);
    for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j++){
            if(mat[i][j] != 0)
                adj[i].push_back({mat[i][j], j}); // {weight, vertex}
        }
    }

    primMST(adj, V, 0);

    return 0;
}

/*

Sample Input:
5
0 2 0 6 0
2 0 3 8 5
0 3 0 0 7
6 8 0 0 9
0 5 7 9 0
Expected Output:
Edge            Weight
------------------------
1 - 2           2
2 - 3           3
2 - 5           5
1 - 4           6
------------------------
Minimum Cost (Budget) : 16

Dry Run (Step-by-step):
Start: key[] = [0, INF, INF, INF, INF]

Step 1: Pick vertex 1 (key=0) → update neighbours
        key[] = [0, 2, INF, 6, INF]

Step 2: Pick vertex 2 (key=2, min) → update neighbours
        key[] = [0, 2, 3, 6, 5]

Step 3: Pick vertex 5 (key=5, min) → update neighbours
        key[] = [0, 2, 3, 6, 5]   (no improvement)

Step 4: Pick vertex 3 (key=3) → no better updates

Step 5: Pick vertex 4 (key=6)

MST edges: 1-2(2), 2-3(3), 2-5(5), 1-4(6)
Total = 16 ✅

Complexity:
ValueTimeO(V²) — with adjacency matrixTime (optimised)O(E log V) — with min-heap + adjacency listSpaceO(V) for key[], parent[], inMST[]
*/
