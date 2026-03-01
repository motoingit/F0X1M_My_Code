# Java Access Modifiers Demonstration

This project demonstrates the visibility and accessibility of the four Java access modifiers: **public**, **protected**, **default** (package-private), and **private**.

## 📁 Project Structure

The project is organized into packages to simulate real-world scenarios:

- **src/**
  - **Main.java**: The entry point of the application.
  - **package1/**
    - `Parent.java`: The base class containing variables with all four access modifiers.
    - `Neighbor.java`: A class in the *same* package as `Parent`.
  - **package2/**
    - `Child.java`: A subclass of `Parent` in a *different* package.
    - `Stranger.java`: An unrelated class in a *different* package.

## 🔑 Access Modifiers Overview

| Modifier | Keyword | Visibility | Scope |
| :--- | :--- | :--- | :--- |
| **Public** | `public` | Everywhere | Accessible from any class anywhere in the project. |
| **Protected** | `protected` | Same Package + Subclasses | Accessible within the same package AND by subclasses in other packages. |
| **Default** | *(none)* | Same Package Only | Accessible only by classes within the same package. Not visible to subclasses outside the package. |
| **Private** | `private` | Class Only | Accessible only within the class where it is declared. |

## 🧪 Detailed Breakdown

### 1. `Parent.java` (The Source)
Defines four variables:
```java
public int publicVar = 10;
protected int protectedVar = 20;
int defaultVar = 30; // No keyword
private int privateVar = 40;
```
- **Visible here:** ALL (Public, Protected, Default, Private).

### 2. `Neighbor.java` (Same Package)
Located in `package1`.
- **Can Access:**
  - `publicVar` (Public)
  - `protectedVar` (Protected - same package rule)
  - `defaultVar` (Default - same package rule)
- **Cannot Access:**
  - `privateVar` (Private is class-restricted)

### 3. `Child.java` (Different Package - Subclass)
Located in `package2`, extends `Parent`.
- **Can Access:**
  - `publicVar` (Public)
  - `protectedVar` (Protected - subclass inheritance rule)
- **Cannot Access:**
  - `defaultVar` (Default is package-restricted)
  - `privateVar` (Private is class-restricted)

### 4. `Stranger.java` (Different Package - Unrelated)
Located in `package2`.
- **Can Access:**
  - `publicVar` (Public)
- **Cannot Access:**
  - `protectedVar` (Protected requires same package or inheritance)
  - `defaultVar` (Default is package-restricted)
  - `privateVar` (Private is class-restricted)

## 🚀 How to Run

1. Open a terminal in the project root.
2. Compile all files:
   ```bash
   javac src/package1/*.java src/package2/*.java src/Main.java
   ```
3. Run the Main class:
   ```bash
   java -cp src Main
   ```

## 📝 Notes
- Check the commented-out lines in `Neighbor.java`, `Child.java`, and `Stranger.java` to see what lines would cause compilation errors if uncommented.
- This demonstrates encapsulation, a core principle of Object-Oriented Programming (OOP).
