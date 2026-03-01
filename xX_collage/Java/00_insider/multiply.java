
//Question : n= 5 print he table
class multiply{
	public static void main(String args[] ){
		int n = Integer.parseInt(args[0]);
		
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= 10; j++){
				System.out.println(i + " X " + j + " = " + (i*j));
			}
		}
	}
}	

/*
	javac .\multiply.java                                                           
	java multiply 2

1 X 1 = 1
1 X 2 = 2
1 X 3 = 3
1 X 4 = 4
1 X 5 = 5
1 X 6 = 6
1 X 7 = 7
1 X 8 = 8
1 X 9 = 9
1 X 10 = 10

2 X 1 = 2
2 X 2 = 4
2 X 3 = 6
2 X 4 = 8
2 X 5 = 10
2 X 6 = 12
2 X 7 = 14
2 X 8 = 16
2 X 9 = 18
2 X 10 = 20
*/
