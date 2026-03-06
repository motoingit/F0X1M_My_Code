#include <iostream>
#include <vector>

using namespace std;

void printCycles(const vector<vector<int>>& foundPaths) {
    if(foundPaths.empty()){
        cout << "No Hamiltonian Cycle found." << endl;
        return;
    }

    for(const auto &path : foundPaths){
        for(const auto &p : path){
            cout << p << "->";
        }
        cout << path[0] << endl;
    }
}

void fun1(vector<vector<int>> &adjMat, vector<bool> &visArr, vector<int> &path, vector<vector<int>> &allPath, int currNode){
    
    path.push_back(currNode); //! start from 0 node
    visArr[currNode] = true;

    if(adjMat.size() == path.size() && adjMat[path.front()][path.back()] == 1){
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

void solveForCycles(vector<vector<int>> &adjMat){
    vector<int> path;
    vector<bool> visArr(adjMat.size(), false);
    vector<vector<int>> allPath;

    //* now rec find all path possible
    fun1(adjMat,visArr,path,allPath,0);

    printCycles(allPath);
}


int main(){
    vector<vector<int>> graph1 = {
        // 0 1 2 3 4  (Node Labels)
        {0, 1, 1, 1, 0}, // 1
        {1, 0, 1, 1, 0}, // 2
        {1, 1, 0, 1, 1}, // 3
        {1, 1, 1, 0, 1}, // 4
        {0, 0, 1, 1, 0},  // 5
    };

    // The "Star Graph" - Guaranteed to have no cycles
    vector<vector <int>> graph2 = {
      //0  2  3  4  5  6  7   (Node Labels)
        {0, 1, 0, 1, 1, 0, 0}, // 1
        {1, 0, 1, 0, 0, 0, 0}, // 2
        {0, 1, 0, 1, 0, 0, 1}, // 3
        {1, 0, 1, 0, 0, 1, 0}, // 4
        {1, 0, 0, 0, 0, 1, 0}, // 5
        {0, 0, 0, 1, 1, 0, 1}, // 6
        {0, 0, 1, 0, 0, 1, 0}  // 7
    };

    // cout << "Graph 1 Hamiltonian Cycles:" << endl;
    // solveForCycles(graph1);

    cout << "\nGraph 2 Hamiltonian Cycles:" << endl;
    solveForCycles(graph2);

    return 0;
}
