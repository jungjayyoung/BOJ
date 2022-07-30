
import java.util.Scanner;
import java.io.FileInputStream;

/*
   사용하는 클래스명이 Solution 이어야 하므로, 가급적 Solution.java 를 사용할 것을 권장합니다.
   이러한 상황에서도 동일하게 java Solution 명령으로 프로그램을 수행해볼 수 있습니다.
 */
class Solution
{
	public static void main(String args[]) throws Exception
	{
		
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();

        for (int tc = 1; tc <= t; tc++) {

            int n = sc.nextInt();

            int [][] board = new int [n][n];
            int[][] col = new int[n][n];
            int[][] row = new int[n][n];


            for (int y = 0; y < n; y++) {
                for (int x = 0; x < n; x++) {
                    board[y][x] = sc.nextInt();
                }
            }

            for (int y = 0; y < n; y++) {
                for (int x = 0; x < n; x++) {
                    row[y][x] = board[y][x];
                }
            }


            for (int x = 0; x < n; x++) {
                for (int y = 0; y < n; y++) {
                    col[x][y] = board[y][x];
                }
            }

            System.out.println("#" + tc);

            // 90, 180, 270 도

            for (int i = 0; i < n; i++) {

                for (int j = n - 1; j >= 0; j--) {
                    System.out.print(col[i][j]);
                }
                System.out.print(" ");

                for (int j = n - 1; j >= 0; j--) {
                    System.out.print(row[n - i - 1][j]);
                }
                System.out.print(" ");

                for (int j = 0; j < n; j++) {
                    System.out.print(col[n - i - 1][j]);
                }
                System.out.println();
                
            }


        }
	}
}