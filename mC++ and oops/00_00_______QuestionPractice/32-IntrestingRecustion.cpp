#include <iostream>
#include <cstdio> // For getchar, putchar, EOF
using namespace std;
void reverseInput() {
    int c = getchar(); // Use int, not char
    if (c == EOF) return;
    reverseInput();
    putchar(c);
}

int main() {
    cout << "Enter text :";
    reverseInput();
    return 0;
}
