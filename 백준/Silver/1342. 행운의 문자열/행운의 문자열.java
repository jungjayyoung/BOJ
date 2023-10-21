
import java.io.*;
import java.util.*;


public class Main {

	static char[] c; 
	static String s;
	static int[] visited;
	static int cntt = 0;
	
	public static void main(String[] args) throws IOException{
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		s = br.readLine();
		c = s.toCharArray();
		visited = new int[s.length()];
		
		Arrays.sort(c);
		do {
			
			boolean check = false;
			
			for(int i = 1; i < s.length();i++) {
				
				if(c[i-1] == c[i]) {
					check = true;
					break;
				}
				
			}
			
			if(!check) {
				cntt++;
			}
			
			
		}while(nextPermutation(c));
		
		
		
		System.out.println(cntt);
	}
	
	static boolean nextPermutation(char[] str) {
		
		int i = s.length() - 1;
		
		while(i > 0 && str[i-1] >= str[i]) i--;
		
		if(i == 0) {
			return false;
		}
		
		int j = s.length() - 1;
		while(str[i-1] >= str[j]) j--;
		
		swap(str, i-1 ,j);
		
		int k = s.length() - 1;
		
		
		while(i < k) swap(str,i++,k--);
		
		return true;
		
	}
	
	public static void swap(char[] c,int i, int j) {
		
		char tmp = c[i]; c[i] = c[j]; c[j] = tmp;
		
	}

}
