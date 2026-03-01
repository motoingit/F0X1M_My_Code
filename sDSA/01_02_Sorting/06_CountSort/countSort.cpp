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
void countSort(vector <int> &arr){
    if(arr.size() <= 1){
        return ;
    }

    int maxVal = *max_element(arr.begin(), arr.end());
    int minVal = *min_element(arr.begin(), arr.end());

    int tempIdxFactor = -minVal; //this will +ve or -ve
    int nFreqArr = maxVal - minVal + 1;;
    vector <int> freqArr(nFreqArr, 0);

    for(int i = 0; i < arr.size(); i++) { // puting zero in freq
        freqArr[arr[i]+tempIdxFactor]++;
    }

    // int cumFreqArr[nFreqArr]; //!This is not standard C++ (only GCC allows it).
    vector<int> cumFreqArr(nFreqArr);
    cumFreqArr[0] = freqArr[0];
    for(int i = 1; i < nFreqArr; i++) {
        cumFreqArr[i] = cumFreqArr[i-1] + freqArr[i];
    }


    vector<int> tempArray(arr.size());
    for(int i = arr.size()-1; i >= 0; i--) {
        int idxC = arr[i] + tempIdxFactor;
        int idxA = --cumFreqArr[idxC];
        tempArray[idxA] = idxC - tempIdxFactor;
    }

    arr = tempArray;
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
