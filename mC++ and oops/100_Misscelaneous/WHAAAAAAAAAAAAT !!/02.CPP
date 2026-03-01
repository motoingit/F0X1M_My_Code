#include <iostream>
using namespace std;

int main(){
     int n,arr[1][1] = {0};
     cout << "enter the size of matrix : " ;
     cin >> n;
     arr[n][n]; // is it like arr[a][b] giving value (here no bound check)
     for(int i = 0; i < n; i++){
          for(int j = 0; j < n; j++)
               cout << arr[i][j] << " ";
     cout << endl;
     }
return 0;}