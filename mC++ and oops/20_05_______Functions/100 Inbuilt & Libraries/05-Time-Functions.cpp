#include <iostream>
#include <ctime>
using namespace std;

int main() {
    time_t now = time(0); // current time
    char* dt = ctime(&now); // convert to string
    cout << "Current time: " << dt;
}
