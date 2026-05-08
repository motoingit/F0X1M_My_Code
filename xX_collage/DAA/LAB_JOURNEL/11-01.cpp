/*
Approach — Interval DP:

dp[i][j] = minimum cost to multiply matrices i through j
Base case: dp[i][i] = 0 (single matrix, no cost)
For each chain length l from 2 to n, try every split point k:
dp[i][j] = min(dp[i][k] + dp[k+1][j] + p[i-1] * p[k] * p[j])
Answer: dp[1][n]


Why DP not greedy? No single greedy rule works — optimal split depends on ALL subproblem costs. We need to try every possible split point.
*/

/* Question: Matrix Chain Multiplication — Minimum scalar multiplications */

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int n;
    cin >> n;

    // p[] stores dimensions: matrix i has size p[i-1] x p[i]
    // For n matrices we need n+1 values
    vector<int> p(n + 1);

    // Read each matrix dimension a x b
    // Consecutive matrices: col of matrix i == row of matrix i+1
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        if (i == 0) p[0] = a;
        p[i + 1] = b;
    }

    // dp[i][j] = min cost to multiply matrix i..j (1-indexed)
    vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, 0));

    // l = chain length (2 to n)
    for (int l = 2; l <= n; l++) {
        for (int i = 1; i <= n - l + 1; i++) {
            int j = i + l - 1;
            dp[i][j] = LLONG_MAX;

            // Try every split point k between i and j
            for (int k = i; k < j; k++) {
                long long cost = dp[i][k]
                               + dp[k+1][j]
                               + (long long)p[i-1] * p[k] * p[j];
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }

    cout << dp[1][n] << "\n";
    return 0;
}
