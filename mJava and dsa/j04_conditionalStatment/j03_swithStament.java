import java.util.Scanner;

public class j03_swithStament {
    public static void main(String[] args) {
        
        Scanner sc = new Scanner(System.in);

        System.out.println("Press a number:");
        System.out.println("1 → Namaste");
        System.out.println("2 → Hello");
        System.out.println("3 → Bonjour");

        int control = sc.nextInt();

        switch (control) {

            case 1:
                System.out.println("Namaste");
                break;

            case 2:
                System.out.println("Hello");
                break;

            case 3:
                System.out.println("Bonjour");
                break;

            default:
                System.out.println("Invalid input");
        }
        sc.close();
    }
}
