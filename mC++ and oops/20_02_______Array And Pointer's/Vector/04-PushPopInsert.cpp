#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> xyz = {1, 2, 3}; // Initial vector

    int control = 1, value, pos;
    while (control) {
        cout << "\n----- MENU -----\n";
        cout << "1. Push Back\n";
        cout << "2. Pop Back\n";
        cout << "3. Insert at Position\n";
        cout << "4. Erase at Position\n";
        cout << "5. Clear Vector\n";
        cout << "6. Display Vector\n";
        cout << "0. Exit\n";
        cout << "Enter Control: ";
        cin >> control;

        switch (control) {
        case 1: // push_back
            cout << "Enter value: ";
            cin >> value;
            xyz.push_back(value);
            break;

        case 2: // pop_back
            if (!xyz.empty()) {
                cout << "Popped Value: " << xyz.back() << endl;
                xyz.pop_back();
            } else {
                cout << "Vector is empty.\n";
            }
            break;

        case 3: // insert
            cout << "Enter position and value: ";
            cin >> pos >> value;
            if (pos >= 0 && pos <= xyz.size())
                xyz.insert(xyz.begin() + pos, value);
            else
                cout << "Invalid position.\n";
            break;

        case 4: // erase at position
            cout << "Enter position to erase: ";
            cin >> pos;
            if (pos >= 0 && pos < xyz.size()) {
                cout << "Erased Value: " << xyz[pos] << endl;
                xyz.erase(xyz.begin() + pos);
            } else {
                cout << "Invalid position.\n";
            }
            break;

        case 5: // clear
            xyz.clear();
            cout << "Vector cleared.\n";
            break;

        case 6: // display
            if (xyz.empty()) {
                cout << "Vector is empty.\n";
            } else {
                cout << "Vector contents: ";
                for (int val : xyz)
                    cout << val << " ";
                cout << endl;
            }
            break;

        case 0:
            cout << "Exiting program.\n";
            return 0;

        default:
            cout << "Invalid choice.\n";
            break;
        }
    }
    return 0;
}
