import java.io.*;
import java.util.*;

public class Main {
	
	static int n,m,k;
	static int[][] A;
	static Deque<Integer>[][] tree;
	static int[][] dead_tree;
	static List<Integer> tmp[][];
	static int dx[] = {-1,0,1,-1,1,-1,0,1};
	static int dy[] = {-1,-1,-1,0,0,1,1,1};
	static int[][] land; //현재 땅의 양분

	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		st = new StringTokenizer(br.readLine()," ");
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		int k = Integer.parseInt(st.nextToken());
		
		
		A = new int[n+1][n+1];
		land = new int[n+1][n+1];
		
		tree = new ArrayDeque[n+1][n+1];
		dead_tree = new int[n+1][n+1];
		tmp = new ArrayList[n+1][n+1];
		
		// x,y 좌표에 나무를 집어넣을 리스트를 만들어 준다.
		// 죽은 나무의 양분을 저장할 곳
		for(int i=0;i<n+1;i++) {
			for(int j=0;j<n+1;j++) {
				tree[i][j] = new ArrayDeque<>();
				tmp[i][j] = new ArrayList<>();
			}
		}
		
		// 겨울에 추가할 양분의 양 A[][] 배열을 입력받는다.
		for(int y = 1; y <= n; y++) {
			st = new StringTokenizer(br.readLine()," ");
			for(int x = 1; x <= n; x++) {
				A[y][x] = Integer.parseInt(st.nextToken());
			}
		}
		
		// x,y 좌표에 나무를 집어넣는다.
		// 나이순으로 정렬이 안된  tmp에 집어넣는다.
		for(int i =0; i < m; i++) {
			st = new StringTokenizer(br.readLine()," ");
			int a,b,c;
			a = Integer.parseInt(st.nextToken()); // y
			b = Integer.parseInt(st.nextToken()); // x
			c = Integer.parseInt(st.nextToken()); // 나이
			tmp[a][b].add(c);
		}
		
		// tmp 정렬 후 x,y 좌표 나무 덱에 집어넣기
		for(int y = 1; y<= n; y++) {
			for(int x = 1; x<= n; x++) {
				if(!tmp[y][x].isEmpty()) {
					Collections.sort(tmp[y][x]);
					for(int j = 0; j < tmp[y][x].size();j++) {
						tree[y][x].offerLast((tmp[y][x].get(j)));
					}
				}
			}
		}
		
		
		// 현재 땅의 양분
		for(int y = 1; y <= n; y++) {
			for(int x =1; x <= n; x++) {
				land[y][x] = 5;
			}
		}
		
		while(k > 0) {
			
			// 봄
			// 나이가 어린 나무부터 양분을 먹고 양분이 부족하면 그 나무는 죽는다.
			for(int y = 1; y <= n; y++) {
				
				for(int x = 1; x <= n; x++) {
					
					// 현재 땅에 나무가 존재
					if(!tree[y][x].isEmpty()) {
						int size = tree[y][x].size();
						
						for(int i = 0; i < size; i++) {
							int cur_age = tree[y][x].pollFirst();
							// 현재 나무의 나이보다 양분이 부족하다면
							if(land[y][x] < cur_age) {
								dead_tree[y][x] += cur_age / 2;
							// 양분이 존재 한다면
							}else {
								// 나이 만큼 양분이 감소
								land[y][x] -= cur_age;
								// 나이가 1 증가
								tree[y][x].offerLast(cur_age + 1);
							}
							
							
						}
		
						
					}
					
				}
			} ///////// 봄 끝
			
			// 여름
			for(int y = 1; y <= n; y++) {
				for(int x =1; x <= n; x++) {
					if(dead_tree[y][x] != 0) {
						// 죽은 나무 양분 추가하고 리스트 초기화
						land[y][x] += dead_tree[y][x];
						dead_tree[y][x] = 0;
					}
				}
			}
			
			// 가을
			for(int y = 1; y <=n;y++) {
				
				for(int x = 1; x <= n; x++) {
					
					if(!tree[y][x].isEmpty()) {
						
						int size = tree[y][x].size();
						
						for(int i = 0; i < size;i++) {
							int cur_tree_age = tree[y][x].poll();
							tree[y][x].offerLast(cur_tree_age);
							// 5의 배수이면 번식한다.
							if(cur_tree_age % 5 == 0) {
								
								for(int j = 0; j< 8; j++) {
									int nextx = x + dx[j];
									int nexty = y + dy[j];
									
									if(nextx < 1 || nexty < 1 || nextx > n || nexty > n ) continue;
									
									tree[nexty][nextx].offerFirst(1);
									
								}
								
							}
							//  좌표 한 곳 번식 끝 
						}
						
					}
					
				}
			}
			// 전체 좌표 번식 끝
			
			// 겨울
			// S2D2가 양분 추가
			for(int y = 1; y <= n; y++) {
				for(int x = 1; x <= n; x++) {
					land[y][x] += A[y][x];
				}
			}
			
			k--;
		}
		int cnt = 0;
		for(int y = 1; y <= n; y++) {
			for(int x = 1; x <= n; x++) {
				if(!tree[y][x].isEmpty())
					cnt += tree[y][x].size();
			}
		}
		System.out.println(cnt);
		
	}

}
