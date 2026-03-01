#include <iostream>
#include <iomanip> // setw
#include <string>
using namespace std;

int main() {
    int a = 11, b = 222, c = 3333;

    int x = ((a*b) + c + (100/20));  // dont you think the manupulation is done here
    cout << x << endl;                  // by the smooth brackets
    

    return 0;
}
