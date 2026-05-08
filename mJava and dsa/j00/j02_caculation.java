package j00;

import java.util.Scanner;

public class j02_caculation {
    public static float inputX(int ctrl, Scanner sc){

        float res, p, r;
        int nY;

        System.out.print("Enter Principle : ");
        p = sc.nextFloat();
        System.out.print("Enter Rate : ");
        r = sc.nextFloat();
        System.out.print("Enter Years : ");
        nY = sc.nextInt();

        if(ctrl == 1){
            res = p*(1+r/100)*nY;
        }else if (ctrl == 2){
            res = p * nY + p * nY * ((nY + 1) / 2) * (r / 100) * (1 / 12);
        }else{
            System.out.println("Error : 101");
            res = -1;
        }

        return res;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("(1) [to term Deposit]      (2) [to Rate Deposit]           (0)[to Exit] : ");
        
        float res = 0f;
        int ctrl = -1;

        do{
            ctrl= sc.nextInt();
            switch (ctrl) {
                case 0:
                    System.out.println("Exit.");
                    break;
                    
                case 1:
                    res = inputX(ctrl, sc);
                    System.out.println("Maturity is : "+res);
                    break;
    
                case 2:
                    res = inputX(ctrl, sc);
                    System.out.println("Maturity is : "+res);
                    break;
            
                default:
                    System.out.println("Try Again (Error : invalid input)");
                    break;
            }

        }while(ctrl != 0);

        sc.close();
    }
}

/*
    in java the static class can be called the other static class if the y are on same

    static data is only acces by static fuction
*/
