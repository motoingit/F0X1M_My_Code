public class j02_whileLoop{
    public static void main(String[] args) {

        int i = 1;
        while (true) { // this cannnot convert 1 to true . . . LOL

            if(i == 100){
                break;
            }
            System.out.println("Im Infinity from " + i);
            i++;
        }
    }
}