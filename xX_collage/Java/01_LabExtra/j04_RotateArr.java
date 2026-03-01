import java.util.Scanner;

public class j04_RotateArr{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int arr[] = new int[n];
        int i=0;
        for (int x : arr) {
           arr[i]=sc.nextInt();
           i++;
        //     // System.out.println(x);
        }
        // for (int i = 0; i < arr.length; i++) { //auto boxing | property | wrapperclass of Integer
        //     x = sc.nextInt();
        // }

        int brr[] = new int[n];

        for (int i = 0; i < arr.length; i++) { //auto boxing | property | wrapperclass of Integer
            System.out.print(arr[]+ " ");
        }


        sc.close();
    }
}
