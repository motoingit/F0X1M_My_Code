#include <iostream>
using namespace std;

class XYZ {
    
private:
    int score[5];  // fixed size array
public:
    // Parameterized constructor
    XYZ(int val) {
        for (int i = 0; i < 5; i++) {
            score[i] = val;  // initialize all elements with val
        }
        cout << "Object created with value " << val << endl;
    }

    ~XYZ() {
        cout << "Destructor is here !" << endl;
    }

    void display() {
        for (int i = 0; i < 5; i++) {
            cout << score[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    XYZ* pointer = new XYZ(5);  // call constructor

    pointer->display();

    delete pointer;  // call destructor
    return 0;
}
