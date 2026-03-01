#include <iostream>
using namespace std;

#define MODE 2   // Change this to 1, 2, or 3 to see different outputs

int main() {

#if MODE == 1
    cout << "Mode 1: Basic mode" << endl;
#elif MODE == 2
    cout << "Mode 2: Intermediate mode" << endl;
#else
    cout << "Mode 3: Advanced mode" << endl;
#endif

    cout << "This line always runs." << endl;
    return 0;
}
