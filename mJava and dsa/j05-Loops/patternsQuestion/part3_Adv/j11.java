/*
Enter n for 1Module : 5
    1
   212
  32123
 4321234
543212345
*/

import java.util.Scanner;

public class j11 {
    public static void main(String[] args){
        
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter n for 1Module : ");
        int n = sc.nextInt();

        for(int i = 1; i <= n; i++){
            for(int s = 1; s <= n-i; s++){
                System.err.print(" ");
            }
            for(int j = i; j >= 1; j--){
                System.err.print(j);
            }
            for(int j = 2; j <= i; j++){
                System.err.print(j);
            }
            System.err.print("\n");
        }
        sc.close();
    }
}