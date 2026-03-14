// Question : 
//* Zero based

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool isBipertite(vector<vector<int>> &adjMat, int nVertex){
    vector<int> colorArr(nVertex, -1);

    for(int i = 0; i < nVertex; i++){
        if(colorArr[i] != -1){
            continue;
        }

        queue <int> qq;
        qq.push(i);
        colorArr[i] = 0;

        while (!qq.empty()){
            int currNode = qq.front(); qq.pop();

            for (int j = 0; j < nVertex; j++){
                //* if neigbor is edge and neibour is not coloued
                if(adjMat[currNode][j] == 1 && colorArr[j] == -1){
                    colorArr[j] = !(colorArr[currNode]);
                    qq.push(j);
                }else if(adjMat[currNode][j] == 1 
                    && colorArr[j] != -1 
                    && colorArr[currNode] == colorArr[j]){
                    return false;
                }
            }
        }
        
    }

    return true;
}

int main(){
    vector<vector<int>> adjMatrix = {
        //0 1 2 3 4 5 6 7 8
        {0,1,0,0,0,0,0,1,0}, // 0
        {1,0,1,0,0,0,0,1,0}, // 1
        {0,1,0,1,0,1,0,0,1}, // 2
        {0,0,1,0,1,1,0,0,0}, // 3
        {0,0,0,1,0,1,0,0,0}, // 4
        {0,0,1,1,1,0,1,0,0}, // 5
        {0,0,0,0,0,1,0,1,1}, // 6
        {1,1,0,0,0,0,1,0,1}, // 7
        {0,0,1,0,0,0,1,1,0}  // 8
    };

    (isBipertite(adjMatrix, adjMatrix.size()) ? cout << "Yes" : cout << "No");

return 0;}
