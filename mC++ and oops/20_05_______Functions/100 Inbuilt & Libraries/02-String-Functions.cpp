#include <iostream>
#include <string> 
using namespace std;

int main() {
    string s = "Hello World";
    
    cout << "Length: " << s.length() << endl;          // length of string
    cout << "Substring: " << s.substr(0, 5) << endl;   // "Hello"
    cout << "Find: " << s.find("World") << endl;       // position of "World"
    cout << "Replace: " << s.replace(6, 5, "C++") << endl; // replace word
    s.append(" Rocks!");                               // add text
    cout << "Append: " << s << endl;
}
