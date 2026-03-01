
/*

    string sen = "HELLO WORLD";

    //for each loop
    for(char ch : sen)
        cout << ch << " ";

    //for loop
    for(int i = 0; i < sen.length(); i++){
        char ch = sen[i];
        cout << ch << " ";
    }

*/



#include<iostream>
using namespace std;
int main() {
    string x = "MOHITsingh";

    //you can take char i.
    for (auto i : x) {
        cout << i << " ";
    }
    return 0;
}
