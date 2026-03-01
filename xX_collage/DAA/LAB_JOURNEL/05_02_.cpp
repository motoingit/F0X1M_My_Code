#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int key;
    cin >> key; 

    sort(arr.begin(), arr.end()); // nlogn

    int i = 0, j = n - 1;
    bool found = false;

    while(i < j) {
        int currentSum = arr[i] + arr[j];
        
        if(currentSum == key) {
            cout << arr[i] << " " << arr[j] << endl;
            found = true;
            break; // termination
        } else if(currentSum < key) {
            i++;
        } else {
            j--;
        }
    }

    if(!found) {
        cout << "No Such Elements Exist" << endl; 
    }
}

int main() {
    int t;
    if (cin >> t) {     //NOTE: i have done this so i can make sure that the input is a sucess
        while(t--) {
            solve();
        }
    }
    return 0;
}
