public class j01_PatternValidate{
    public static void main(String[] args) {
        //!   -\\ is the sybol pointer
        //*  ^ start pointer     and     $ is end
        String pattern1 = "^[A-Z]{2}\\d{2}-[A-Z]{2}-\\d{4}$";
        String pattern2 = "^[A-Z]{2}d{4}+$"; //? four or
        //  more
        System.out.println("UK07-AA-1245".matches(pattern1));
        System.out.println("UK07+AA+1245".matches(pattern1));
    }
}
