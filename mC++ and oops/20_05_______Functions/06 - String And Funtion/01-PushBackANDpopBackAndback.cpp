#include <iostream>
#include <string>
using namespace std;
int main(){
    //at first
    string  x = "Good.";
    cout << x << endl;

    //after push back x
    x.push_back('X');
    cout << x << endl;

    //before poping getting the last char
    char popped = x.back();
    
    //after popback
    x.pop_back();
    cout << x << endl;

return 0;}