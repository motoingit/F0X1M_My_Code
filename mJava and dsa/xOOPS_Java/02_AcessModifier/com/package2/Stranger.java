package package2;

import package1.Parent;

public class Stranger {
    public void accessCheck() {
        Parent p = new Parent();
        System.out.println("--- Inside Stranger Class (Different Package, Non-Subclass) ---");
        
        System.out.println("Public Variable: " + p.publicVar);       // Accessible
        
        // System.out.println("Protected Variable: " + p.protectedVar); // NOT ACCESSIBLE! (Protected is visible only in same package or via inheritance)
        // Compile Error: protectedVar has protected access in package1.Parent
        
        // System.out.println("Default Variable: " + p.defaultVar);     // NOT ACCESSIBLE! (Default is visible only in same package)
        // Compile Error: defaultVar is not public in package1.Parent; cannot be accessed from outside package
        
        // System.out.println("Private Variable: " + p.privateVar);     // NOT ACCESSIBLE! (Private is visible only in Parent class)
        // Compile Error: privateVar has private access in package1.Parent
        
        System.out.println("----------------------------------------\n");
    }
}
