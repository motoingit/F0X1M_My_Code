
//Given an unsorted array, find the Kth smallest (or largest) element in O(n) worst-case time.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void countSortPositive(vector<int> &arr) {
    int n = arr.size();
    if (n <= 1) return;

    int maxVal = *max_element(arr.begin(), arr.end());

    vector<int> freq(maxVal + 1, 0);

    // Count frequency
    for (int x : arr) {
        freq[x]++;
    }

    // Rebuild array (in-place overwrite)
    int idx = 0;
    for (int i = 0; i <= maxVal; i++) {
        while (freq[i]--) {
            arr[idx++] = i;
        }
    }
}

void countSortWithNegatives(vector<int> &arr) {
    int n = arr.size();
    if (n <= 1) return;

    int minVal = *min_element(arr.begin(), arr.end());
    int maxVal = *max_element(arr.begin(), arr.end());

    int range = maxVal - minVal + 1;

    vector<int> freq(range, 0);

    // Count frequency
    for (int x : arr) {
        freq[x - minVal]++;
    }

    // Rebuild array
    int idx = 0;
    for (int i = 0; i < range; i++) {
        while (freq[i]--) {
            arr[idx++] = i + minVal;
        }
    }
}

void countSortStable(vector<int> &arr) {
    int n = arr.size();
    if (n <= 1) return;

    int minVal = *min_element(arr.begin(), arr.end());
    int maxVal = *max_element(arr.begin(), arr.end());
    int range = maxVal - minVal + 1;

    // 1) Frequency
    vector<int> freq(range, 0);
    for (int x : arr) {
        freq[x - minVal]++;
    }

    // 2) Cumulative frequency (prefix sums)
    for (int i = 1; i < range; i++) {
        freq[i] += freq[i - 1];
    }

    // 3) Build output (RIGHT → LEFT for stability)
    vector<int> output(n);
    for (int i = n - 1; i >= 0; i--) {
        int idx = arr[i] - minVal;
        int pos = --freq[idx];   // last available position
        output[pos] = arr[i];    // place original value
    }

    // 4) Copy back
    arr = output;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        int k;
        cin >> k;

        if( k <= 0 || k > n){
            cout << "not present\n";
            return -1;
        }

        countSortPositive(arr);
        cout << arr[k-1] << "\n";
    }

    return 0;
}
