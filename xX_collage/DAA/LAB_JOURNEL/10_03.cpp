/*
Approach:

Majority Element → Boyer-Moore Voting Algorithm (O(n), O(1) space)

Phase 1: Find candidate
Phase 2: Verify candidate count > n/2


Median → Sort array, pick middle element

Odd n → arr[n/2]
Even n → average of arr[n/2 - 1] and arr[n/2]




Why Boyer-Moore? Finds majority candidate in one pass without a hashmap — O(n) time, O(1) space.
*/

/* Question: Majority Element + Median of unsorted array */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ── Boyer-Moore Voting ───────────────────────────────────────
// Phase 1: find candidate, Phase 2: verify
bool majorityElement(vector<int>& arr, int& majorElem) {
    int n = arr.size();

    // Phase 1 — find candidate
    int candidate = arr[0], count = 1;
    for (int i = 1; i < n; i++) {
        if (arr[i] == candidate) count++;
        else                     count--;
        if (count == 0) {
            candidate = arr[i];
            count = 1;
        }
    }

    // Phase 2 — verify candidate
    count = 0;
    for (int x : arr)
        if (x == candidate) count++;

    if (count > n / 2) {
        majorElem = candidate;
        return true;
    }
    return false;
}

// ── Median ───────────────────────────────────────────────────
// Works on a COPY (sort doesn't affect original)
double findMedian(vector<int> arr) {
    sort(arr.begin(), arr.end());
    int n = arr.size();
    if (n % 2 == 1)
        return arr[n / 2];
    else
        return (arr[n/2 - 1] + arr[n/2]) / 2.0;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    // Majority element check
    int majorElem;
    if (majorityElement(arr, majorElem))
        cout << "yes\n";
    else
        cout << "no\n";

    // Median
    double median = findMedian(arr);
    // Print as int if whole number, else as decimal
    if (median == (int)median)
        cout << (int)median << "\n";
    else
        cout << median << "\n";

    return 0;
}

/*
Sample Input:
9
4 4 2 3 2 2 3 2 2
Boyer-Moore Trace:
candidate=4, count=1
4 → match    count=2
2 → differ   count=1
3 → differ   count=0  → new candidate=3, count=1
2 → differ   count=0  → new candidate=2, count=1
2 → match    count=2
3 → differ   count=1
2 → match    count=2
2 → match    count=3

Candidate = 2
Verify: 2 appears 5 times > 9/2=4  ✅ → majority element
Median trace:
Sorted: [2, 2, 2, 2, 2, 3, 3, 4, 4]
n=9 (odd) → median = arr[4] = 2
Expected Output:
yes
2  ✅

Edge Cases handled:
CaseBehaviourNo majority elementprints noEven nprints average of two middle elementsAll same elementscorrectly identified as majorityn=1single element is both majority and median

Complexity:
TimeSpaceMajority (Boyer-Moore)O(N)O(1)Median (sort)O(N log N)O(N) for copy
*/
