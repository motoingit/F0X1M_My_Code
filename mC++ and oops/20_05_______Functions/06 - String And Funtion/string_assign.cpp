#include <iostream>
#include <string>
using namespace std;
int main() {
    string as1, as2 = "Initial", as3;
    cout << "Assign examples:" << endl;
    as1.assign("Assigned");
    cout << "as1 after assign: " << as1 << endl;
    as2 = "Reassigned";
    cout << "as2 after operator=: " << as2 << endl;
    as3.assign(as1, 0, 4); // assign substring
    cout << "as3 after assign substring: " << as3 << endl;
    return 0;
}
