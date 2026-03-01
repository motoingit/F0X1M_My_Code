/*
Enter Row And Column : 4 6
121212
212121
121212
212121
*/

#include <iostream>
using namespace std;
int main(){  
    int r,c;
    cout << "Enter Row And Column : "; cin >> r; cin >> c;

    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            if(i%2 != 0){
                if(j%2 != 0)
                    cout << 1;
                else if(j%2 == 0)
                    cout << 2;
            } else if(i%2 == 0){
                if(j%2 == 0)
                    cout << 1;
                else if(j%2 != 0)
                    cout << 2;
            }
        }
        cout << endl;
    }
return 0;}

