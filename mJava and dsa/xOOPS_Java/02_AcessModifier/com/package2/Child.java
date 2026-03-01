package package2;

import package1.Parent;

public class Child extends Parent {
    public void accessCheck() {
        System.out.println("--- Inside Child Class (Different Package, Subclass) ---");
        
        System.out.println("Public Variable: " + publicVar);       // Accessible via inheritance
        System.out.println("Protected Variable: " + protectedVar); // Accessible via inheritance (Different Package but Subclass)
        
        // System.out.println("Default Variable: " + defaultVar);  // NOT ACCESSIBLE! (Default is visible only in same package)
        // Compile Error: defaultVar is not public in package1.Parent; cannot be accessed from outside package
        
        // System.out.println("Private Variable: " + privateVar);  // NOT ACCESSIBLE! (Private is visible only in Parent class)
        // Compile Error: privateVar has private access in package1.Parent
        
        System.out.println("----------------------------------------\n");
    }
}
