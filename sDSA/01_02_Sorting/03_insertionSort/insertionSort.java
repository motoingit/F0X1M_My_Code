public class insertionSort{
    static void swap(int arr[],  int i, int j){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    // Print the Array !
    static void printArr(int arr[]){
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        int arr[] = {1, 7, 0, 3, -1};

        printArr(arr);

        //!      Time Complexity: O(N2) 
        for (int i = 1; i < arr.length; i++) { //* let arr[0] sorted sub-array */
            int current = arr[i];
            int idx = i - 1;

            while (idx >= 0 && arr[idx] > current) {
                arr[idx + 1] = arr[idx];
                idx--;
            }

            arr[idx + 1] = current;
        }

        printArr(arr);
    }
}
