// Question : 

/*
Given a graph (directed or undirected), determine whether a path exists between a given source vertex and a destination vertex.

The graph is provided in the form of an adjacency matrix (or adjacency list). You must design an algorithm using Depth First Search (DFS) to check if at least one path exists from the source vertex to the destination vertex.
*/

#include <iostream>
#include <vector>
using namespace std;

bool findConnection(const vector <vector<int>> &adjMatrix, 
vector<bool>& visitedArr, int src, const int &des){
    
    if(src == des){
        return true;
    }
    
    visitedArr[src] = true;

    for (int i = 0; i < adjMatrix[src].size(); i++) {
        if(adjMatrix[src][i] == 1){
            if (findConnection(adjMatrix, visitedArr, i, des) == true) {
                    return true;
            }
        }
    }

    return false;
}

int main(){
    int nVertex;
    cin >> nVertex;

    vector <vector<int>> adjMatrix(nVertex, vector<int>(nVertex));

    for (int i = 0; i < adjMatrix.size(); i++) {
        for (int j = 0; j < adjMatrix[i].size(); j++) {
            int x;
            cin >> x;
            adjMatrix[i][j] = x;
        }
    }
    
    int src, des;
    cin >> src >> des;

    vector<bool> visitedArr(nVertex, false);

    if (findConnection(adjMatrix, visitedArr, src - 1, des - 1)) {
        cout << "Yes Path Exists";
    } else {
        cout << "No Such Path Exists";
    }
return 0;}

/*
8

0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0
0 0 0 0 0 0 1 0
0 0 1 0 0 0 0 0
0 0 0 1 0 0 0 0
0 0 0 0 1 0 0 0 
1 1 0 0 0 1 0 0
1 0 0 0 1 0 0 0

2 4
*/
