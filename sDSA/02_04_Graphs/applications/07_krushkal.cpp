// Question : 

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Edge {
    int weight;
    int child;
    int parent;
};

struct Compare {
    bool operator()(Edge& a, Edge& b) {
        return a.weight > b.weight;
    }
};

/**
 * find
 */
int find(vector<int>& parent, int x) {
    if (parent[x] != x)
    parent[x] = find(parent, parent[x]); // path compression
    return parent[x];
}


/**
 * union
 */
bool unite(vector<int>& parent, vector<int>& rank, int x, int y) {
    int px = find(parent, x);
    int py = find(parent, y);

    if (px == py) return false; // same root → cycle!

    if (rank[px] < rank[py]) swap(px, py);
    parent[py] = px;
    if (rank[px] == rank[py]) rank[px]++;

    return true;
}


/**
 * Printing all the Graph Detials
 */
void printGraph(vector<vector<Edge>>& adjList) {
    cout << "\n--- Graph ---" << endl;
    for (int i = 0; i < adjList.size(); i++) {
        cout << "Node " << i << " : ";
        for (auto& edge : adjList[i]) {
            cout << "-> " << edge.child << " [w=" << edge.weight << "] ";
        }
        cout << endl;
    }
}

/**
 * Main Krushkals
 */
void krushkal(vector<vector<Edge>> &adjList, vector<vector<Edge>> &mstList) {
    int totalWeight = 0;
    int nV = adjList.size();

    // DSU setup
    vector<int> parent(nV), rank(nV, 0);
    priority_queue<Edge, vector<Edge>, Compare> pq;

    for (int i = 0; i < nV; i++) parent[i] = i;

    // inserting edge
    for (auto& edgeList : adjList) {
        for (auto& edge : edgeList) {
            if (edge.parent < edge.child){  // avoid pushing same edge twice
                pq.push(edge);
            }
        }
    }

    int edgesAdded = 0;

    while (!pq.empty()){
        Edge currEdge = pq.top();
        pq.pop();

         //! cycle check — if same root, skip
        if (!unite(parent, rank, currEdge.parent, currEdge.child))
            continue;

        totalWeight += currEdge.weight;

        mstList[currEdge.parent].push_back(currEdge);
        mstList[currEdge.child].push_back({currEdge.weight, currEdge.child, currEdge.parent});

        edgesAdded++;
    }
    

}

int main(){
    int nV, nE;
    cout << "Enter nV : " ;
    cin >> nV;
    cout << "Enter nE : ";
    cin >> nE;
    
    vector<vector<Edge>> adjList(nV);

    cout << "Enter edges\n(source, weight, destination)\n" << endl;
    for (int i = 0; i < nE; i++) {
        int u, w, v;
        cin >> u >> w >> v;
        // Since it's undirected, add edges for both directions
        adjList[v].push_back({w, u, v});
        adjList[u].push_back({w, v, u});
    }

    vector<vector<Edge>> mstList(nV);
    krushkal(adjList, mstList);

    printGraph(mstList);

return 0;}
