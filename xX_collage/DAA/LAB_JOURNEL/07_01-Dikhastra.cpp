/* Question : Dikhastra
*/

//* from one src to every node - find shortest path
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
 
using namespace std;
typedef pair<int, int> edge;

void dikhastra(vector<vector<edge>>& adjList, int src, int nVertex){
    vector<int> dist(nVertex, INT_MAX);
    vector<int> par(nVertex, -1);
    priority_queue<edge, vector<edge>, greater<edge>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()){
        auto [dis, u] = pq.top(); pq.pop();

        if(dis > dist[u]) continue;

        for (auto& [w, v] : adjList[u]) {
            if(dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
                par[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    // Print shortest path and distance from each friend to Akshay's house
    for (int i = 0; i < nVertex; i++) {
        if (i == src) continue;

        cout << "\nFrom " << i << " ->  " << src;
        if (dist[i] == INT_MAX) {
            cout << "\n  No path exists\n";
            continue;
        }
        cout << "\n  Distance: " << dist[i];
        cout << "\n  Path: ";

        // Reconstruct path
        vector<int> path;
        for (int cur = i; cur != -1; cur = par[cur])
            path.push_back(cur);
            
        reverse(path.begin(), path.end());

        for (int j = 0; j < path.size(); j++) {
            cout << path[j];
            if (j != path.size()-1) cout << " -> ";
        }
        cout << "\n";
    }
}

int main(){
    int nVertex;
    cin >> nVertex;

    // based 0-idx
    // -1 -> noRelation
    vector<vector<int>> adjMat(nVertex, vector<int>(nVertex));
    for (int i = 0; i < nVertex; i++) {
        for (int j = 0; j < nVertex; j++) {
            cin >> adjMat[i][j];
        }
    }

    // mat -> list
    vector<vector<edge>> adjList(nVertex);
    for (int i = 0; i < nVertex; i++) {
        for (int j = 0; j < nVertex; j++) {
            if(adjMat[i][j] != -1){
                //?     src             dis        des
                adjList[i].push_back({adjMat[i][j], j});
            }
        }
    }

    int src = 0;
    dikhastra(adjList, src, nVertex);

return 0;}

/*
5
0 10 3 -1 -1
10 0 1 2 -1
3 1 0 8 2
-1 2 8 0 7
-1 -1 2 7 0

5
0 2 -1 -1 -1
2 0 3 -1 -1
-1 3 0 1 -1
-1 -1 1 0 -1
-1 -1 -1 -1 0

4
0 1 4 -1
1 0 2 6
4 2 0 3
-1 6 3 0
*/
