/* Practical 03 : 
Write a Java program to determine whether two given integers form a Friendly Pair (also known as an Amicable Pair). Friendly numbers are two or more numbers that share the same abundancy, where abundancy is defined as the ratio of the sum of proper divisors of a number to the number itself.

The program should accept two integers as input from the user. It should compute the sum of all proper divisors of each number and then compare their abundancy ratios. If the ratios are equal, the program should display “Friendly Pair”; otherwise, it should display “Not Friendly Pair”.

For example, the numbers 6 and 28 are Friendly Pair because
(sum of divisors of 6) / 6 = (sum of divisors of 28) / 28.
The program must use the Scanner class to take input from the user.
*/

import java.util.Scanner;

public class j03_IsFriendlyPairs{
    // Method to calculate sum of proper divisors
    public static int getSum(int num){
        int sum = 0;
        for(int i=1; i<=num/2; i++){
            if(num % i == 0){
                sum += i;
            }
        }
        return sum;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter n1 n2 : ");

        //with the help of nextfuction we can read data !;
        //with next() it only reads the one word
        int num1 = sc.nextInt();
        int num2 = sc.nextInt();

        int sum1 = getSum(num1);
        int sum2 = getSum(num2);

        // Check Friendly Pair condition
        if ((sum1 / (float) num1) == (sum2 / (float) num2)) {
            System.out.println("Friendly Pair");
        } else {
            System.out.println("Not Friendly Pair");
        }

        /*
            when cout is writen the bridge form a stream b/w keyboard and screen;
            of you forgot to sc.close() its randomly going data (althoung no errror)
        */
        //! java dont have operator overloading

        sc.close(); //! 
    }
}
