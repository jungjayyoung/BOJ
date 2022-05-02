#include <iostream>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

int n,m;
char board[11][11];
int visited[11][11][11][11]; // 빨강x,y 파랑 x,y 2 좌표를 동시에 방문했는지 체크

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

queue<pair<pair<int,int>,int>> red;
queue<pair<pair<int,int>,int>> blue;
bool check = false;
int ans = 9876543;
void bfs(){



    while (!red.empty()) {

        bool red_hole = false;
        bool blue_hole = false;

        int cur_red_x = red.front().first.first;
        int cur_red_y = red.front().first.second;
        int cur_blue_x = blue.front().first.first;
        int cur_blue_y = blue.front().first.second;
        int cur_red_cnt = red.front().second;
        int cur_blue_cnt = blue.front().second;

        red.pop();
        blue.pop();

        // 직선 움직이는 도중에 구멍이 있는지 체크
        // 만약에 구멍에 파랑, 빨강 둘 다 빠지면 큐에 집어넣지 말기, 다른 방향 탐색하기
        //0: 왼쪽, 1: 아래쪽, 2: 오른쪽, 3:위쪽
        for (int i = 0; i < 4; i++) {
            int next_red_x = cur_red_x + dx[i];
            int next_red_y = cur_red_y + dy[i];
            int next_blue_x = cur_blue_x + dx[i];
            int next_blue_y = cur_blue_y + dy[i];


          
            // 빨강과 파란색이 같은 직선 상에 있는지 체크하고 빨강을 먼저 움직일지 파랑을 먼저 움직일지 결정

            if (board[next_red_y][next_red_x] == '#' && board[next_blue_y][next_blue_x] == '#') {
                continue;
            }

            if (i == 0) { // 왼쪽
                while (board[next_red_y][next_red_x] != '#') {
                    if (board[next_red_y][next_red_x] == 'O') {
                        red_hole = true;
                        break;
                    }
                    next_red_x += dx[i];
                    next_red_y += dy[i];

                }

                while (board[next_blue_y][next_blue_x] != '#') {
                    if (board[next_blue_y][next_blue_x] == 'O') {
                        blue_hole = true;
                        break;
                    }
                    next_blue_x += dx[i];
                    next_blue_y += dy[i];
                }

                if (blue_hole && red_hole) {
                    blue_hole = false;
                    red_hole = false;
                    continue;
                } else if (blue_hole) {

                    blue_hole = false;
                    continue;
                }else if (red_hole) {

                    ans = min(ans, cur_red_cnt + 1);
                    check = true;
                    red_hole = false;
                    continue;
                }

                // 구멍이 없었다면 좌표 업데이트
                next_red_x -= dx[i];
                next_red_y -= dy[i];
                next_blue_x -= dx[i];
                next_blue_y -= dy[i];

                //만약에 좌표가 같다면 순서정하기
                if (next_red_x == next_blue_x && next_red_y == next_blue_y) {

                    if (cur_blue_x < cur_red_x) {
                        next_red_x -= dx[i];
                        next_red_y -= dy[i];
                    } else {
                        next_blue_y -= dy[i];
                        next_blue_x -= dx[i];
                    }

                }
                if (visited[next_red_x][next_red_y][next_blue_x][next_blue_y]) continue;

                visited[next_red_x][next_red_y][next_blue_x][next_blue_y] = 1;

                red.push({{next_red_x, next_red_y}, cur_red_cnt + 1});
                blue.push({{next_blue_x, next_blue_y}, cur_blue_cnt + 1});


            } else if (i == 1) { // 아래쪽
                while (board[next_red_y][next_red_x] != '#') {
                    if (board[next_red_y][next_red_x] == 'O') {
                        red_hole = true;
                        break;
                    }
                    next_red_x += dx[i];
                    next_red_y += dy[i];

                }

                while (board[next_blue_y][next_blue_x] != '#') {
                    if (board[next_blue_y][next_blue_x] == 'O') {
                        blue_hole = true;
                        break;
                    }
                    next_blue_x += dx[i];
                    next_blue_y += dy[i];
                }

                if (blue_hole && red_hole) {
                    blue_hole = false;
                    red_hole = false;
                    continue;
                }else if (blue_hole) {

                    blue_hole = false;
                    continue;
                } else if (red_hole) {

                    ans = min(ans, cur_red_cnt + 1);
                    check = true;
                    red_hole = false;
                    continue;
                }

                // 구멍이 없었다면 좌표 업데이트
                next_red_x -= dx[i];
                next_red_y -= dy[i];
                next_blue_x -= dx[i];
                next_blue_y -= dy[i];

                //만약에 좌표가 같다면 순서정하기
                if (next_red_x == next_blue_x && next_red_y == next_blue_y) {

                    if (cur_blue_y < cur_red_y) {
                        next_blue_x -= dx[i];
                        next_blue_y -= dy[i];
                    } else {
                        next_red_y -= dy[i];
                        next_red_x -= dx[i];
                    }

                }
                if (visited[next_red_x][next_red_y][next_blue_x][next_blue_y]) continue;

                visited[next_red_x][next_red_y][next_blue_x][next_blue_y] = 1;

                red.push({{next_red_x, next_red_y}, cur_red_cnt + 1});
                blue.push({{next_blue_x, next_blue_y}, cur_blue_cnt + 1});

            } else if (i == 2) { //오른쪽
                while (board[next_red_y][next_red_x] != '#') {
                    if (board[next_red_y][next_red_x] == 'O') {
                        red_hole = true;
                        break;
                    }
                    next_red_x += dx[i];
                    next_red_y += dy[i];

                }

                while (board[next_blue_y][next_blue_x] != '#') {
                    if (board[next_blue_y][next_blue_x] == 'O') {
                        blue_hole = true;
                        break;
                    }
                    next_blue_x += dx[i];
                    next_blue_y += dy[i];
                }

                if (blue_hole && red_hole) {
                    blue_hole = false;
                    red_hole = false;
                    continue;
                }else if (blue_hole) {

                    blue_hole = false;
                    continue;
                } else if (red_hole) {

                    ans = min(ans, cur_red_cnt + 1);
                    check = true;
                    red_hole = false;
                    continue;
                }

                // 구멍이 없었다면 좌표 업데이트
                next_red_x -= dx[i];
                next_red_y -= dy[i];
                next_blue_x -= dx[i];
                next_blue_y -= dy[i];

                //만약에 좌표가 같다면 순서정하기
                if (next_red_x == next_blue_x && next_red_y == next_blue_y) {

                    if (cur_blue_x < cur_red_x) {
                        next_blue_x -= dx[i];
                        next_blue_y -= dy[i];
                    } else {
                        next_red_y -= dy[i];
                        next_red_x -= dx[i];
                    }

                }
                if (visited[next_red_x][next_red_y][next_blue_x][next_blue_y]) continue;

                visited[next_red_x][next_red_y][next_blue_x][next_blue_y] = 1;

                red.push({{next_red_x, next_red_y}, cur_red_cnt + 1});
                blue.push({{next_blue_x, next_blue_y}, cur_blue_cnt + 1});


            } else if (i == 3) {  //위쪽
                while (board[next_red_y][next_red_x] != '#') {
                    if (board[next_red_y][next_red_x] == 'O') {
                        red_hole = true;
                        break;
                    }
                    next_red_x += dx[i];
                    next_red_y += dy[i];

                }

                while (board[next_blue_y][next_blue_x] != '#') {
                    if (board[next_blue_y][next_blue_x] == 'O') {
                        blue_hole = true;
                        break;
                    }
                    next_blue_x += dx[i];
                    next_blue_y += dy[i];
                }

                if (blue_hole && red_hole) {
                    blue_hole = false;
                    red_hole = false;
                    continue;
                }else if (blue_hole) {

                    blue_hole = false;
                    continue;
                } else if (red_hole) {

                    ans = min(ans, cur_red_cnt + 1);
                    check = true;
                    red_hole = false;
                    continue;
                }

                // 구멍이 없었다면 좌표 업데이트
                next_red_x -= dx[i];
                next_red_y -= dy[i];
                next_blue_x -= dx[i];
                next_blue_y -= dy[i];

                //만약에 좌표가 같다면 순서정하기
                if (next_red_x == next_blue_x && next_red_y == next_blue_y) {

                    if (cur_blue_y < cur_red_y) {
                        next_red_x -= dx[i];
                        next_red_y -= dy[i];
                    } else {
                        next_blue_y -= dy[i];
                        next_blue_x -= dx[i];
                    }

                }
                if (visited[next_red_x][next_red_y][next_blue_x][next_blue_y]) continue;

                visited[next_red_x][next_red_y][next_blue_x][next_blue_y] = 1;

                red.push({{next_red_x, next_red_y}, cur_red_cnt + 1});
                blue.push({{next_blue_x, next_blue_y}, cur_blue_cnt + 1});

            }

        }
    }
    if(check){
        if (ans > 10) {
            cout << -1;
        }else
            cout << ans;
    }else{
        cout << -1;
    }

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;

        for (int j = 0; j < m; j++) {
            board[i][j] = str[j];

            if (board[i][j] == 'R') {
                red.push({{j, i}, 0});
            } else if (board[i][j] == 'B') {
                blue.push({{j, i}, 0});
            }
        }
    }


    visited[red.front().first.first][red.front().first.second][blue.front().first.first][blue.front().first.second] = 1;

    bfs();



    return 0;
}