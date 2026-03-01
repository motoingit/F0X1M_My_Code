// Binary Search helper
function binarySearch(arr, left, right, x) {
    while (left <= right) {
        const mid = Math.floor(left + (right - left) / 2);

        if (arr[mid] === x) return mid;
        if (arr[mid] < x) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

// Exponential Search
function exponentialSearch(arr, x) {
    const n = arr.length;

    if (n === 0) return -1;
    if (arr[0] === x) return 0;

    let i = 1;
    while (i < n && arr[i] <= x) {
        i *= 2;
    }

    //todo : the use of floor is js weakness fade !
    return binarySearch(arr, Math.floor(i / 2), Math.min(i, n - 1), x);
}


arr = [2, 3, 5, 7, 9, 12, 15, 18, 20];
x = 15;

result = exponentialSearch(arr, x);

if (result != -1)
    console.log(`Element found at index ${result}`)
else
    console.log(`Element not found`)
