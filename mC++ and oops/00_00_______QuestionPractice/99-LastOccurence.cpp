#include <iostream>
#include <vector>
using namespace std;

int main() {
    //                                   ---------- METHOD 1 ----------
                        cout << "\n=== METHOD 1: Search by Iterating Forward ===\n";
    vector<char> sentence = {'c','a','n','c','e','r'};
    
    cout << "Enter a character to search: ";
    char x;
    cin >> x;

    int idx = -1; // -1 means not found
    for (int i = 0; i < sentence.size(); i++) {
        if (x == sentence[i]) {
            idx = i; // Keep updating to find last match
        }
    }

    if (idx == -1) {
        cout << "Character not found.\n";
    } else {
        cout << "Last match found at index " << idx << " (0-based index).\n";
    }


    //                           ---------- METHOD 2 ----------
                    cout << "\n=== METHOD 2: Search by Iterating Backward ===\n";
    vector<char> sen = {'c','a','n','c','e','r'};
    
    cout << "Enter a character to search: ";
    char y;
    cin >> y;

    int idx2 = -1;
    for (int i = sen.size() - 1; i >= 0; i--) {
        if (y == sen[i]) {
            idx2 = i;
            break; // First match from the end = last occurrence
        }
    }

    if (idx2 == -1) {
        cout << "Character not found.\n";
    } else {
        cout << "Last match found at index " << idx2 << " (0-based index).\n";
    }

    return 0;
}
