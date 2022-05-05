#include <iostream>
#include <algorithm>

using namespace std;
int n,m,k;

int board[101][101];
int visited[101][101];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int ans = 0;
int cnt = 1;


void dfs(int x, int y) {


    if (ans < cnt) {
        ans = max(ans, cnt);
    }
    visited[y][x] = 1;

    for (int i = 0; i < 4; i++) {

        int nextx = x + dx[i];
        int nexty = y + dy[i];

        if (nextx < 0 || nextx > m || nexty < 0 || nexty > n) {
            continue;
        }

        if (!visited[nexty][nextx] && board[nexty][nextx] == 1) {

            cnt++;
            dfs(nextx, nexty);

        }
    }




}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> k;


    for (int i = 0; i < k; i++) {
        int y, x;
        cin >> y >> x;

        board[y][x] = 1;
    }


    for (int y = 1; y <= n; y++) {

        for (int x = 1; x <= m; x++) {

            if (!visited[y][x] && board[y][x] == 1) {
                cnt = 1;
                visited[y][x] = 1;
                dfs(x, y);
            }

        }
    }

    cout << ans;


    return 0;
}