#include <iostream>
#include <string>
using namespace std;
int main() {
    string f1 = "Hello World", f2 = "Banana", f3 = "C++ Programming";
    cout << "find() examples:" << endl;
    cout << "'World' in f1: " << f1.find("World") << endl;
    cout << "'na' in f2: " << f2.find("na") << endl;
    cout << "'Java' in f3: ";
    size_t pos = f3.find("Java");
    if (pos != string::npos) cout << pos << endl;
    else cout << "not found" << endl;
    return 0;
}
