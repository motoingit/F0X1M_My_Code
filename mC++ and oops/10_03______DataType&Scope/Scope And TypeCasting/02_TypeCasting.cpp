#include <iostream>
using namespace std;

// Base and Derived classes to demo dynamic_cast
class Base {
public:
    virtual void greet() { cout << "Hello from Base\n"; }
    virtual ~Base() {}  // Polymorphic base needs virtual destructor
};

class Derived : public Base {
public:
    void greet() override { cout << "Hello from Derived\n"; }
};

int main() {

    // ---------------------------
    // 1. Implicit Typecasting
    // ---------------------------
    int i = 65.002;
    float f = i*0.02;  // int to float (automatic)
    cout << "Implicit cast int->float: " << static_cast<float> (f) << endl;


    // ---------------------------
    // 2. Literal Formats
    // ---------------------------
    int hexVal = 0x21;     // Hexadecimal (33 decimal)
    int octVal = 021;      // Octal (17 decimal)
    float floatLit = -3.2f;  // float literal with suffix f
    cout << "Hex literal 0x21: " << hexVal << endl;
    cout << "Octal literal 021: " << octVal << endl;
    cout << "Float literal -3.2f: " << floatLit << endl;



    // ---------------------------
    // 3. C-Style Cast
    // ---------------------------
    float pi = 3.14159f;
    int truncatedPi = (int)pi;  // Explicit cast: float to int
    cout << "C-style cast float->int: " << truncatedPi << endl;



    // ---------------------------
    // 4. C++ static_cast (Recommended)
    // ---------------------------
    double dVal = 9.99;
    int intVal = static_cast<int> (dVal);  // truncates to 9
    cout << "static_cast double->int: " << intVal << endl;






 //              DONE             // with basics
 












    // Convert int to char using static_cast
    char ch = static_cast<char>(i);
    cout << "static_cast int->char: " << ch << endl;



    // ---------------------------
    // 5. const_cast (Removing constness)
    // ---------------------------
    const int constInt = 100;
    int* ptr = const_cast<int*>(&constInt);
    *ptr = 200;  // Modifying const object undefined behavior, but demo only
    cout << "const_cast to remove const: " << *ptr << endl;




    // ---------------------------
    // 6. reinterpret_cast (Low-level, dangerous)
    // ---------------------------
    int num = 65;
    char* charPtr = reinterpret_cast<char*>(&num);
    cout << "reinterpret_cast int* to char*: " << *charPtr << " (ASCII char of 65)" << endl;




    // ---------------------------
    // 7. dynamic_cast (Safe downcasting with polymorphism)
    // ---------------------------
    Base* basePtr = new Derived();  // Upcasting (safe)
    Derived* derivedPtr = dynamic_cast<Derived*>(basePtr);  // Downcasting safely

    if (derivedPtr) {
        cout << "dynamic_cast successful: ";
        derivedPtr->greet();
    } else {
        cout << "dynamic_cast failed\n";
    }




    // Clean up
    delete basePtr;

    return 0;
}
