/* Ques:  TypeHere */ 

class A {
    public void show(){
        System.out.println("Hello from A");
    }
}

public class Main{
    public static void main(String[] args) {
        A obj = new A() {
            public void show(){
                System.out.println("Hello from Main");
            }
        };

        obj.show();
    }
}
