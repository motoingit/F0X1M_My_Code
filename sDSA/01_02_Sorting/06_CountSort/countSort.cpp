// Question : Counting Sort 

/*
    /// Counting Sort
    /// - Non-comparison based sorting algorithm
    /// - Time Complexity: O(n + range)
    /// - Space Complexity: O(range)
    ///- Efficient when range of values is small
    /// - Can handle negative numbers using index shifting
    /// - Stable when implemented using cumulative frequency & backward traversal
    ///todo: Only for the small deviation values in array
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

///? no concept of -ve element
void countSortBasic(){
    //todo: Hold
    // int maxIdx = -1, minIdx = -1;
    // for(int i = 0; i < n; i++) {
    //     if(maxIdx == -1 || arr[maxIdx] < arr[i]){
    //         maxIdx = i;
    //     }
        
    //     if(minIdx == -1 || arr[minIdx] > arr[i]){
    //         minIdx = i;
    //     }
    // }
}

///? stability yes we mimic that already !
#include <vector>
#include <algorithm>

using namespace std;

void countSort(vector<int>& arr) {
    if (arr.size() <= 1) return;

    // Find range of values
    int minValue = *min_element(arr.begin(), arr.end());
    int maxValue = *max_element(arr.begin(), arr.end());

    int range = maxValue - minValue + 1;

    // Frequency array
    vector<int> frequency(range, 0);

    //Cumulative Freq
    for (int value : arr) {
        frequency[value - minValue]++;
    }

    // Convert frequency to prefix sum (Cumulative Sum)
    for (int i = 1; i < range; i++) {
        frequency[i] += frequency[i - 1];
    }

    // Output array
    vector<int> sorted(arr.size());

    // Traverse from end to maintain stability
    for (int i = arr.size() - 1; i >= 0; i--) {
        int index = arr[i] - minValue;
        int position = --frequency[index];
        sorted[position] = arr[i];
    }

    // Copy back
    arr = sorted;
}

int main(){ 
    int n;
    cin >> n;
    vector <int> arr(n);
    
    for(int i = 0; i < arr.size(); i++) {// input
        cin >> arr[i];
    }

    countSort(arr);

    for(int i = 0; i < arr.size(); i++) {// input
        cout << arr[i] << " ";
    }
    cout << endl;

return 0;}
