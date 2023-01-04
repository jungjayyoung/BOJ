#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;

int map[51][51];
int water_add[51][51];
int visited[51][51];

int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, -1, -1, -1, 0, 1, 1, 1};

int dx2[] = {-1, -1, 1, 1};
int dy2[] = {-1, 1, -1, 1};

queue<pair<int,int>> q;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    cin >> n >> m;

    for (int y = 1; y <= n; y++) {

        for (int x = 1; x <= n; x++) {
            cin >> map[y][x];
        }
    }

    q.push({1, n});
    q.push({2, n});
    q.push({1, n - 1});
    q.push({2, n - 1});

    for (int i = 0; i < m; i++) {


        fill(&visited[0][0], &visited[51][0], 0);
        int d, s;

        cin >> d >> s;


        while (!q.empty()) {


            int curx = q.front().first;
            int cury = q.front().second;
            q.pop();

            int nx = curx + (dx[d - 1] * s);
            int ny = cury + (dy[d - 1] * s);

            if(nx > n) nx = nx % n;
            if(nx < 1) nx = n + nx % n;

            if(ny > n) ny = ny % n;
            if(ny < 1) ny = n + ny % n;

            visited[ny][nx] = 1;

            // 비가 내려 저장된 물 양 1 증가
            map[ny][nx]++;

        }



        for (int y = 1; y <= n; y++) {

            for (int x = 1; x <= n; x++) {
                int cnt = 0;
                if (visited[y][x]) {

                    for (int j = 0; j < 4; j++) {
                        int nx = x + dx2[j];
                        int ny = y + dy2[j];

                        if (nx < 1 || ny < 1 || nx > n || ny > n) continue;
                        if(map[ny][nx] == 0) continue;

                        cnt++;

                    }
                    map[y][x] += cnt;
                }
            }
        }


        for (int y = 1; y <= n; y++) {

            for (int x = 1; x <= n; x++) {
                if(visited[y][x]) continue;
                if (map[y][x] >= 2) {
                    q.push({x, y});
                    map[y][x] -= 2;
                }
            }
        }

    }

    int ans = 0;
    for (int y = 1; y <= n; y++) {

        for (int x = 1; x <= n; x++) {
            ans += map[y][x];
        }
    }


    cout << ans;



    return 0;
}