#include <iostream>
using namespace std;

class Car {
    string model; // Private by default in class
    // To access this member, we need to use public methods
public:
    void setModel(string m) { model = m; }
    void display() { cout << "Car model: " << model; }
};

int main() {

    Car c;
    c.setModel("Tesla");
    c.display();
    
return 0;}

/*
class (Class)
	• Encapsulates data (attributes) and functions (methods) together.
	• By default, members are private.
	• Supports OOP concepts like encapsulation, inheritance, and polymorphism.

    • Similar to struct but with private members by default.
    • Supports encapsulation, inheritance, and polymorphism.
    - Often used for complex data structures and behaviors.

    • Members can be private, protected, or public.
    • Provides better control over data access and manipulation.
*/