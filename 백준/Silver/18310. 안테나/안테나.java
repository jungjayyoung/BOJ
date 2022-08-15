import java.io.*;
import java.util.*;



public class Main {

	static int[] arr;
	
	public static void main(String[] args) throws IOException{
		
	
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		int n = Integer.parseInt(br.readLine());
		arr = new int[n];
		st = new StringTokenizer(br.readLine()," ");
		
		
		for(int i = 0; i< n; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}
		
		Arrays.sort(arr);
		
		System.out.println(arr[(n - 1) / 2]);
		
		
		

	}

}
