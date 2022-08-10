import java.io.*;
import java.util.*;




public class Main {

	static int n,m,r;
	static int[][] board;
	
	
	static void solve(int num) {
		
		if(num == 1) {
			
			int[][] copy_board = new int[n][m];
			
			for(int y = 0; y < n; y++) {
				
				for(int x = 0; x <m; x++) {
					copy_board[y][x] = board[y][x];
				}
			}
			
			for(int i = 0; i < n; i++) {
				
				for(int j = 0; j < m; j++) {
					board[i][j] = copy_board[n - i - 1][j];
				}
			}
		
		}else if(num == 2) {
			int[][] copy_board = new int[n][m];
			
			for(int y = 0; y < n; y++) {
				
				for(int x = 0; x <m; x++) {
					copy_board[y][x] = board[y][x];
				}
			}
			
			for(int i =0; i < m; i++) {
				
				for(int j = 0; j < n; j++) {
					board[j][i] = copy_board[j][m - i - 1];
				}
			}
			
		}else if(num == 3) {
			
			int[][] copy_board = new int[n][m];
			
			for(int y = 0; y < n; y++) {
				
				for(int x = 0; x <m; x++) {
					copy_board[y][x] = board[y][x];
				}
			}
			board = new int[m][n];
			
			for(int y = 0; y < m; y++) {
				for(int x = 0; x < n; x++) {
					
					board[y][x] = copy_board[n - x - 1][y];
				}
			}
			
			int tmp = n;
			n = m;
			m = tmp;
		
		}else if(num == 4) {
			
			int[][] copy_board = new int[n][m];
			
			for(int y = 0; y < n; y++) {
				
				for(int x = 0; x <m; x++) {
					copy_board[y][x] = board[y][x];
				}
			}
			board = new int[m][n];
			
			for(int y = 0; y < m; y++) {
				for(int x = 0; x < n; x++) {
					
					board[y][x] = copy_board[x][m - y - 1];
				}
			}
			
			int tmp = n;
			n = m;
			m = tmp;
			
		}else if(num == 5) {
			
			int[][] copy_board = new int[n][m];
			
			for(int y = 0; y <n; y++) {
				for(int x =0; x <m; x++) {
					copy_board[y][x] = board[y][x];
				}
			}
			
			//1
			for(int y = 0; y < n / 2; y++) {
				
				for(int x = 0; x < m / 2; x++) {
					board[y][x] = copy_board[n / 2 + y][x];
				}
			}
			
			//2
			for(int y = 0; y < n / 2; y++) {
				
				for(int x = m / 2; x < m; x++) {
					board[y][x] = copy_board[y][x - m / 2 ];
				}
			}
			
			//3
			for(int y = n / 2; y < n; y++) {
				
				for(int x = m / 2; x < m; x++) {
					board[y][x] = copy_board[y - n / 2][x];
				}
			}
			
			//4
			for(int y = n / 2; y < n; y++) {
				for(int x = 0; x < m / 2; x++) {
					board[y][x] = copy_board[y][m / 2 + x];
				}
			}

			
			
		}else if(num == 6) {
			
			int[][] copy_board = new int[n][m];
			
			for(int y = 0; y <n; y++) {
				for(int x =0; x <m; x++) {
					copy_board[y][x] = board[y][x];
				}
			}
			
			//1
			for(int y = 0; y < n / 2; y++) {
				
				for(int x = 0; x < m / 2; x++) {
					board[y][x] = copy_board[y][x + m / 2];
				}
			}
			
			//2
			for(int y = 0; y < n / 2; y++) {
				
				for(int x = m / 2; x < m; x++) {
					board[y][x] = copy_board[y+ n / 2][x];
				}
			}
			
			//3
			for(int y = n / 2; y < n; y++) {
				
				for(int x = m / 2; x < m; x++) {
					board[y][x] = copy_board[y][x - m / 2];
				}
			}
			
			//4
			for(int y = n / 2; y < n; y++) {
				for(int x = 0; x < m / 2; x++) {
					board[y][x] = copy_board[y - n / 2][x];
				}
			}
			
		}
		
		
	}
	
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		st = new StringTokenizer(br.readLine()," ");
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		r = Integer.parseInt(st.nextToken());
		
		board = new int[n+1][m+1];
		for(int y = 0; y < n; y++) {
			
			st = new StringTokenizer(br.readLine()," ");
			
			for(int x = 0; x < m; x++) {
				
				board[y][x] = Integer.parseInt(st.nextToken());
				
			}
		}
		
		st = new StringTokenizer(br.readLine(), " ");
		for(int i = 0; i < r; i++) {
			int a = Integer.parseInt(st.nextToken());
			
			solve(a);
				
		}
		
		for(int y = 0; y < n; y++) {
			
			for(int x = 0; x < m; x++) {
				System.out.print(board[y][x] + " ");
			}
			System.out.println();
		}

	}

}
