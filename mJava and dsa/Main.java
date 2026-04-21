import java.util.Scanner;

public class Main {
    public static void merge(int arr[], int st, int mid, int end) {
        int nL = mid - st + 1, nR = end - mid;
        int[] arrL = new int[nL];
        int[] arrR = new int[nR];

        // ✅ copy separately with 0-based indexing
        for (int i = 0; i < nL; i++) arrL[i] = arr[st + i];
        for (int i = 0; i < nR; i++) arrR[i] = arr[mid + 1 + i];

        // ✅ merge back using 0-based i, j and original k
        int i = 0, j = 0, k = st;
        while (i < nL && j < nR) {
            if (arrL[i] <= arrR[j]) arr[k++] = arrL[i++];
            else arr[k++] = arrR[j++];
        }

        // ✅ copy leftovers
        while (i < nL) arr[k++] = arrL[i++];
        while (j < nR) arr[k++] = arrR[j++];
    }

    public static void mergeSort(int arr[], int st, int end) {
        if (st == end) return;

        int mid = st + (end - st) / 2;  // ✅ also fixed mid calculation
        mergeSort(arr, st, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, st, mid, end);
    }

    public static void main(String[] args) {
        int[] arr = {9, 8, 7, 6, 5, 4, 1, 0};
        mergeSort(arr, 0, arr.length - 1);

        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
    }
}
