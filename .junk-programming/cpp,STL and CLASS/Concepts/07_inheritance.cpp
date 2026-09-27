// ============================================================
//  07_inheritance.cpp   — PILLAR 3
//  RUN:  g++ 07_inheritance.cpp -o 07 && ./07
// ------------------------------------------------------------
//  CONCEPT: Inheritance = a child class reuses a parent's
//  members and adds its own. Write common code ONCE.
//    'protected' members: visible to children, hidden from outside.
//    "is-a" test: a DeliveryPartner IS-A User. ✓
// ============================================================
#include <iostream>
#include <string>
using namespace std;

// -------- BASE (parent) class --------
class User
{
protected:                 // children can use these; outsiders cannot
    string name;
    int    id;

public:
    User(string n, int i) { name = n; id = i; }

    void login()           // written ONCE, inherited by all children
    {
        cout << name << " (id " << id << ") logged in\n";
    }
};

// -------- DERIVED (child) classes --------
class Customer : public User
{
public:
    Customer(string n, int i) : User(n, i) {}   // pass up to parent

    void browse()
    {
        cout << name << " is browsing restaurants\n";  // uses protected 'name'
    }
};

class DeliveryPartner : public User
{
public:
    DeliveryPartner(string n, int i) : User(n, i) {}

    void goOnline()
    {
        cout << name << " is now online for deliveries\n";
    }
};

int main()
{
    Customer rahul("Rahul", 1);
    DeliveryPartner ravi("Ravi", 501);

    rahul.login();    // inherited from User — not rewritten in Customer
    rahul.browse();   // Customer's own

    ravi.login();     // inherited from User
    ravi.goOnline();  // DeliveryPartner's own
    return 0;
}
