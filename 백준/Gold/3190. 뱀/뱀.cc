#include <iostream>
#include <algorithm>
#include <queue>
#include <deque>

using namespace std;

int board[102][102];
int apple[102][102];
int visited[102][102];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

deque<pair<int, int>> body;
queue<pair<int,char>> order;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;

    cin >> n >> k;


    for (int i = 0; i < k; i++) {
        int y, x;
        cin >> y >> x;
        apple[y - 1][x - 1] = 1;
    }

    int l;

    cin >> l;



    for (int i = 0; i < l; i++) {
        int a;
        char b;
        cin >> a >> b;
        order.push({a, b});
    }

    body.push_back({0, 0});
    // 처음 방향은 오른쪽
    int cur_dir = 0;
    int time = 0;
    bool eat_apple = false;


    visited[0][0] = 1;

    while (1) {

        eat_apple = false;
        time++;

        pair<int,int> cur_head = body.front();


        int cur_head_x = cur_head.first;
        int cur_head_y = cur_head.second;
        int cur_tail_x = body.back().first;
        int cur_tail_y = body.back().second;
        int next_x = cur_head.first + dx[cur_dir];
        int next_y = cur_head.second + dy[cur_dir];

        // 벽에 부딫이면 게임 오버
        if (next_x >= n || next_x < 0 || next_y >= n || next_y < 0) {

            break;
        }

        // 자기 몸에 부딫이면 게임 오버
        if(visited[next_y][next_x]){

            break;
        }



        // 만약에 사과가 있으면
        if (apple[next_y][next_x] == 1) {
            apple[next_y][next_x] = 0;
            body.push_front({next_x, next_y});
            eat_apple = true;
        } else{ // 만약에 사과가 없으면
            body.pop_back();
            body.push_front({next_x, next_y});
        }


        // 보드 판에서 뱀이 점령한 칸인 visited를 업데이트
        visited[next_y][next_x] = 1;
        if (!eat_apple) {
            visited[cur_tail_y][cur_tail_x] = 0;
        }

        // 방향 바꾸기
        if (order.front().first == time) {

            // 왼쪽 회전
            if (order.front().second == 'D') {
                cur_dir++;
                if (cur_dir >= 4) {
                    cur_dir = 0;
                }
            } else { // 오른쪽 회전
                cur_dir--;
                if (cur_dir <= -1) {
                    cur_dir = 3;
                }
            }
            order.pop();
        }

    }


    cout << time;

    return 0;
}

