#include <iostream>
#include <vector>
using namespace std;

int countInv(vector<int>& arr, int size){
    int invCount = 0;

    for(int i = 0; i < size-1; i++) {
        for(int j = i+1; j < size; j++) {
            if(arr[i] > arr[j]){
                invCount++;
            }
        }
    }
    return invCount;
}

int main() {
    vector<int> arr = {4,8,1,3,5,8,1};

    cout << countInv(arr,arr.size());
return 0;}
