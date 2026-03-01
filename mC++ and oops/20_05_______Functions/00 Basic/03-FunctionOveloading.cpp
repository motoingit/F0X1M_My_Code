
    ///same name but different parameters
    ///Function Overloading


#include <iostream>
using namespace std;

// Function to calculate area of a square
float area(float side) {
    return side * side;
}

// Function to calculate area of a rectangle
float area(float length, float width) {
    return length * width;
}

// Function to calculate area of a triangle
float area(float base, float height, char type) {
    if (type == 'T') { // General triangle
        return 0.5f * base * height;
    }
    else if (type == 'E') { // Equilateral triangle (all sides equal)
        // base here means side length
        return (sqrt(3) / 4) * base * base;
    }
    else if (type == 'I') { // Isosceles triangle (two sides equal)
        // base = base length, height = equal side length
        float h = sqrt((height * height) - ((base * base) / 4));
        return 0.5f * base * h;
    }
    else {
        return -1; // Invalid type
    }
}

// Function to calculate area of a circle
float area(double radius) {
    return 3.14159 * radius * radius;
}

int main() {

    cout << "Area of square (side=5): " << area(5.0f) << endl;
    cout << "Area of rectangle (5x3): " << area(5.0f, 3.0f) << endl;
    cout << "Area of triangle (base=6, height=4): " << area(6.0f, 4.0f, 'T') << endl;
    cout << "Area of circle (radius=2.5): " << area(2.5) << endl;

return 0;}
