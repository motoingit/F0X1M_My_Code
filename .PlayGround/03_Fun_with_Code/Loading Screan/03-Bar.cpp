#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

int main() {
    int total = 20;
    cout << "Loading:\n[";
    for (int i = 0; i < total; i++) {
        cout << "#" << flush;
        this_thread::sleep_for(chrono::milliseconds(200));
    }
    cout << "] Done!" << endl;
    return 0;
}
