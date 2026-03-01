
// let code
//   https://www.hackerearth.com/practice/basic-programming/input-output/basics-of-input-output/practice-problems/algorithm/best-index-1-45a2f8ff/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> a(n), p(n+1, 0);

    for(int i=0; i<n; i++) cin >> a[i]; // for input

    for(int i=0; i<n; i++) p[i+1] = p[i] + a[i];

    long long ans = -LLONG_MAX;
    
    for(int i=0; i<n; i++){
        int r = n - i;
        int k = floor((sqrt(8.0 * r + 1) - 1) / 2);
        int t = k * (k + 1) / 2;
        long long s = p[i + t] - p[i];
        ans = max(ans, s);
    }
    cout << ans;
    return 0;
}