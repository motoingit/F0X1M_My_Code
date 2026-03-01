#include <iostream>
using namespace std;
int main(){
    int x = 5;  // 0101 in binary
    int y = 3;  // 0011 in binary

    cout << "x = " << x << " (Binary: 0101)" << endl;
    cout << "y = " << y << " (Binary: 0011)" << endl << endl;

    cout << "Bitwise AND (x & y)  = " << (x & y) << endl;   // 0001 -> 1
    cout << "Bitwise OR  (x | y)  = " << (x | y) << endl;   // 0111 -> 7
    cout << "Bitwise XOR (x ^ y)  = " << (x ^ y) << endl;   // 0110 -> 6
    cout << "Bitwise NAND ~(x & y) = " << ~(x & y) << endl; // 1110 (-2 in 2's complement)
    cout << "Bitwise NOR ~(x | y)  = " << ~(x | y) << endl; // 1000 (-8 in 2's complement)
    cout << "Bitwise XNOR ~(x ^ y) = " << ~(x ^ y) << endl; // 1001 (-7 in 2's complement)

return 0;}