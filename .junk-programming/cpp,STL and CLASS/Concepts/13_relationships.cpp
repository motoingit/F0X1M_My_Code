
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// ---- part used in COMPOSITION (owned) ----
class Kitchen
{
public:
    Kitchen()  { cout << "   [kitchen built inside restaurant]\n"; }
    ~Kitchen() { cout << "   [kitchen demolished with restaurant]\n"; }
};

// ---- part used in AGGREGATION (independent life) ----
class Chef
{
public:
    string name;
    Chef(string n) { name = n; }
};

class Restaurant
{
private:
    string name;
    Kitchen kitchen;             // COMPOSITION: member object, born & dies here
    vector<Chef*> chefs;         // AGGREGATION: only pointers to outside chefs
public:
    Restaurant(string n) : name(n) { cout << "[restaurant " << name << " opened]\n"; }
    ~Restaurant() { cout << "[restaurant " << name << " closed]\n"; }

    void hire(Chef* c)           // chefs exist outside; we just reference them
    {
        chefs.push_back(c);
        cout << "   " << c->name << " now cooks at " << name << "\n";
    }
    string getName() { return name; }
};

// ---- ASSOCIATION: Customer just uses a Restaurant, no ownership ----
class Customer
{
    string name;
public:
    Customer(string n) { name = n; }
    void rate(Restaurant& r, double stars)
    {
        cout << name << " rated " << r.getName() << " " << stars << " stars\n";
    }
};

int main()
{
    Chef sanjeev("Chef Sanjeev");    // chefs are born FIRST, independently
    Chef ranveer("Chef Ranveer");

    {
        Restaurant r("Chotiwala");   // kitchen is born WITH the restaurant
        r.hire(&sanjeev);            // aggregation: borrow the chefs
        r.hire(&ranveer);

        Customer rahul("Rahul");
        rahul.rate(r, 4.5);          // association: use, then walk away

        cout << "--- leaving restaurant scope ---\n";
    }                                // restaurant dies → kitchen dies with it

    cout << "\nAfter closure, " << sanjeev.name << " & " << ranveer.name
         << " are still available for hire.\n";   // aggregation proof
    return 0;
}
