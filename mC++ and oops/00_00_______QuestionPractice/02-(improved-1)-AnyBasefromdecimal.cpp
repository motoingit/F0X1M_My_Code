#include <iostream>
using namespace std;

// Reverse an integer (works correctly only when digits are 0-9)
void reverseInt(int &n) {
    int rev = 0;
    while (n > 0) {
        rev = rev * 10 + (n % 10);
        n /= 10;
    }
    n = rev;
}

int main() {
    int base, num;
    cout << "Enter base and number (decimal): ";
    if (!(cin >> base >> num)) {
        cout << "Invalid input\n";
        return 1;
    }

    if (base < 2 || base > 10) {
        cout << "This integer-only method supports base 2..10.\n";
        return 1;
    }

    if (num == 0) {
        cout << "Number in base " << base << " is: 0\n";
        return 0;
    }

    int temp = num;
    int sum = 0;

    // Debug print of remainders from LSB -> MSB
    cout << "Remainders (LSB -> MSB): ";
    while (temp > 0) {
        int rem = temp % base;      // correct remainder for each step
        cout << rem << ' ';
        sum = sum * 10 + rem;       // append remainder as a digit
        temp /= base;
    }
    cout << '\n';

    reverseInt(sum); // reverse to get MSB -> LSB order
    cout << "The number " << num << " in base " << base << " is: " << sum << '\n';
    return 0;
}
