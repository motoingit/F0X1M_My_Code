public class j02_substring{
    public static void main(String[] args) {
        String sentence = "My_Name";

        // substring [inclusive_st, exclusive_end)
        String name = sentence.substring(3, sentence.length()); // [Name]
        //* substring(st)    here end = sentence.length()   automaticaly
        System.out.println(name);


        //! strings are immutable
    }
}

