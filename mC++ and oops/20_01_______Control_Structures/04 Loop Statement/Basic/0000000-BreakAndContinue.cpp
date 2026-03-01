#include <iostream>
using namespace std;

int main() {
    for (int i = 1; i <= 10; i++) {
        if (i == 3) {
            continue; // Skip printing 3
        }
        if (i == 7) {
            break; // Stop the loop when i becomes 7
        }
        cout << i << " ";
    }

    return 0;
}
