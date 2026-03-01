class Moto1{
	public static int add(int a, int b){
		return a+b;
	}
	public static void main(String args[] ){
		int a = Integer.parseInt(args[0]);
		int b = Integer.parseInt(args[1]);
		System.out.println("Addition of "+a+" and " + b + " is " + add(a,b));
	}
}

/*
	javac .\sample3.java  
	java Moto1 100 200

	output : Addition of 100 and 200 is 300
*/
