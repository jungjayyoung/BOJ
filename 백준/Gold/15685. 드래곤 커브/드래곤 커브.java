import java.io.*;
import java.util.*;



public class Main {

	static int n;
	static int board[][] = new int[101][101];
	static List<Integer> dir_list;
	static List<Integer> origin;
	static int dx[] = {-1,0,1,0};
	static int dy[] = {0,1,0,-1};
	
	
	public static void main(String[] args) throws IOException{
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		
		n = Integer.parseInt(br.readLine());
		
		
		for(int i = 0; i < n; i++) {
			
			st = new StringTokenizer(br.readLine()," ");
			int xx,yy,d,g;
			dir_list = new ArrayList<>();
			origin = new ArrayList<>();
			
			xx = Integer.parseInt(st.nextToken());
			yy = Integer.parseInt(st.nextToken());
			d = Integer.parseInt(st.nextToken());
			g = Integer.parseInt(st.nextToken());
			
			
			
			dir_list.add(d); //  방향을 집어넣는다.
			origin.add(d);
			//세대 만큼 돌린다.
			
			int nextx = xx;
			int nexty = yy;
			int dir;
			board[yy][xx] = 1; 
			// 0 세대부터 시작
			// 스타트 위치는 갱신만 해주고 방향만 리스트에 집어넣는다.
			for(int j = 0; j<g + 1; j++) {
				
				
				
				for(int k = 0; k < dir_list.size(); k++) {
					
					dir = dir_list.get(k);
					
					if(dir == 0) { // 오른쪽
						nextx = nextx + 1;
					}else if(dir == 1) { // 위쪽
						nexty = nexty - 1;
					}else if(dir == 2) { // 왼쪽
						nextx = nextx - 1;
					}else if(dir == 3) { // 아래쪽
						nexty = nexty + 1;
					}
					board[nexty][nextx] = 1;
					
					
				}
				
				int cur_size = origin.size();
				for(int k = cur_size - 1; k >= 0; k--) {
					
					int dd = origin.get(k);
					
					int cnt = 0;
					while(true) {
						
						if(cnt >= 2) {
							break;
						}
						dd--;
						if(dd < 0) {
							dd = 3;
						}
						
						cnt++;
					}
					dd--;
					if(dd < 0) {
						dd = 3;
					}
					origin.add(dd);
				}
				
				
				dir_list.clear();
				
				for(int k = origin.size() / 2; k < origin.size(); k++) {
					dir_list.add(origin.get(k));
				}
				
				

				
			}
			
			
		}
		
		int cnt = 0;
		for(int y = 0; y <= 99; y++) {
			
			for(int x = 0; x <= 99; x++) {
				if(board[y][x] == 1 && board[y][x + 1] == 1
						&& board[y + 1][x] == 1 && board[y + 1][x + 1] == 1) {
					cnt++;
				}
			}
			
		}
		
		System.out.println(cnt);

	}

}
