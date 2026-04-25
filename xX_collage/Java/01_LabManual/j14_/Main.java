import java.util.Scanner;
import Course.Course;
import Enrollment.Enrollment;
import Student.Student;

public class Main{
    public static void main(String[] args) {
        Enrollment myEnrollment = new Enrollment();
        Scanner sc = new Scanner(System.in);

        int courseCMD = 0;
        System.out.println("Choose your Course ! ");
        System.out.println("[1] B.Tech\t|\t[2] BCA");
        courseCMD = sc.nextInt();

        Course myCourse;
        switch (courseCMD) {
            case 1:
                System.out.println("B.Tech is Choosen !");
                myCourse = new Course("B-100", "btech", 10);
                myEnrollment.courseReference = myCourse;
                break;
                
                case 2:
                    System.out.println("BCA is Choosen !");
                    myCourse = new Course("B-101", "bca", 6);
                    break;
                    
                default:
                    System.out.println("Wrong Input !");
                    myCourse = null;
                    break;
        }
        if (myCourse == null) {
            System.err.println("You cannot Proceed !");
            return;
        }
        myEnrollment.courseReference = myCourse;
        
        System.out.println("Enter YOur student Details : ");
        String currName = sc.next();
        String currID = sc.next();
        int currAge = sc.nextInt();

        Student myStudent = new Student(currID, currName, currAge);
        
        //Enrol
        myEnrollment.courseReference = myCourse;
        myEnrollment.studentReference = myStudent;
        
    
        //show
        System.out.println("Your Course Details :");
        System.out.println(myEnrollment.courseReference.courseID);
        System.out.println(myEnrollment.courseReference.courseName);
        System.out.println(myEnrollment.courseReference.courseCredit);
        System.out.println("Your Details :");
        System.out.println(myEnrollment.studentReference.studentID);
        System.out.println(myEnrollment.studentReference.studentName);
        System.out.println(myEnrollment.studentReference.studentAge);

        sc.close();
    }
}
