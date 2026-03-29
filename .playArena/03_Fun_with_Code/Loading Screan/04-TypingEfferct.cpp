#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

int main() {
    string text = "Loading Please Wait...";
    for (char c : text) {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(150));
    }
    cout << "\nDone!" << endl;
    return 0;
}
