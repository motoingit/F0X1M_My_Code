// Demonstration: Vector Input and Output
#include <iostream>
#include <vector>
using namespace std;

int main() {





    // ---------------- Situation 1 ----------------
    cout << "\n--- Situation 1 ---\n";
    cout << "Enter 10 elements: ";

    vector<int> xyz(10); // Pre-sized vector

    // Input
    for (int i = 0; i < 10; i++) {
        cin >> xyz[i];
    }

    // Output
    cout << "Entered elements: ";
    for (int i = 0; i < 10; i++) {
        cout << xyz[i] << " ";
    }
    cout << endl;







    // ---------------- Situation 2 ----------------
    cout << "\n--- Situation 2 ---\n";
    cout << "Enter 10 elements: ";

    vector<int> x; // Empty vector

    // Input using push_back()
    for (int i = 0; i < 10; i++) {
        int value;
        cin >> value;
        x.push_back(value);
    }

    // Output
    cout << "Entered elements: ";
    for (int i = 0; i < x.size(); i++) {
        cout << x[i] << " ";
    }
    cout << endl;


    // situation 3
    for(int ele : x){
        cout << ele << " ";
    }
    cout << endl ;

    // situation 4
    int idx = 0;
    while(idx < x.size()){
        cout << x[idx++] << " " ;
    }

    return 0;
}
