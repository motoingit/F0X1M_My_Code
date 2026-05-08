/* Question: Floyd-Warshall — All Pair Shortest Path */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

const int INF = 1e9;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> mat(n, vector<int>(n));

    // Read matrix — handles both integers and "INF" tokens
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            string token;
            cin >> token;
            mat[i][j] = (token == "INF") ? INF : stoi(token);
        }
    }

    //main algo
    for (int via = 0; via < n; via++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][via] != INF && mat[via][j] != INF)
                    mat[i][j] = min(mat[i][j], mat[i][via] + mat[via][j]);
            }
        }
    }

   cout << "Shortest Distance Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j) cout << " ";
            if (mat[i][j] >= INF) cout << "INF";
            else                  cout << mat[i][j];
        }
        cout << "\n";
    }

    return 0;
}

/*
Sample Input:
5
0 10 5 5 INF
INF 0 5 5 5
INF INF 0 INF 10
INF INF INF 0 20
INF INF INF 5 0
Expected Output:
Shortest Distance Matrix:
0 10 5 5 15
INF 0 5 5 5
INF INF 0 15 10
INF INF INF 0 20
INF INF INF 5 0
*/
