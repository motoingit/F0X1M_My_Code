#include <iostream>
using namespace std;

int main() {
    int a = 5, b = 5;

    // Pre-increment: value is incremented BEFORE use
    int pre = ++a;  // a becomes 6, then used

    // Post-increment: value is used BEFORE increment
    int post = b++; // b is used as 5, then becomes 6

    cout << "Pre-increment result (pre = ++a): " << pre << endl;
    cout << "Post-increment result (post = b++): " << post << endl;
    cout << "Final value of a: " << a << endl;
    cout << "Final value of b: " << b << endl;

    return 0;
}
