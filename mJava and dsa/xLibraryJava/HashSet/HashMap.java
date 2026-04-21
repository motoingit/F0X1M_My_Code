package xLibraryJava.HashSet;
//hashset in java

import java.util.HashSet;
import java.util.Iterator;

public class HashMap{
    public static void main(String[] args) {
        HashSet<Integer> set = new HashSet<>();
        
        set.add(1);
        set.add(2);
        set.add(3);

        // contains() + remove() pattern
        if(set.contains(3)) {
            set.remove(3);
        }
        //* You can also just call set.remove(3) directly — it returns false if not found, no exception. */

        if (!set.contains(4)) {
            set.add(4);
            set.add(5);
        }

        System.out.println(set.size());

        ///
        Iterator it = set.iterator();
        
        while (it.hasNext()) {
            System.out.print(it.next() + " ");
        }
        System.out.println();
        
        // // or syso()
        // System.out.print(set);
    }
}
