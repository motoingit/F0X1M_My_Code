#include <iostream>
#include <string>
using namespace std;

// 1. No-argument, No-return Function
void showWelcomeMessage() {
    cout << "Welcome to the program!" << endl;
}

// 2. No-argument, With-return Function
int getPinCode() {
    return 1234;  // Returns a fixed integer value
}

// 3. With-arguments, No-return Function
void printSum(int a, int b) {
    cout << "Sum is: " << a + b << endl;
}

// 4. With-arguments, With-return Function
int add(int a, int b) {
    return a + b;  // Takes two integers and returns their sum
}

// 5. Functions with Default Arguments
void showMessage(string message, string level = "INFO") {
    cout << level << ": " << message << endl;
}

// 7. Recursive Function (factorial)
int factorial(int n) {
    if (n <= 1) {
        return 1;  // Base case
    } else {
        return n * factorial(n - 1);  // Recursive step
    }
}

// 8. Overloaded Functions to calculate area
int calculateArea(int side) {  // Square
    return side * side;
}

int calculateArea(int length, int width) {  // Rectangle
    return length * width;
}

double calculateArea(double base, double height) {  // Triangle
    return 0.5 * base * height;
}

// 9. Inline Function (small and frequently used)
inline int square(int x) {
    return x * x;
}

int main() {
    // 1.
    showWelcomeMessage();

    // 2.
    cout << "Pin Code: " << getPinCode() << endl;

    // 3.
    printSum(10, 20);

    // 4.
    int result = add(15, 25);
    cout << "Add result: " << result << endl;

    // 5.
    showMessage("File not found.", "WARNING");
    showMessage("Operation successful.");  // uses default "INFO"

    // 7.
    cout << "Factorial of 5: " << factorial(5) << endl;

    // 8.
    cout << "Area of square (5): " << calculateArea(5) << endl;
    cout << "Area of rectangle (4x6): " << calculateArea(4, 6) << endl;
    cout << "Area of triangle (3.0, 7.0): " << calculateArea(3.0, 7.0) << endl;

    // 9.
    cout << "Square of 8: " << square(8) << endl;

    return 0;
}
