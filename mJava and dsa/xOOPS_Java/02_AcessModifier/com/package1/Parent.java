package package1;

public class Parent {
    // 1. PUBLIC Access Modifier
    // Accessible from ANYWHERE in the project (any package, any subclass, any class).
    public int publicVar = 10;

    // 2. PROTECTED Access Modifier
    // Accessible within the SAME package and by SUBCLASSES in different packages.
    protected int protectedVar = 20;

    // 3. DEFAULT (Package-Private) Access Modifier (No keyword)
    // Accessible ONLY within the SAME package. Not accessible outside the package, even by subclasses.
    int defaultVar = 30; 

    // 4. PRIVATE Access Modifier
    // Accessible ONLY within THIS CLASS itself.
    private int privateVar = 40;

    public void displayVariablesInsideClass() {
        System.out.println("--- Inside Parent Class (Same Class) ---");
        System.out.println("Public Variable: " + publicVar);
        System.out.println("Protected Variable: " + protectedVar);
        System.out.println("Default Variable: " + defaultVar);
        System.out.println("Private Variable: " + privateVar);
        System.out.println("----------------------------------------\n");
    }
    
    // Getter for private variable demonstration (Encapsulation)
    public int getPrivateVar() {
        return privateVar;
    }
}
