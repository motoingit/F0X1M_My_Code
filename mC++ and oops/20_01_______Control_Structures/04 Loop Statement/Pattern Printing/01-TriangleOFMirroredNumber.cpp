/*
Enter Row : 7
      1
     121
    12321
   1234321
  123454321
 12345654321
1234567654321
*/

#include <iostream>
using namespace std;
int main(){
    int n;
    cout << "Enter Row : "; cin >> n;

    for(int i = 1; i <= n; i++){
        for(int s = 1; s <= n - i; s++){
            cout << " " ;
        }

        for(int j = 1; j <= i; j++){
            cout << j;
        }
        for(int j = i - 1; j >= 1; j--){
            cout << j;
        }
        cout << endl;
    }
return 0;}



/* MY WORST DAY 

#include <iostream>
using namespace std;
int main(){
    int n,m;
    cout << "Enter Row : "; cin >> n;

    for(int i = 1; i <= n; i++){
        for(int s = 1; s <= n - i; s++){
            cout << " " ;
        }

        m = ((i*2 - 1)/2) + 1;

        for(int j = 1; j <= m; j++){
            cout << j <<" ";
        }
        for(int j = m - 1; j >= 1; j--){
            cout << j <<" ";
        }
        cout << endl;
    }
return 0;}

*/