/*
    1-100 500
    101-200 1per + rental(500)
    101-200 1.2per + rental(500)
    101-200 1.5per + rental(500)
*/

import java.util.Scanner;

public class Logic{
    String name;
    int phoneNo;
    int nCall;
    int balance;

    Logic(String name, int phoneNo, int nCall){
        name = name;
        phoneNo = phoneNo;
        nCall = nCall;
        balance = 0;
    }
    public static calc(){
        if(nCall <= 100){
            balance += 500;
        }else if(nCall <= 200){
            balance += + 500;
        }else if(nCall <= 300){

        }else{

        }
    }
}

public class Test{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String name = sc.next();
        int phoneNo = sc.nextInt();
        int nCall = sc.nextInt();

        Logic p1 = new Logic();
        p1.calc();
        p1.display();
    }
}

/*
telecoll (phone no and noof)
compute(){
    if
    if


}

display()
*/
