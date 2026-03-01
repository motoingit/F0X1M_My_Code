
class Employee {
    private String name;
    private Integer age;
    public void printDetails(){
        System.out.println("Name : "+name);
        System.out.println("Age : "+age);
    }
    public Employee(String name, Integer age){
        this.name = name;
        this.age = age;
    }
    public void setAge(Integer age) {
        this.age = age;
    }
    public void setName(String name) {
        this.name = name;
    }
    public Integer getAge() {
        return age;
    }
    public String getName() {
        return name;
    }
}

public class firstClass{
    public static void main(String[] args) {
        System.out.println("Hello World");

        Employee e1 = new Employee("Mohit Singh", 80);
        e1.printDetails();

        System.out.println("Printing the Name of Employe : "+e1.getName());
    }
}

/*
//* Only One Class can be Public
//* The secondary class not be public or private
*/
