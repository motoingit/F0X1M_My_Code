package j00_Basics;

// import java.util.*;
import java.util.Scanner;

public class j02_input{
    public static void main(String[] args){

        Scanner sc = new Scanner(System.in);

        System.out.println("Enter Sir-name Name :");
        String name = sc.nextLine(); //! if twor bowr boom

        System.out.print("Enter full name: ");
        String fullName = sc.nextLine();

        System.out.print("Enter Date: ");
        int date = sc.nextInt();

        // Float day = sc.nextFloat();

        System.out.print("Enter Date: ");
        float day = sc.nextFloat();


        //! System.out.print(name,fullName,date,day);

        System.out.println("\n--- Output ---");
        System.out.println("Name: " + name);
        System.out.println("Full Name: " + fullName);
        System.out.println("Date: " + date);
        System.out.println("Day: " + day);
        
        sc.close();
    }
}
