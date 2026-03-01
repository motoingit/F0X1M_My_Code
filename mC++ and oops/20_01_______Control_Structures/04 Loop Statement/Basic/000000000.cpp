#include <iostream>
#include <vector>
using namespace std;

int main() {

    cout << "=== FOR LOOP ===" << endl;
    // Prints 0 to 4 using for loop
    for(int i = 0; i < 5; i++) {
        cout << i << " ";
    }
    cout << "\n" << endl;

    cout << "=== WHILE LOOP ===" << endl;
    // Prints 0 to 4 using while loop
    int j = 0;
    while(j < 5) {
        cout << j << " ";
        j++;
    }
    cout << "\n" << endl;

    cout << "=== DO-WHILE LOOP ===" << endl;
    // Prints 0 to 4 using do-while loop
    int k = 0;
    do {
        cout << k << " ";
        k++;
    } while(k < 5);
    cout << "\n" << endl;

    cout << "=== RANGE-BASED FOR LOOP ===" << endl;
    // Prints elements of a vector using range-based for loop
    vector<int> nums = {1, 2, 3, 4, 5};
    for(auto x : nums) {
        cout << x << " ";
    }
    cout << "\n" << endl;

    return 0;
}
