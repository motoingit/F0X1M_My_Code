typedef struct {
    int index;
    int comparisons;
} Result;

Result binarySearch(int arr[], int size, int key) {
    Result res;

    int low = 0;
    int high = size - 1;
    int com = 0;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        com++;
        if (arr[mid] == key){
            res.index = mid;
            break;
        }
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    res.comparisons = com;
    return res;  // element not found
}
