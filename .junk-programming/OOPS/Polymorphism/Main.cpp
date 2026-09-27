/*
====================================================================
   POLYMORPHISM — COMPLETE GUIDE (Compile-time + Runtime)
====================================================================

  Analogy for the whole topic:
  Think of the word "drive". A person can "drive" a car, "drive" a
  golf ball, or "drive" a point home in an argument. Same WORD,
  different BEHAVIOR depending on context. That's polymorphism —
  "one interface, many forms."

  Two kinds in C++:
  1. COMPILE-TIME (Static) Polymorphism
       - Decided at compile time, based on function signature
       - Achieved via: Function Overloading, Operator Overloading
  2. RUNTIME (Dynamic) Polymorphism
       - Decided at runtime, based on actual object type
       - Achieved via: Virtual Functions (Overriding)
====================================================================
*/

#include <iostream>
using namespace std;

/* ==================================================================
   PART 1: COMPILE-TIME POLYMORPHISM
   ================================================================== */

/* ---- 1a. FUNCTION OVERLOADING ----
   Same function name, different parameter list.
   Compiler picks the right one based on arguments AT COMPILE TIME.

   Analogy: A vending machine slot labeled "Insert Coin" accepts
   ₹1, ₹5, ₹10 coins — same slot, different coin, different result
   (different snack dispensed) — decided the instant you insert it.
*/
class Calculator {
public:
    int add(int a, int b) {
        cout << "[Overload: int, int]   ";
        return a + b;
    }
    double add(double a, double b) {
        cout << "[Overload: double, double]   ";
        return a + b;
    }
    int add(int a, int b, int c) {
        cout << "[Overload: int, int, int]   ";
        return a + b + c;
    }
};

/* ---- 1b. OPERATOR OVERLOADING ----
   Redefining what an existing operator (+, -, <<, etc.) does
   for a user-defined type.

   Analogy: "+" normally means "add numbers". You're teaching it
   a NEW meaning — "combine two Money objects" — same symbol,
   new context.
*/
class Money {
public:
    double amount;
    Money(double amt) : amount(amt) {}

    // Overload '+' so Money + Money makes sense
    Money operator+(const Money& other) {
        return Money(this->amount + other.amount);
    }

    // Overload '<<' so cout << Money works nicely
    friend ostream& operator<<(ostream& os, const Money& m) {
        os << "Rs." << m.amount;
        return os;
    }
};


/* ==================================================================
   PART 2: RUNTIME POLYMORPHISM
   ================================================================== */

/* ---- 2a. THE PROBLEM WITHOUT VIRTUAL ----
   If doPayment() is NOT virtual, calling it through a base
   pointer ALWAYS runs the base version, no matter what the
   actual object is. This defeats the purpose of polymorphism.

   Analogy: mailing a letter addressed to "The Manager" instead
   of a real name — it always reaches whoever holds that generic
   title in the BASE office, never the specific derived person.
*/

/* ---- 2b. THE FIX: VIRTUAL FUNCTIONS + PURE VIRTUAL (ABSTRACT CLASS) ---- */
class Payment {
protected:
    // Pure virtual: NO body here, subclasses MUST implement it.
    // This also makes Payment an ABSTRACT class (can't do `new Payment`)
    virtual void paymentLogic() = 0;

public:
    // Virtual destructor: REQUIRED whenever you delete via base pointer,
    // otherwise derived class destructors won't run -> resource leaks.
    virtual ~Payment() {
        cout << "Payment destroyed\n";
    }

    // Virtual: lets derived classes override it, but here we don't even
    // need to override doPayment itself — only paymentLogic().
    // This is the TEMPLATE METHOD PATTERN: base defines the SKELETON,
    // subclasses fill in ONE customizable step.
    virtual void doPayment(string name, double amount) {
        printf("Payment-ID: %s, with amount: %.2f\n", name.c_str(), amount);
        this->paymentLogic();   // <-- dynamic dispatch happens HERE
        printf("Payment Complete\n\n");
    }
};

class CreditPayment : public Payment {
protected:
    void paymentLogic() override {
        cout << "Doing Payment from Credit\n";
    }
};

class DebitPayment : public Payment {
protected:
    void paymentLogic() override {
        cout << "Doing Payment from Debit\n";
    }
};

class UpiPayment : public Payment {
protected:
    void paymentLogic() override {
        cout << "Doing Payment from UPI\n";
    }
};


/* ==================================================================
   PART 3: WHEN RUNTIME POLYMORPHISM FAILS (classic traps)
   ================================================================== */

/* ---- 3a. OBJECT SLICING ----
   Polymorphism ONLY works through pointers/references.
   Assigning a derived object to a base object BY VALUE "slices off"
   the derived part.

   Analogy: photocopying someone's ID card — you get the name and
   photo (base info), but not their personality (derived behavior).
*/
class Base {
public:
    virtual void show() { cout << "Base::show()\n"; }
};
class Derived : public Base {
public:
    void show() override { cout << "Derived::show()\n"; }
};

void demonstrateSlicing() {
    Derived d;
    Base b = d;        // <-- SLICING happens here (copy by value)
    b.show();           // Output: "Base::show()"  -- polymorphism LOST

    Base& refToD = d;   // reference, NOT sliced
    refToD.show();       // Output: "Derived::show()" -- polymorphism WORKS
}

/* ---- 3b. VIRTUAL CALL FROM A CONSTRUCTOR ----
   During base class construction, the derived part of the object
   doesn't exist yet, so C++ deliberately uses the BASE version of
   any virtual function called from the base constructor.

   Analogy: asking for someone's job title while they're still
   filling in the "name" field on a form — you only get the
   placeholder answer, because the rest of the form isn't done yet.
*/
class BaseCtor {
public:
    BaseCtor() {
        cout << "In BaseCtor constructor, calling virtual: ";
        greet();   // looks polymorphic, but ISN'T here
    }
    virtual void greet() { cout << "Hello from BaseCtor\n"; }
};
class DerivedCtor : public BaseCtor {
public:
    void greet() override { cout << "Hello from DerivedCtor\n"; }
};


/* ==================================================================
   MAIN: run every section
   ================================================================== */
int main() {
    cout << "===== PART 1: COMPILE-TIME POLYMORPHISM =====\n";

    Calculator calc;
    cout << calc.add(2, 3) << endl;          // picks int,int version
    cout << calc.add(2.5, 3.5) << endl;      // picks double,double version
    cout << calc.add(1, 2, 3) << endl;       // picks 3-arg version

    Money m1(100), m2(250);
    Money m3 = m1 + m2;      // operator+ overload
    cout << "Money sum: " << m3 << endl;     // operator<< overload
    cout << endl;


    cout << "===== PART 2: RUNTIME POLYMORPHISM =====\n";

    Payment* payments[3];
    payments[0] = new CreditPayment();
    payments[1] = new DebitPayment();
    payments[2] = new UpiPayment();

    for (int i = 0; i < 3; i++) {
        payments[i]->doPayment("txn-" + to_string(i), 1000 * (i + 1));
    }
    for (int i = 0; i < 3; i++) {
        delete payments[i];   // virtual destructor ensures correct cleanup
    }
    cout << endl;


    cout << "===== PART 3a: OBJECT SLICING DEMO =====\n";
    demonstrateSlicing();
    cout << endl;

    cout << "===== PART 3b: VIRTUAL CALL FROM CONSTRUCTOR DEMO =====\n";
    DerivedCtor dc;   // watch: constructor prints "Hello from BaseCtor", NOT Derived's

    return 0;
}
