import java.util.Scanner;


public class j04_UpdateBit{
    public static void main(String[] args) {
        int orgNum = 5; //0101
        int pos = 2;
        int bitMask = 1 << pos;
        
        Scanner sc = new Scanner(System.in);

        boolean ctrl = sc.nextBoolean(); //todo:    input(true or false) not 1 or 0
        if(ctrl){
            int newNumber = bitMask | orgNum;
            System.out.println("The New nuber on set bit is "+newNumber);
        }else{
            int newNumber = ~bitMask & orgNum;
            System.out.println("The New nuber on set bit is "+newNumber);
        }
        sc.close();
    }
}
