public class moto{
    public static void main(String[] args) {
        String s1 = "Mohit";
        String s2 = new String("Mohit");

        if(s1 == s2){ //! 
            System.out.println("Equal");
        }else{
            System.out.println("Not Equal");
        }
        
        if(s1.equals(s2)){
            System.out.println("Equal");
        }else{
            System.out.println("Equal");
        }

        // for primitive it sees value
        // for refrence obj it sees adress
    }
}
