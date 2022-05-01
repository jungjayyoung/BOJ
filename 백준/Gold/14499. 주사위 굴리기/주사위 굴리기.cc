#include <iostream>

using namespace std;

int board[21][21];

int dice[7]; // 1: 위쪽면, 2: 북쪽면, 3: 동쪽면, 4: 서쪽면, 5: 남쪽면, 6: 아래쪽면
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, x, y, k;

    cin >> n >> m >> y >> x >> k;

    for (int yy = 0; yy < n; yy++) {
        for (int xx = 0; xx < m; xx++) {
            cin >> board[yy][xx];
        }
    }
    int cur_x = x;
    int cur_y = y;

    for (int i = 0; i < k; i++) {
        int dir;
        cin >> dir;
        int next_x = cur_x + dx[dir - 1];
        int next_y = cur_y + dy[dir - 1];

        if (next_x >= m || next_x < 0 || next_y >= n || next_y < 0) {
            continue;
        }


        // dice[1]: 윗면, dice[6]: 아랫면
        if (dir == 1) { // 동쪽

            swap(dice[1], dice[4]);
            swap(dice[3], dice[6]);
            swap(dice[3], dice[4]);


        } else if (dir == 2) {// 서쪽
            swap(dice[1], dice[3]);
            swap(dice[4], dice[6]);
            swap(dice[3], dice[4]);

        } else if (dir == 3) {// 북쪽

            swap(dice[1], dice[2]);
            swap(dice[5], dice[6]);
            swap(dice[1], dice[6]);


        } else if (dir == 4) {// 남쪽

            swap(dice[1], dice[2]);
            swap(dice[5], dice[6]);
            swap(dice[2], dice[5]);

        }

        if (board[next_y][next_x] == 0) {
            board[next_y][next_x] = dice[6];
        }else{
            dice[6] = board[next_y][next_x];
            board[next_y][next_x] = 0;
        }

        cout << dice[1] << "\n";

        cur_x = next_x;
        cur_y = next_y;

    }




    return 0;
}