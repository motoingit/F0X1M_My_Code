#include <iostream>
using namespace std;

union Data {                // Union to hold different data types with the 
    int intVal;           // same memory location as the largest member memory size
    float floatVal;
};

int main() {
    Data d;
    d.intVal = 10; // Store an integer in the union
    cout << d.intVal << endl; // Output: 10

    d.floatVal = 5.5; // Store a float in the union (overwrites intVal)
    cout << d.floatVal << endl; // Output: 5.5
    
    
    // Accessing intVal now results in undefined behavior since it was overwritten
    cout << d.intVal << endl; // This would be incorrect and could lead to unexpected output
}

/*
    A union allows storing different data types in the same memory location.
    Only one member can hold a value at a time, saving memory.
    Only one value can be stored at a time (if you store a new member, the previous one is overwritten in memory)
    
    The size of the union is determined by the size of its largest member.
    Accessing a member that was not most recently written to results in undefined behavior.
*/  