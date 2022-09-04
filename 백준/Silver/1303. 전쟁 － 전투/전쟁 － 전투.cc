#include <iostream>
#include <algorithm>

using namespace std;

int n,m;

char board[101][101];
int visited[101][101];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int dfs(int x, int y, char cur){


    visited[y][x] = 1;

    int cnt = 1;
    for (int i = 0; i < 4; i++) {
        int nextx = x + dx[i];
        int nexty = y + dy[i];

        if(nextx < 0 || nexty < 0 || nextx >= n || nexty >= m) continue;

        if(!visited[nexty][nextx] && board[nexty][nextx] == cur){
            cnt = cnt + dfs(nextx, nexty, cur);
        }

    }

    return cnt;

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);


    cin >> n >> m;


    for (int y = 0; y < m; y++) {

        for (int x = 0; x < n; x++) {

            cin >> board[y][x];

        }
    }

    int w_total = 0;
    int b_total = 0;

    for (int y = 0; y < m; y++) {

        for (int x = 0; x < n; x++) {
            if (!visited[y][x]) {

                int num;


                if(board[y][x] == 'W'){
                    num = dfs(x, y, board[y][x]);
                    w_total += num * num;
                }else if(board[y][x] == 'B'){
                    num = dfs(x, y,board[y][x]);
                    b_total += num * num;
                }

            }
        }
    }


    cout << w_total << " " << b_total;

    return 0;
}