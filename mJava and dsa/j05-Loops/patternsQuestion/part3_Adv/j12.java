/*
n = odd

*/

import java.util.Scanner;

public class j12 {
    public static void main(String[] args){
        
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter n for 1Module : ");
        int n = sc.nextInt();

        for(int i = 1; i <= n; i++){
            for(int s = 1; s <= n-i; s++){
                System.err.print(" ");
            }
            for(int j = 1; j <= 2*i-1; j++){
                System.err.print("*");
            }
            System.err.print("\n");
        }

        //! to flip logic just down-counter the outermost loo[]
        for(int i = n - 1; i >=1; i--){
            for(int s = 1; s <= n-i; s++){
                System.err.print(" ");
            }
            for(int j = 1; j <= 2*i-1; j++){
                System.err.print("*");
            }
            System.err.print("\n");
        }

        sc.close();
    }
}