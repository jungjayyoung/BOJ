#include <iostream>
#include <queue>


using namespace std;

int n,m;
char board[51][51];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int visited[51][51];
int cache[51][51];
queue<pair<int,int>> q;
int ans = 0;


void bfs(){

    while (!q.empty()) {

        int cur_x = q.front().first;
        int cur_y = q.front().second;

        q.pop();

        for (int i = 0; i < 4; i++) {

            int nextx = cur_x + dx[i];
            int nexty = cur_y + dy[i];

            if (nextx < 0 || nexty < 0 || nextx >= m || nexty >= n) {
                continue;
            }

            if (!visited[nexty][nextx] && board[nexty][nextx] == 'L') {
                visited[nexty][nextx] = 1;
                q.push({nextx, nexty});
                cache[nexty][nextx] = cache[cur_y][cur_x] + 1;
                ans = max(ans, cache[nexty][nextx]);
            }


        }


    }

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);


    cin >> n >> m;


    for (int y = 0; y < n; y++) {

        for (int x = 0; x < m; x++) {
            cin >> board[y][x];
        }
    }

    for (int y = 0; y < n; y++) {

        for (int x = 0; x < m; x++) {
            fill(&visited[0][0], &visited[51][0], 0);
            fill(&cache[0][0], &cache[51][0], 0);
            if (board[y][x] == 'L') {

                q.push({x, y});
                visited[y][x] = 1;
                bfs();

            }
        }
    }


    cout << ans;

    return 0;
}