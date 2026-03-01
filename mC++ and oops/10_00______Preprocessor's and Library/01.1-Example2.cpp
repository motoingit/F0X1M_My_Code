#include <iostream>
using namespace std;

// Define a macro (comment this will disable debug related code)
#define ANDROID

int main() {

#ifdef ANDROID //(if debug == is defined)
    cout << "Android code is here" << endl;
#elif IOS
    cout << "IOS Code HERE" << endl;
#else //(else if debug is not defined)
    cout << "Browser Code is Here" << endl;
#endif // end of the header guard  || Ends the conditional compilation section.


    // This line will always run regardless of the debug mode
    cout << "This line always runs." << endl;

    return 0;
}
