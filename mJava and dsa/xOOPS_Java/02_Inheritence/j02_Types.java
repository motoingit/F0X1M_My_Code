public class j02_Types {

    // ==============================
    // 1️⃣ SINGLE INHERITANCE
    // ==============================
    static class Animal {
        void eat() {
            System.out.println("Animal eats");
        }
    }

    static class Dog extends Animal {
        void bark() {
            System.out.println("Dog barks");
        }
    }

    // ==============================
    // 2️⃣ MULTILEVEL INHERITANCE
    // ==============================
    static class Vehicle {
        void start() {
            System.out.println("Vehicle starts");
        }
    }

    static class Car extends Vehicle {
        void drive() {
            System.out.println("Car drives");
        }
    }

    static class SportsCar extends Car {
        void turbo() {
            System.out.println("Sports car turbo mode ON");
        }
    }

    // ==============================
    // 3️⃣ HIERARCHICAL INHERITANCE
    // ==============================
    static class Shape {
        void display() {
            System.out.println("Displaying shape");
        }
    }

    static class Circle extends Shape {
        void draw() {
            System.out.println("Drawing Circle");
        }
    }

    static class Rectangle extends Shape {
        void draw() {
            System.out.println("Drawing Rectangle");
        }
    }

    // ==============================
    // 4️⃣ MULTIPLE INHERITANCE (INTERFACES)
    // ==============================
    interface Printer {
        void print();
    }

    interface Scanner {
        void scan();
    }

    static class MultiFunctionMachine implements Printer, Scanner {
        public void print() {
            System.out.println("Printing document");
        }

        public void scan() {
            System.out.println("Scanning document");
        }
    }

    // ==============================
    // 5️⃣ HYBRID INHERITANCE
    // (Combination of hierarchical + multiple)
    // ==============================
    interface WiFi {
        void connectWiFi();
    }

    static class Device {
        void powerOn() {
            System.out.println("Device powered ON");
        }
    }

    static class Laptop extends Device implements WiFi {
        public void connectWiFi() {
            System.out.println("Laptop connected to WiFi");
        }
    }

    static class Mobile extends Device implements WiFi {
        public void connectWiFi() {
            System.out.println("Mobile connected to WiFi");
        }
    }

    // ==============================
    // MAIN METHOD
    // ==============================
    public static void main(String[] args) {

        System.out.println("---- Single Inheritance ----");
        Dog d = new Dog();
        d.eat();
        d.bark();

        System.out.println("\n---- Multilevel Inheritance ----");
        SportsCar sc = new SportsCar();
        sc.start();
        sc.drive();
        sc.turbo();

        System.out.println("\n---- Hierarchical Inheritance ----");
        Circle c = new Circle();
        c.display();
        c.draw();

        Rectangle r = new Rectangle();
        r.display();
        r.draw();

        System.out.println("\n---- Multiple Inheritance (Interfaces) ----");
        MultiFunctionMachine m = new MultiFunctionMachine();
        m.print();
        m.scan();

        System.out.println("\n---- Hybrid Inheritance ----");
        Laptop l = new Laptop();
        l.powerOn();
        l.connectWiFi();

        Mobile mob = new Mobile();
        mob.powerOn();
        mob.connectWiFi();
    }
}


/*
🔥 Key Strategic Insight

Java does not allow:
class A extends B, C ❌

Java allows:
class A implements B, C ✅

That’s how Java avoids the Diamond Problem.

*/
