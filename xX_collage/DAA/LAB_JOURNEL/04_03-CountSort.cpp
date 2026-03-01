
//Given an unsorted array, find the Kth smallest (or largest) element in O(n) worst-case time.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

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

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        int k;
        cin >> k;

        if( k <= 0 || k > n){
            cout << "not present\n";
            return -1;
        }

        countSort(arr);
        cout << arr[k-1] << "\n";
    }

    return 0;
}
