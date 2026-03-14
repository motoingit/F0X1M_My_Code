package com.demo.ext;

import com.demo.core.BaseSystem;

/**
 * Demonstrates:
 * 1. Inheritance across packages
 * 2. Polymorphism (Implementation of abstract method)
 * 3. Scope (Protected member access vs Package-Private)
 */
public class ExtendedSystem extends BaseSystem {

    public ExtendedSystem(String name, String id) {
        super(name, id);
    }

    @Override
    public void initialize() {
        System.out.println("[ExtendedSystem] Initializing " + this.systemName);
        
        // PROTECTED Access: systemId is accessible here even though we are 
        // in com.demo.ext because ExtendedSystem extends BaseSystem.
        System.out.println("[ExtendedSystem] Accessing Protected ID: " + this.systemId);

        // DEFAULT (Package-Private) Access:
        // versionTag would NOT be accessible here. Uncommenting would cause error.
        // System.out.println(this.versionTag); // ERROR: versionTag is not public or protected
    }

    public void runExtendedTask() {
        System.out.println("[ExtendedSystem] Running task unique to ExtendedSystem.");
    }
}
