/*
5
* * * * * 
* * * *
* * *
* *
*
*/
import java.util.Scanner;

public class j04 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int x = sc.nextInt();

        for(int i = x; i >= 1; i--){
            for(int j = 1; j <= i; j++){
                System.err.print("* ");
            }
            System.out.print('\n');
        }
        sc.close();
    }
}
