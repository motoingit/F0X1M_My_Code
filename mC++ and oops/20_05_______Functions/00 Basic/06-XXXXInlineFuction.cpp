#include <iostream>
using namespace std;

// Regular function
int regularAdd(int a, int b) {
    return a + b;
}

// Inline function - Method 1: using 'inline' keyword
inline int inlineAdd(int a, int b) {
    return a + b;
}

// Inline function - Method 2: defined inside class (automatically inline)
class Calculator {
public:
    // Functions defined inside class are automatically inline
    int multiply(int a, int b) {
        return a * b;
    }
    
    // Explicitly declared inline
    inline int divide(int a, int b) {
        if (b != 0) {
            return a / b;
        }
        return 0;
    }
    
    // Declared inside, defined outside (still inline)
    int subtract(int a, int b);
};

// Definition outside class - still inline because declared inside
inline int Calculator::subtract(int a, int b) {
    return a - b;
}

// Complex function - compiler may ignore inline request
inline int complexFunction(int n) {
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;  // Factorial calculation
    }
    return result;
}

// Recursive function - usually not inlined
inline int recursiveFactorial(int n) {
    if (n <= 1) return 1;
    return n * recursiveFactorial(n - 1);
}

int main() {
    int x = 10, y = 5;
    
    cout << "=== Inline Function Demonstration ===\n\n";
    
    // Regular function call
    cout << "Regular function: " << x << " + " << y << " = " 
         << regularAdd(x, y) << "\n";
    
    // Inline function call
    cout << "Inline function: " << x << " + " << y << " = " 
         << inlineAdd(x, y) << "\n";
    
    // Class inline functions
    Calculator calc;
    cout << "\nClass inline functions:\n";
    cout << "Multiply: " << x << " * " << y << " = " 
         << calc.multiply(x, y) << "\n";
    cout << "Divide: " << x << " / " << y << " = " 
         << calc.divide(x, y) << "\n";
    cout << "Subtract: " << x << " - " << y << " = " 
         << calc.subtract(x, y) << "\n";
    
    // Complex function (may not be inlined)
    cout << "\nComplex inline function:\n";
    cout << "Factorial of 5: " << complexFunction(5) << "\n";
    
    // Recursive function (usually not inlined)
    cout << "Recursive factorial of 5: " << recursiveFactorial(5) << "\n";
    
    // Performance demonstration
    cout << "\n=== Performance Test ===\n";
    cout << "Both functions produce same result, but inline may be faster\n";
    cout << "due to elimination of function call overhead.\n";
    
    return 0;
}

/*
=== INLINE FUNCTION BEHAVIOR ===

Without inline:
1. Function call made
2. Parameters pushed to stack
3. Jump to function address
4. Execute function
5. Return value
6. Clean up stack
7. Return to caller

With inline (when successful):
1. Function code directly inserted at call site
2. No stack operations
3. No jumps
4. Direct execution
5. Faster execution

Example:
regularAdd(5, 3) → Call overhead + execution
inlineAdd(5, 3)  → Directly becomes: 5 + 3 (in compiled code)
*/