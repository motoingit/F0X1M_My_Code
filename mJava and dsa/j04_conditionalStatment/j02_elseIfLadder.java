
import java.util.Scanner;

public class j02_elseIfLadder {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int num = sc.nextInt();

        int target = 100;

        if(num > target){
            System.out.println("Greater");
        }else if(num < target){
            System.out.println("Lesser");
        }else{
            System.out.println("Equal");
        }

        sc.close();
    }
}
