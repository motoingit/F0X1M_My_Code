

import java.util.Scanner;

public class j00_basic {
    public static void main (String args[]){
        Scanner sc = new Scanner(System.in);
        int age = sc.nextInt();

        if(age < 18){
            System.out.println("Your are TeenAger \n");
        }else{
            System.out.println("Your are Adult \n");
        }

        sc.close();
    }
}
