public class j11_final_Variable {
    final float PI = 3.14f;

    public static void main(String[] args) {
        j11_final_Variable obj = new j11_final_Variable();
        System.out.println(obj.PI); 
        obj.PI = 4.8f; //! final meaing the consttant variable here
    }
}
