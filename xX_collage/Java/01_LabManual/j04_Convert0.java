import java.util.Scanner;

public class j04_Convert0{
    public static int method2(int number){
        String numberStr1 = String.valueOf(number);
        StringBuilder numberStr2 = new StringBuilder();

        for(int j = 0; j < numberStr1.length(); j++){
            if(numberStr1.charAt(j) == '0'){
                numberStr2 .append('1');
            }else{
                numberStr2 .append(numberStr1.charAt(j));
            }
        }

        return Integer.parseInt(numberStr2.toString());
    }

    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        int number = scan.nextInt();
        int numberTemp = number;

        //*Method 1 */
        int i = 1;
        while(numberTemp > 0){
            
            if(numberTemp % 10 == 0){
                number += i;
            }

            numberTemp /= 10;
            i *= 10;
        }
        
        //*Method 2 */
        // number = method2(number);

        System.out.println(number);
        scan.close();
    }
}


