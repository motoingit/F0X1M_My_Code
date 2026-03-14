# Java OOP & Scope Demonstration

A terminal-based utility to visualize and understand Java's **Encapsulation, Polymorphism, Inheritance, Namespaces, Abstraction,** and **Access Modifiers**.

## Project Structure & Scope Labeling

```text
java-oop-demo/
└── src/
    └── com/
        └── demo/
            ├── core/                 <-- [PACKAGE SCOPE: Core Logic]
            │   ├── BaseSystem.java    <-- [ABSTRACT CLASS] (Protected/Private/Public demo)
            │   ├── EncapsulatedData.java <-- [ENCAPSULATION] (Private fields, Getters/Setters)
            │   └── InternalHelper.java   <-- [PACKAGE-PRIVATE] (Accessible only within com.demo.core)
            ├── ext/                  <-- [PACKAGE SCOPE: Extensions]
            │   └── ExtendedSystem.java <-- [INHERITANCE/POLYMORPHISM] (Cross-package protected access)
            ├── util/                 <-- [PACKAGE SCOPE: Utilities]
            │   └── FinalLogger.java   <-- [FINAL CLASS] (Cannot be inherited)
            └── Main.java             <-- [ENTRY POINT] (Demonstrates all concepts)
```

## Concepts Explained

| Concept | Demonstration |
| :--- | :--- |
| **Encapsulation** | `EncapsulatedData` uses `private` fields with `public` accessors. |
| **Polymorphism** | `BaseSystem` reference holding an `ExtendedSystem` instance. |
| **Inheritance** | `ExtendedSystem` extends `BaseSystem`. |
| **Abstraction** | `BaseSystem` is an `abstract` class with an `abstract` method. |
| **Namespaces** | Logical separation using `com.demo.core`, `com.demo.ext`, etc. |
| **Final Class** | `FinalLogger` cannot be subclassed. |
| **Access Modifiers** | `public`, `protected`, `private`, and `default` (package-private). |

## How to Run

1.  Open your terminal in the `java-oop-demo` directory.
2.  Compile all files:
    ```bash
    javac -d bin src/com/demo/*.java src/com/demo/core/*.java src/com/demo/ext/*.java src/com/demo/util/*.java
    ```
3.  Run the demo:
    ```bash
    java -cp bin com.demo.Main
    ```
