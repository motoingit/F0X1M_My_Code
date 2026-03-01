public class j03_clearBit{
    public static void main(String[] args) {
        int orignalNumber = 5; //0101
        int pos = 2;

        int bitmask = 1 << pos;
        bitmask = ~(bitmask);

        int newNumber = bitmask & orignalNumber;
        System.out.println("The New nuber on reset bit is "+newNumber);
    }
}
