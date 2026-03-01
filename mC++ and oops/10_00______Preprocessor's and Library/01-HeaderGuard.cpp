#include <iostream>
using namespace std;

// Define a macro (comment this will disable debug related code)
#define DEBUG

int main() {


    // Using a macro to conditionally compile code

#ifdef DEBUG //(if debug == is defined)
    cout << "Debug mode is ON" << endl;
#else //(else if debug is not defined)
    cout << "Debug mode is OFF" << endl;
#endif // end of the header guard


    

            // This line will always run regardless of the debug mode
                cout << "This line always runs." << endl;





        // alternative way to use header guards
#ifndef DEBUG
    cout << "Debug mode is OFF (alternative way)" << endl;
#else
    cout << "Debug mode is ON (alternative way)" << endl;
#endif

    return 0;
}
