#include <stdio.h>

// Define a macro (comment this will disable debug related code)
#define DEBUG

int main() {


    // Using a macro to conditionally compile code

#ifdef DEBUG //(if debug == is defined)
    printf("Debug mode is present or definded or ON");
#else //(else if debug is not defined)
    cout << "Debug mode is OFF" << endl;
#endif // end of the header guard


    

            // This line will always run regardless of the debug mode
        printf("dont care if debug is on or what");






        // alternative way to use header guards
#ifndef DEBUG
        printf("alternative Debug mode is notpresent or off");

#else
        printf("alternative Debug mode is present or definded or ON");

#endif

    return 0;
}
