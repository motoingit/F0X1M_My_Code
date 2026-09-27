package Course;

public class Course{
   public String courseID;
   public String courseName;
   public Integer courseCredit;

   public Course(){
      courseID = "NULL";
      courseName = "NULL";
      courseCredit = 0;
   }
   public Course(String id, String name, int credit){
      courseID = id;
      courseName = name;
      courseCredit = credit;
   }

   public String getCourseInfo(){
      return courseID;
   }
}
