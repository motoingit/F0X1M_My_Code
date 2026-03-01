//reverse given string

public class j00_Reverse_Of_String{
    //! Java is pass-by-value only.
    // void swap(char &x, char &y){
    // }
    public static void main(String[] args) {
        StringBuilder str = new StringBuilder("MohitSingh");
        System.out.println(str);
        
        int front = 0;
        int rear = str.length() -1;
        while (front < rear){               //!  O(n) time complexity
            
            char frontChar = str.charAt(front);
            char rearChar = str.charAt(rear);
            
            str.setCharAt(rear, frontChar);
            str.setCharAt(front, rearChar);
            
            //todo: FUCKKKKKK                 front++, rear--;
            front++;
            rear--;
        }
        
        System.out.println(str);
    }
}
