import java.io.*;
import java.util.*;


public class Main {
	
	static int N,r,c;
	static int cnt = 0;
	
	
	static void solve(int x, int y, int n) {
		
		
		
		if(n == 1) {

			for(int i = y; i < y+1;i++) {
				for(int j = x; j < x+1;j++) {
					if(j == c && i == r) {
						System.out.println(cnt);
						System.exit(0);
					}
					cnt++;
				}
			
			}
			
			for(int i = y; i < y+1;i++) {
				for(int j = x + 1; j < x+2;j++) {
					if(j == c && i == r) {
						System.out.println(cnt);
						System.exit(0);
					}
					cnt++;
					
				}
			
			}
			
			for(int i = y + 1; i < y+2;i++) {
				for(int j = x; j < x+1;j++) {
					if(j == c && i == r) {
						System.out.println(cnt);
						System.exit(0);
					}
					cnt++;
				}
			
			}
			
			for(int i = y + 1; i < y+2;i++) {
				for(int j = x + 1; j < x+2;j++) {
					if(j == c && i == r) {
						System.out.println(cnt);
						System.exit(0);
					}
					cnt++;
				}
			
			}
			
			return;
		}
		
		
		if(c < x + (int)Math.pow(2, n) && r < y + (int)Math.pow(2, n) && c >= x && r >= y) {
			solve(x,y,n - 1);
			solve(x + (int)Math.pow(2,n - 1),y,n - 1);
			solve(x,y + (int)Math.pow(2,n - 1),n - 1);
			solve(x + (int)Math.pow(2,n - 1),y + (int)Math.pow(2,n - 1),n - 1);
		}else {
			
			cnt += (int)Math.pow(2, n) * (int)Math.pow(2, n);
		}
		
		
		
		
	}

	public static void main(String[] args) throws IOException{

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		st = new StringTokenizer(br.readLine(), " ");
		
		N = Integer.parseInt(st.nextToken());
		r = Integer.parseInt(st.nextToken());
		c = Integer.parseInt(st.nextToken());
		
			
		solve(0,0,N);
				
		
	
	}

}
