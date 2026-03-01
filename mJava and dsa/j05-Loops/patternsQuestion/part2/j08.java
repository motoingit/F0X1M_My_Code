/*

    7
        1 
        0 1
        1 0 1
        0 1 0 1
        1 0 1 0 1
        0 1 0 1 0 1
        1 0 1 0 1 0 1
*/
import java.util.Scanner;

public class j08 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int x = sc.nextInt();

        for(int i = 1; i <= x; i++){
            for(int j = 1; j <= i; j++){
                if((i+j)%2 == 0)
                    System.err.print("0 ");
                else{
                    System.err.print("1 ");
                }
            }
            System.out.print('\n');
        }
        sc.close();
    }
}
