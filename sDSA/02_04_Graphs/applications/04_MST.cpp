#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Edge {
    int src, des, weight;
};

struct Compare {
    bool operator()(Edge a, Edge b) {
        return a.weight > b.weight;
    }
};

int findParent(int v, vector<int>& parent){
    if(parent[v] == v)
        return v;
    return parent[v] = findParent(parent[v], parent);
}

void unionSet(int a, int b, vector<int>& parent){
    a = findParent(a,parent);
    b = findParent(b,parent);
    parent[b] = a;
}

vector<vector<int>> mst(vector<vector<int>>& adjMat){

    int n = adjMat.size();

    vector<vector<int>> mstMat(n, vector<int>(n,0));

    priority_queue<Edge, vector<Edge>, Compare> pq;

    // push edges
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(adjMat[i][j]!=0){
                pq.push({i,j,adjMat[i][j]});
            }
        }
    }

    vector<int> parent(n);
    for(int i=0;i<n;i++) parent[i]=i;

    while(!pq.empty()){

        Edge e = pq.top();
        pq.pop();

        int p1 = findParent(e.src,parent);
        int p2 = findParent(e.des,parent);

        if(p1 != p2){

            mstMat[e.src][e.des] = e.weight;
            mstMat[e.des][e.src] = e.weight;

            unionSet(p1,p2,parent);
        }
    }

    return mstMat;
}

int main(){

    vector<vector<int>> graph1 = {
        {0,2,4,0,0,0},
        {2,0,2,4,2,0},
        {4,2,0,0,3,0},
        {0,4,0,0,3,2},
        {0,2,3,3,0,2},
        {0,0,0,2,2,0}
    };

    auto result = mst(graph1);

    cout << "MST Matrix:\n";

    for(auto &row : result){
        for(auto &x : row)
            cout << x << " ";
        cout << endl;
    }
}
