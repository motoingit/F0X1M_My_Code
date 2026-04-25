// Dikahstra Algorithm

#include<iostream>
#include<queue>
#include<vector>

using namespace std;

struct Edge {
    int weight;
    int child;
    int parent;
};

class Sol{
public:

    pair<vector<int>, vector<int>> dikastraAlgo(int nV, vector<vector<Edge>>& adjList, int src) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        vector<int> dist(nV, 1e9);
        vector<int> parent(nV, -1);

        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            auto [xDis, xNode] = pq.top();
            pq.pop();

            if (xDis > dist[xNode]) continue;

            for (auto& ele : adjList[xNode]) {
                int yNode   = ele.child;
                int xWeight = ele.weight;

                if (xDis + xWeight < dist[yNode]) {
                    dist[yNode] = xDis + xWeight;
                    parent[yNode] = xNode; // ⭐ important
                    pq.push({dist[yNode], yNode});
                }
            }
        }

        return {dist, parent};
    }

    void printPath(int node, vector<int>& parent) {
        if (node == -1) return;
        printPath(parent[node], parent);
        cout << node << " ";
    }
};

int main() {
    int nV, nE;
    cin >> nV >> nE;

    vector<vector<Edge>> adjList(nV);

    for (int i = 0; i < nE; i++) {
        int u, w, v;
        cin >> u >> w >> v;
        adjList[u].push_back({w, v, u});
        adjList[v].push_back({w, u, v});
    }

    Sol obj;
    auto result = obj.dikastraAlgo(nV, adjList, 0);

    vector<int> dist = result.first;
    vector<int> parent = result.second;

    cout << "\n--- Shortest Paths from Source (0) ---\n";

    for (int i = 0; i < nV; i++) {
        cout << "To Node " << i << " | Distance = " << dist[i] << " | Path = ";
        obj.printPath(i, parent);
        cout << endl;
    }

    return 0;
}
