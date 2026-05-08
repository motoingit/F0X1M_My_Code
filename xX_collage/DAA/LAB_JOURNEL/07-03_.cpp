/* Question: Shortest path with exactly K edges (DP approach) */

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

const int INF = INT_MAX / 2;

int main() {
    int V;
    cin >> V;

    vector<vector<int>> mat(V, vector<int>(V));
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            cin >> mat[i][j];

    int src, dst, k;
    cin >> src >> dst;
    cin >> k;

    // dp[e][v] = min cost to reach v from src in exactly e edges
    // (k+1) rows, V columns
    vector<vector<long long>> dp(k + 1, vector<long long>(V, INF));
    dp[0][src] = 0;

    for (int e = 1; e <= k; e++) {
        for (int u = 0; u < V; u++) {
            if (dp[e-1][u] == INF) continue;   // can't extend from unreachable
            for (int v = 0; v < V; v++) {
                if (mat[u][v] == 0) continue;   // no edge
                dp[e][v] = min(dp[e][v],
                               dp[e-1][u] + mat[u][v]);
            }
        }
    }

    // Output
    if (dp[k][dst] == INF)
        cout << "no path of length k is available\n";
    else
        cout << "Weight of shortest path from ("
             << src + 1 << "," << dst + 1
             << ") with " << k << " edges : "
             << dp[k][dst] << "\n";

    return 0;
}
