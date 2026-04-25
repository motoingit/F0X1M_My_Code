/* Ques:  BankTransationClass implementting Threads and Depositclass and CashOut class for the transationala threads simulating the way of order of the flow with understanding threads
 */ 

public class BankTransaction extends Thread{
   public static void main(String[] args) {
      public transationID;
      
      
      BankTransaction(String id){
         this.transationID = id;
      }

      public void run(){
         System.out.println("Transaction ID: " + this.transationID);
         try{
            Thread.sleep(1000);
         }catch(InterruptedException e){
            e.printStackTrace();
         }
      }
   }
}

public class BankDeposite extends Thread{
   public static void main(String[] args) {
      public String accountNumber;
      public Integer balance;  


   }
}

public class Main{
   public static void main(String[] args) {
      
   }
}

