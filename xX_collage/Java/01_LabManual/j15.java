/* Ques: ExceptionHandling 
      Condition :
         Name first letter should be caps
         eID should b/w 2001 to 5000
         dID should b/w 1 to 5
*/ 

public class j15{
   public static Boolean checkCaps(String str){
      if( str == null){
         System.out.println("Error ");
      }else if(str.length() > 0){
         if(str.charAt(0) <= 90){
            return true;
         }else{
            return false;
         }
      }

      return false;
   }
   public static void main(String[] args) {
      Employee emp1 = null;

      // for input condition
      try{
         emp1 = new Employee("John Doe", 2001, 4);
         if(emp1.departmentID < 1 || emp1.departmentID > 5){
            throw new IllegalArgumentException("Department ID must be between 1 and 5.");
         }else if(emp1.employeeID < 2001 || emp1.employeeID > 5000){
            throw new IllegalArgumentException("Employee ID must be between 2001 and 5000");
         }else if(!checkCaps(emp1.employeeName)){
            throw new IllegalArgumentException("First cpas please");
         }
         //else no worry
      } catch (IllegalArgumentException e) {
         System.err.println("Error : " + e.getMessage());
      }

      //details
      System.err.println(emp1.employeeName);
      System.err.println(emp1.employeeID);
      System.err.println(emp1.departmentID);


   }
}

class Employee{
   public String employeeName;
   public Integer employeeID;
   public Integer departmentID;

   // Employee(){
   //    this.employeeName = "Unknown";
   //    this.employeeID = 0;
   //    this.departmentID = "Unknown";
   // }

   Employee(String name, Integer id, Integer did){
      this.employeeName = name;
      this.employeeID = id;
      this.departmentID = did;
   }
}
