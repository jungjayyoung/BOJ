#include <iostream>
#include <queue>
#include <algorithm>



using namespace std;

int n;
int board[21][21];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int check = false; // 엄마 상어에게 도움을 요청할 수 있으면 true
int f_x, f_y;
int baby_shark_size = 2;
queue<pair<int,int>> q;
int fish_cnt = 0;
int cache[21][21];
int n_x = 25;
int n_y = 25;
int min_distance =123456;

void bfs(int x, int y){

    q.push({x, y});

    cache[y][x] = 0;

    while (!q.empty()) {

        int cur_x = q.front().first;
        int cur_y = q.front().second;

        q.pop();

        // 만약에 먹을 수 있는 물고기를 찾았으면
        if (board[cur_y][cur_x] < baby_shark_size && board[cur_y][cur_x] != 0) {

            //true로 바꿔준다
            check = true;
            // 최소 거리의 물고기를 찾는다.
            if (min_distance >= cache[cur_y][cur_x]) {
                min_distance = cache[cur_y][cur_x];

                // 최소 거리의 물고기들이 여러 마리 라면
                // 먼저 가장 위쪽의 물고기를 먹고
                //가장 위쪽이 동일하면 가장 왼쪽 물고기를 먹는다
                if (cur_y < n_y) {

                    n_y = cur_y;
                    n_x = cur_x;
                } else if (cur_y == n_y) {
                    n_y = cur_y;
                    if(n_x > cur_x)
                        n_x = cur_x;
                }

            }


            continue;
        }

        for (int i = 0; i < 4; i++) {
            int nextx = cur_x + dx[i];
            int nexty = cur_y + dy[i];

            if (nextx < 0 || nextx >= n || nexty < 0 || nexty >= n) {
                continue;
            }

            if(board[nexty][nextx] > baby_shark_size) continue;

            if(cache[nexty][nextx] > cache[cur_y][cur_x] + 1) {

                cache[nexty][nextx] = cache[cur_y][cur_x] + 1;
                q.push({nextx, nexty});

            }


        }


    }





}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;


    for (int y = 0; y < n; y++) {

        for (int x = 0; x < n; x++) {
            cin >> board[y][x];
            if (board[y][x] == 9) {
                f_x = x;
                f_y = y;
            }
        }
    }



    // f_x : 아기 상어의 시작 x 위치
    // f_y : 아기 상어의 시작 y 위치
    // 처음 아기 상어의 크기는 2
    //아기 상어의 이동은 1초가 걸린다.
    //아기 상어의 크기는 본인의 크기만큼의 물고기를 먹어야 크기가 1 커진다.
    // 먹을 수 있는 물고기가 한 마리 라면 그 물고기를 먹으러 간다.
    // 만약에 한 마리 이상이라면 거리가 가장 가까운 물고기를 먹고
    // 만약에 그런 물고기가 여러 마리라면 가장 위에 있는 물고기
    // 가장 위가 여러마리 라면 가장 왼쪽에 있는 물고기

    int ans = 0;


    while(1){
        fill(&cache[0][0], &cache[21][0], 54321);
        min_distance = 123456;
        check = false;


        bfs(f_x, f_y);

        if(!check) {
            break;
        }

        ans += min_distance;
        board[n_y][n_x] = 9;
        board[f_y][f_x] = 0;

        fish_cnt++;
        if (fish_cnt >= baby_shark_size) {
            baby_shark_size++;
            fish_cnt = 0;
        }

        f_x = n_x;
        f_y = n_y;
        n_x = 25;
        n_y = 25;
    }


    cout << ans;

    return 0;
}