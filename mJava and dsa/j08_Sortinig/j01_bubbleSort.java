public class j01_bubbleSort{
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
        // arr.length() == 5 ;
        for (int i = 0; i < arr.length - 1; i++) {
            boolean swapped = false;
            for (int j = 0; j < arr.length - i - 1; j++) {
                if(arr[j] > arr[j+1]){
                    swap(arr,j,j+1);
                    swapped = true;
                }
            }
            if(!swapped)
                break;
        }

        printArr(arr);
    }
}
