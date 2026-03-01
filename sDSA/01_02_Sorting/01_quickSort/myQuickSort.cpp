// Question : 
#include <iostream>
#include <vector>
#include <random>

using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

int myRandom(int min, int max) {
    static std::mt19937 gen(std::random_device{}());
    std::uniform_int_distribution<int> dist(min, max);
    return dist(gen);
}

int partition(vector <int> &arr, int low, int high){
    int pivot = myRandom(low,high);
    swap(arr[pivot], arr[high]);

    int  par_i = low-1;
    for(int ptr_j = low; ptr_j < high; ptr_j++) { //^ high is piviot ele
        if(arr[ptr_j] <= arr[high]){ //!  <= for ascending and >= for decending
            par_i++;
            swap(arr[par_i], arr[ptr_j]);
        }
    }
    swap(arr[++par_i], arr[high]);

    return par_i;
}

void quickSort_st(vector <int> &arr, int low, int high){
    if( low >= high ){
        return;
    }

    int pivot = partition(arr, low, high);
    quickSort_st(arr, low, pivot-1);
    quickSort_st(arr, pivot+1, high);
}

void printArr(const vector<int>& arr) {
    for (int x : arr)
        cout << x << " ";
    cout << endl;
}


int main(){
    int n; cin >> n;
    vector<int> arr(n);

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    quickSort_st(arr,0,n-1);

    printArr(arr);

return 0;}
