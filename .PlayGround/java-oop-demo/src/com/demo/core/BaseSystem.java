package com.demo.core;

/**
 * Demonstrates:
 * 1. Abstraction (Abstract class)
 * 2. Access Modifiers (Private, Protected, Public, Package-Private)
 */
public abstract class BaseSystem {
    // Private: Accessible ONLY within this class
    private String systemSecret = "TOP_SECRET_123";

    // Protected: Accessible within package AND by subclasses in other packages
    protected String systemId;

    // Package-Private (Default): Accessible ONLY within com.demo.core
    String versionTag = "v1.0-alpha";

    // Public: Accessible from anywhere
    public String systemName;

    public BaseSystem(String name, String id) {
        this.systemName = name;
        this.systemId = id;
    }

    // Abstract method: Must be implemented by subclasses
    public abstract void initialize();

    public void showIdentity() {
        System.out.println("[BaseSystem] Name: " + systemName + " | ID: " + systemId);
        // systemSecret is accessible here because we are inside BaseSystem
        System.out.println("[BaseSystem] Accessing Private Secret: " + systemSecret);
    }
}
