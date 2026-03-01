import java.util.Scanner;

public class j00_basic {
    public static void main(String[] args){

        int arr[] = new int[3]; //* order doesnt matter */
        for(int i = 0; i < 3; i++){
            arr[i] = i + 1;
        }

        for(int i = 0; i < 3; i++){
            System.out.println(arr[i] +" "+ arr);
        }

        /* //! this is hashmap random value
            1 [I@7ad041f3
            2 [I@7ad041f3
            3 [I@7ad041f3
        */
    }
}