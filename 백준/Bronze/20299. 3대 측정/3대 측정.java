
import java.io.*;
import java.util.*;

public class Main {
	
	static int n,s,m; // 동아리 수, 3명 능력합, 개인능력조건
	static ArrayList<int[]> club = new ArrayList<>();
	static int ans = 0;
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		st = new StringTokenizer(br.readLine()," ");
		
		n = Integer.parseInt(st.nextToken());
		s = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		
		
		
		for(int i = 0; i< n; i++) {
			int a,b,c;
			int sum = 0;
			st = new StringTokenizer(br.readLine()," ");
			
			a = Integer.parseInt(st.nextToken());
			b = Integer.parseInt(st.nextToken());
			c = Integer.parseInt(st.nextToken());
			
			
			// a,b,c 3명의 능력 합을 sum 에 저장한다.
			sum = a + b + c;
			// 1. 능력 합이 s를 넘기지 못하면 continue
			if(sum < s) continue;
			
			// 2. 개인 별 능력치가 m을 넘지 못하는 팀원이 있으면 continue
			if(a < m || b < m || c < m) continue;
			
			// 3. 조건을 만족하면 club에 3명을 추가한다.
			club.add(new int[] {a,b,c});
			ans++;
		}
		
		// 4. 조건을 만족하는 동아리 수 출력
		System.out.println(ans);
		
		// 5. 각 동아리별 동아리 원 능력치 출력
		for(int i = 0; i < club.size(); i++) {
			int tmp[] = club.get(i);
			System.out.print(tmp[0] + " " + tmp[1] + " " + tmp[2] + " ");
		}
		

	}

}
