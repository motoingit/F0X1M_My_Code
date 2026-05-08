/* 
Activity Selection — Maximum Non-Conflicting Activities
Problem (Compact):
Given N activities with start and finish times, select the maximum number of non-conflicting activities a single person can do. Activity B is compatible with A if start(B) >= finish(A).

Approach — Greedy (Earliest Finish First):

Sort activities by finish time (ascending)
Always pick the activity that ends earliest — leaves maximum room for future activities
Include next activity only if its start ≥ last selected activity's finish


Why earliest finish? Finishing early never blocks more future activities than any other choice. This greedy choice is provably optimal.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Activity {
    int id;     // original 1-based index
    int start;
    int finish;
};

int main() {
    int n;
    cin >> n;

    vector<int> s(n), f(n);
    for (int i = 0; i < n; i++) cin >> s[i];
    for (int i = 0; i < n; i++) cin >> f[i];

    // Build activity list (1-indexed ids)
    vector<Activity> acts(n);
    for (int i = 0; i < n; i++)
        acts[i] = {i + 1, s[i], f[i]};

    // Sort by finish time ascending (greedy criterion)
    sort(acts.begin(), acts.end(), [](const Activity& a, const Activity& b) {
        return a.finish < b.finish;
    });

    vector<int> selected;

    // Always pick first (earliest finishing) activity
    selected.push_back(acts[0].id);
    int lastFinish = acts[0].finish;

    for (int i = 1; i < n; i++) {
        // Compatible if start >= finish of last selected
        if (acts[i].start >= lastFinish) {
            selected.push_back(acts[i].id);
            lastFinish = acts[i].finish;
        }
    }

    // Sort selected ids for clean output (original order)
    sort(selected.begin(), selected.end());

    cout << "No. of non-conflicting activities: " << selected.size() << "\n";
    cout << "List of selected activities: ";
    for (int i = 0; i < (int)selected.size(); i++) {
        if (i) cout << ", ";
        cout << selected[i];
    }
    cout << "\n";

    return 0;
}

/*
Sample Input:
10
1 3 0 5 3 5 8 8 2 12
4 5 6 7 9 9 11 12 14 16
Activities table (before sort):
IDStartFinish114235306457539659781188129214101216
After sort by finish time → Greedy picks:
Pick  Act 1  (finish=4,  lastFinish=4)
Skip  Act 2  (start=3  < 4 ❌)
Skip  Act 3  (start=0  < 4 ❌)
Pick  Act 4  (start=5  ≥ 4 ✅, lastFinish=7)
Skip  Act 5  (start=3  < 7 ❌)
Skip  Act 6  (start=5  < 7 ❌)
Pick  Act 7  (start=8  ≥ 7 ✅, lastFinish=11)
Skip  Act 8  (start=8  < 11 ❌)
Skip  Act 9  (start=2  < 11 ❌)
Pick  Act 10 (start=12 ≥ 11 ✅, lastFinish=16)
Expected Output:
No. of non-conflicting activities: 4
List of selected activities: 1, 4, 7, 10  ✅

Complexity:
ValueTimeO(N log N) — dominated by sortSpaceO(N) — activity storageSonnet 4.6AdaptiveClaude is AI and can m
*/
