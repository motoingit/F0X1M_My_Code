// Question : 
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int nV;
    cin >> nV;
    vector<vector<int>> adjList(nV); 

    for(int i = 0; i < nV; i++) {
        int nE;
        cin >> nE;
    
        while (nE--){
            int x;
            cin >> x;
            adjList[i].push_back(x);
        }
    }

    int i = 0;
    for(auto x : adjList){
        cout << i << " : ";
        for(auto y : x){
            cout << y << ", ";
        }
        cout << endl;
        i++;
    }
return 0;}

/*

0 : 3, 
1 : 3,
2 : 7, 5,
3 : 0, 1, 6,
4 : 7,
5 : 2,
6 : 3,
7 : 2, 4,
8 : 9, 10,
9 : 8, 10,
10 : 8, 9,
11 :


12

1
3

1
3

2
7 5

3
0 1 6

1
7

1
2

1
3

2
2 4

2
9 10

2
8 10

2
8 9

0

*/
