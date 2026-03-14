package com.demo.core;

/**
 * Demonstrates:
 * 1. Package-Private Scope (No modifier)
 * This class cannot be accessed outside of com.demo.core.
 */
class InternalHelper {
    static void logOperation(String op) {
        System.out.println("[InternalHelper] Logging internal core op: " + op);
    }
}
