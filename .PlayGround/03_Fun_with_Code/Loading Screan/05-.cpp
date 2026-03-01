#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

int main() {
    int length = 20;
    for (int i = 0; i < 40; i++) {
        cout << "\r[";
        for (int j = 0; j < length; j++) {
            if (j == i % length) cout << "O";
            else cout << "-";
        }
        cout << "]" << flush;
        this_thread::sleep_for(chrono::milliseconds(200));
    }
    cout << "\nDone!" << endl;
    return 0;
}
