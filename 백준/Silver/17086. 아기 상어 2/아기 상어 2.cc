#include <iostream>
#include <queue>

using namespace std;


int n,m;

int map[51][51];
int visited[51][51];

int dx[] = {-1, 0, 1, 0, 1, -1, -1, 1};
int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};

int ans = 0;

void bfs(int x, int y){

    queue<pair<pair<int,int>,int>> q;
    fill(&visited[0][0], &visited[51][0], 0);

    q.push({{x, y}, 0});
    visited[y][x] = 1;
    int ans2 = 54321;

    while (!q.empty()) {

        int curx = q.front().first.first;
        int cury = q.front().first.second;
        int cnt = q.front().second;

        q.pop();

        if (map[cury][curx] == 1) {
            //cout << x << " " << y << " " << cnt << "\n";
            ans2 = min(ans2, cnt);
        }


        for (int i = 0; i < 8; i++) {
            int nx = curx + dx[i];
            int ny = cury + dy[i];

            if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;

            if (!visited[ny][nx]) {
                visited[ny][nx] = 1;
                q.push({{nx, ny}, cnt + 1});
            }

        }


    }

    ans = max(ans, ans2);

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    for (int y = 0; y < n; y++) {

        for (int x = 0; x < m; x++) {
            cin >> map[y][x];
        }
    }


    for (int y = 0; y < n; y++) {

        for (int x = 0; x < m; x++) {
            if (map[y][x] == 0) {
                bfs(x, y);
            }
        }
    }

    cout << ans;




    return 0;
}