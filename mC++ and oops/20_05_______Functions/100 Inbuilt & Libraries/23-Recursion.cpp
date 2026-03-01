#include <iostream>
using namespace std;

// Recursive function to calculate factorial
long long factorial(int n) {
    // Base case: factorial of 0 and 1 is 1
    if (n <= 1) {
        return 1;
    }
    
    // Recursive case: n! = n * (n-1)!
    return n * factorial(n - 1);
}

// Enhanced version with input validation
long long factorialSafe(int n) {
    // Handle negative numbers
    if (n < 0) {
        cout << "Error: Factorial is not defined for negative numbers!\n";
        return -1;  // Error indicator
    }
    
    // Base case
    if (n <= 1) {
        return 1;
    }
    
    // Recursive case
    return n * factorialSafe(n - 1);
}

// Function to demonstrate the recursion step by step
long long factorialDebug(int n, int depth = 0) {
    // Print indentation for visualization
    for (int i = 0; i < depth; i++) {
        cout << "  ";
    }
    
    cout << "factorial(" << n << ") called\n";
    
    // Base case
    if (n <= 1) {
        for (int i = 0; i < depth; i++) {
            cout << "  ";
        }
        cout << "Base case reached: returning 1\n";
        return 1;
    }
    
    // Recursive case
    long long result = n * factorialDebug(n - 1, depth + 1);
    
    for (int i = 0; i < depth; i++) {
        cout << "  ";
    }
    cout << "factorial(" << n << ") = " << n << " * factorial(" << n-1 << ") = " << result << "\n";
    
    return result;
}

int main() {
    int number, choice;
    long long result;
    
    cout << "=== Factorial Calculator (Recursion) ===\n";
    cout << "1. Simple factorial\n";
    cout << "2. Safe factorial (with error handling)\n";
    cout << "3. Debug factorial (shows recursion steps)\n";
    cout << "4. Exit\n";
    
    do {
        cout << "\nEnter your choice (1-4): ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter a number: ";
                cin >> number;
                result = factorial(number);
                cout << "Factorial of " << number << " = " << result << "\n";
                break;
                
            case 2:
                cout << "Enter a number: ";
                cin >> number;
                result = factorialSafe(number);
                if (result != -1) {
                    cout << "Factorial of " << number << " = " << result << "\n";
                }
                break;
                
            case 3:
                cout << "Enter a number (recommended: small numbers for clarity): ";
                cin >> number;
                if (number < 0) {
                    cout << "Cannot calculate factorial of negative numbers!\n";
                } else if (number > 10) {
                    cout << "Warning: Large numbers will create long output.\n";
                    cout << "Continue? (1 for yes, 0 for no): ";
                    int confirm;
                    cin >> confirm;
                    if (!confirm) break;
                }
                cout << "\n--- Recursion Trace ---\n";
                result = factorialDebug(number);
                cout << "\nFinal Result: " << number << "! = " << result << "\n";
                break;
                
            case 4:
                cout << "Thank you for using the factorial calculator!\n";
                break;
                
            default:
                cout << "Invalid choice! Please enter 1-4.\n";
        }
        
    } while (choice != 4);
    
    // Additional examples
    cout << "\n=== Quick Examples ===\n";
    for (int i = 0; i <= 10; i++) {
        cout << i << "! = " << factorial(i) << "\n";
    }
    
    return 0;
}

/*
=== How Recursion Works in Factorial ===

Mathematical Definition:
- 0! = 1 (by definition)
- 1! = 1 (by definition)  
- n! = n × (n-1)! for n > 1

Example: 5! = 5 × 4 × 3 × 2 × 1 = 120

Recursion Trace for factorial(5):
factorial(5) → 5 × factorial(4)
            → 5 × (4 × factorial(3))
            → 5 × (4 × (3 × factorial(2)))
            → 5 × (4 × (3 × (2 × factorial(1))))
            → 5 × (4 × (3 × (2 × 1)))
            → 5 × (4 × (3 × 2))
            → 5 × (4 × 6)
            → 5 × 24
            → 120

Memory Stack:
factorial(5)  ←  Active
factorial(4)  ←  Waiting
factorial(3)  ←  Waiting  
factorial(2)  ←  Waiting
factorial(1)  ←  Returns 1

Time Complexity: O(n)
Space Complexity: O(n) - due to recursion stack
*/