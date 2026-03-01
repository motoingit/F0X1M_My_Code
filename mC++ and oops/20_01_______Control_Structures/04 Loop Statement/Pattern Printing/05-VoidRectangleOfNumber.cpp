/*
Enter Row And Column : 4 7
1234567
1     7
1     7
1234567
*/

#include <iostream>
using namespace std;
int main(){  
    int r,c;
    cout << "Enter Row And Column : "; cin >> r; cin >> c;

    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            if( i == 1 || i == r || j == 1 || j == c){
                cout << j;
            }
            else{
                cout << " ";
            }
        }
        cout << endl;
    }
return 0;}

