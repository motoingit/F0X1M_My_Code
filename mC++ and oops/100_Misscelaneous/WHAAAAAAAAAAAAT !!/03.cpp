// BACK CODI

#include <iostream>
#define MAX 4
using namespace std;
int main(){
  int arr[MAX][MAX] = {0}; arr[3][3] = 4;

  for(int i = 0, j = 0;true;NULL){ // is it the same as n^2 TC
    
    if(arr[i][j] == 4){
      cout << i << j << " Found" << std::endl;
      break;
    }

    j++;

    if(j == MAX)
      j = 0, i++;
  }
 

}