
#include <iostream>
using namespace std;

class Wallet
{
private:
    double balance;                 

public:
    Wallet(double openingBalance)
    {
        if(openingBalance >= 0)
        {
            this->balance = openingBalance;
        }
        else
        {
            this->balance = 0;
        }
    }

    Wallet(string name, double openingBalance)
    {
        cout << "Welcome, " << name << endl;
        if(openingBalance >= 0)
        {
            this->balance = openingBalance;
        }
        else
        {
            this->balance = 0;
        }
    }

    void addMoney(double amount)       
    {
        if (amount <= 0) 
        { 
            cout << "   rejected: top-up must be positive\n"; 
            return; 
        }
        this->balance += amount;
        cout << "   added Rs." << amount << " | balance Rs." << this->balance << "\n";
    }

    void pay(double amount)            
    {
        if (amount <= 0 || amount > this->balance) 
        { 
            cout << "   payment rejected\n"; 
            return; 
        }
        this->balance -= amount;
        cout << "   paid Rs." << amount << " | balance Rs." << balance << "\n";
    }

    double getBalance() 
    { 
        return this->balance; 
    }  
};

int main()
{
    Wallet rahulWallet(500);

    cout << "attack 1: direct write\n";
    // rahulWallet.balance = 999999;   
    cout << "   compiler blocks the line itself\n\n";

    cout << "attack 2: negative top-up\n";  
    rahulWallet.addMoney(-500);
    cout << "\nattack 3: overspend\n";       
    rahulWallet.pay(9000);
    cout << "\nhonest use\n";                 
    rahulWallet.addMoney(200); 
    rahulWallet.pay(650);
    cout << "\nfinal balance Rs." << rahulWallet.getBalance() << "\n";
    return 0;
}
