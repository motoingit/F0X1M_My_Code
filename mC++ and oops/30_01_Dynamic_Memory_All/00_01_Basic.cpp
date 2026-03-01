#include <iostream>

int main() {
    int* pointer = new int(19);  // dynamically allocates memory for one int and initializes it to 19

    std::cout << *pointer << std::endl;   // prints 19
    *pointer = 10;                        // updates the value stored in that memory location
    std::cout << *pointer << std::endl;   // prints 10

    delete pointer;   // frees the memory previously allocated (very important!)

    return 0;
}
