#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, k;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int dx2[] = {-1, -1, 1, 1};
int dy2[] = {-1, 1, -1, 1};

int map[3001][3001]; // n * m 판
int visited[3001][3001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    cin >> n >> m >> k;

    for (int i = 0; i < k; i++) {
        int yy, xx, d;
        cin >> yy >> xx >> d;

        if (d == 0) {
            map[yy][xx] = 1;
        }

        // 1. 위쪽부터 시작
        int sx = xx;
        int sy = yy - d;
        if (sx >= 1 && sx <= m && sy >= 1 && sy <= n) map[sy][sx] = 1;

        // 2. 남서쪽으로
        while (sy < yy) {
            if (sx >= 1 && sx <= m && sy >= 1 && sy <= n) map[sy][sx] = 1;
            sx = sx - 1;
            sy = sy + 1;
        }


        //3. 동남쪽으로
        while (sx < xx) {
            if (sx >= 1 && sx <= m && sy >= 1 && sy <= n) map[sy][sx] = 1;
            sx = sx + 1;
            sy = sy + 1;
        }

        //4. 북동쪽으로
        while (sy > yy) {
            if (sx >= 1 && sx <= m && sy >= 1 && sy <= n) map[sy][sx] = 1;
            sx = sx + 1;
            sy = sy - 1;
        }
        //5. 북서쪽으로

        while(sx > xx){
            if (sx >= 1 && sx <= m && sy >= 1 && sy <= n) map[sy][sx] = 1;
            sx = sx - 1;
            sy = sy - 1;
        }

    }


    queue<pair<pair<int,int>,int>> q;

    visited[1][1] = 1;
    q.push({{1, 1}, 0}); // x좌표, y좌표, 이동횟수


    int ans;
    bool check = false;
    while (!q.empty()) {
        int curx = q.front().first.first;
        int cury = q.front().first.second;
        int cnt = q.front().second;

        q.pop();

        if (cury == n && curx == m) {
            ans = cnt;
            check = true;
            break;
        }


        for (int i = 0; i < 4; i++) {
            int nx = curx + dx[i];
            int ny = cury + dy[i];

            if (nx < 1 || ny < 1 || nx > m || ny > n || map[ny][nx] == 1) continue;

            // 교통 정체가 아닌 길이면서 방문하지 않은 곳이면 방문처리해주고 큐에 넣는다.
            if (visited[ny][nx] == 0 && map[ny][nx] == 0) {
                visited[ny][nx] = 1;
                q.push({{nx, ny}, cnt + 1});
            }

        }



    }
//    for (int y = 1; y <= n; y++) {
//
//        for (int x = 1; x <= m; x++) {
//            cout << map[y][x] << " ";
//
//        }
//        cout << "\n";
//    }

    if (check) {
        cout << "YES" << "\n";
        cout << ans;
    }else{
        cout << "NO";
    }


    return 0;
}