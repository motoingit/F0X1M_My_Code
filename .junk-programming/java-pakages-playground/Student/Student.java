package Student;

public class Student{
   public String studentID;
   public String studentName;
   public Integer studentAge;

   public Student(){
      studentID = "NULL";
      studentName = "NULL";
      studentAge = 0;
   }
   public Student(String id, String name, int age){
      studentID = id;
      studentName = name;
      studentAge = age;
   }

   public String getStudentInfo(){
      return studentID;
   }
}
