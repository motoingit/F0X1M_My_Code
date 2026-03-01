import java.util.ArrayList;
import java.util.Scanner;

class ArrayDemo{
    // For Searching Pair
    public void arrayFunction(ArrayList<Integer> arr, Integer target){
        for (int i = 0; i < 9; i++) {
            for (int j = i+1; j < 10; j++) {
                int sum = arr.get(i) + arr.get(j);
                if(sum == target){
                    System.out.println("Found : " + arr.get(i) + " and " + arr.get(j));
                }
            }
        }
    }
    // For Merging sorted array
    public ArrayList<Integer> arrayFunction(ArrayList<Integer> arr1, ArrayList<Integer> arr2){
        int size1 = arr1.size(), size2 = arr2.size();
        ArrayList<Integer> arr3 = new ArrayList<>();
        int p1 = 0, p2 = 0;

        while (p1 < size1 && p2 < size2) {
            if(arr1.get(p1) <= arr2.get(p2)){
                arr3.add(arr1.get(p1++));
            }else{
                arr3.add(arr2.get(p2++));
            }
        }

        while (p1 < size1) {
            arr3.add(arr1.get(p1++));
        }
        while (p2 < size2) {
            arr3.add(arr2.get(p2++));
        }

        return arr3;
    }
}

public class j10_ArrayDemo{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        ArrayList<Integer> arr = new ArrayList<>();
        System.out.println("Enter Array (n=10) : ");
        for (int i = 0; i < 10; i++) {
            int x = sc.nextInt();
            arr.add(x);
        }
        
        System.out.println("Enter Target : ");
        int target = sc.nextInt();

        ArrayDemo tool = new ArrayDemo();
        tool.arrayFunction(arr, target); // first overload test

        //


        ArrayList<Integer> arr1 = new ArrayList<>();
        ArrayList<Integer> arr2 = new ArrayList<>();

        System.out.println("Enter Array1 (n=5) : ");
        for (int i = 0; i < 5; i++) {
            int x = sc.nextInt();
            arr1.add(x);
        }
        System.out.println("Enter Array2 (n=5) : ");
        for (int i = 0; i < 5; i++) {
            int x = sc.nextInt();
            arr2.add(x);
        }

        ArrayList<Integer> arr3 = tool.arrayFunction(arr2, arr1);
        System.out.println( " Merged Array : "+ arr3);

        sc.close();
    }
}
