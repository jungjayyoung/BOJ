#include <iostream>
#include <string>
#include <algorithm>
#include <queue>

#define NMAX 12345678
using namespace std;

int w, h, k;
char map[21][21];
int visited[11];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
pair<int,int> d[11];

int ans;
bool check = false;
int dist[11][11];

bool bfs(int st){

    int dist2[21][21];
    fill(&dist2[0][0], &dist2[21][0], -1);
    queue<pair<pair<int,int>,int>> q;

    // dist2[a][b]: 점 st에서 점(b,a) 까지의 거리
    dist2[d[st].first][d[st].second] = 0;
    q.push({{d[st].first, d[st].second}, 0});

    while (!q.empty()) {

        int curx = q.front().first.first;
        int cury = q.front().first.second;
        int cnt = q.front().second;

        q.pop();


        for (int i = 0; i < 4; i++) {
            int nx = curx + dx[i];
            int ny = cury + dy[i];

            if(nx <0 || ny <0 || nx >= w || ny >= h || dist2[nx][ny] != -1 || map[ny][nx] == 'x') continue;
            q.push({{nx, ny}, cnt + 1});
            dist2[nx][ny] = cnt+1;
        }

    }

    for (int i = 0; i <= k; i++) {
        dist[st][i] = dist2[d[i].first][d[i].second];
        if(dist[st][i] == -1) return false;
    }

    return true;

}

void dfs(int cur, int idx, int sum){

    if (idx == k) {

        ans = min(ans, sum);
        return;
    }

    for (int i = 1; i <= k; i++) {
        if(visited[i]) continue;
        visited[i] = 1;
        dfs(i, idx + 1, sum + dist[cur][i]);
        visited[i] = 0;
    }
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    while (true) {
        fill(&dist[0][0], &dist[21][0], -1);
        fill(visited, visited + 11, 0);

        cin >> w >> h;
        if (w == 0 && h == 0) {
            break;
        }

        k = 0;

        for (int y = 0; y < h; y++) {
            string str;
            cin >> str;
            for (int x = 0; x < w; x++) {
                map[y][x] = str[x];
                if (map[y][x] == '*') {
                    k++;
                    d[k].first = x;
                    d[k].second = y;
                } else if (map[y][x] == 'o') {
                    d[0].first = x;
                    d[0].second = y;
                }
            }
        }

        check = false;

        for (int i = 0; i <= k; i++) {
            if (!bfs(i)) {
                check = true;
                break;
            }
        }
        if (check) {
            cout << -1 << "\n";
            continue;
        }

        ans = NMAX;
        dfs(0, 0, 0);


        cout << ans << "\n";


    }




    return 0;
}