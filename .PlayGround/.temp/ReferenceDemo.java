class Student {
    String name;

    Student(String name) {
        this.name = name;
    }

    void display() {
        System.out.println("Name: " + name);
    }
}

public class ReferenceDemo {
    public static void main(String[] args) {

        // Step 1: Create object
        Student s1 = new Student("Moto");

        // Step 2: Another reference pointing to SAME object
        Student s2 = s1;

        // Change using s2
        s2.name = "Changed by s2";

        System.out.println("After modifying with s2:");
        s1.display();  // affected
        s2.display();  // affected

        // Step 3: Change reference of s2 to NEW object
        s2 = new Student("New Object");

        // Modify new object
        s2.name = "Modified New Object";

        System.out.println("\nAfter changing s2 reference:");
        s1.display();  // NOT affected
        s2.display();  // new object
    }
}
