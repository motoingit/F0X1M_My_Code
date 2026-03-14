public class j00_basic {

    public static void main(String[] args) {

        // ===============================
        // 1. Arithmetic Operators
        // ===============================
        int a = 10;
        int b = 3;

        System.out.println("Arithmetic Operators:");
        System.out.println("a + b = " + (a + b));
        System.out.println("a - b = " + (a - b));
        System.out.println("a * b = " + (a * b));
        System.out.println("a / b = " + (a / b));
        System.out.println("a % b = " + (a % b));


        // ===============================
        // 2. Increment / Decrement
        // ===============================
        int x = 5;

        System.out.println("\nIncrement / Decrement:");
        System.out.println("x = " + x);
        System.out.println("x++ = " + (x++)); // post increment
        System.out.println("after x++ -> " + x);

        System.out.println("++x = " + (++x)); // pre increment

        System.out.println("x-- = " + (x--)); // post decrement
        System.out.println("--x = " + (--x)); // pre decrement


        // ===============================
        // 3. Relational Operators
        // ===============================
        int p = 10;
        int q = 20;

        System.out.println("\nRelational Operators:");
        System.out.println("p == q : " + (p == q));
        System.out.println("p != q : " + (p != q));
        System.out.println("p > q  : " + (p > q));
        System.out.println("p < q  : " + (p < q));
        System.out.println("p >= q : " + (p >= q));
        System.out.println("p <= q : " + (p <= q));


        // ===============================
        // 4. Logical Operators
        // ===============================
        boolean cond1 = true;
        boolean cond2 = false;

        System.out.println("\nLogical Operators:");
        System.out.println("cond1 && cond2 : " + (cond1 && cond2));
        System.out.println("cond1 || cond2 : " + (cond1 || cond2));
        System.out.println("!cond1 : " + (!cond1));


        // ===============================
        // 5. Bitwise Operators
        // ===============================
        int m = 5; // 0101
        int n = 3; // 0011

        System.out.println("\nBitwise Operators:");
        System.out.println("m & n : " + (m & n));
        System.out.println("m | n : " + (m | n));
        System.out.println("m ^ n : " + (m ^ n));
        System.out.println("~m : " + (~m));


        // ===============================
        // 6. Shift Operators
        // ===============================
        int num = 8; // 00001000

        System.out.println("\nShift Operators:");
        System.out.println("num << 1 : " + (num << 1));
        System.out.println("num >> 1 : " + (num >> 1));

    }
}

/*
        //  +
        //  -
        //  *
        //  /
        //  %

        //  ++
        //  --

        //? true and false
        //  ==
        //  !=
        //  <
        //  >
        //  >=
        //  <=

        //  &&
        //  ||
        //  !

        //  &
        //  |
        //  ^
        //  ~
        //  <<
        //  >>
*/
