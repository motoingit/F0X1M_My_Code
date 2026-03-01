#include <iostream>
using namespace std;

// ---------------------------
// 1. #define → Create a macro
// ---------------------------
#define MODE 2
#define FEATURE_ENABLED

int main() {



    

    // ---------------------------------
    // 2. #ifdef → If macro is defined
    // ---------------------------------
#ifdef FEATURE_ENABLED
    cout << "Feature is ENABLED" << endl;
#endif





    // ---------------------------------
    // 3. #ifndef → If macro is NOT defined
    // ---------------------------------
#ifndef DEBUG
    cout << "Debug mode is NOT enabled" << endl;
#endif





    // -------------------------------------------------
    // 4. #if / #elif / #else → Conditional compilation
    // -------------------------------------------------
#if MODE == 1
    cout << "Mode 1 selected" << endl;

#elif MODE == 2
    cout << "Mode 2 selected" << endl;

#else
    cout << "Other mode selected" << endl;
#endif 








    // ---------------------------
    // Always executes at runtime
    // ---------------------------
    cout << "Program finished." << endl;

    return 0;
}
