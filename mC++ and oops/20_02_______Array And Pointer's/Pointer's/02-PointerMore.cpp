#include <iostream>
using namespace std;

int main() {
    int a = 10;
    int* b = &a; // Pointer to 'a'
        
    // & ---> (Address of) Operator
    cout << "The address of a is (direct)" << &a << endl;
    cout << "The address of a is (indirect in b)" << b << endl;

    // * ---> (value at) Dereference operator
    cout << "The value at address b is " << *b << endl;

                        // Pointer to pointer
    int** c = &b;
    cout << "The address of b is " << &b << endl;
    cout << "The address of b is " << c << endl;
    cout << "The value at address c is " << *c << endl;
    cout << "The value at address value_at(value_at(c)) is " << **c << endl;

    return 0;
}
