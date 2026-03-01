#include <iostream>
#include <iomanip> // setw
#include <string>
using namespace std;

int main() {
    int a = 11, b = 222, c = 3333;

    // left justified by default
    cout << "The Value of a is " << a << endl;
    cout << "The Value of b is " << b << endl;
    cout << "The Value of c is " << c << endl;

    // for right justified          //set(x) gives
    cout << "The Value of a is " << setw(4) << a << endl;
    cout << "The Value of b is " << setw(4) << b << endl;
    cout << "The Value of c is " << setw(4) << c << endl;
    



    return 0;
}
