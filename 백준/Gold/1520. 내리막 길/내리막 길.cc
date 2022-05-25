#include <iostream>


using namespace std;

int n,m;
int board[501][501];
int dp[501][501]; // dp[a][b]: (b,a) 에서 (n - 1,m - 1) 까지 경로의 갯수

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};


int ans = 0;
int dfs(int x, int y){


    if (x == n - 1 && y == m - 1) {
        return 1;
    }

    if (dp[y][x] != -1) {
        return dp[y][x];
    }

    dp[y][x] = 0;

    for (int i = 0; i < 4; i++) {
        int nextx = x + dx[i];
        int nexty = y + dy[i];


        if (nextx < 0 || nextx >= n || nexty < 0 || nexty >= m) {
            continue;
        }

        if (board[nexty][nextx] < board[y][x]) {

            dp[y][x] = dp[y][x] + dfs(nextx, nexty);

        }

    }


    return dp[y][x];


}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> m >> n;


    for (int y = 0; y < m; y++) {

        for (int x = 0; x < n; x++) {
            cin >> board[y][x];
        }
    }

    dp[0][0] = 1;

    fill(&dp[0][0], &dp[501][0], -1);

    cout << dfs(0, 0);


    return 0;
}