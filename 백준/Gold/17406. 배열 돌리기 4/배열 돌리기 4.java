import java.io.*;
import java.util.*;


public class Main {

	
	static int n,m,k;
	static int[][] board;
	
	static int[] visited;
	// 동,남,서,북
	static int[] dx = {1,0,-1,0};
	static int[] dy = {0,1,0,-1};
	static List<int[]> arr = new ArrayList<int[]>();
	static int ans = 123456789;
	
	
	static void turn(int rr,int cc, int ss, int board3[][],int copy_board[][]) {
		
		
		int turn_cnt = ((rr + ss) -(rr - ss)) / 2;
		//회전하는 배열의 겹친 개수 만큼 각각 돌린다.
		for(int i = turn_cnt; i >= 1; i--) {
			int cur_x = cc - i;
			int cur_y = rr - i;
			int start_x = cur_x;
			int start_y = cur_y;
			
			
			//처음에 동에서 시작
			int cur_dir = 0;
			
			int nextx;
			int nexty;
			
			while(true) {
				
				nextx = cur_x + dx[cur_dir];
				nexty = cur_y + dy[cur_dir];
				

				board3[nexty][nextx] = copy_board[cur_y][cur_x];
				
				
				if(nextx == start_x && nexty == start_y) {
					break;
				}
				
				cur_x = nextx;
				cur_y = nexty;
				
				
				
				// 방향 바꾸기
				if((cur_x == cc - i && cur_y == rr + i) || (cur_x == cc + i && cur_y == rr + i) || (cur_x == cc + i && cur_y == rr - i) || (cur_x == cc - i && cur_y == rr - i)) {
					cur_dir++;
					if(cur_dir > 4) {
						cur_dir = 0;
					}
				}
				
				
			}
			
		}
		
		
	}
	
	
	static void bt(int cnt,int board2[][]) {
		
		
		if(cnt == k) {
			 //배열 최소값 계산
			for(int y = 1; y <=n; y++) {
				int sum = 0;
				for(int x = 1; x<=m; x++) {
					
					sum += board2[y][x];
				}
				
				ans = Math.min(ans, sum);
				
			}
			
			
			return;
		}
		int[][] copy_board  = new int[n+1][m+1];

		
		// 회전하기 전의 배열을 복사한다.
		for(int y = 1; y <=n; y++) {
			
			for(int x = 1; x <=m; x++) {
				copy_board[y][x] = board2[y][x];
			
			}
		}
		
		
		
		
		for(int i = 0; i<k; i++) {
			
			int[][] changed_board =new int[n+1][m+1];
			for(int y = 1; y <=n; y++) {
				
				for(int x = 1; x <=m; x++) {
					changed_board[y][x] = board2[y][x];
				
				}
			}

		
			if(visited[i] == 0) {
				visited[i] = 1;
				int rr,cc,ss;
				
				
				rr = arr.get(i)[0];
				cc = arr.get(i)[1];
				ss = arr.get(i)[2];
				
				//배열을 회전하는 함수
				turn(rr,cc,ss,changed_board,copy_board);
				
				
				// bt에 changed_board를 집어넣는다
				bt(cnt + 1,changed_board);
				

				visited[i] = 0;
				
				
				
			}
			
		}
		
	}
	
	
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		
		
		st = new StringTokenizer(br.readLine()," ");
		
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		k = Integer.parseInt(st.nextToken());
		
		board = new int[n + 1][m + 1];

		
		// 인덱스는 1,1 부터 시작
		for(int y =1; y <= n; y++) {
			
			st = new StringTokenizer(br.readLine(), " ");
			for(int x = 1; x <= m; x++) {
				
				board[y][x] = Integer.parseInt(st.nextToken());
			}
		}
		
		
		//arr 의 사이즈가 백트래킹의 for문 대상이 된다
		visited = new int[k];
		for(int i = 0; i < k;i++) {
			st = new StringTokenizer(br.readLine()," ");
			int r = Integer.parseInt(st.nextToken());
			int c = Integer.parseInt(st.nextToken());
			int s = Integer.parseInt(st.nextToken());
			arr.add(new int[] {r,c,s});
		}
		
		bt(0,board);
		
		System.out.println(ans);
		

	}

}
