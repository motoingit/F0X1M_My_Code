// Question : 
#include <iostream>
#include <vector>
using namespace std;

bool helperFuction(vector<vector<int>> &adjMat, vector<int> &visited, int src, vector<int> &path, int count){
    if(==)
    visited[src] = 1;
    path[count] = src;

    for(int i = 0; i < adjMat.size(); i++){
        if(adjMat[src][i] == 1){

            bool flag = helperFuction(adjMat, visited, i, path, count+1);
            if ( flag == false){
                path[count] = -1;
                visited[i] = 0;
            }
        }
    }

    return false
}

void hamiltonian(vector<vector<int>> adjMat){
    vector <int> visited(adjMat.size(), 0);
    vector <int> path(adjMat.size(), -1);

    helperFuction(adjMat, visited, 0, path, 0);

    if(adjMat.size() - 1  ){
        cout << "Hamiltonian Cycle";
    }
}

int main(){
    int n = 5;
    int vector<vector<int>> G1 = {
        {0, 1, 1, 0, 1},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}
    };

    int vector<vector<int>> G2 = {
        {0, 1, 1, 1, 1},
        {1, 0, 0, 0, 0},
        {1, 0, 0, 0, 0},
        {1, 0, 0, 0, 0},
        {1, 0, 0, 0, 0}
    };

    hamiltonian(G1);

return 0;}
