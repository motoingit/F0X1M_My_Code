

// default parameter should be in extream right 

#include <iostream>
using namespace std;

// Function to calculate area of a square
float area(float x, int y = 10) { // Default Parameter
    return x * x;
}

int main() {
    float side = 5.0f;
    float areaSq = area(2); // purpusly no argument
    cout << "Area of square (side=" << side << "): ";
    cout << areaSq << endl;

return 0;}
