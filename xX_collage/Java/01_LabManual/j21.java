/* Ques: ArrayList */

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class j21{
   public static void swapPair(List<String> arrList) {
      for (int i = 0; i < arrList.size() - 1; i += 2) {
         String temp = arrList.get(i);
         arrList.set(i, arrList.get(i + 1));
         arrList.set(i + 1, temp);
      }
   }
   public static void main(String[] args) {
      Scanner sc = new Scanner(System.in);

      int nInput = sc.nextInt();
      List<String> arrList = new ArrayList<>();

      for (int i = 0; i < nInput; i++) {
         arrList.add(sc.next());
      }

      swapPair(arrList);

      System.out.println(arrList);

      sc.close();
   }
}
