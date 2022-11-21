#include <iostream>
#include <queue>
#include <algorithm>
#define NMAX 123456789
using namespace std;


int map[16][16];
int visited[16][16];
int water[16][16];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int tt;

	cin >> tt;

	for (int t = 1; t <= tt; t++) {

		int n;
		int a, b, c, d;
		queue<pair<pair<int, int>, pair<int,int>>> q;
		fill(&visited[0][0], &visited[16][0], 0);
		fill(&water[0][0], &water[16][0], 0);

		cin >> n;

		for (int y = 0; y < n; y++) {
			for (int x = 0; x < n; x++) {
				cin >> map[y][x];
			}
		}
		cin >> a >> b >> c >> d;

		q.push({ {b,a},{0,0} });

		int storm = 0;
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < n; x++) {
				if (map[y][x] == 2) {
					water[y][x] = 2;
					q.push({ {x,y},{0,1} });
					storm++;
				}
			}
		}
		int ans = NMAX;

		int s_cnt = 0;

		while (!q.empty()) {

			int curx = q.front().first.first;
			int cury = q.front().first.second;
			int cnt = q.front().second.first;
			int type = q.front().second.second;

			q.pop();


			if (type == 0 && curx == d && cury == c) {
				ans = min(ans, cnt);
				break;
			}
			if (s_cnt > storm) {
				break;
			}

			if (type == 1) {
				s_cnt++;
				water[cury][curx]--;

				if (water[cury][curx] < 0) {
					water[cury][curx] = 2;
				}

				q.push({ {curx,cury},{cnt + 1,type} });
				continue;
			}
			else
				s_cnt = 0;


			for (int i = 0; i < 4; i++) {

				int nx = curx + dx[i];
				int ny = cury + dy[i];

				if (nx < 0 || ny < 0 || nx >= n || ny >= n || map[ny][nx] == 1) continue;

				if (type == 0 &&!visited[ny][nx]) {

					if (water[ny][nx] != 0) {
						q.push({ {curx,cury},{cnt + 1,type} });
					}
					else {
						visited[ny][nx] = 1;
						q.push({ {nx,ny},{cnt + 1,type} });
					}
					
					
				}
			}
		}

		if (ans == NMAX) {
			cout << "#" << t << " " << -1 << "\n";
		}
		else {
			cout << "#" << t << " " << ans << "\n";
		}

	



	}


	return 0;
}