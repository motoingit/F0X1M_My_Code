import java.util.Scanner;

public class j02 {

    public static void infiniteInput() {
        Scanner sc = new Scanner(System.in);
        int pos = 0, neg = 0, zero = 0;

        //* sc.hasNextInt(), read not consume the input stream and then return true and false
        while (sc.hasNextInt()) {
            int num = sc.nextInt();

            if (num > 0) pos++;
            else if (num < 0) neg++;
            else zero++;
        }

        System.out.println("Pos = " + pos + " Neg = " + neg + " Zero = " + zero);
        sc.close();
    }

    public static void main(String[] args) {
        infiniteInput();
    }
}
