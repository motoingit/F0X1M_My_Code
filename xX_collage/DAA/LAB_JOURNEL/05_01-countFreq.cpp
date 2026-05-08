#include <iostream>
#include <vector>

using namespace std;

// only lowercase alphabets
char mostFrequentChar(vector<char> &arr) {
    vector<int> freq(26, 0);

    // Count frequency
    for (char ch : arr) {
        freq[ch - 'a']++;
    }

    // Find max frequency
    int maxIdx = 0;
    for (int i = 1; i < 26; i++) {
        if (freq[i] > freq[maxIdx]) {
            maxIdx = i;
        }
    }

    return maxIdx + 'a';
}

int main() {
    int n;
    cin >> n;

    vector<char> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << mostFrequentChar(arr);

    return 0;
}
