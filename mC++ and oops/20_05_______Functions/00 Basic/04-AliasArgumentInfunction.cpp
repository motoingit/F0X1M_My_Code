
#include <iostream>
using namespace std;

// Function to calculate area of a square
float area(float &x) { // like a pointer but just derefrence operator
    return x * x;
}

int main() {
    float side = 5.0f;
    float areaSq = area(side);
    cout << "Area of square (side=" << side << "): ";
    cout << areaSq << endl;

return 0;}
