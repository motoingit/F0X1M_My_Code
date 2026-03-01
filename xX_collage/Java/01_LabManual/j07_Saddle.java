import java.util.Scanner;

public class j07_Saddle{
    public static void swap(int []arr, int a, int b) {
        int temp = arr[a];
        arr[a] = arr[b];
        arr[b] = temp;
    }
    public static void sort(int []arr){
        for (int i = 0; i < arr.length; i++) {
            int minIdx = i;
            for (int j = i+1; j < arr.length; j++) {
                if(arr[minIdx] > arr[j]){
                    minIdx = j;
                }
            }
            swap(arr, i, minIdx); // noting hapen if same i and idx
        }
    }
    public static int findSattleEle(int [][]arr){
        for (int i = 0; i < arr.length; i++) {
            sort(arr[i]);
        }

        int max = arr[0][0]; //! hard code
        for (int i = 1; i < arr.length; i++) {
            if(max < arr[i][0]){
                max = arr[i][0];
            }
        }

        return max;
    }
    public static void inputArr(int [][]arr, Scanner sc){
        for (int i = 0; i < arr.length; i++) {
            for (int j = 0; j < arr[i].length; j++) {
                arr[i][j] = sc.nextInt();
            }
        }
    }

    public static void outputArr(int [][]arr){
        for (int i = 0; i < arr.length; i++) {
            for (int j = 0; j < arr[i].length; j++) {
                System.out.print( arr[i][j] + " ");
            }
            System.out.println();
        }
    }
    public static void main(String []args ){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();

        int arr [][] = new int[n][m];

        inputArr(arr, sc);

        outputArr(arr);

        System.out.println( findSattleEle(arr) + " is desired ele ");
        sc.close();
    }
}
