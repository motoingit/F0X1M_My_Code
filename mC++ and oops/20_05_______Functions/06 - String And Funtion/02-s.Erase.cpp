#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    string s = "banana";
    char toRemove = 'a';

    // Remove all 'a' characters

    //or you can right  ##auto it = remove(s.begin(), s.end(), toRemove);
    s.erase(remove(s.begin(), s.end(), toRemove), s.end());

    cout << s << endl; // Output: bnn

    return 0;
}