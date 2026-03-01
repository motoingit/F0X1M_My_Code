
import java.util.Scanner;

public class j06_Jagged2{
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

        for (int[] is : arr) {
            int avg = 0;
            int sum = 0;
            for (int is2 : is) {
                sum += is2;
            }
            avg = sum/is.length;
            
            if(avg < 10){
                System.out.println("Fail : F");
            }else if(avg < 30){
                System.out.println("Poor : E");
            }else if(avg < 50){
                System.out.println("Just Pass : D");
            }else if(avg < 70){
                System.out.println("Good : C");
            }else if(avg < 80){
                System.out.println("Great : B");
            }else if(avg < 90){
                System.out.println("Great : B");
            }else if(avg <= 100){
                System.out.println("Great : A");
            }
            
        }

        sc.close();
    }s
}
