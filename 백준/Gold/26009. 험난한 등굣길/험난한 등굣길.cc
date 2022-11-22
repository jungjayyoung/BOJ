#include <iostream>
#include <queue>
#include <algorithm>
#define NMAX 12345678
using namespace std;

int n, m, k;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int dx2[] = {-1, -1, 1, 1};
int dy2[] = {-1, 1, -1, 1};

int map[3001][3001];
int dp[3001][3001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    cin >> n >> m >> k;

    for (int i = 0; i < k; i++) {
        int yy, xx, d;
        cin >> yy >> xx >> d;

        for (int j = 0; j <= d; j++) {

            for (int a = 0; a < 4; a++) {
                int nx = xx + dx[a] * j;
                int ny = yy + dy[a] * j;

                if (nx < 1 || ny < 1 || nx > m || ny > n) continue;
                map[ny][nx] = 1;
            }


            for (int a = 0; a < 4; a++) {
                int nx = xx + dx2[a] * j;
                int ny = yy + dy2[a] * j;

                if (nx < 1 || ny < 1 || nx > m || ny > n) continue;
                if ((abs(nx - xx) + abs(ny - yy)) <= d) {
                    map[ny][nx] = 1;
                }
            }


        }
    }


    queue<pair<pair<int,int>,int>> q;
    fill(&dp[0][0], &dp[3001][0], NMAX);

    dp[1][1] = 0;
    q.push({{1, 1}, 0});


    int ans;
    bool check = false;
    while (!q.empty()) {
        int curx = q.front().first.first;
        int cury = q.front().first.second;
        int cnt = q.front().second;

        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = curx + dx[i];
            int ny = cury + dy[i];

            if (nx < 1 || ny < 1 || nx > m || ny > n || map[ny][nx] == 1) continue;

            if (dp[ny][nx] > dp[cury][curx] + 1 && map[ny][nx] == 0) {
                dp[ny][nx] = dp[cury][curx] + 1;
                q.push({{nx, ny}, cnt + 1});
            }

        }



    }



    if (dp[n][m] != NMAX) {
        cout << "YES" << "\n";
        cout << dp[n][m];
    }else{
        cout << "NO";
    }


    return 0;
}