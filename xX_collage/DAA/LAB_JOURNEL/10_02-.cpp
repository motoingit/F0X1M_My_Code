/*
Task Scheduling with Deadlines — Maximum TasksProblem (Compact):
Given N tasks each with a duration and deadline, schedule the maximum number of tasks (executed sequentially, start from time 0) such that no task misses its deadline.Approach — Earliest Deadline First (EDF Greedy):

Sort tasks by deadline ascending
Maintain a running currentTime
Greedily include a task if currentTime + duration ≤ deadline
Skip if it would cause a deadline miss

Why EDF? Scheduling the most urgent (earliest deadline) task first minimises the chance of future deadline violations — provably optimal for maximising task count.

*/

/* Question: Task Scheduling — Maximum tasks within deadlines */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Task {
    int id;
    int duration;
    int deadline;
};

int main() {
    int n;
    cin >> n;

    vector<int> dur(n), dead(n);
    for (int i = 0; i < n; i++) cin >> dur[i];
    for (int i = 0; i < n; i++) cin >> dead[i];

    vector<Task> tasks(n);
    for (int i = 0; i < n; i++)
        tasks[i] = {i + 1, dur[i], dead[i]};

    // Sort by deadline ascending (EDF greedy criterion)
    sort(tasks.begin(), tasks.end(), [](const Task& a, const Task& b) {
        return a.deadline < b.deadline;
    });

    vector<int> selected;
    int currentTime = 0;

    for (auto& t : tasks) {
        // Can we finish this task before its deadline?
        if (currentTime + t.duration <= t.deadline) {
            selected.push_back(t.id);
            currentTime += t.duration;
        }
        // else skip — adding it would push everything past deadlines
    }

    // Sort by original id for clean output
    sort(selected.begin(), selected.end());

    cout << "Max number of tasks = " << selected.size() << "\n";
    cout << "Selected task numbers : ";
    for (int i = 0; i < (int)selected.size(); i++) {
        if (i) cout << ", ";
        cout << selected[i];
    }
    cout << "\n";

    return 0;
}

/*
Sample Input:
7
2 1 3 2 2 2 1
2 3 8 6 2 5 3
Tasks Table:
IDDurationDeadline122213338426522625713
After sort by deadline → EDF trace:
currentTime = 0

Task 1  (dur=2, dead=2): 0+2=2  ≤ 2  ✅ → pick,  time=2
Task 5  (dur=2, dead=2): 2+2=4  > 2  ❌ → skip
Task 2  (dur=1, dead=3): 2+1=3  ≤ 3  ✅ → pick,  time=3
Task 7  (dur=1, dead=3): 3+1=4  > 3  ❌ → skip
Task 6  (dur=2, dead=5): 3+2=5  ≤ 5  ✅ → pick,  time=5
Task 4  (dur=2, dead=6): 5+2=7  > 6  ❌ → skip
Task 3  (dur=3, dead=8): 5+3=8  ≤ 8  ✅ → pick,  time=8
Expected Output:
Max number of tasks = 4
Selected task numbers : 1, 2, 3, 6  ✅

Complexity:
ValueTimeO(N log N) — sort dominatesSpaceO(N)
EDF vs Activity Selection — Key Difference:
Activity SelectionTask SchedulingSort byFinish timeDeadlineConstraintstart ≥ lastFinishtime + dur ≤ deadlineTime trackedLast finish timeCumulative durationGoalMax non-overlappingMax within deadlines
*/
