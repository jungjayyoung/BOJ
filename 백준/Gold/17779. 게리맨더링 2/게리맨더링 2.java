import java.io.*;
import java.util.*;

public class Main {
	static int n;
	static int[][] board;
	static int[][] boardLine;
	static int dx[] = {-1,0,1,0};
	static int dy[] = {0,1,0,-1};
	static int ans =123456789;

	static void solve(int x,int y,int d1,int d2) {
		
		// 경계선 만들기
		int d1_cnt = 1;
		int d2_cnt = 1;
		
		boardLine[x][y] = 5;
		// 1번 경계선
		while(d1_cnt <= d1 && d2_cnt <= d2) {	
			boardLine[x + d1_cnt][y - d1_cnt] = 5;
			d1_cnt++;
		}
		
		d1_cnt = 1;
		d2_cnt = 1;
		// 2번 경계선
		while(d1_cnt <= d1 && d2_cnt <= d2) {	
			boardLine[x + d2_cnt][y + d2_cnt] = 5;
			d2_cnt++;
		}
		
		d1_cnt = 1;
		d2_cnt = 1;
		//3번 경계선
		while(d1_cnt <= d1 && d2_cnt <= d2) {	
			boardLine[x + d1 + d2_cnt][y - d1 + d2_cnt] = 5;
			d2_cnt++;
		}
		
		
		d1_cnt = 1;
		d2_cnt = 1;
		//4 번 경계선
		while(d1_cnt <= d1 && d2_cnt <= d2) {	
			boardLine[x + d2 + d1_cnt][y + d2 - d1_cnt] = 5;
			d1_cnt++;
		}
		
		boolean check = false;
		int arr[] = new int[n + 1];
		
		for(int yy = 1; yy <= n; yy++) {
			int five_cnt = 0;
			for(int xx = 1; xx <= n; xx++) {
				if(boardLine[yy][xx] == 5) {
					five_cnt++;
				}
				
			}
			if(five_cnt == 2) {
				arr[yy] = 1;
			}
		}
		
		for(int yy = 1; yy <= n; yy++) {
			for(int xx = 1; xx <=n; xx++) {
				
				if(arr[yy] == 1) {
					if(boardLine[yy][xx] == 5) {
						if(check)
							check = false;
						else
							check = true;
					}
					
					if(boardLine[yy][xx] == 0 && check) {
						boardLine[yy][xx] = 5;
					}
					
				}
				
			}
			
			
		}
			
		// 1번 선거구
		for(int yy = 1; yy < x + d1; yy++) {
			for(int xx = 1; xx <= y; xx++) {
				if(boardLine[yy][xx] == 5) continue;
				boardLine[yy][xx] = 1;
			}
		}
		
		// 2번 선거구
		for(int yy = 1; yy <= x + d2; yy++) {
			for(int xx = y+1; xx <= n; xx++) {
				if(boardLine[yy][xx] == 5) continue;
				boardLine[yy][xx] = 2;
			}
		}

		// 3번 선거구
		for(int yy = x + d1; yy <= n; yy++) {
			for(int xx = 1; xx < y -d1 + d2; xx++) {
				if(boardLine[yy][xx] == 5) continue;
				boardLine[yy][xx] = 3;
			}
		}
		// 4번 선거구
		for(int yy = x + d2 + 1; yy <= n; yy++) {
			for(int xx = y - d1 + d2; xx <= n; xx++) {
				if(boardLine[yy][xx] == 5) continue;
				boardLine[yy][xx] = 4;
			}
		}
		
		int one = 0;
		int two = 0;
		int three = 0;
		int four = 0;
		int five = 0;
		int maxx = -1;
		int minn = 123456789;
		for(int yy = 1; yy <=n; yy++) {
			for(int xx = 1; xx <=n; xx++) {
				if(boardLine[yy][xx] == 1) {
					one += board[yy][xx];
				}else if(boardLine[yy][xx] == 2) {
					two += board[yy][xx];
				}else if(boardLine[yy][xx] == 3) {
					three += board[yy][xx];
				}else if(boardLine[yy][xx] == 4) {
					four += board[yy][xx];
				}else if(boardLine[yy][xx] == 5) {
					five += board[yy][xx];
				}
				
			}		
		}
		
		maxx = Math.max(Math.max(Math.max(Math.max(one, two), three), four), five);
		minn = Math.min(Math.min(Math.min(Math.min(one, two), three), four), five);
		ans = Math.min(ans, maxx - minn);
		
		
	}
	

	public static void main(String[] args) throws IOException{

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		n = Integer.parseInt(br.readLine());
		
		board = new int[n+1][n+1];
		boardLine = new int[n+1][n+1];
		
		for(int y = 1; y <= n; y++) {

			st = new StringTokenizer(br.readLine()," ");
			for(int x = 1; x <= n; x++) {
				board[y][x] = Integer.parseInt(st.nextToken());
			}
		}
		
		
		for(int y = 1; y <=n; y++) {
			
			for(int x = 1; x <= n; x++) {
				
				for(int d1 = 1; x + d1 <= n; d1++) {
					
					for(int d2 = 1; y + d2 <= n; d2++) {
						
						if((y + d1 + d2 > n) || (x + d2 > n) || (x - d1 < 1)) continue;
						for(int[]a : boardLine) {
							Arrays.fill(a, 0);
						}
						
						solve(y,x,d1,d2);
					
					}
					
				}
				
				
			}
		}
		
		System.out.println(ans);
		
		
	}

}
