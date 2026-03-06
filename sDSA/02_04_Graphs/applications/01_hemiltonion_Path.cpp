#include <iostream>
#include <vector>
using namespace std;

void printPaths(const vector<vector<int>>& foundPaths) {
    if(foundPaths.empty()){
        cout << "No Hamiltonian Paths found." << endl;
        return;
    }

    for(const auto &path : foundPaths){
        for(const auto &p : path){
            cout << p << "->";
        }
        cout << endl;
    }
}

void fun1(vector<vector<int>> &adjMat, vector<bool> &visArr, vector<int> &path, vector<vector<int>> &allPath, int currNode){
    
    path.push_back(currNode); //! start from 0 node
    visArr[currNode] = true;

    if(adjMat.size() == path.size()){
        cout << "Finded Path !" << endl;
        allPath.push_back(path);
    }else{
        for(int i = 0; i < adjMat.size(); i++){
            if(adjMat[currNode][i] == 1 && visArr[i] == false){
                fun1(adjMat, visArr, path, allPath, i);
            }
        }
    
    }

    // 4. Backtrack: Remove current node from path and mark as unvisited for other routes
    path.pop_back();
    visArr[currNode] = false;
}

void solveForPaths(vector<vector<int>> &adjMat){
    vector<int> path;
    vector<bool> visArr(adjMat.size(), false);
    vector<vector<int>> allPath;

    //* now rec find all path possible
    fun1(adjMat,visArr,path,allPath,0);

    printPaths(allPath);
}

int main(){
    vector<vector<int>> graph1 = {
        {0, 1, 1, 0, 1},
        {1, 0, 1, 1, 1},
        {1, 1, 0, 1, 0},
        {0, 1, 1, 0, 1},
        {1, 1, 0, 1, 0}
    };

    vector<vector <int>> graph2 = {
        {0, 1, 1, 1, 1},
        {1, 0, 0, 0, 0},
        {1, 0, 0, 0, 0},
        {1, 0, 0, 0, 0},
        {1, 0, 0, 0, 0}
    };

    vector<vector <int>> graph3 = {
        // 0  1  2  3  4  5  6  7  8
        {0, 1, 0, 0, 0, 0, 0, 0, 1}, // 0
        {1, 0, 1, 0, 0, 0, 0, 1, 1}, // 1
        {0, 1, 0, 1, 0, 0, 0, 1, 0}, // 2
        {0, 0, 1, 0, 1, 0, 1, 0, 0}, // 3
        {0, 0, 0, 1, 0, 1, 0, 0, 0}, // 4
        {0, 0, 0, 0, 1, 0, 1, 0, 0}, // 5
        {0, 0, 0, 1, 0, 1, 0, 0, 0}, // 6
        {0, 1, 1, 0, 0, 0, 0, 0, 1}, // 7
        {1, 1, 0, 0, 0, 0, 0, 1, 0}  // 8
    };

    cout << "\nGraph 3 Hamiltonian Paths:" << endl;
    solveForPaths(graph3);

    return 0;
}
