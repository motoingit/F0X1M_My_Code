#include <iostream>
using namespace std;

int main() {
    int a, b, choice;
    cout << "Enter two numbers: ";
    cin >> a >> b;

    cout << "\nMenu:\n";
    cout << "1. Add\n2. Subtract\n3. Multiply\n4. Divide\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        
        case 1:
            cout << "Result: " << a + b << endl;
        case 2:
            cout << "Result: " << a - b << endl;
        case 3:
            cout << "Result: " << a * b << endl;
        default:
            cout << "Invalid choice!" << endl;
        case 4:
            if (b != 0)
                cout << "Result: " << (float)a / b << endl;
            else
                cout << "Error: Division by zero!" << endl;
        
    }

    return 0;
}
