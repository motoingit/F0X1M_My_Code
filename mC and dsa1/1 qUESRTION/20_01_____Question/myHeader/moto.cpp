#include <iostream>
#include "moto_header.h"

int add(int a, int b) {
    return a + b;
}

int divi(int a, int b) {
    if (b == 0) {
        std::cout << "divisor is 0\n";
        return -1;
    }
    return a / b;
}
