/*
Enter n for 1Module : 5
     *****
    *****
   *****
  *****
 *****
*/

import java.util.Scanner;

public class j10 {
    public static void main(String[] args){
        
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter n for 1Module : ");
        int n = sc.nextInt();

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n-i+1; j++){
                System.err.print(" ");
            }
            for(int j = 1; j <= n; j++){
                System.err.print("*");
            }
            System.err.print("\n");
        }
        sc.close();
    }
}