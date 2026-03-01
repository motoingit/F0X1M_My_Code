#include <iostream>
#include <string>
using namespace std;
int main() {

    string s1 = "Apple", s2 = "Banana", s3 = "Orange", s4 = "Grape";
    cout << "Swap examples:" << endl;
    cout << "Before swap: s1 = " << s1 << ", s2 = " << s2 << endl;

    s1.swap(s2);
    cout << "After swap: s1 = " << s1 << ", s2 = " << s2 << endl;
    cout << "Before swap: s3 = " << s3 << ", s4 = " << s4 << endl;
    
    swap(s3, s4);
    cout << "After swap: s3 = " << s3 << ", s4 = " << s4 << endl;
    string s5 = "First", s6 = "Second";
    string temp = s5; s5 = s6; s6 = temp;
    cout << "Manual swap: s5 = " << s5 << ", s6 = " << s6 << endl;
    
    return 0;
}
