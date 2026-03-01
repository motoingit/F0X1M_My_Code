#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

int main() {
    cout << "Loading";
    for (int i = 0; i < 10; i++) {
        cout << "." << flush;
        this_thread::sleep_for(chrono::milliseconds(300));
    }
    cout << " Done!" << endl;
    return 0;
}
