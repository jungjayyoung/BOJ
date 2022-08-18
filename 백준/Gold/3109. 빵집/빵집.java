import java.io.*;
import java.util.*;

public class Main {
	
	static int r, c;
	static char [][] board;
	static boolean [][] visited;
	static int []dx = {1,1,1};
	static int []dy = {-1,0,1};
	static int ans = 0;
	static boolean check = false;
	
	static void dfs(int x, int y) {
		
		
		visited[y][x] = true;
		
		
		if(x == c - 1) {
			ans++;
			check = true;
			return;
		}
		
		
		for(int i = 0; i <3; i++) {
			int nextx = x + dx[i];
			int nexty = y + dy[i];
			
			if(nextx < 0 || nexty < 0 || nextx >= c || nexty >= r) continue;
			
			if(board[nexty][nextx] == '.' && !visited[nexty][nextx]) {
				
				dfs(nextx,nexty);
				if(check) return;
			}
			
		}
		
		
	}
	

	public static void main(String[] args) throws IOException{

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		
		st = new StringTokenizer(br.readLine()," ");
		r = Integer.parseInt(st.nextToken());
		c = Integer.parseInt(st.nextToken());
		
		visited = new boolean[r][c];
		board = new char[r][c];
		
		for(int y = 0; y < r; y++) {
			String s = br.readLine();
			for(int x = 0; x < c; x++) {
				
				board[y][x] = s.charAt(x);
				
			}
		}
		
		
	   for(int y = 0; y <r; y++) {
		   check = false;
			dfs(0,y);
	
		}
		
		
	   System.out.println(ans);
		
		
		br.close();
	}
	


}
