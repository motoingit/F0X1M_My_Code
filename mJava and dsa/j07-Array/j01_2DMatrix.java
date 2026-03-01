import java.util.Scanner;

public class j01_2DMatrix {
    public static void main(String[] args){

        //! int arr[][] = new int[3][];
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), m = sc.nextInt();

        int arr[][] = new int[n][m];

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                arr[i][j] = sc.nextInt();
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                System.out.println(arr[i][j] + " ");
            }
            System.err.println();
        }

        sc.close();
    }
}