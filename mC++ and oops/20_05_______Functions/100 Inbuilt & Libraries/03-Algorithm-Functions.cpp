#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    vector<int> v = {5, 2, 8, 1, 3};
    
    sort(v.begin(), v.end()); // ascending sort
    cout << "Sorted: ";
    for(int x : v) cout << x << " ";
    cout << endl;
    
    reverse(v.begin(), v.end()); // reverse
    cout << "Reversed: ";
    for(int x : v) cout << x << " ";
    cout << endl;

    if(binary_search(v.begin(), v.end(), 3))  // search
        cout << "Found 3" << endl;

    cout << "Max element: " << *max_element(v.begin(), v.end()) << endl;
    cout << "Min element: " << *min_element(v.begin(), v.end()) << endl;
}
