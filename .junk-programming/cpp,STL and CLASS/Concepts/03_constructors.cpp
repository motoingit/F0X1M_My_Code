// ============================================================
//  03_constructors.cpp
//  RUN:  g++ 03_constructors.cpp -o 03 && ./03
// ------------------------------------------------------------
//  CONCEPT: A constructor runs automatically when an object is
//  born. Same name as the class, no return type.
//    - Constructor OVERLOADING : many constructors, different params
//    - COPY constructor        : build a new object from an old one
// ============================================================
#include <iostream>
#include <string>
using namespace std;

class Order
{
public:
    static int nextId;      // shared id generator (see file 04)
    int    id;
    string item;
    int    quantity;
    double price;

    // 1) DEFAULT constructor (no arguments)
    Order()
    {
        id = nextId++;
        item = "Not selected"; quantity = 0; price = 0;
        cout << "[default ctor] Order #" << id << "\n";
    }

    // 2) OVERLOADED constructor (one argument)
    Order(string itemName)
    {
        id = nextId++;
        item = itemName; quantity = 1; price = 0;
        cout << "[1-arg ctor]   Order #" << id << "\n";
    }

    // 3) OVERLOADED constructor (three arguments)
    Order(string itemName, int qty, double p)
    {
        id = nextId++;
        item = itemName; quantity = qty; price = p;
        cout << "[3-arg ctor]   Order #" << id << "\n";
    }

    // 4) COPY constructor — takes a const reference of its own class
    Order(const Order& other)
    {
        id = nextId++;                 // a copy is a NEW order → new id
        item = other.item;             // clone the data
        quantity = other.quantity;
        price = other.price;
        cout << "[copy ctor]    Order #" << id
             << " cloned from #" << other.id << "\n";
    }

    void show()
    {
        cout << "   #" << id << ": " << quantity << " x " << item
             << " = Rs." << price * quantity << "\n";
    }
};

int Order::nextId = 1001;   // define + initialise the static member

int main()
{
    cout << "--- constructor overloading ---\n";
    Order o1;                          // default
    Order o2("Masala Dosa");           // 1-arg
    Order o3("Chole Bhature", 2, 120); // 3-arg
    o1.show(); o2.show(); o3.show();

    cout << "\n--- copy constructor ---\n";
    Order o4 = o3;                     // "repeat my last order!"
    o4.show();
    return 0;
}
