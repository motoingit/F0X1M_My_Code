/*

        4
    1
    12
    123
    1234
*/
import java.util.Scanner;

public class j06 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int x = sc.nextInt();

        for(int i = 1; i <= x; i++){
            for(int j = 1; j <= i; j++){
                System.err.print(j);
            }
            System.out.print('\n');
        }
        sc.close();
    }
}
