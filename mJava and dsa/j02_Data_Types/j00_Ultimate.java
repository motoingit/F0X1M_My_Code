package j02_Data_Types;

public class j00_Ultimate {

    public static void main(String[] args) {

        // =========================
        // PRIMITIVE DATA TYPES
        // =========================

        byte b = 10; // stored using 8-bit two's complement representation
        short s = 100;
        int i = 1000;
        long l = 100000L;

        float f = 10.5f;
        double d = 99.99;

        char c = 'A';
        boolean flag = true;

        System.out.println("=== Primitive Data Types ===");
        System.out.println("byte: " + b);
        System.out.println("short: " + s);
        System.out.println("int: " + i);
        System.out.println("long: " + l);
        System.out.println("float: " + f);
        System.out.println("double: " + d);
        System.out.println("char: " + c);
        System.out.println("boolean: " + flag);


        // =========================
        // NON-PRIMITIVE DATA TYPES
        // =========================

        String name = "Mohit";

        int[] arr = {1, 2, 3, 4, 5};

        Student obj = new Student();   // Class & Object

        System.out.println("\n=== Non-Primitive Data Types ===");
        System.out.println("String: " + name);

        System.out.print("Array: ");
        for (int x : arr) {
            System.out.print(x + " ");
        }

        System.out.println("\nObject calling method:");
        obj.display();
    }
}

// Non-Primitive: Class
class Student {
    void display() {
        System.out.println("This is a Student object");
    }
}

