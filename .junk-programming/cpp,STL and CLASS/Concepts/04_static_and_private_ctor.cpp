// ============================================================
//  04_static_and_private_ctor.cpp
//  RUN:  g++ 04_static_and_private_ctor.cpp -o 04 && ./04
// ------------------------------------------------------------
//  CONCEPT A: static (class) member — ONE copy shared by every
//             object; exists even before any object is created.
//  CONCEPT B: "Whatever belongs to the class belongs to the
//             object too" — a static member is reachable through
//             the class name AND through any object.
//  CONCEPT C: PRIVATE constructor — the class controls its own
//             creation (Singleton: exactly one instance).
// ============================================================
#include <iostream>
#include <string>
using namespace std;

class Restaurant
{
public:
    string name;                       // INSTANCE: each object its own
    static int totalRestaurants;       // CLASS: one shared copy

    Restaurant(string n)
    {
        name = n;
        totalRestaurants++;            // the shared counter grows
    }

    // a STATIC member function: belongs to the class, not an object
    static int getTotal()
    {
        // cout << name;   // ERROR: no object here, whose name?
        return totalRestaurants;
    }
};
int Restaurant::totalRestaurants = 0;  // created at load time, before main

// ---- PRIVATE CONSTRUCTOR (Singleton) ----
class AppConfig
{
private:
    string appName;
    AppConfig() { appName = "FoodieExpress"; cout << "[the ONE config created]\n"; }

public:
    static AppConfig& getInstance()    // the single controlled door
    {
        static AppConfig only;         // built once, reused forever
        return only;
    }
    void show() { cout << "   App = " << appName << "\n"; }
};

int main()
{
    cout << "Before any object, total = " << Restaurant::getTotal() << "\n";

    Restaurant r1("Chotiwala");
    Restaurant r2("Punjabi Tadka");

    // reachable via CLASS and via OBJECT — both read the same counter
    cout << "Via class : " << Restaurant::getTotal() << "\n";
    cout << "Via r1    : " << r1.getTotal() << "\n";
    cout << "Via r2    : " << r2.getTotal() << "\n";

    cout << "\n--- private constructor / singleton ---\n";
    // AppConfig c;                     // COMPILE ERROR: ctor is private
    AppConfig::getInstance().show();
    AppConfig::getInstance().show();    // note: created only ONCE
    return 0;
}
