
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// ---- owned part (composition) ----
class Kitchen
{
public:
    Kitchen()  { cout << "     Kitchen built inside restaurant\n"; }
    ~Kitchen() { cout << "     Kitchen demolished with restaurant\n"; }
};

// ---- independent part (aggregation) ----
class Chef
{
public:
    string name;
    Chef(string n) { name = n; }
};

class Restaurant
{
private:
    string        name;
    Kitchen       kitchen;    // COMPOSITION  ──◆  owned member object
    vector<Chef*> chefs;      // AGGREGATION  ──◇  borrowed pointers
public:
    Restaurant(string n) : name(n) { cout << "  [Restaurant " << name << " opened]\n"; }
    ~Restaurant() { cout << "  [Restaurant " << name << " closed]\n"; }

    void addChef(Chef* c) { chefs.push_back(c); }
    string getName() { return name; }
    void serve() { cout << "     " << name << " cooking with " << chefs.size() << " chefs\n"; }
};

// ---- uses the restaurant (association) ----
class Customer
{
private:
    string name;
public:
    Customer(string n) { name = n; }
    void orderFrom(Restaurant& r)     // ASSOCIATION ── plain line
    {
        cout << "     " << name << " ordered from " << r.getName() << "\n";
    }
};

int main()
{
    // Chefs exist independently (they'll be AGGREGATED, not owned)
    Chef sanjeev("Sanjeev");
    Chef ranveer("Ranveer");

    // A customer exists independently (will ASSOCIATE, not be owned)
    Customer rahul("Rahul");

    cout << "OPEN:\n";
    {
        Restaurant chotiwala("Chotiwala");   // Kitchen COMPOSED inside it now
        chotiwala.addChef(&sanjeev);         // chefs AGGREGATED (borrowed)
        chotiwala.addChef(&ranveer);
        chotiwala.serve();

        rahul.orderFrom(chotiwala);          // customer ASSOCIATES (uses)

        cout << "\nCLOSE:\n";
    }   // Restaurant dies -> Kitchen dies WITH it (composition).

    // ...but chefs and customer are untouched:
    cout << "\nSURVIVORS (not owned by the restaurant):\n";
    cout << "     Chefs " << sanjeev.name << " & " << ranveer.name
         << " -> available for a new restaurant\n";
    cout << "     Customer Rahul -> can order from a different restaurant\n";
    return 0;
}
