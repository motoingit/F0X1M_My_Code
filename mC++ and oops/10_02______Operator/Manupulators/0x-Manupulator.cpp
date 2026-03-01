#include <iostream>
#include <iomanip> // setw
#include <string>
using namespace std;

int main() {
    int num = 255;
    double pi = 3.14159265;

    cout << "=== Number Base Manipulators ===" << endl;
    cout << dec << num << " (decimal)" << endl;
    cout << hex << num << " (hex)" << endl;
    cout << oct << num << " (octal)" << endl;
    cout << showbase << hex << num << " (hex with base)" << endl;

    cout << "\n=== Output Formatting ===" << endl;
    cout << setw(10) << setfill('*') << right << 42 << endl;
    cout << fixed << setprecision(3) << pi << endl;
    cout << scientific << uppercase << pi << endl;

    cout << "\n=== Boolean Manipulators ===" << endl;
    cout << boolalpha << true << " " << false << endl;
    cout << noboolalpha << true << " " << false << endl;

    cout << "\n=== Special Manipulators ===" << endl;
    cout << "Hello" << ends << "World" << endl;
    cout << "Hello" << flush << "World" << endl;

    return 0;
}
