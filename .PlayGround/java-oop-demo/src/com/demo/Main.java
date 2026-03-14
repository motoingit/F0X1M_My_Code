package com.demo;

import com.demo.core.BaseSystem;
import com.demo.core.EncapsulatedData;
import com.demo.ext.ExtendedSystem;
import com.demo.util.FinalLogger;

/**
 * Main Demo to showcase Java OOP concepts and Scope.
 */
public class Main {
    public static void main(String[] args) {
        System.out.println("=== JAVA OOP & SCOPE DEMONSTRATION ===");

        // 1. ABSTRACTION & POLYMORPHISM
        // Creating an ExtendedSystem instance but holding it in a BaseSystem reference.
        BaseSystem mySystem = new ExtendedSystem("Mainframe-01", "UUID-7788");

        System.out.println("\n--- 1. Polymorphism & Abstraction ---");
        mySystem.showIdentity();
        mySystem.initialize(); // Calls the concrete implementation in ExtendedSystem

        // 2. ENCAPSULATION
        System.out.println("\n--- 2. Encapsulation ---");
        EncapsulatedData data = new EncapsulatedData(100.0);
        System.out.println("Initial Value: " + data.getInternalValue());

        data.setInternalValue(250.5);
        System.out.println("Updated Value: " + data.getInternalValue());

        // Validating encapsulation (Negative value rejection)
        data.setInternalValue(-50);

        // 3. SCOPE & NAMESPACES
        System.out.println("\n--- 3. Scope & Namespaces ---");
        System.out.println("Public systemName: " + mySystem.systemName);

        // Note: mySystem.systemId is NOT accessible here because it is protected
        // and Main is not in com.demo.core nor a subclass of BaseSystem.
        // System.out.println(mySystem.systemId); // ERROR

        // 4. FINAL CLASS
        System.out.println("\n--- 4. Final Class & Static Access ---");
        FinalLogger.log("Demo Completed Successfully.");

        System.out.println("\n======================================");
    }
}
