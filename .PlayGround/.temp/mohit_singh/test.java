
import java.util.Scanner;

public class test {
    public static void swap (int arr[], int a, int b){
        int temp = arr[a];
        arr[a] = arr[b];
        arr[b] = temp;
    }
    public static void sortSign(int arr[], int n){
        int low = 0, i = 0, high = n-1;
        while (low < high && i <= high && i < n) {
            if( arr[i] > 0){
                swap(arr, i, high);
                high--;
            }else if(arr[i] < 0){
                if(i != low){
                    swap(arr, i, low);
                }
                low++;
                i++;
            }else{
                i++; //increment on 0 or -ve
            }
        }
    }
    public static void printArr(int []arr, int n){
        for (int x : arr) {
            System.out.print(x + " ");
        }
        System.out.println();
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int arr[] = new int[n];

        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        sortSign(arr, n);
        printArr(arr, n);

        sc.close();
    }
}
