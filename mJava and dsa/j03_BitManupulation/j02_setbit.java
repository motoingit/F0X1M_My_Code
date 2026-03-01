public class j02_setbit{
    public static void main(String[] args) {
        int orignalNumber = 5; //0101
        int pos = 1;
        
        int bitmask = 1 << pos;

        int newNumber = bitmask | orignalNumber;
        System.out.println("The New nuber on setting bit is "+newNumber);
    }
}
