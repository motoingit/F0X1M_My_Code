#include <iostream>
#include <string>
using namespace std;

string decimalToBase(int num, int base) {
    if (num == 0) return "0";
    string digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"; // Supports up to base 36
    string result = "";

    while (num > 0) {
        int rem = num % base;
        result = digits[rem] + result; // Prepend remainder
        num /= base;
    }
    return result;
}

int main() {
    int num, base;
    cout << "Enter decimal number and target base: ";
    cin >> num >> base;

    if (base < 2 || base > 36) {
        cout << "Base must be between 2 and 36" << endl;
        return 1;
    }

    cout << num << " in base " << base << " is " << decimalToBase(num, base) << endl;
    return 0;
}
