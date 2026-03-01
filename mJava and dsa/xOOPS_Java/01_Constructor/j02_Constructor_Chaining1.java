
class Basic{
    public String name;
    public Integer age;

    //  todo :     Constructor chaining       */
    Basic(String name, Integer age){
        this.name = name;
        this.age = age;
    }
    Basic(String name){
        this(name, 40);
    }
    Basic(){
        this("Mohit");
    }

    public void allDetails(){
        System.out.println("Name : " + this.name);
        System.out.println("Age : " + this.age);
    }
}

public class j02_Constructor_Chaining1{
    public static void main(String[] args) {
        Basic p2 = new Basic();
        p2.allDetails();
    }
}
