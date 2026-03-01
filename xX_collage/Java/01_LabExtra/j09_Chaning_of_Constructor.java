
public class j09_Chaning_of_Constructor {
    String name;
    int age;

    //* Constructor chaining */
    
    j09_Chaning_of_Constructor(String name, int age){
        this.name = name;
        this.age = age;
    }
    j09_Chaning_of_Constructor(String name){
        this(name, 21);
    }
    j09_Chaning_of_Constructor(){
        this("Mohit");
    }

    public static void main(String[] args) {
        j09_Chaning_of_Constructor p1 = new j09_Chaning_of_Constructor(); //! example
        System.out.println("Name : " + p1.name);
        System.out.println("Name : " + p1.age);
    }
}
