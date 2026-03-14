package com.demo.core;

/**
 * Demonstrates:
 * 1. Encapsulation (Private fields with public methods)
 */
public class EncapsulatedData {
    private double internalValue;
    private boolean isActive;

    public EncapsulatedData(double value) {
        this.internalValue = value;
        this.isActive = true;
    }

    // Public Getter
    public double getInternalValue() {
        return internalValue;
    }

    // Public Setter with Validation (The benefit of encapsulation)
    public void setInternalValue(double newValue) {
        if (newValue >= 0) {
            this.internalValue = newValue;
        } else {
            System.out.println("[EncapsulatedData] Error: Value cannot be negative!");
        }
    }

    public boolean isActive() {
        return isActive;
    }
}
