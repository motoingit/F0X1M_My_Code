
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Chef
{
public:
    string name;
    Chef(string n) { name = n; cout << "   Chef " << name << " (exists independently)\n"; }
    ~Chef() { cout << "   Chef " << name << " retired\n"; }
};

class Restaurant
{
private:
    string name;
    vector<Chef*> chefs;         // AGGREGATION: pointers only — NOT owned
public:
    Restaurant(string n) { name = n; cout << "[Restaurant " << name << " opened]\n"; }
    ~Restaurant() { cout << "[Restaurant " << name << " closed]\n"; }

    void addChef(Chef* c)        // borrow an already-existing chef
    {
        chefs.push_back(c);
        cout << "   " << c->name << " now cooks at " << name << "\n";
    }
    void listChefs()
    {
        cout << "   " << name << " kitchen team: ";
        for (Chef* c : chefs) cout << c->name << "  ";
        cout << "\n";
    }
};

int main()
{
    // Chefs are born FIRST and OUTSIDE any restaurant.
    Chef sanjeev("Sanjeev");
    Chef ranveer("Ranveer");

    {
        Restaurant r("Chotiwala");
        r.addChef(&sanjeev);
        r.addChef(&ranveer);     // the SAME chef could also work elsewhere
        r.listChefs();

        cout << "--- restaurant scope ending ---\n";
    }   // Restaurant destroyed here. Its vector<Chef*> vanishes...
        // ...but the Chef OBJECTS are untouched (aggregation!).

    cout << "\nAfter closure, " << sanjeev.name << " and " << ranveer.name
         << " are still available for hire.\n";
    cout << "(Their destructors run only now, at end of main.)\n";
    return 0;
}
