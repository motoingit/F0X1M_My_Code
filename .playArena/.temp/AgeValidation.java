// Step 1: Create your Custom Exception class
class ManualException extends Exception {
    public ManualException(String message) {
        super(message);
    }
}

// Step 2: Main class
public class AgeValidation {

    public static void main(String[] args) {

        // Test with age 17 (should throw exception)
        System.out.println("--- Testing age 17 ---");
        try {
            useOfThrows(17);
        } catch (ManualException e) {
            System.out.println("Exception caught: " + e.getMessage());
        }

        // Test with age 20 (should pass)
        System.out.println("\n--- Testing age 20 ---");
        try {
            useOfThrows(20);
        } catch (ManualException e) {
            System.out.println("Exception caught: " + e.getMessage());
        }

    }

    // Step 3: Method that throws ManualException
    static void useOfThrows(int age) throws ManualException {

        if (age < 18) {
            throw new ManualException("Age is lesser than 18! Your age: " + age);
        } else {
            System.out.println("You are allowed to enter. Your age: " + age);
        }

        System.out.println("Done!");
    }

}
