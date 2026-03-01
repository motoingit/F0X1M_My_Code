package j00_Basics;

import java.util.Scanner;

public class j02_1_input_Problem {
    public static void main(String[] args){

        Scanner sc = new Scanner(System.in);

        System.out.println("Enter Full name : "); //? "Mohit Singh\n"
        String name = sc.next(); //after this " singh\n"

        System.out.println("Enter Salary : ");
        float salary = sc.nextInt();

        System.out.println("Enter Father Name : ");
        // string fatherName = sc.next();
        String fatherName = sc.next();

        System.out.println("\n--- Output ---");
        System.out.println("Name: " + name);
        System.out.println("Salary: " + salary);
        System.out.println("Father name :" + fatherName);
        
        sc.close();
    }
}
