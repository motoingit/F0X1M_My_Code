// ============================================================
//  01_class_and_objects.cpp
//  RUN:  g++ 01_class_and_objects.cpp -o 01 && ./01
// ------------------------------------------------------------
//  CONCEPT: A class is a blueprint. Objects are real instances.
//  KEY IDEA: All objects of the same class share the SAME
//  methods, but a method BEHAVES DIFFERENTLY for each object
//  because each object holds DIFFERENT DATA.
//
//  (No header files: the class is declared AND defined right
//   here, so a beginner reads one file top-to-bottom.)
// ============================================================
#include <iostream>
#include <string>
using namespace std;

class Customer
{
public:
    // characteristics (data members)
    string name;
    string city;
    double walletBalance;

    // behaviour (member function) — ONE copy shared by all objects
    void placeOrder(string item, double price)
    {
        if (price > walletBalance)
        {
            cout << name << ": can't afford " << item << "\n";
            return;
        }
        walletBalance -= price;
        cout << name << " ordered " << item
             << " | balance left: Rs." << walletBalance << "\n";
    }
};

int main()
{
    // Two objects built from ONE blueprint
    Customer rahul;
    rahul.name = "Rahul";  rahul.city = "Haridwar";  rahul.walletBalance = 500;

    Customer priya;
    priya.name = "Priya";  priya.city = "Dehradun";  priya.walletBalance = 90;

    // SAME method, DIFFERENT behaviour — because data differs
    rahul.placeOrder("Biryani", 250);   // succeeds
    priya.placeOrder("Biryani", 250);   // fails

    return 0;
}
