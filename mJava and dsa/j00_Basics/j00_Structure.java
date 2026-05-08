
/*
    Java code is written inside a class, and on that class we have to make the Main fuction.

    for ex :

        ///*folderName
        package folderName;
            ///! class mendatory
            class file_name{
                ///todo:mainFuc
                public static void main(String[] args){
                    ///? Your logical code
                }
            }
*/


package j00_Basics;

public class j00_Structure {     //same as file name
    public static void main(String[] args) { //*     main function
        System.out.println("Hello World"); //?    System is inbuild class
    }
}



/*
    //* JDK (Java devlopment kit) === JRE + compiler (javac) + tools (debugger, javadoc, etc.)
    //* JRE (Java Runtime Environment) === JVM + core libraries (java.lang, java.util, etc.)
    //* JVM (Java Virtual Machine) === Executes bytecode, manages memory, performs JIT compilation

                ///todo:    JDK ---> JRE ---> JVM 
    ///? Source Code (.java) -->  javac (part of JDK) ->> Bytecode (.class)


    #Compilation:
        sourcecode -> compiler(JDK) -> ByteCode.class
    #Execution:
        ByteCode -> Binary (NativeCode)

*/

//! flow of java program from born to death
/*
SOURCE CODE (.java)
      |
      |  <-- SYNTAX ERROR happens HERE
      |      (before compiler even starts working)
      |      e.g. missing semicolon, wrong brackets
      ↓
  COMPILER (JDK/javac)
      |
      |  <-- COMPILE TIME ERROR happens HERE
      |      (compiler understands syntax but finds logical issues)
      |      e.g. type mismatch, undeclared variable,
      |           incompatible types, missing method
      ↓
  BYTECODE (.class)
      |
      |      (this file is clean, no errors survived)
      ↓
    JVM
      |
      |  <-- RUNTIME ERROR happens HERE
      |      (everything looked fine but blew up during execution)
      |      e.g. NullPointerException, ArrayIndexOutOfBounds,
      |           divide by zero, StackOverflow
      ↓
   OUTPUT
*/
