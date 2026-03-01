#include <iostream>
using namespace std;

enum Day { MON, TUE, WED, THU, FRI, SAT, SUN };
// Enum values are automatically assigned starting from 0

enum Month { JAN = 100, FEB, MAR, APR, MAY = 200, JUN, JUL, AUG, SEP, OCT, NOV, DEC };  // but the next value have relationship with the previous one
// Enum values can be explicitly set, e.g., JAN = 100, FEB = 101, etc.

int main(){

    Day today = MON;

    switch(today){
        case MON:
            cout << "Monday";
            break;  
        case TUE:
            cout << "Tuesday";
            break;
        case WED:
            cout << "Wednesday";
            break;
        case THU:
            cout << "Thursday";
            break;
        case FRI:
            cout << "Friday";
            break;
        case SAT:
            cout << "Saturday";
            break;
        case SUN:
            cout << "Sunday";
            break;
        default:
            cout << "Invalid day";
            break;
    }

    cout << endl;
    
return 0;}

/*

// An enum, short for enumeration
• Defines a set of named integral constants which Improves readability by avoiding magic numbers.
    - 0 for MON, 1 for TUE, etc.



*/