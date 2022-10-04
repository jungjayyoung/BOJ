import java.io.*;
import java.util.*;

public class Main {

	static int board[][] = new int[10][10];
	static int n;
	static int row[][] = new int[10][10];
	static int col[][] = new int[10][10];
	static ArrayList<int[]> pos = new ArrayList<>();
	
	
	static boolean check(int x,int y,int num) {
		
		int cx = 3 * (x / 3);
		int cy = 3 * (y / 3);
		
		for(int yy = cy; yy < cy + 3; yy++) {
			
			for(int xx = cx; xx < cx + 3; xx++) {
				
				if(board[yy][xx] == num) {
					
					return false;
				}
				
			}
		}
		
		return true;
		
		
	}
	
	static void bt(int cnt) {
		
		if(cnt >= n) {
			for(int y = 0; y < 9; y++) {
				
				for(int x = 0; x < 9; x++) {
					System.out.print(board[y][x]);
				}
				System.out.println();
			}
			
			System.exit(0);
		}
		
		int []cur = pos.get(cnt);
		int curx = cur[0];
		int cury = cur[1];
		
		for(int i = 1; i <= 9; i++) {
			
			if(row[cury][i] == 1 || col[curx][i] == 1) continue;
			
			if(check(curx,cury,i)) {
				board[cury][curx] = i;
				row[cury][i] = 1;
				col[curx][i] = 1;
				bt(cnt+1);
				board[cury][curx] = 0;
				row[cury][i] = 0;
				col[curx][i] = 0;
				
			}
			
			
		}
		
	}
	
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		int cnt = 0;
		
		for(int y = 0; y < 9; y++) {
			String str = br.readLine();
			
			for(int x = 0; x < 9; x++) {
				board[y][x] = str.charAt(x) - '0';
				if(board[y][x] == 0) {
					cnt++;
					pos.add(new int[] {x,y});
				}
				row[y][board[y][x]] = 1;
				col[x][board[y][x]] = 1;
			}
		}
		
		
		n = cnt;
		
		
		bt(0);
		
		
		
		

	}

}
