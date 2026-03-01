
public class j10_StaticVariable {
    String name;
    int age;
    static String collageName;

    j10_StaticVariable(String name, int age){
        this.age = age;
        this.name = name;
    }

    static void changeStaticName(String name){
        j10_StaticVariable.collageName = name;
    }
    public static void main(String[] args) {
        j10_StaticVariable s1 = new j10_StaticVariable("Mohit", 30);
        System.out.println(s1.name + " " + s1.age + " " + j10_StaticVariable.collageName);

        j10_StaticVariable.changeStaticName("GEU");
        
        j10_StaticVariable s2 = new j10_StaticVariable("Rohit", 50);
        System.out.println(s2.name + " " + s2.age + " " + j10_StaticVariable.collageName);
    }
}
