package j00_Basics;
public class j03_Calculation {
    //! BODmas doesnt work in Programming
    public static void main(String[] args) {

        int a = 10;
        int sum = a + 90;
        System.out.println(sum);

        int x = 10, y = 5;

        //todo:  just evaluate from left to right
        int exp1 = x * y / x - y;
        int exp2 = (x * y) / (x - y);

        System.out.println(exp1);
        System.out.println(exp2);
    }
}
