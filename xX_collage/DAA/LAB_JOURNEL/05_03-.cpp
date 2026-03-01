#include <iostream>
#include <vector>

using namespace std;

int main(){
    int m;
    cin >> m;
    vector<int> arr(m);
    for(int i = 0; i < m; i++) 
        cin >> arr[i];
    
    int n;
    cin >> n;
    vector<int> brr(n);
    for(int i = 0; i < n; i++) 
        cin >> brr[i]; 
    
    // with twopinter m+n
    int i = 0; 
    int j = 0; 
    bool foundAny = false;
    
    while(i < m && j < n) {
        if (arr[i] < brr[j]) {
            i++;

        }else if (brr[j] < arr[i]) {
            j++;

        }else {

            cout << arr[i] << " ";
            foundAny = true; // found common element
            i++;
            j++;
        }
    }
    
    if(!foundAny) cout << "No Common Elements"; // Optional handling
    cout << endl;

return 0;}
