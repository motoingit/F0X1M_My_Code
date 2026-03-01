
public class j03_fabonaci {

    public static void printFabonaci(int n){

        if(n == 1){
            System.out.print("0 ");
            return;
        }else{
            System.out.print("0 ");
        }

        int a = 0, b = 1;
        for(int i = 2; i <= n; i++){
            System.out.print(b+" ");

            int tmp = b;
            b = a + b;
            a = tmp;
        }
    }
    public static void main(String[] args) {
        printFabonaci(10);
    }
}