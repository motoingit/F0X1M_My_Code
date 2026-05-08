import java.util.ArrayList;
import java.util.List;

public class j22 {

    public static List<Integer> alternate(List<Integer> list1, List<Integer> list2) {
        List<Integer> result = new ArrayList<>();

        int i = 0;
        int size1 = list1.size();
        int size2 = list2.size();

        while (i < size1 && i < size2) {
            result.add(list1.get(i));   // from list1 first
            result.add(list2.get(i));   // then list2
            i++;
        }

        // Append remaining elements from the longer list
        while (i < size1) {
            result.add(list1.get(i++));
        }
        while (i < size2) {
            result.add(list2.get(i++));
        }

        return result;
    }

    public static void main(String[] args) {
        List<Integer> list1 = List.of(1, 2, 3, 4, 5);
        List<Integer> list2 = List.of(6, 7, 8, 9, 10, 11, 12);

        List<Integer> result = alternate(list1, list2);
        System.out.println(result);
    }
}
