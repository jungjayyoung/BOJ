#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n, m;

int map[1001][1001];
int visited[1001][1001];
queue<pair<pair<int, int>,int>> q;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int sx, sy;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;


    for (int y = 0; y < n; y++) {

        for (int x = 0; x < m; x++) {
            cin >> map[y][x];
            if (map[y][x] == 2) {
                q.push({{x, y}, 0});
                sx = x;
                sy = y;
            }
        }
    }

    while (!q.empty()) {
        int curx = q.front().first.first;
        int cury = q.front().first.second;
        int cnt = q.front().second;

        q.pop();
        visited[cury][curx] = cnt;

        for (int i = 0; i < 4; i++) {
            int nx = curx + dx[i];
            int ny = cury + dy[i];

            if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
            if(map[ny][nx] != 1) continue;
            if(nx == curx && ny == cury) continue;

            if (!visited[ny][nx]) {
                visited[ny][nx] = 1;
                q.push({{nx, ny}, cnt + 1});
            }
        }
    }


    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            if (x == sx && y == sy) {
                cout << 0 << " ";
            } else if (visited[y][x] == 0) {
                if (map[y][x] == 0) {
                    cout << 0 << " ";
                }else
                    cout << -1 << " ";
            }else
                cout << visited[y][x] << " ";
        }
        cout << "\n";
    }



    return 0;
}