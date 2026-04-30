

public class Hello {
   public static void show() {
       int y;
       System.out.println(y); // Error: variable y not initialized
   }
   int x; // default = 0
   public static void main(String[] args) {
      show();
   }
}
