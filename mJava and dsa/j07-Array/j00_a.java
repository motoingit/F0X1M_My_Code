import java.lang.*;
import java.util.Scanner;

public class Main{
    static void fun1(){
        Scanner sc = new Scanner(System.in);

        int r = 2, c = 2;
        int[][] arr = new int[r][c];

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                arr[i][j] = sc.nextInt();
            }
        }
        
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                System.out.print(arr[i][j] + " ");
            }
        }

        sc.close();
    }
    static void fun2(){
        Scanner sc = new Scanner(System.in);

        int r = 5;
        int[][] arr = new int[r][];

        for (int i = 0; i < r; i++) {
            int c = sc.nextInt();
            arr[i] = new int[c];

            for (int j = 0; j < c; j++) {
                arr[i][j] = sc.nextInt();
            }
        }
        
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < arr[i].length; j++) {
                System.out.print(arr[i][j] + " ");
            }
            System.out.println();
        }

        sc.close();
    }
    
    static void main(String[] args) {
       
    }
}
