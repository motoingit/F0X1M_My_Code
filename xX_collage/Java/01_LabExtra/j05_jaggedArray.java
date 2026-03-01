import java.util.Scanner;

public class j05_jaggedArray{
    public static void inputArr(int []arr, Scanner sc){
            for (int j = 0; j < arr.length; j++) {
                arr[j] = sc.nextInt();
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

        int arr[][] = new int[n][];
        for (int i = 0; i < n; i++) {
            int m = sc.nextInt();
            arr[i] = new int[m];
            
            inputArr(arr[i], sc);
        }

        outputArr(arr);

        sc.close();
    }
}
