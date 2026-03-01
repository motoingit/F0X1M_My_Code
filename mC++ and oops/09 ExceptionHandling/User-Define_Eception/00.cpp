#include <iostream>
#include <exception>
using namespace std;

// User-defined exception
class AgeExcept : public exception {
public:
    const char* what() const noexcept override {
        return "Age is below 18. Not eligible to vote.";
    }
};

int main() {
    int ctrl, age;

    while (true) {
        cout << "\n1: Check age\n0: Exit\nEnter CMD: ";
        cin >> ctrl;

        switch (ctrl) {

            case 1:
                cout << "Enter Age: ";
                cin >> age;

                try {
                    if (age < 18)
                        throw AgeExcept();
                    cout << "You are eligible to vote!" << endl;
                }
                catch (const AgeExcept& e) {
                    cout << e.what() << endl;
                }
                break;

            case 0:
                return 0;

            default:
                cout << "Invalid command!" << endl;
        }
    }
}
