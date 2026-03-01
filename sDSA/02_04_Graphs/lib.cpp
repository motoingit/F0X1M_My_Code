#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

class Graph
{
public:
    int nV, nE;
    vector<vector<int>> adjMat;

    Graph() {
        nV = 0;
        nE = 0;
    }

    void initMat(int n) {
        adjMat.assign(n, vector<int>(n, 0));
    }

    void addEdge_undirrectd(int src, int des) {
        adjMat[src][des] = 1;
        adjMat[des][src] = 1;
    }

    void quickStart() {
        cout << "Enter nV: ";
        cin >> nV;
        initMat(nV);

        cout << "Enter nE: ";
        cin >> nE;

        for(int i = 0; i < nE; i++) {
            int src, des;
            cout << "Enter src des: ";
            cin >> src >> des;
            addEdge_undirrectd(src, des);
        }
    }

    void printAdjMatrix() {
        cout << "adj mat: " << endl;
        for(auto &row : adjMat) {
            for(auto val : row) {
                cout << val << " ";
            }
            cout << endl;
        }
    }

    void printAdjList_Dummy() {
        cout << "Adj lsit: " << endl;
        for(int i = 0; i < nV; i++) {
            cout << i << " : ";
            for(int j = 0; j < nV; j++) {
                if(adjMat[i][j] == 1)
                    cout << j << " ";
            }
            cout << endl;
        }
    }

    // deep tracerse
    void dfs(int src) 
    {
        vector<bool> visited(nV, false);
        stack<int> st;

        st.push(src);

        cout << "dfs: ";

        while(!st.empty()) 
        {
            int node = st.top();
            st.pop();

            if(!visited[node]) 
            {
                cout << node << " ";
                visited[node] = true;

                for(int i = nV - 1; i >= 0; i--) 
                { // why to push in reverse
                    if(adjMat[node][i] == 1 && !visited[i])
                        st.push(i);
                }
            }
        }
    }

    //for the level order
    void bfs(int src) {
        vector<bool> visited(nV, false);
        queue<int> q;

        q.push(src);
        visited[src] = true;

        cout << "\nBFS Traversal: ";

        while(!q.empty()) {
            int node = q.front();
            q.pop();
            cout << node << " ";

            for(int i = 0; i < nV; i++) {
                if(adjMat[node][i] == 1 && !visited[i]) {
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
    }
};

int main()
{
    Graph obj;
    obj.quickStart();

    obj.printAdjMatrix();
    obj.printAdjList_Dummy();

    obj.dfs(2);
    obj.bfs(2);

    return 0;
}
