#include <iostream>
#include <string>
using namespace std;

int main() {
    cout << "pqr" + 5 << endl;  // Outputs: "6pqr"
    cout << ("pqr" + 2) << endl;  // Moves pointer ahead, risky!

    return 0;
}
