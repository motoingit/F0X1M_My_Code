import java.util.ArrayList;
import java.util.List;
// import java.util.Random;
import java.util.concurrent.ThreadLocalRandom;
import java.util.Collections;

public class j03_RandomGenration{
    // public static int genrateRandom(int min, int max) {
    //     Random ran = new Random();
    //     int randomNo = ran.nextInt((max-min+1)+min);
    //     return randomNo;
    // }
    public static void main(String[] args) {
        List <Integer> list = new ArrayList<>();

        
        int min = 0, max = list.size();
        int it = ThreadLocalRandom.current().nextInt(0,10); // 0 -> 9
        while(it != 0){
            int randomNo = ThreadLocalRandom.current().nextInt(min, max);
            list.set(randomNo,0);
            it--;
        }

        for (Integer x : list) { //* you can use var which works like auto from cpp */
            System.out.print(x+" ");
        }
        System.out.println();

        int i = 0, j = list.size()-1;
        while (i < j) {
            if(list.indexOf(i) == 0){
                Collections.swap(list, i, j);
                j--;
                continue; //not run below
            }
            i++;
        }
        
        for (Integer x : list) { //* you can use var which works like auto from cpp */
            System.out.print(x+" ");
        }
    }

}

/* ! failing for this
0 0 30 0 50 
50 0 30 0 0

10 0 30 40 0 
10 0 30 40 0
*/

