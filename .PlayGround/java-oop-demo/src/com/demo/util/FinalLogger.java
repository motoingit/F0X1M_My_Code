package com.demo.util;

/**
 * Demonstrates:
 * 1. Final Class Abstraction (Cannot be inherited)
 */
public final class FinalLogger {
    // Private constructor: Cannot be instantiated
    private FinalLogger() {}

    public static void log(String message) {
        System.out.println("[FinalLogger] LOG: " + message);
    }
}

// Attempts to extend this would fail:
// class ChildLogger extends FinalLogger {} // ERROR: Cannot inherit from final class
