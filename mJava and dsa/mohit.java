import java.util.Scanner;
import java.util.InputMismatchException;

public class mohit {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

            System.out.println("Step 1: Type a word (e.g., 'Hello'):");
            // We store the input as a String
            String str = sc.next(); 
            System.out.println("You typed the string: " + str);

            System.out.println("\nStep 2: Now type that SAME word again to cause an error:");
            // TRAP: We use nextInt() but provide the String from Step 1.
            // Since nextInt() expects digits, 'Hello' will crash it.
            
            System.out.println("This line will never print if you typed a word!");

            sc.close();
    }
}
