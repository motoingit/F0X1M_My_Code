#include <iostream>
using namespace std;

int main() {
    string username;
    string password;
    bool adminOverride = false;

    cout << "Enter username: ";
    cin >> username;

    cout << "Enter password: ";
    cin >> password;

    // Simulate login system
    if ((username == "a" && password == "a") || adminOverride == true) {
        cout << "Access Granted!" << endl;
    } else {
        cout << "Access Denied!" << endl;
    }

    return 0;
}
