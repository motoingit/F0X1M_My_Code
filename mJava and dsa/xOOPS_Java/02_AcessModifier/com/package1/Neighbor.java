package package1;

public class Neighbor {
    public void accessCheck() {
        Parent p = new Parent();
        System.out.println("--- Inside Neighbor Class (Same Package) ---");
        
        System.out.println("Public Variable: " + p.publicVar);       // Accessible
        System.out.println("Protected Variable: " + p.protectedVar); // Accessible (Same Package)
        System.out.println("Default Variable: " + p.defaultVar);     // Accessible (Same Package)
        
        // System.out.println("Private Variable: " + p.privateVar);  // NOT ACCESSIBLE! (Private is visible only within Parent class)
        // Compile Error: privateVar has private access in package1.Parent
        
        System.out.println("----------------------------------------\n");
    }
}
