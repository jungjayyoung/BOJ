
import java.io.*;
import java.util.*;



public class Main {

	static int n,m,r;
	static int board[][];
	static int dx[] = {0,1,0,-1};
	static int dy[] = {1,0,-1,0};
	
	
	

    // 재귀를 사용하여 배열을 돌리는 방법!
	static void rotate(int y1, int x1, int y2, int x2) {
		
		if(y1 >= y2 || x1 >= x2) return;
		
		int tmp = board[y1][x1];
		for(int x =x1; x < x2; x++) board[y1][x] = board[y1][x+1];
		for(int y = y1; y < y2; y++) board[y][x2] = board[y+1][x2];
		for(int x = x2; x > x1; x--) board[y2][x] = board[y2][x-1];
		for(int y = y2; y > y1; y--) board[y][x1] = board[y - 1][x1];
		board[y1 + 1][x1] = tmp;
		rotate(y1+1,x1+1,y2-1,x2-1);
		
	}
	
	public static void main(String[] args) throws IOException{

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		
		st = new StringTokenizer(br.readLine()," ");
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		r = Integer.parseInt(st.nextToken());
		
		
		board = new int[n+1][m+1];

		
		for(int y = 1; y <=n; y++) {
			
			st = new StringTokenizer(br.readLine()," ");
			for(int x = 1; x <= m; x++) {
				board[y][x] = Integer.parseInt(st.nextToken());
			}
		}
		
		for(int i=0; i<r;i++) {
			rotate(1,1,n,m);
		}
		
		

		for(int y = 1; y <= n; y++) {
			
			for(int x = 1; x <= m; x++) {
				System.out.print(board[y][x] + " ");
			}
		
			System.out.println();
		
		}

	}
}
