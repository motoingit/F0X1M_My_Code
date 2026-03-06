#include <iostream>
#include <vector>
#include <algorithm> // Required for std::reverse

using namespace std;

int main() {
    vector<int> arrList = {1, 2, 3, 4, 5, 6};
    int n = arrList.size();
    int k = 2; // Let's rotate by 2 for this example
    k %= n;

    // Standard 3-step reversal for Right Rotation
    reverse(arrList.begin(), arrList.begin() + (n - k)); // Part 1

    reverse(arrList.begin() + (n - k), arrList.end());   // Part 2

    reverse(arrList.begin(), arrList.end());             // Whole array

    for (int x : arrList) cout << x << " "; // Output: 5 6 1 2 3 4
    return 0;
}
