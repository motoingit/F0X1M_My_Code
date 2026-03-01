#include <iostream>
#include <string>

using namespace std;

int main() {
    string s1 = "Hello";
    string s2 = "World";
    string s3;

    // 1. s.length() - Returns the length of the string
    cout << "1. Length of s1: " << s1.length() << endl; // Output: 5

    // 2. s1.swap(s2) - Swaps the contents of two strings
    cout << "2. Before swap: s1 = " << s1 << ", s2 = " << s2 << endl;
    s1.swap(s2);
    cout << "   After swap: s1 = " << s1 << ", s2 = " << s2 << endl; // Output: s1 = World, s2 = Hello

    // 3. s1.empty() - Checks if the string is empty
    cout << "3. Is s1 empty? " << (s1.empty() ? "Yes" : "No") << endl; // Output: No (s1 is now "World")
    cout << "   Is s3 empty? " << (s3.empty() ? "Yes" : "No") << endl; // Output: Yes (s3 is empty)

    // 4. s2.assign(source_string) - Assigns new content to the string
    cout << "4. Before assign: s2 = " << s2 << endl; // s2 is "Hello"
    s2.assign("C++ Programming");
    cout << "   After assign: s2 = " << s2 << endl; // Output: C++ Programming

    // 5. s1.at(index) - Returns the character at a specified position (with bounds checking)
    cout << "5. Character at index 0 in s1: " << s1.at(0) << endl; // s1 is "World", Output: W
    try {
        cout << "   Character at index 10 in s1: " << s1.at(10) << endl; // This will throw an out_of_range exception
    } catch (const out_of_range& e) {
        cerr << "   Error: " << e.what() << endl;
    }

    // 6. s1.find(substring) - Searches for the first occurrence of a substring
    string search_str = "or";
    size_t found_pos = s1.find(search_str); // s1 is "World"
    if (found_pos != string::npos) {
        cout << "6. '" << search_str << "' found in s1 at position: " << found_pos << endl; // Output: 1
    } else {
        cout << "6. '" << search_str << "' not found in s1." << endl;
    }

    search_str = "xyz";
    found_pos = s1.find(search_str);
    if (found_pos != string::npos) {
        cout << "   '" << search_str << "' found in s1 at position: " << found_pos << endl;
    } else {
        cout << "   '" << search_str << "' not found in s1." << endl; // Output: not found
    }

    return 0;
}
