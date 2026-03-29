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

    vector<int> dikastraAlgo(int nV, vector<vector<Edge>>& adjList, int src) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> dist(nV, 1e9);

        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            auto [xDis, xNode] = pq.top();  // ← copy, not reference (& is bug here)
            pq.pop();

            if (xDis > dist[xNode]) continue; // ← skip outdated entries

            for (auto& ele : adjList[xNode]) {
                int yNode   = ele.child;
                int xWeight = ele.weight;

                if (xDis + xWeight < dist[yNode]) {
                    dist[yNode] = xDis + xWeight;
                    pq.push({dist[yNode], yNode});
                }
            }
        }
        return dist;
    }

    void printGraph(vector<vector<Edge>>& adjList, vector<int>& dist) {
        cout << "\n--- Shortest Distances ---\n";
        for (int i = 0; i < adjList.size(); i++) {
            cout << "Node " << i << " - dist=" << dist[i] << " : ";
            for (auto& edge : adjList[i]) {
                cout << "{ " << edge.child << " [w=" << edge.weight << "] }";
            }
            cout << endl;
        }
    }
};

int main() {
    int nV, nE;
    cout << "Enter nV : ";
    cin >> nV;
    cout << "Enter nE : ";
    cin >> nE;

    vector<vector<Edge>> adjList(nV);

    cout << "Enter edges\n(source weight destination)\n";
    for (int i = 0; i < nE; i++) {
        int u, w, v;
        cin >> u >> w >> v;
        adjList[u].push_back({w, v, u});
        adjList[v].push_back({w, u, v});
    }

    Sol obj1;
    vector<int> dist = obj1.dikastraAlgo(nV, adjList, 0);
    obj1.printGraph(adjList, dist);

    return 0;
}

/*
0 4 1
0 4 2
1 2 2
2 3 3
2 6 5
2 1 4
3 2 5
4 3 5
*/
