#include <iostream>
#include <vector>
#include <random>

using namespace std;

int comparisons = 0;
int swapsCount = 0;

void swapCount(int &a, int &b) {
    swapsCount++;
    int temp = a;
    a = b;
    b = temp;
}

// genrate Number
int myRandom(int min, int max) {
    static mt19937 gen(random_device{}());
    uniform_int_distribution<int> dist(min, max);
    return dist(gen);
}

int partition(vector<int> &arr, int low, int high) {
    int pivotIdx = myRandom(low, high);
    swapCount(arr[pivotIdx], arr[high]); 

    int i = low - 1;

    for (int j = low; j < high; j++) {
        comparisons++;             
        if (arr[j] <= arr[high]) {
            i++;
            swapCount(arr[i], arr[j]);
        }
    }

    swapCount(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int> &arr, int low, int high) {
    if (low >= high) return;

    int pivot = partition(arr, low, high);
    quickSort(arr, low, pivot - 1);
    quickSort(arr, pivot + 1, high);
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

        comparisons = 0;
        swapsCount = 0;

        quickSort(arr, 0, n - 1);

        for (int x : arr)
            cout << x << " ";
        cout << endl;

        cout << "comparisons = " << comparisons << endl;
        cout << "swaps = " << swapsCount << endl;
    }

    return 0;
}
