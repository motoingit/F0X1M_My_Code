import java.util.ArrayList;
import java.util.Scanner;

public class j20 {

    public static void removeEvenLength(ArrayList<String> list) {
        for (int i = list.size() - 1; i >= 0; i--) {
            if (list.get(i).length() % 2 == 0) {
                list.remove(i);
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int nInput = sc.nextInt();
        ArrayList<String> arrList = new ArrayList<>();

        for (int i = 0; i < nInput; i++) {
            arrList.add(sc.next());
        }

        removeEvenLength(arrList);

        System.out.println("Result : >>");
        for (String str : arrList) {
            System.out.println(str);
        }

        sc.close();
    }
}
