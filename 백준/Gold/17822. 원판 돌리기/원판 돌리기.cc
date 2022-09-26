#include <iostream>
#include <list>
#include <vector>

using namespace std;



int arr[51][51]; // arr[n][m]

int n, m, t;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

bool check = false;


void dfs(int x ,int y,int cur_num) {

	

	for (int i = 0; i < 4; i++) {
		int nextx = x + dx[i];
		int nexty = y + dy[i];

		if (nextx > m - 1) {
			nextx = 0;
		}
		else if (nextx < 0) {
			nextx = m - 1;
		}

		if (nexty > n || nexty < 0 || arr[nexty][nextx] != cur_num) continue;

		if (arr[nexty][nextx] == cur_num) {
			arr[nexty][nextx] = -1;
			check = true;
			dfs(nextx, nexty,cur_num);
		}

	}


}


int cnt_num(int x,int y) {

	int cnt = 0;
	for (int i = 0; i < y; i++) {

		for (int j = 0; j < x; j++) {

			if (arr[i][j] != -1) {
				cnt++;
			}

		}
	}

	return cnt;

}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);



	cin >> n >> m >> t;

	// -1은 제거한 숫자라는 뜻
	
	list<int> r[51];

	for (int ii = 0; ii < n; ii++) {
		for (int jj = 0; jj < m; jj++) {
			int num;
			cin >> num;
			r[ii].push_back(num);
		}
	}

	fill(&arr[0][0], &arr[51][0], -1);

	for (int i = 0; i < t; i++) {
		
		
		
		int x, d, k;
		cin >> x >> d >> k;

		for (int r_num = 0; r_num < n; r_num++) {

			//원판이 x의 배수인 경우
			if ((r_num + 1) % x == 0) {

				//시계 방향
				if (d == 0) {

					// k칸 회전
					for (int j = 0; j < k; j++) {
						int tmp = r[r_num].back();
						r[r_num].pop_back();
						r[r_num].push_front(tmp);
					}

				}// 반시계 방향
				else if (d == 1) {

					// k칸 회전
					for (int j = 0; j < k; j++) {
						int tmp = r[r_num].front();
						r[r_num].pop_front();
						r[r_num].push_back(tmp);
					}

				}

			}

		}
		////////////////////// 원판 회전 끝

		// arr[n][m]
		// 개별 요소에 접근하기 위해 벡터에 집어넣기
		for (int i = 0; i < n; i++) {

			for (int j = 0; j < m; j++) {

				arr[i][j] = r[i].front();
				r[i].pop_front();
			}
			
		}

		
	
		// 인접한 숫자 체크
		bool check2 = false;
		
		for (int y = 0; y < n; y++) {

			for (int x = 0; x < m; x++) {
				check = false;
				if (arr[y][x] != -1) {
					dfs(x, y, arr[y][x]);
					if (check) {
						arr[y][x] = -1;
						check2 = true;
					}
				}

			}
		}
		
		// 인접한 숫자가 없으면?
		if (!check2) {
			int total = 0;
			double avg = 0.0;
			for (int y = 0; y < n; y++) {

				for (int x = 0; x < m; x++) {
					if (arr[y][x] != -1) {
						total += arr[y][x];
					}
				}
			}

			// 평균 구하기
			avg = (double)total / cnt_num(m,n);

			//평균으로 부터 원판 업데이트
			for (int y = 0; y < n; y++) {

				for (int x = 0; x < m; x++) {

					if (arr[y][x] != -1) {
						if ((double)arr[y][x] < avg) {
							arr[y][x] = arr[y][x] + 1;
						}
						else if ((double)arr[y][x] > avg) {
							arr[y][x] = arr[y][x] - 1;
						}
					}

				}
			}

		}
		
		for (int ii = 0; ii < n; ii++) {
			for (int jj = 0; jj < m; jj++) {
				r[ii].push_back(arr[ii][jj]);
			}
		}

	}

	int ans = 0;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			if (arr[y][x] != -1) {
				ans += arr[y][x];
			}
		}
	}
	

	cout << ans;

	return 0;
}