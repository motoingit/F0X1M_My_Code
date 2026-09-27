
#include <iostream>
#include <string>
using namespace std;

class Restaurant
{
private:
    string name;
public:
    Restaurant(string n) { name = n; }
    string getName() { return name; }
};

class Customer
{
private:
    string name;
public:
    Customer(string n) { name = n; }

    // The Restaurant is passed IN for one method call only.
    // We keep NO permanent pointer to it — pure "uses-a".
    void rate(Restaurant& r, double stars)
    {
        cout << name << " rated " << r.getName() << ": " << stars << " stars\n";
    }
    void order(Restaurant& r)
    {
        cout << name << " ordered from " << r.getName() << "\n";
    }
};

int main()
{
    // Both objects created INDEPENDENTLY — neither makes the other.
    Customer   rahul("Rahul");
    Restaurant chotiwala("Chotiwala");

    // They interact... then walk away. No ownership formed.
    rahul.order(chotiwala);
    rahul.rate(chotiwala, 4.5);

    // A different customer uses the SAME restaurant — many-to-many is normal.
    Customer priya("Priya");
    priya.rate(chotiwala, 4.0);

    cout << "\nBoth Customer and Restaurant live on independently.\n";
    return 0;
}
