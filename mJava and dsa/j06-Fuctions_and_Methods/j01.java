
public class j01 {
    public static int calculateFactorial(int n){
        int x = 1;
        if(n < 0){
            
        }else if(n == 0 || n == 1 || n == 2){

        }

        for(int i = 1; i <= n; i++){
            x *= i;
        }
        return x;
    }
    public static void main(String[] args) {
        int fact = calculateFactorial(3);
        System.err.print(fact);
    }
}
