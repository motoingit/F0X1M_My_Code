/*
7 7
* * * * * * * 
*           *
*           *
*           *
*           *
*           *
* * * * * * *
*/
import java.util.Scanner;

public class j02 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int x = sc.nextInt();
        int y = sc.nextInt();

        for(int i = 1; i <= x; i++){
            for(int j = 1; j <= y; j++){
                if(i == 1 || i == x || j == 1 || j == y){
                    System.err.print("*");
                }else{
                    System.err.print(" ");
                }
            }
            System.out.print('\n');
        }
        sc.close();
    }
}
