// Question : 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printVecArr(vector <int> &arr){
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;
}

int main(){
    vector <int> arr = {3,5,23,322,532,1,-1};
    int max = *max_element(arr.begin(), arr.end());
    int min = *min_element(arr.begin(), arr.end());

    // printVecArr(arr);
    fill(arr.begin(), arr.end(), 0);
    // printVecArr(arr);
    
return 0;}
