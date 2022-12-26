#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int h, w, n;
char map[1001][1001];
int visited[1001][1001];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

queue<pair<pair<int,int>,int>> q;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> h >> w >> n;


    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            cin >> map[y][x];
            if (map[y][x] == 'S') {
                q.push({{x, y}, 0});
                visited[y][x] = 1;
            }
        }
    }

    int ans = 0;
    for (int k = 1; k <= n; k++) {
        int goal = k + '0';

        while (!q.empty()) {

            int curx = q.front().first.first;
            int cury = q.front().first.second;
            int cnt = q.front().second;

            if (map[cury][curx] == goal) {
                ans += cnt;
                while (!q.empty()) {
                    q.pop();
                }
                fill(&visited[0][0], &visited[1001][0], 0);
                q.push({{curx, cury}, 0});
                visited[cury][curx] = 1;

                break;
            }

            q.pop();

            for (int i = 0; i < 4; i++) {
                int nx = curx + dx[i];
                int ny = cury + dy[i];

                if (nx < 0 || ny < 0 || nx >= w || ny >= h) continue;
                if(visited[ny][nx]) continue;

                if (!visited[ny][nx] && map[ny][nx] != 'X') {
                    visited[ny][nx] = 1;
                    q.push({{nx, ny}, cnt + 1});
                }

            }


        }

    }

    cout << ans;

    return 0;
}
