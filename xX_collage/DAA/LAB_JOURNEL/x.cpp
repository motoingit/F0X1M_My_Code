// Question : DFS
#include <iostream>
#include <vector>

using namespace std;

void fun1(vector <vector<int>> & adjList, vector <bool> & visitedList, int src, int des, string path){

    if(src < 0 || src >= (int)adjList.size()) return; //NODE this is just for the verify

    visitedList[src] = true;
    path += " -> " + to_string(src);

    if(src == des){
        cout << path << "\n";
        return;
    }

    for(auto u : adjList[src]){
        if(u < 0 || u >= (int)adjList.size()) continue; //NODE this is just for the verify
        if(!visitedList[u]){
            fun1(adjList, visitedList, u, des, path);
        }
    }
}

int main(){
    int nV;
    cin >> nV;
    vector <vector<int>> adjList (nV);
    vector <bool> visitedList(nV, false);

    for(int i = 0; i < nV; i++) {
        int nE;
        cin >> nE;
    
        while (nE--){
            int x;
            cin >> x;
            adjList[i].push_back(x);
        }
    }

    int src, des;
    cin >> src >> des;

    string path = "Start";
    fun1(adjList, visitedList, src, des, path);
    
return 0;}

/*

6

3
1 2 4

5
0 2 3 4 5

3
0 1 5

3
1 4 5

2
0 1 4

2
1 2 3

*/
