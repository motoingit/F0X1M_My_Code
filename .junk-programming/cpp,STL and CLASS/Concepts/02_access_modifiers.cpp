// ============================================================
//  02_access_modifiers.cpp
//  RUN:  g++ 02_access_modifiers.cpp -o 02 && ./02
// ------------------------------------------------------------
//  CONCEPT: Access modifiers decide WHO can touch a member.
//    private   : only inside the class
//    protected : inside the class + child classes  (see file 07)
//    public    : everyone
// ============================================================
#include <iostream>
#include <string>
using namespace std;

class Customer
{
private:
    // DATA is private: nobody outside can read/write it directly
    double walletBalance;

protected:
    // visible to this class AND its children (used later, file 07)
    string name;

public:
    // PUBLIC behaviour = the only doors into the object
    void setUp(string n, double balance)
    {
        name = n;
        walletBalance = (balance >= 0) ? balance : 0;   // guard
    }

    void addMoney(double amount)
    {
        if (amount <= 0) { cout << "Invalid top-up\n"; return; }
        walletBalance += amount;
        cout << name << " added Rs." << amount
             << " | balance: Rs." << walletBalance << "\n";
    }

    double getBalance()          // controlled read (a "getter")
    {
        return walletBalance;
    }
};

int main()
{
    Customer rahul;
    rahul.setUp("Rahul", 500);

    // rahul.walletBalance = 999999;  // COMPILE ERROR: private!
    // ^ Uncomment in class — the compiler itself blocks the line.

    rahul.addMoney(200);
    cout << "Read via public getter: Rs." << rahul.getBalance() << "\n";
    return 0;
}
