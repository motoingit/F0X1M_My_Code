// Question : Redix Sort

/*
    /// ! non -ve
    recerse_Lexograpic sort
*/

//*   O(d*(n+base)) == o(n)
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void countSort(vector <int> &arr, int redix, int pos){ //todo: Modified CountSOrt for redix
    if(arr.size() <= 1){
        return;
    }

    vector <int> freqArr(redix, 0); // 0 -> 9

    for(int i = 0; i < arr.size(); i++) {
        freqArr[(arr[i]/pos)%10]++;
    }

    vector<int> cumFreqArr(redix);
    cumFreqArr[0] = freqArr[0];
    for(int i = 1; i < redix; i++) {
        cumFreqArr[i] = cumFreqArr[i-1] + freqArr[i];
    }

    vector<int> tempArray(arr.size());
    for(int i = arr.size()-1; i >= 0; i--) {
        tempArray[--cumFreqArr[(arr[i]/pos)%10]] = arr[i];
    }

    arr = tempArray;
}

void redixSort(vector <int> &arr){
    if(arr.size() <= 1){
        return;
    }

    int maxEle = *(max_element(arr.begin(), arr.end()));

    for (int digiPlace = 1; maxEle/digiPlace; digiPlace *= 10){
        countSort(arr, 10, digiPlace); //todo: base 10
    }

}

int main(){
    int n = 0;
    cin >> n;
    vector <int> arr(n);

    //input
    for(int i = 0; i < arr.size(); i++) {
        cin >> arr[i]; 
    }

    redixSort(arr);

    //input
    for(int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " "; 
    }

return 0;}
/*
10
567 974 742 000 6523 875 927 59 4578 458

0 59 458 567 742 875 927 974 4578 6523 
*/
