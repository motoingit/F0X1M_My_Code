/*
Approach — Unbounded Knapsack DP:

dp[s] = number of ways to make sum s
Base: dp[0] = 1 (one way to make 0 — pick nothing)
For each coin, for each sum from coin to N:
dp[s] += dp[s - coin]
Outer loop over coins ensures combinations (not permutations) — each set counted once


Coin-outer vs Sum-outer: Looping coins in outer loop avoids counting {2,3} and {3,2} as different ways.
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> coins(n);
    for (int i = 0; i < n; i++) cin >> coins[i];

    int N;
    cin >> N;

    vector<long long> dp(N + 1, 0);
    dp[0] = 1; // base case

    for (int c : coins)
        for (int s = c; s <= N; s++)
            dp[s] += dp[s - c];

    cout << dp[N] << "\n";
    return 0;
}

/*
Test 1 (given):
Input:          Output:
4               5
2 5 6 3
10
Ways: {2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5}, {5,5}

Test 2 — single coin divides N:
Input:          Output:
1               1
5
10
Only way: {5,5}

Test 3 — no way possible:
Input:          Output:
3               0
4 6 8
3
No combo of 4,6,8 sums to 3

Test 4 — many ways:
Input:          Output:
3               4
1 2 3
4
Ways: {1,1,1,1}, {1,1,2}, {1,3}, {2,2}

Complexity:
ValueTimeO(N × C) — N = target sum, C = coin countSpaceO(N) — 1D dp arraySonnet 4.6Adaptive
*/
