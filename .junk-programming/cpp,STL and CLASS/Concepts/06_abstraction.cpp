// ============================================================
//  06_abstraction.cpp   — PILLAR 2
//  RUN:  g++ 06_abstraction.cpp -o 06 && ./06
// ------------------------------------------------------------
//  CONCEPT: Abstraction = expose WHAT, hide HOW.
//    - A PURE VIRTUAL method ( = 0 ) declares a behaviour with
//      no body. Its class becomes ABSTRACT: no objects allowed.
//    - An INTERFACE CLASS has ONLY pure virtual methods (a pure
//      contract). Any child MUST implement them.
//  The app talks to "a payment method" without knowing which one.
// ============================================================
#include <iostream>
using namespace std;

// INTERFACE: pure contract, no data, all pure virtual
class IPayment
{
public:
    virtual void payNow(double amount) = 0;   // pure virtual (=0)
    virtual ~IPayment() {}                     // virtual destructor
};

class UpiPayment : public IPayment
{
public:
    void payNow(double amount) override
    { cout << "   Rs." << amount << " paid via UPI (instant)\n"; }
};

class CardPayment : public IPayment
{
public:
    void payNow(double amount) override
    { cout << "   Rs." << amount << " paid via Card (OTP verified)\n"; }
};

class CashOnDelivery : public IPayment
{
public:
    void payNow(double amount) override
    { cout << "   Rs." << amount << " to be collected in cash\n"; }
};

int main()
{
    // IPayment p;   // COMPILE ERROR: abstract class, can't instantiate

    // We hold everything as IPayment* — we don't care which kind:
    IPayment* methods[] = { new UpiPayment(), new CardPayment(), new CashOnDelivery() };

    for (IPayment* m : methods)
    {
        m->payNow(240);     // same call → different behaviour (abstraction)
        delete m;
    }
    return 0;
}
