

class Cat {
    String name;

    // Constructor
    Cat(String name) {
        this.name = name;
        System.out.println("Cat object created in Heap: " + this);
    }

    void meow() {
        System.out.println("Meow! I am " + name);
    }
}

public class GarbageCollection {

    public static void main(String[] args) {
        
        doCatStuff();
        System.out.println("\n[main] doCatStuff() finished. 'myCat' reference is now out of scope.");
        System.out.println("[main] Cat object in Heap is now UNREACHABLE → eligible for GC.\n");

        // Request GC (not guaranteed, but usually triggers in demo)
        System.out.println("[main] Requesting Garbage Collection...");
        System.gc(); //! its not like if we dont call it doesnt mark for swi

        System.out.println("\nI'm done doing cat stuff.");
    }

    // 1 usage
    private static void doCatStuff() {
        System.out.println("--- Inside doCatStuff() ---");
        Cat myCat = new Cat("cat1");         // Object created on Heap, reference on Stack
        myCat.meow();

        myCat = null;                  // Reference removed → object now unreachable
        System.out.println("[doCatStuff] myCat set to null → no reference pointing to Cat object.");
        System.out.println("--- Leaving doCatStuff() ---\n");
    }
}
