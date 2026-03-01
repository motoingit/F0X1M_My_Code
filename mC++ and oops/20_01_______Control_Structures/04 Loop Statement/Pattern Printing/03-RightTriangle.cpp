/*
Enter Row : 3
1
12
123
*/

#include <iostream>
using namespace std;
int main(){ 
    int n;
    cout << "Enter Row : "; cin >> n;

    for(int i = 1; i <= n; i++){
        for(int s = 1; s <= i; s++){
            cout << s;
        }
        cout << endl;
    }
return 0;}

