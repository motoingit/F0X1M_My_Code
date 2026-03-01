class Basic{
    public String name;
    public Integer age;
    
    //* Parameterized */
    public Basic(String name, int age){
        this.age = age;
        this.name = name;
    }
    
    //* Default */
    public Basic(){
        this.age = 0;
        this.name = "NULL";
    }

    //* Copy */
    public Basic(Basic obj){
        this.age = obj.age;
        this.name = obj.name;
    }
}

public class j01_Basic{
    public static void main(String[] args) {
        Basic p1 = new Basic();
        Basic p2 = new Basic("Mohit", 21);
        Basic p3 = new Basic(p2);
    }
}
