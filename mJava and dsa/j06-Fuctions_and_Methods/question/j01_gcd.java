
public class j01 {
    public static int gcd(int a, int b) { //!Euclidean Method
        while (b != 0) {
            int r = a % b;
            a = b;
            b = r;
        }
        return a;
    }

    public static void main(String[] args) {
        System.out.println(gcd(243, 33)); // Output: 2
    }
}
