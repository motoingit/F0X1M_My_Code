/*
Enter r and c : 5 6

******
*    *
*    *
*    *
******
*/
//Note : row no should be even, r >= 3
#include <iostream>
using namespace std;
int main(){  
    int r, c;
    cout << "Enter r and c : "; cin >> r >> c;

    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            if(i == 1 || i == r || j == 1 || j == c){
                cout << "*";
            } else{
                cout << " ";
            }
        }
        cout << endl;
    }
return 0;}

