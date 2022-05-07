#include <iostream>
#include <string>


using namespace std;

int r,c,k;
char board[6][6];
int visited[6][6];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int ans[100];

void dfs(int x, int y,int cnt) {


    visited[y][x] = 1;

    if (x == c - 1 && y == 0) {

        ans[cnt]++;

        return;
    }
    for (int i = 0; i < 4; i++) {
        int nextx = x + dx[i];
        int nexty = y + dy[i];

        if (nextx < 0 || nextx >= c || nexty < 0 || nexty >= r) {
            continue;
        }
        if (board[nexty][nextx] == 'T') continue;

        if (!visited[nexty][nextx] && board[nexty][nextx] == '.') {
            dfs(nextx, nexty, cnt + 1);
            visited[nexty][nextx] = 0;
        }
    }

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);


    cin >> r >> c >> k;

    for (int i = 0; i < r; i++) {
        string str;
        cin >> str;

        for (int j = 0; j < str.size(); j++) {

            board[i][j] = str[j];

        }
    }


    dfs(0, r - 1, 1);


    cout << ans[k];

    return 0;
}