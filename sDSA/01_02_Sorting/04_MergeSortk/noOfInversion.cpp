#include <iostream>
#include <vector>
using namespace std;

int merge(vector<int>& arr, int st, int mid, int end) {
    int nL = mid - st + 1;
    int nR = end - (mid+1) + 1;

    vector<int> left(nL), right(nR);

    // Copy data
    int i = 0, j = 0, x = st;
    while (i < nL){
        left[i++] = arr[x++];
    }
    while (j < nR){ //j and x are already at position
        right[j++] = arr[x++];
    }

    i = 0, j = 0, x = st;
    int nInv = 0; //todo: to count inv
    
    // Merge
    while (i < nL && j < nR) {
        if (left[i] <= right[j]){
            arr[x++] = left[i++];
        }else{
            //? nInv += (mid-i+1); wrong
            nInv += (nL-i); //todo: NOt clear here
            arr[x++] = right[j++];
        }
    }

    // Copy remaining
    while (i < nL)
        arr[x++] = left[i++];

    while (j < nR)
        arr[x++] = right[j++];

    return nInv;
}

int mergeSort(vector<int>& arr, int st, int end) {
    if (st == end) // st >= end     all good
        return 0;

    int mid = st + (end - st) / 2;

    int leftInvCount = mergeSort(arr, st, mid);
    int RightInvCount = mergeSort(arr, mid + 1, end);
    int InvCount = merge(arr, st, mid, end); //! what is this

    return leftInvCount + RightInvCount + InvCount;
}

void printArr(const vector<int>& arr) {
    for (int x : arr)
        cout << x << " ";
    cout << endl;
}

int main() {
    vector<int> arr = {1,2,0 , 0, 3,6,4};

    printArr(arr);
    int nInv = mergeSort(arr, 0, arr.size() - 1);
    printArr(arr);

    cout << nInv;
    return 0;
}
