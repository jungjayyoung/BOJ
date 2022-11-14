#include <iostream>
#include <algorithm>

using namespace std;

int n,m;
int board[1001][1001];

int dp[1001][1001][3]; // 이전

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;




    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            cin >> board[y][x];
        }
    }

    // \ : 0, | : 1, /: 2

    for (int x = 0; x < m; x++) {
        dp[0][x][0] = board[0][x];
        dp[0][x][1] = board[0][x];
        dp[0][x][2] = board[0][x];
    }



    for (int y = 1; y < n; y++) {

        for (int x = 0; x < m; x++) {

            if (x == 0) {
                dp[y][x][1] = dp[y - 1][x][2] + board[y][x];
                dp[y][x][2] = min(dp[y - 1][x + 1][0], dp[y - 1][x + 1][1]) + board[y][x];
            } else if (x == m - 1) {
                dp[y][x][0] = min(dp[y - 1][x - 1][1], dp[y - 1][x - 1][2]) + board[y][x];
                dp[y][x][1] = dp[y - 1][x][0] + board[y][x];
            }else{
                dp[y][x][0] = min(dp[y - 1][x - 1][1], dp[y - 1][x - 1][2]) + board[y][x];
                dp[y][x][1] = min(dp[y - 1][x][0], dp[y - 1][x][2]) + board[y][x];
                dp[y][x][2] = min(dp[y - 1][x + 1][0], dp[y - 1][x + 1][1]) + board[y][x];

            }

        }

    }

    int ans =123456789;

    for (int x = 0; x < m; x++) {
        if (x == 0) {
            ans = min(ans, dp[n - 1][x][1]);
            ans = min(ans, dp[n - 1][x][2]);

        } else if (x == m - 1) {
            ans = min(ans, dp[n - 1][x][0]);
            ans = min(ans, dp[n - 1][x][1]);

        }else{
            ans = min(ans, dp[n - 1][x][0]);
            ans = min(ans, dp[n - 1][x][1]);
            ans = min(ans, dp[n - 1][x][2]);

        }

    }

    cout << ans;



    return 0;
}