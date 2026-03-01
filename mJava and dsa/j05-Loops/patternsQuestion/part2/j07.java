/*

    10
        1 
        2 3
        4 5 6
        7 8 9 10
        11 12 13 14 15
        16 17 18 19 20 21
        22 23 24 25 26 27 28
        29 30 31 32 33 34 35 36
        37 38 39 40 41 42 43 44 45
        46 47 48 49 50 51 52 53 54 55 
*/
import java.util.Scanner;

public class j07 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int x = sc.nextInt();

        int  z = 1;
        for(int i = 1; i <= x; i++){
            for(int j = 1; j <= i; j++){
                System.err.print(z+" ");
                z++;
            }
            System.out.print('\n');
        }
        sc.close();
    }
}
