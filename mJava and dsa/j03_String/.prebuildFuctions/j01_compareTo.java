public class j01_compareTo {
    public static void main(String[] args) {
        String name1 = "Any";
        String name2 = "Bny";

        //1     s1 > s2 : +ve
        //1     s1 = s2 : null
        //1     s1 < s2 : -ve

        if(name1.compareTo(name2) == 0){
            System.err.println("String is Equal");
        }else if(name1.compareTo(name2) > 0){
            System.err.println("Caller string is Big");
        }else if(name1.compareTo(name2) < 0){
            System.err.println("aregumented string is Big");
        }




        String name3 = "Tonny";
        String name4 = "Tonny";
        //todo:  why we use compareTo , when this is giving ans !
        if(name3 == name4){
            System.err.println("String is Equal");
        }else{
            System.err.println("String is not Equal");
        }





        /* Because in java string are objects, so there are many edge cases where your
            name1 == name2  //! gives error
            so the ans will be clear when we see STRING BUILDER CLASS       
            
            Q: then you will also know why we introduce SBC when we already have {String} class
        */
        if(new String("Tonny") == new String("Tonny")){
            System.err.println("String is Equal");
        }else{
            System.err.println("String is not Equal");
        }
    }
}
