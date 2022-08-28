import java.io.*;
import java.util.*;

public class Main {
	static int n, m;
	
	static List<Integer>[] arr;
	static int visited[];
	static int cnt =0;
	static boolean check = false;
	
	static void dfs(int cur,int cnt) {
		
		visited[cur] = 1;
		if(cnt == 4) {
			check = true;
			return;
		}
		
		for(int i = 0; i < arr[cur].size();i++) {
			int next = arr[cur].get(i);
			if(visited[next] == 0) {
				dfs(next,cnt + 1);
				if(check) return;
			}
			
			
		}
		visited[cur] = 0;
		
	}

	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		st = new StringTokenizer(br.readLine()," ");
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		
		arr = new List[n];
		
		for(int i =0; i<n;i++) {
			arr[i] = new ArrayList<Integer>();
		}
		
		for(int i = 0; i < m; i++) {
			st = new StringTokenizer(br.readLine()," ");
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			arr[a].add(b);
			arr[b].add(a);
		}
		
		for(int i = 0; i<n; i++) {
			cnt =0;
			visited = new int[n];
			dfs(i,0);
			if(check) {
				break;
			}
			
		}
		
		if(check) {
			System.out.println(1);
		}else
			System.out.println(0);

	}

}
