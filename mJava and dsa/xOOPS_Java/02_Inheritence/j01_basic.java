class Parent {
    void display() {
        System.out.println("Parent method");
    }

    void color(){
        System.out.println("Parent Colour");
    }
}

class Child extends Parent {
    @Override //! implicity writing
    void display() {
        System.out.println("Child method");
    }
    
    void color(){
        super.color(); //! this is for calling parent version
        System.out.println("Child Colour");
    }
}

public class j01_basic{
    public static void main(String[] args) {
        // When you do this:
        Child obj1 = new Child();
        obj1.display();  // Prints "Child method" - child version is called as it has higher priority


        Child obj2 = new Child();
        obj2.color();  // Prints "Child method" - child version is called as it has higher priority

    }
}
