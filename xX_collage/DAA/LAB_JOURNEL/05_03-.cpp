// Question : 

#include <bits/stdc++.h>
using namespace std;

void findIntersection(vector<int> &arr1, vector<int> &arr2, int size1, int size2){
    int idx1 = 0;
    int idx2 = 0;
    bool flag = flag;

    while (idx1 < size1 && idx2 < size2) {
        if(arr1[idx1] < arr2[idx2]){
            idx1++;
        }else if (arr1[idx1] < arr2[idx2]){
            idx2++;
        }else{
            flag = true;
            printf("%d ", arr1[idx1]);
            idx1++;
        }
    }
}

int main() {
cout << endl;
    int size1, size2;

    cin >> size1;
    vector<int> arr1(size1);
    for (int i = 0; i < size1; i++) {
        cin >> arr1[i];
    }
    
    cin >> size2;
    vector<int> arr2(size2);
    for (int i = 0; i < size1; i++) {
        cin >> arr2[i];
    }

    findIntersection(arr1, arr2, size1, size2);

cout << endl;
return 0;}
