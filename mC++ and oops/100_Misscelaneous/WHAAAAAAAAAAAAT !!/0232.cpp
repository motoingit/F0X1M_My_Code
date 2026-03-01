#include <iostream>
using namespace std;


/*
int x = 10;
int &y = x;
*/

int & swap( int &a, int &b ){
    int temp = a;
    a = b;
    b = temp;
return a;
}

int main() {
    int x = 10, y = 20;
    swap(x,y) = 200;   //howwwwwwwwwwwwwwwwwwwww

    cout << x << "  " << y ;
return 0;}