// Question : Given an unsorted array of integers, design and implement an algorithm to determine whether two distinct elements exist in the array such that their sum is equal to a given key value.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> arr(n);

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    int i = 0, j = n-1;
    int res, key;
    int flag = false;
    cin >> key;

    while(i < j){
        res = arr[i] + arr[j];
        if(key == res){
            cout << arr[i] << " " << arr[j] << endl;
            flag = true;
            i++;
        }else if(key < res){
            j--;
        }else{
            i++;
        }
    }
    if(flag == false){
        cout << "no pair Found !" << endl;
    }

return 0;}
