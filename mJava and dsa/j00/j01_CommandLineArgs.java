package j00;

public class j01_CommandLineArgs {
    public static int main(String[] args) {
        if(args.length < 4){
            return 404;
        }
        String name = args[0];  //* only single word is acceptable
        String course = args[1];
        int rollno = Integer.parseInt(args[2]);
        int sem = Integer.parseInt(args[3]);

        /* Is String is the non primitive type ? 
            Yes, its class based dataType
        */

        System.out.println("Name : "+name);
        System.out.println("Course : "+course);
        System.out.println("Roll No : "+rollno);
        System.out.println("Semester : "+sem);

        //!! String.valueOf(num);
        return 100;
    }
}

/*

if ($?) { javac j01_01_commandLineArgument.java } ; if ($?) { java j01_01_commandLineArgument Mohit B.Tech 35 4 }

*/
