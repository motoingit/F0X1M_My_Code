#include <iostream>
using namespace std;

// Function prototype
void sayHello();

int main() {
    cout << "Program started." << endl;

    // Function call
    sayHello();

    cout << "Program ended." << endl;
    return 0;
}

// Function definition
void sayHello() {
    cout << "Hello! This is a function." << endl;
}