#include <iostream>
#include <string>
using namespace std;
int main() {
    string e1 = "", e2 = "Not empty", e3;
    cout << "Empty examples:" << endl;
    cout << "e1 is " << (e1.empty() ? "empty" : "not empty") << endl;
    cout << "e2 is " << (e2.empty() ? "empty" : "not empty") << endl;
    cout << "e3 is " << (e3.empty() ? "empty" : "not empty") << endl;
    return 0;
}
