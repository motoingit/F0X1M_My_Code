/* Ques:  TypeHere */

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class j22{
   public static List<Integer> alternateList(List<Integer> l1, List<Integer> l2){
      List<Integer> l0 = new ArrayList<>();

      int i = 0;

      while (i < l1.size() && i < l2.size()) {
         l0.add(l1.get(i));
         l0.add(l2.get(i));
         i++;
      }

      while (i < l1.size()) {
         l0.add(l1.get(i));
         i++;
      }

      while (i < l2.size()) {
         l0.add(l2.get(i));
         i++;
      }

      return l0;
   }
   public static void main(String[] args) {
      Scanner sc = new Scanner(System.in);

      List<Integer> l1 = new ArrayList<>();
      List<Integer> l2 = new ArrayList<>();


      int len1 = sc.nextInt();
      for (int i = 0; i < len1; i++) {
         l1.add(sc.nextInt());
      }
      
      int len2 = sc.nextInt();
      for (int i = 0; i < len2; i++) {
         l2.add(sc.nextInt());
      }

      List<Integer> l0 = alternateList(l1, l2);
      System.out.println(l0);

      sc.close();
   }
}
