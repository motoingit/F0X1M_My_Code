#include <iostream>
#include <string>
using namespace std;
int main() {
    string at1 = "World";
    cout << "at() examples:" << endl;
    cout << "at1.at(0): " << at1.at(0) << endl;
    cout << "at1.at(2): " << at1.at(2) << endl;
    try {
        cout << "at1.at(10): ";
        cout << at1.at(10) << endl;
    } catch (const out_of_range& e) {
        cout << "Error: " << e.what() << endl;
    }
    return 0;
}
