#include <iostream>
#include <algorithm>

using namespace std;
int n, m;
int board[501][501];
int visited[501][501];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int ans = 0;
int cnt = 0;
int s = 0;


void dfs(int x, int y){

    visited[y][x] = 1;
    s++;

    for (int i = 0; i < 4; i++) {
        int nextx = x + dx[i];
        int nexty = y + dy[i];

        if (nextx < 0 || nextx >= m || nexty < 0 || nexty >= n) {
            continue;
        }

        if (!visited[nexty][nextx] && board[nexty][nextx] == 1) {
            dfs(nextx, nexty);
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

            s = 0;
            if (!visited[y][x] && board[y][x] == 1) {

                cnt++;

                dfs(x, y);
                ans = max(ans, s);

            }
        }
    }

    cout << cnt << "\n";
    cout << ans;



    return 0;
}