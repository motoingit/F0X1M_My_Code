#include <iostream>
#include <utility>
#include <iomanip> 
using namespace std;

int main() {
    pair<int, string> p = {1, "One"};
    cout << "Pair: " << p.first << ", " << p.second << endl;
    
    int a = 5, b = 10;
    swap(a, b); // swap values
    cout << "After swap: a=" << a << ", b=" << b << endl;

    double num = 123.456789;
    cout << fixed << setprecision(2) << "Formatted: " << num << endl; // 123.46
}
