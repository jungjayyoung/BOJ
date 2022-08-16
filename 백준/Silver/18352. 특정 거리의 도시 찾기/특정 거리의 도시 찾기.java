import java.io.*;
import java.util.*;


public class Main {
	static int n, m, k, x;
	
	static List<Integer>[] g;
	static int[] dist;
	static int[] visited;
	
	
	static void bfs() {
		
		Queue<int[]> q = new ArrayDeque<int[]>();
		q.offer(new int[]{x,0});
		visited[x] = 1;
		
		while(!q.isEmpty()) {
			
			int[] pos = q.poll();
			int cur_city = pos[0];
			int cnt = pos[1];
			
			dist[cur_city] = cnt;
			
			
			for(int i = 0; i<g[cur_city].size();i++) {
				int next = g[cur_city].get(i);
				
				if(visited[next] == 0) {
					visited[next] = 1;
					q.offer(new int[] {next,cnt + 1});
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
		k = Integer.parseInt(st.nextToken());
		x = Integer.parseInt(st.nextToken());
		
		g = new List[n + 1];
		dist = new int[n + 1];
		visited = new int[n + 1];
		
		// null pointer 가 안만들어지게 객체부터 생성
		for(int i =0; i<=n; i++) {
			g[i] = new ArrayList<Integer>();
		}
		
		for(int i = 0; i < m; i++) {
			st = new StringTokenizer(br.readLine(), " ");
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			g[a].add(b);
			
		}
		
		bfs();
		
		boolean check = false;
		
		for(int i =1; i<= n; i++) {
			
			if(dist[i] == k) {
				
				System.out.println(i);
				check = true;
			}
			
			
		}
		if(!check) {
			System.out.println(-1);
		}
		
		
		
	}

}
