#include <iostream>
using namespace std;

int main(){
    cout << " Enter your age :";
    int a;
    cin >> a;

    if(a > 18)
        cout << "Yo are  a adult";
    else if(a > 12)
        cout << " your are a teeenager";
    else
        cout << "you are a chiled";
return 0;}