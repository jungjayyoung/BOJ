#include <iostream>
#include <queue>
#include <algorithm>


using namespace std;

char board[51][51];
int r,c;
int water[51][51];
int water_visited[51][51];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int visited[51][51];
int cache[51][51];
int d_x, d_y;

queue<pair<int,int>> q; // 물
queue<pair<int,int>> qq; // 두더지
int ans = 8765;

void bfs(){


    while(!q.empty()){

        int cur_x = q.front().first;
        int cur_y = q.front().second;

        q.pop();

        for (int i = 0; i < 4; i++) {
            int nextx = cur_x + dx[i];
            int nexty = cur_y + dy[i];

            if (nextx < 0 || nexty < 0 || nextx >= c || nexty >= r) {
                continue;
            }

            if(board[nexty][nextx] != 'X' && board[nexty][nextx] != 'D' && !water_visited[nexty][nextx]) {
                q.push({nextx, nexty});
                water_visited[nexty][nextx] = 1;
                water[nexty][nextx] = water[cur_y][cur_x] + 1;
            }

        }

    }

}

void bfs2(){


    while (!qq.empty()) {

        int cur_x = qq.front().first;
        int cur_y = qq.front().second;

        qq.pop();

        if (cur_x == d_x && cur_y == d_y) {
            ans = min(ans, cache[cur_y][cur_x]);
            return;
        }


        for (int i = 0; i < 4; i++) {
            int nextx = cur_x + dx[i];
            int nexty = cur_y + dy[i];

            if (nextx < 0 || nexty < 0 || nextx >= c || nexty >= r) {
                continue;
            }

            if (board[nexty][nextx] != 'X' && !visited[nexty][nextx]) {

                if (water[nexty][nextx] > cache[cur_y][cur_x] + 1 || !water_visited[nexty][nextx]) {
                    visited[nexty][nextx] = 1;
                    qq.push({nextx, nexty});
                    cache[nexty][nextx] = cache[cur_y][cur_x] + 1;
                }

            }


        }

    }



}

// 비버굴이 D
// 두더지가 S
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);


    cin >> r >> c;

    for (int y = 0; y < r; y++) {

        for (int x = 0; x < c; x++) {
            cin >> board[y][x];
            //물로 차있는 곳을 큐에 집어넣는다
            if (board[y][x] == '*') {
                q.push({x, y});
                water_visited[y][x] = 1;
            }

            if(board[y][x] == 'S'){
                qq.push({x, y});
                visited[y][x] = 1;
            }

            if (board[y][x] == 'D') {
                d_x = x;
                d_y = y;
            }

            if (board[y][x] == 'X') {
                visited[y][x] = 1;
                water_visited[y][x] = 1;
            }
        }
    }


    // bfs를 통해 물이 차오르는 시간을 각 타일마다 기록한다
    bfs();

    bfs2();

//    for (int y = 0; y < r; y++) {
//
//        for (int x = 0; x < c; x++) {
//            cout << water[y][x] << " ";
//        }
//        cout << "\n";
//    }
//
//    cout << "\n";
//
//    for (int y = 0; y < r; y++) {
//
//        for (int x = 0; x < c; x++) {
//            cout << cache[y][x] << " ";
//        }
//        cout << "\n";
//    }

    if (ans == 8765) {
        cout << "KAKTUS";
    }else{
        cout << ans;
    }

    return 0;
}