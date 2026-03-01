#include <iostream>
using namespace std;

int main() {
    if (sizeof(void*) == 4)
        cout << "You are using a 32-bit OS" << endl;
    else if (sizeof(void*) == 8)
        cout << "You are using a 64-bit OS" << endl;
return 0;}
