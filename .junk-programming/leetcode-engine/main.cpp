#include <iostream>
#include <vector>
#include "test_runner.h"

// =============================================
//   ONLY EDIT INSIDE Solution
// =============================================
class Solution {
public:
    void sort(std::vector<int>& arr) {
        // your code here
        int n = arr.size();
        for (int i = 0; i < n - 1; i++)
            for (int j = 0; j < n - i - 1; j++)
                if (arr[j] > arr[j + 1])
                    std::swap(arr[j], arr[j + 1]);
    }
};
// =============================================

int main() {
    std::vector<std::string> testFiles = {
        "testcases/best_case.txt",
        "testcases/avg_case.txt",
        "testcases/worst_case.txt",
    };

    Solution solution;
    runAll(testFiles, solution);

    return 0;
}
