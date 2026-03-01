// Question : 
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int nV;
    cin >> nV;
    vector <vector<bool>> adj(nV, vector<bool> (nV, false));

    int nE;
    cin >> nE;

    int i = nE;
    while(i--){
        int x,y;
        cin >> x >> y;
        adj[x][y] = true;
        adj[y][x] = true;
    }

    for(auto x : adj){
        for(auto y : x){
            cout << y << " " ;
        }
        cout << endl;
    }

return 0;}

/*




*/
