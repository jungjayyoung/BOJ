import java.util.*;
import java.io.*;

public class Main {

	public static void main(String[] args) throws IOException{
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		//StringTokenizer st = new StringTokenizer(bf.readLine()," ");
		
		
		int n = Integer.parseInt(bf.readLine());
		int [] arr = new int[n + 1];
		
		StringTokenizer st = new StringTokenizer(bf.readLine());
		for(int i=1; i<=n; i++) {
			
			arr[i] = Integer.parseInt(st.nextToken());
		}
		
		
		int a = Integer.parseInt(bf.readLine());
		
		for(int i = 0 ; i<a; i++) {
			int b,c;
			st = new StringTokenizer(bf.readLine());
			b = Integer.parseInt(st.nextToken());
			c = Integer.parseInt(st.nextToken());
			if(b == 1) {
				for(int j = 1; j <= n; j++) {
					if(j % c == 0) {
						if(arr[j] == 1) {
							arr[j] = 0;
						}else if(arr[j] == 0) {
							arr[j] = 1;
						}
					}
				}
				
			}else if(b ==2) {
				
				int start = c;
				int end = c;
				
				while(start - 1>= 1 && end + 1 <= n) {
					
					if(arr[start - 1] == arr[end + 1]) {
						start = start - 1;
						end = end + 1;
					}else {
						break;
					}
				}
				
				for(int j = start; j<=end; j++) {
					if(arr[j] == 1) {
						arr[j] = 0;
					}else if(arr[j] == 0){
						arr[j] = 1;
					}
				}
				
			}
		}
		
		for(int i = 1; i<=n;i++) {
			System.out.print(arr[i] + " ");
			
			if((i % 20) == 0) {
				System.out.println();
			}
		}
		
		
	}

}
