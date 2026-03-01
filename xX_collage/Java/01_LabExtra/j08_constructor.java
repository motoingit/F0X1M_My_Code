public class j08_constructor {
    String name;
    int age;
    
    public j08_constructor(String name, int age){ //parametarized
        this.age = age;
        this.name = name;
    }
    public j08_constructor(){ // default
        this.age = 0;
        this.name = "NULL";
    }
    public j08_constructor(j08_constructor obj){ //copy const
        this.age = obj.age;
        this.name = obj.name;
    }

    public void setName(String name){
        this.name = name;
    }
    public void setAge(int age){
        this.age = age;
    }
    public String getName(){
        return this.name;
    }
    public int getAge(){
        return this.age;
    }

    public static void main(String[] args) {
        j08_constructor p1 = new j08_constructor();
        j08_constructor p2 = new j08_constructor("Mohit", 21);
        j08_constructor p3 = new j08_constructor(p2);

        j08_constructor s1 = new j08_constructor("Mohit",21);
        System.out.println("Name : " + s1.getName());
        System.out.println("Age : " + s1.getAge());
    }
}
