public class j02_selectionSort{
    static void swap(int arr[], int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    static void printArr(int arr[]){
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        int arr[] = {7,8,3,2,1};
        printArr(arr);

        for(int i = 0; i < arr.length; i++){
            int sIdx = i;
            for (int j = i; j < arr.length; j++) {
                if(arr[sIdx] > arr[j]){
                    sIdx = j;
                }
            }
            if (sIdx != i) { // just small optimisation
                swap(arr, sIdx, i);
            }

        }

        printArr(arr);
    }
}
