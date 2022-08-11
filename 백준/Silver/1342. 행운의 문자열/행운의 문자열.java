import java.io.*;
import java.util.*;


public class Main {

	static List<Character> c; 
	static String s;
	static int[] visited;
	static int cntt = 0;
	static int[] alp = new int[27];
	
	static void bt(int cnt,String str) {
		
		if(cnt == s.length()) {
			
			boolean check = false;
			
			for(int i = 1; i < str.length();i++) {
				
				if(str.charAt(i) == str.charAt(i-1)) {
					check = true;
					break;
				}
			}
			
			if(!check) {
				cntt++;
			}
			
			return;
		}
		
		
		
		for(int i = 0; i < s.length(); i++) {

			if(visited[i] == 0) {
				
				visited[i] = 1;
				String tmp = str;
				tmp = tmp + c.get(i);
				bt(cnt +1,tmp);
				visited[i] = 0;
			}
			
			
		}
		
		
	}
	
	public static void main(String[] args) throws IOException{
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		s = br.readLine();
		c = new ArrayList<Character>();
		visited = new int[s.length()];
		
		for(int i = 0; i < s.length();i++) {
			
			c.add(s.charAt(i));
			alp[s.charAt(i) - 'a']++;
		}
		
		bt(0,"");

		
		for(int i = 0; i <27;i++) {
			
			if(alp[i] > 1) {
				cntt /= factorial(alp[i]);
			}
			
		}
		System.out.println(cntt);
	}
	
	static int factorial(int n) {
		
		if(n == 1) {
			return 1;
		}
		
		return n * factorial(n-1);
	}

}
