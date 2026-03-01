public class j01_StringBuilder{
    public static void main(String[] args) {
        StringBuilder sb = new StringBuilder("AnyString");
        System.out.println(sb);
        
        //char at
        System.out.println(sb.charAt(0));
        
        //set char
        sb.setCharAt(0, 'P');
        System.out.println(sb); //!  change in sb not other
        
        sb.insert(0, 'S'); //* insert at front */
        System.out.println(sb);

        sb.insert(3, 'X'); //* insert at front */
        System.out.println(sb);

        sb.insert(3, "MOTO"); //* insert at front */
        System.out.println(sb);
        

        //dekete the extra  //*    delete[)   
        sb.delete(2,3);

        //adding at last
        sb.append("e");
    }
}
