public class j01_getbit{
    public static void main(String[] args) {
        int number = 5; // 0101
        int pos = 1;
        int bitmask = 1 << pos; //* Number is still save */

        if((bitmask & number) == 0){
            System.out.println("The Bit at Postion " + pos + " is Zero");
        }else{
            System.out.println("The Bit at Postion " + pos + " is One");
        }
    }
}
