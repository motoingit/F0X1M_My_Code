import package1.Neighbor;
import package1.Parent;
import package2.Child;
import package2.Stranger;

public class Main {
    public static void main(String[] args) {
        System.out.println("========== ACCESS MODIFIER DEMONSTRATION ==========\n");

        // 1. Access inside the class itself
        Parent parent = new Parent();
        parent.displayVariablesInsideClass();

        // 2. Access from a class in the SAME package
        Neighbor neighbor = new Neighbor();
        neighbor.accessCheck();

        // 3. Access from a subclass in a DIFFERENT package
        Child child = new Child();
        child.accessCheck();

        // 4. Access from a non-subclass in a DIFFERENT package
        Stranger stranger = new Stranger();
        stranger.accessCheck();
    }
}
