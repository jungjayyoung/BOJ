import java.util.*;
import java.io.*;

public class Main {

	static int n,m;
	static int student[][];
	
	
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
	
		st = new StringTokenizer(br.readLine()," ");
		
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		
		student = new int[n+1][n+1];
		
		for(int i = 1; i <=n; i++) {
			
			for(int j = 1; j <=n; j++) {
				if(i == j) {
					student[i][j] = 0;
				}else {					
					student[i][j] = 10000000;
				}
			}
		}
		
		
		for(int i = 0; i <m; i++) {
			st = new StringTokenizer(br.readLine()," ");
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			
			student[a][b] = 1;
			
		}
		
		for(int k = 1; k <= n; k++) {
			for(int i = 1; i <=n; i++) {
				for(int j = 1; j <=n; j++) {
					student[i][j] = Math.min(student[i][j], student[i][k] + student[k][j]);
				}
			}
		}
		int ans = 0;
		
		for(int i = 1; i <= n; i++) {
			int cnt = 0;
			
			for(int j = 1; j <=n; j++) {
				
				if(student[i][j] != 10000000 || student[j][i] != 10000000) {
					cnt++;
				}
			}
			if(cnt == n) {
				ans++;
			}
		}
		
		System.out.println(ans);

	}

}
