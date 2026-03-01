#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Graph {
private:
    int V;                      // Number of vertices
    bool directed;              // Graph type
    vector<vector<int>> adj;    // Adjacency list

    /* ==========================================================
       ===================== DFS HELPERS ========================
       ========================================================== */

    // Recursive DFS utility
    void dfsUtil(int node, vector<bool> &visited) {
        visited[node] = true;
        cout << node << " ";

        for (int neighbor : adj[node]) {
            if (!visited[neighbor])
                dfsUtil(neighbor, visited);
        }
    }

    // Undirected cycle detection helper
    bool dfsCycleUndirected(int node, int parent, vector<bool> &visited) {
        visited[node] = true;

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                if (dfsCycleUndirected(neighbor, node, visited))
                    return true;
            }
            else if (neighbor != parent) {
                return true;  // Cycle found
            }
        }
        return false;
    }

    // Directed cycle detection helper (DFS + recursion stack)
    bool dfsCycleDirected(int node,
                          vector<bool> &visited,
                          vector<bool> &recStack) {

        visited[node] = true;
        recStack[node] = true;

        for (int neighbor : adj[node]) {

            if (!visited[neighbor]) {
                if (dfsCycleDirected(neighbor, visited, recStack))
                    return true;
            }
            else if (recStack[neighbor]) {
                return true;  // Back edge found
            }
        }

        recStack[node] = false; // Backtrack
        return false;
    }

public:
    /* ==========================================================
       ===================== CONSTRUCTOR ========================
       ========================================================== */

    Graph(int vertices, bool isDirected = false) {
        V = vertices;
        directed = isDirected;
        adj.resize(V);
    }

    /* ==========================================================
       ===================== ADD EDGE ===========================
       ========================================================== */

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        if (!directed)
            adj[v].push_back(u);
    }

    /* ==========================================================
       ===================== DFS TRAVERSAL ======================
       ========================================================== */

    void DFS() {
        vector<bool> visited(V, false);

        cout << "DFS Traversal: ";
        for (int i = 0; i < V; i++) {
            if (!visited[i])
                dfsUtil(i, visited);
        }
        cout << endl;
    }

    /* ==========================================================
       ===================== BFS TRAVERSAL ======================
       ========================================================== */

    void BFS() {
        vector<bool> visited(V, false);
        queue<int> q;

        cout << "BFS Traversal: ";

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                visited[i] = true;
                q.push(i);

                while (!q.empty()) {
                    int node = q.front();
                    q.pop();

                    cout << node << " ";

                    for (int neighbor : adj[node]) {
                        if (!visited[neighbor]) {
                            visited[neighbor] = true;
                            q.push(neighbor);
                        }
                    }
                }
            }
        }
        cout << endl;
    }

    /* ==========================================================
       ============== CYCLE DETECTION (UNDIRECTED) =============
       ========================================================== */

    bool hasCycleUndirected() {
        if (directed) {
            cout << "Graph is directed. Use directed cycle detection.\n";
            return false;
        }

        vector<bool> visited(V, false);

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (dfsCycleUndirected(i, -1, visited))
                    return true;
            }
        }
        return false;
    }

    /* ==========================================================
       ============== CYCLE DETECTION (DIRECTED - DFS) =========
       ========================================================== */

    bool hasCycleDirectedDFS() {
        if (!directed) {
            cout << "Graph is undirected. Use undirected cycle detection.\n";
            return false;
        }

        vector<bool> visited(V, false);
        vector<bool> recStack(V, false);

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (dfsCycleDirected(i, visited, recStack))
                    return true;
            }
        }
        return false;
    }

    /* ==========================================================
       ====== CYCLE DETECTION (DIRECTED - KAHN'S BFS) ==========
       ========================================================== */

    bool hasCycleDirectedBFS() {
        if (!directed) {
            cout << "Graph is undirected. Use undirected cycle detection.\n";
            return false;
        }

        vector<int> indegree(V, 0);

        // Compute indegree
        for (int i = 0; i < V; i++) {
            for (int neighbor : adj[i]) {
                indegree[neighbor]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        int count = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            count++;

            for (int neighbor : adj[node]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0)
                    q.push(neighbor);
            }
        }

        // If processed nodes != V → cycle exists
        return count != V;
    }

    /* ==========================================================
       ===================== PATH FINDER ========================
       ========================================================== */

    // Shortest path using BFS (works best for unweighted graph)
    vector<int> shortestPath(int src, int dest) {

        vector<bool> visited(V, false);
        vector<int> parent(V, -1);
        queue<int> q;

        visited[src] = true;
        q.push(src);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            if (node == dest)
                break;

            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    parent[neighbor] = node;
                    q.push(neighbor);
                }
            }
        }

        vector<int> path;

        if (!visited[dest]) {
            cout << "No path exists.\n";
            return path;
        }

        for (int at = dest; at != -1; at = parent[at])
            path.push_back(at);

        reverse(path.begin(), path.end());
        return path;
    }
};

/* ==========================================================
   ========================= MAIN ============================
   ========================================================== */

int main() {

    // Example: Directed Graph
    Graph g(6, true);

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 0);  // Cycle
    g.addEdge(3, 4);
    g.addEdge(4, 5);

    g.DFS();
    g.BFS();

    cout << "Directed Cycle (DFS): "
         << g.hasCycleDirectedDFS() << endl;

    cout << "Directed Cycle (BFS Kahn): "
         << g.hasCycleDirectedBFS() << endl;

    vector<int> path = g.shortestPath(3, 5);

    cout << "Shortest Path from 3 to 5: ";
    for (int node : path)
        cout << node << " ";
    cout << endl;

    return 0;
}
