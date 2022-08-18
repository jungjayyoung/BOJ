#include <iostream>
#include <algorithm>


using namespace std;

char board[21][21];
int visited[27];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int r, c;
int ans = 1;

void dfs(int xx, int yy,int cnt){

    ans = max(cnt, ans);

    for (int i = 0; i < 4; i++) {

        int next_y = yy + dy[i];
        int next_x = xx + dx[i];
        if(next_x < 0 || next_y < 0 || next_x >= c || next_y >= r) continue;

        int next_alp = board[next_y][next_x] - 'A';
        if (!visited[next_alp]) {
            visited[next_alp] = 1;
            dfs(next_x, next_y, cnt + 1);
            visited[next_alp] = 0;
        }

    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);


    cin >> r >> c;


    for (int y = 0; y < r; y++) {

        for (int x = 0; x < c; x++) {

            cin >> board[y][x];

        }
    }


    visited[board[0][0] - 'A'] = 1;

    dfs(0, 0, 1);


    cout << ans;

    return 0;
}