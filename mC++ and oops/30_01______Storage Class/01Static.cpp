#include <iostream>
using namespace std;

int add(int n) {
    static int  m = 1;   //declare ones           exist for ever
    m++;
    
    return m + n;
}

int main() {

    for (int i = 1; i < 10; i++)
    {
        cout << add(10) << " ";
    }
    
return 0;}