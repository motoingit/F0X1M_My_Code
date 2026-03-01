#include <iostream>
using namespace std;

// Function prototype
void sayhii();
void sayHello();
int main() {
    cout << "Program started." << endl;

    // Function call
    sayhii();

    cout << "Program ended." << endl;
    return 0;
}

// Function definition
void sayhii() {
    cout << "Hii! This is a function." << endl;
    sayHello();  // Calling another function within this function (STACK)
}
void sayHello() {
    cout << "Hello! This is a function." << endl;
}