#include <iostream>
using namespace std;

int main() {
    int marks;
    cout << "Enter marks: ";
    cin >> marks;

    if (marks >= 33) {
        cout << "Status: Pass" << endl;

        if (marks >= 75) {
            cout << "Division: First (Distinction)" << endl;
        } 
        else if (marks >= 60) {
            cout << "Division: First" << endl;
        }
        else if (marks >= 45) {
            cout << "Division: Second" << endl;
        }
        else {
            cout << "Division: Third" << endl;
        }

    } else {
        cout << "Status: Fail" << endl;
    }

    return 0;
}
