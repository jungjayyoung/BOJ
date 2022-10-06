
import java.io.*;
import java.util.*;

public class Main {
	
	static int n,m;
	static char [][] board;
	static boolean [][][] visited;
	static int dx[] = {0,1,0,-1};
	static int dy[] = {1,0,-1,0};
	static Queue<int[]> q = new ArrayDeque<>();
	
	static int bfs() {
		
		
		while(!q.isEmpty()) {
			
			
			int cur[] = q.poll();
			int curx = cur[0];
			int cury = cur[1];
			int key = cur[2];
			int cnt = cur[3];
			
			if(board[cury][curx] == '1') {
				
				
				return cnt;
			}
			
			
			for(int i = 0; i < 4; i++) {
				int nx = curx + dx[i];
				int ny = cury + dy[i];
				
				if(ny < 0 || nx < 0 || ny >= n || nx >=m || board[ny][nx] == '#') continue;
				
				
				if(!visited[ny][nx][key]) {

					
					if(board[ny][nx] == '.' || board[ny][nx] == '1' || board[ny][nx] == '0') {

						visited[ny][nx][key] = true;
						q.add(new int[] {nx,ny,key,cnt+1});
						
					}else if(board[ny][nx] >= 'a' && board[ny][nx] <= 'f') {

						int newKey = 1 << ((int)board[ny][nx] - 'a');
						int flag = key | newKey;
						visited[ny][nx][flag] = true;
						q.add(new int[] {nx,ny,flag,cnt+1});
					}else if(board[ny][nx] >= 'A' && board[ny][nx] <= 'F') {
						
						int newKey = 1 << ((int)board[ny][nx] - 'A');
						int flag = key & newKey;
						if(flag != 0) {

							visited[ny][nx][key] = true;
							q.add(new int[] {nx,ny,key,cnt+1});
						}
						
						
						
					}
					
					
				}
			}
			
		}
		
		
		return -1;
	}

	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		
		st = new StringTokenizer(br.readLine()," ");
		
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		
		board = new char[n][m];
		visited = new boolean[n][m][1 << 6 + 1];
		
		for(int y = 0; y < n; y++) {
			String str = br.readLine();
			for(int x = 0; x <m; x++) {
				board[y][x] = str.charAt(x);
				if(board[y][x] == '0') {
					q.add(new int[]{x,y,0,0}); // x,y,현재 열쇠상태,움직인 횟수
					visited[y][x][0] = true;
				}
			}
		}
		
		System.out.println(bfs());

	}

}
