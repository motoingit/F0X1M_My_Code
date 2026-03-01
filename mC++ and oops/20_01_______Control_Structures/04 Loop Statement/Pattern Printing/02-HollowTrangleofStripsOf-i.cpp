/*
Enter Row : 7
      1
     2 2
    3   3
   4     4
  5       5
 6         6
7777777777777
*/

#include <iostream>
using namespace std;
int main(){   
    int n;
    cout << "Enter Row : "; cin >> n;

    for(int i = 1; i <= n; i++){
        for(int s = n - i; s >= 1; s--){
            cout << " ";
        }
        for(int j = 1; j <= i*2 - 1; j++){
            if(j == 1 || j == i*2 - 1 || i == n)
                cout << i;
            else
                cout << " ";
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