package Enrollment;

import Course.Course;
import Student.Student;

public class Enrollment {
   public String enrollmentID;
   public Student studentReference;
   public Course courseReference;

   public Enrollment(){
      enrollmentID = "NULL";
      studentReference = null;
      courseReference = null;
   }

   public Enrollment(String id, Student student, Course course){
      enrollmentID = id;
      studentReference = student;
      courseReference = course;
   }

   public String getEnrollmentDetails(){
      return enrollmentID;
   }
}
