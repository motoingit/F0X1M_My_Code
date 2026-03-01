#include <iostream>
#include <chrono>
#include <thread>
using namespace std;

int main() {
    char spinner[] = {'\\', '|', '/', '-'};
    int n = sizeof(spinner) / sizeof(spinner[0]);

    cout << "Loading  ";
    for (int i = 0; i < 40; i++) {   // number of rotations
        cout << "\b" << spinner[i % n] << flush;  
        this_thread::sleep_for(chrono::milliseconds(200));  // speed
    }

    cout << "\bDone!" << endl;  // remove spinner and show "Done!"
    return 0;
}
