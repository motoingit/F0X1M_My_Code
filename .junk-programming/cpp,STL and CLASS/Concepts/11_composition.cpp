// ============================================================
//  11_composition.cpp   — RELATIONSHIP 3 of 3
//  RUN:  g++ 11_composition.cpp -o 11 && ./11
// ------------------------------------------------------------
//  COMPOSITION = "has-a (owned)". The STRONGEST link.
//    * The part is created INSIDE the whole and OWNED by it.
//    * The part cannot meaningfully exist on its own.
//    * When the whole dies, the part DIES with it.
//  Hook: a BODY and its HEART — no body, no heart.
//
//  Here: a Restaurant OWNS its Kitchen and Menu. They are
//  MEMBER OBJECTS (not pointers). They are born in the
//  Restaurant's constructor and destroyed in its destructor —
//  automatically, in reverse order. Watch the destructor log.
// ============================================================
#include <iostream>
#include <string>
using namespace std;

class Kitchen
{
public:
    Kitchen()  { cout << "   Kitchen built\n"; }
    ~Kitchen() { cout << "   Kitchen demolished\n"; }
};

class Menu
{
public:
    Menu()  { cout << "   Menu printed\n"; }
    ~Menu() { cout << "   Menu discarded\n"; }
};

class Restaurant
{
private:
    string  name;
    Kitchen kitchen;    // COMPOSITION: member object, OWNED
    Menu    menu;       // COMPOSITION: member object, OWNED
public:
    Restaurant(string n) : name(n)     // members built BEFORE this body runs
    {
        cout << "[Restaurant " << name << " fully assembled]\n";
    }
    ~Restaurant()
    {
        cout << "[Restaurant " << name << " shutting down]\n";
    }   // after this line, kitchen & menu destructors fire automatically
};

int main()
{
    cout << "Opening a restaurant:\n";
    {
        Restaurant r("Chotiwala");
        cout << "\n...restaurant is running...\n\n";
        cout << "Closing time:\n";
    }   // r goes out of scope -> Restaurant dtor, then Menu dtor, then Kitchen dtor

    cout << "\nThe Kitchen and Menu had NO life outside the Restaurant.\n";
    cout << "They were born with it and died with it = composition.\n";
    return 0;
}
