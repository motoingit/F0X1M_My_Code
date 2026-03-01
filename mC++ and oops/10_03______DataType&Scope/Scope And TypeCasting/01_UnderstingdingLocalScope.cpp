#include <iostream>
using namespace std;

void func() {
    if (true) {
        int x = 20; // block-scoped variable
        cout << "Block x = " << x << endl;
    }
    // cout << x; // error: x is not visible here
}

int main() {
    func();
    return 0;
}
