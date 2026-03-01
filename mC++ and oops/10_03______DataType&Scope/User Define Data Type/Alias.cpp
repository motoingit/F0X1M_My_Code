#include <iostream>
using namespace std;

typedef unsigned int uint;     // Old style alias
using uint2 = unsigned int;    // Modern alias

int main() {
    uint age = 25;     // age is unsigned int
    uint2 salary = 50000; // salary is unsigned int
    cout << age << " " << salary; // Output: 25 50000
}
