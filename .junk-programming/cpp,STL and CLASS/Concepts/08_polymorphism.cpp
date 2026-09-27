#include <iostream>
#include <string>
#include <vector>
using namespace std;

// ---------- COMPILE-TIME: function overloading ----------
class SearchService
{
public:
    void search(string dish)
    { cout << "search: " << dish << "\n"; }

    void search(string dish, double maxPrice)
    { cout << "search: " << dish << " under Rs." << maxPrice << "\n"; }

    void search(string dish, double maxPrice, double minRating)
    { cout << "search: " << dish << " under Rs." << maxPrice
           << " rated " << minRating << "+\n"; }
};

// ---------- RUN-TIME: overriding via virtual ----------
class DeliveryPartner
{
protected:
    string name;
public:
    DeliveryPartner(string n) { name = n; }
    virtual void deliver()          // 'virtual' enables overriding
    { cout << name << " delivers\n"; }
    virtual ~DeliveryPartner() {}
};

class BikePartner : public DeliveryPartner
{
public:
    BikePartner(string n) : DeliveryPartner(n) {}
    void deliver() override
    { cout << name << " [Bike] zooms through traffic\n"; }
};

class CyclePartner : public DeliveryPartner
{
public:
    CyclePartner(string n) : DeliveryPartner(n) {}
    void deliver() override
    { cout << name << " [Cycle] pedals eco-friendly\n"; }
};

int main()
{
    cout << "--- compile-time: overloading ---\n";
    SearchService s;
    s.search("Biryani");
    s.search("Biryani", 200);
    s.search("Biryani", 200, 4.0);

    cout << "\n--- run-time: overriding ---\n";
    vector<DeliveryPartner*> fleet = { new BikePartner("Ravi"),
                                       new CyclePartner("Amit") };
    for (DeliveryPartner* p : fleet)   // ONE type, ONE loop...
    {
        p->deliver();                  // ...behaviour chosen at RUNTIME
        delete p;
    }
    return 0;
}
