/* Question : Floyd-Warshall
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//! INFINITY
const int INF = 1000;

int main(){
   int nEle;
   cin >> nEle;
   vector<vector<int>> matrix(nEle, vector<int>(nEle));

   //Input
   for (int i = 0; i < nEle; i++) {
      for (int j = 0; j < nEle; j++) {
         int value;
         cin >> value;
         matrix[i][j] = value;
      }
   }

   // 2. The Core Floyd-Warshall Logic
   for (int via = 0; via < nEle; via++) {
      for (int i = 0; i < nEle; i++) {
         for (int j = 0; j < nEle; j++) {
               // Only update if a path exists through 'via'
               if (matrix[i][via] != INF && matrix[via][j] != INF) {
                  matrix[i][j] = min(matrix[i][j], matrix[i][via] + matrix[via][j]);
               }
         }
      }
   }

   //putput
   cout << "OutPut Matrix: " << endl;
   for (int i = 0; i < nEle; i++) {
      for (int j = 0; j < nEle; j++) {
         cout << matrix[i][j] << " ";
      }
      cout << endl;
   }


return 0;}

/*
FormatInput:

4
0 3 1000 7
8 0 2 1000
5 1000 0 1
2 1000 1000 0

Ouput:

*/
