#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& arr, int st, int mid, int end, bool &dupFlag) {
    int nL = mid - st + 1;
    int nR = end - (mid+1) + 1;

    vector<int> left(nL), right(nR);

    int i = 0, j = 0, x = st;
    while (i < nL){
        left[i++] = arr[x++];
    }
    while (j < nR){
        right[j++] = arr[x++];
    }

    i = 0, j = 0, x = st;
    
    // Merge
    while (i < nL && j < nR) {
        if (left[i] <= right[j]){
            if(left[i] == right[j])
                dupFlag = true; //todo: this is the tweak !
            arr[x++] = left[i++];
        }else{
            arr[x++] = right[j++];
        }
    }

    // Copy remaining
    while (i < nL)
        arr[x++] = left[i++];

    while (j < nR)
        arr[x++] = right[j++];
}

void mergeSort(vector<int>& arr, int st, int end, bool &dupFlag) {
    if(arr.size() <= 1 || st == end){
        return;
    }

    int mid = st + (end - st) / 2;

    mergeSort(arr, st, mid, dupFlag);
    mergeSort(arr, mid + 1, end, dupFlag);
    merge(arr, st, mid, end, dupFlag);
}

int main() {
    int n; cin >> n;
    vector<int> arr(n);

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    bool flag = false;

    mergeSort(arr, 0, arr.size() - 1, flag);

    cout << flag;
    return 0;
}
