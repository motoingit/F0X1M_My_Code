/*
            Enter n for 1Module : 7
                                        *            *
                                        **          **
                                        ***        ***
                                        ****      ****
                                        *****    *****
                                        ******  ******
                                        **************
                                        **************
                                        ******  ******
                                        *****    *****
                                        ****      ****
                                        ***        ***
                                        **          **
                                        *            *
*/

import java.util.Scanner;

public class j09 {
    public static void main(String[] args){
        
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter n for 1Module : ");
        int n = sc.nextInt();

        for(int i = 1; i <= n; i++){
            int j = 1, s = 1;
            for(j = 1; j <= i; j++){
                System.out.print("*");
            }
            for(s = 1; s <= n*2-i*2; s++){
                System.out.print(" ");
            }
            for(j--; j >= 1; j--){
                System.out.print("*");
            }
            System.out.print("\n");
        }

        for(int i = 2; i<= n; i++){
            int j = 1, s = 1;
            for(j = 1; j <= n-i+1; j++){
                System.out.print("*");
            }
            for(s = 1; s <= i*2-2; s++){
                System.out.print(" ");
            }
            for(j--; j >= 1; j--){
                System.out.print("*");
            }
            System.out.print("\n");
        }

        sc.close();
    }
}