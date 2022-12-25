#include <iostream>


using namespace std;

int n, m, t;

int map[1001][1001];
int visited[1001][1001];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};


void dfs(int x, int y){

    visited[y][x] = 1;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;

        if (!visited[ny][nx] && map[ny][nx] == 255) {
            dfs(nx, ny);
        }

    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    cin >> n >> m;


    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            int a, b, c;
            cin >> a >> b >> c;
            map[y][x] = a + b + c;
        }
    }

    cin >> t;


    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            if (map[y][x] >= 3 * t) {
                map[y][x] = 255;
            }else
                map[y][x] = 0;
        }
    }

    int cnt = 0;

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            if (!visited[y][x] && map[y][x] == 255) {
                cnt++;
                dfs(x, y);
            }
        }
    }

    cout << cnt;

    return 0;
}