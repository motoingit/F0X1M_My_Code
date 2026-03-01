//! java is a typed laguage (you have to define the data type)

package j02_Data_Types;

public class j01_Genral_DataTypes {
    public static void main(String[] args){
        String name = "Hello Bro";
        int age = 20;
        double salary = 2134.4;
        
        System.out.println(name);
        System.out.println(age);
        System.out.println(salary);

        //? two ways to format like c
        System.out.println(name + " " + age + " " + salary);
        System.out.printf("Name: %s | Age: %d | Salary: %.2f%n", name, age, salary);
    }
}
