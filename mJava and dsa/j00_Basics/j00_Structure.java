
/*
    Java code is written inside a class, and on that class we have to make the Main fuction.

    for ex :

        ///*folderName
        package folderName;
            ///!class mendatory
            public class file_name{
                ///todo:mainFuc
                public static void main(String[] args){
                    ///? Your rest code
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