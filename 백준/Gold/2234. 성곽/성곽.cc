#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
int visited[51][51];
int visited2[51][51];

int board[51][51];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
int big_room_size = 0;
int room_cnt[2501];
int combined_room = 1;

queue<pair<int,int>> q; // x, y, 방 개수


void bfs(int num){

    int cnt = 1;
    while (!q.empty()) {
        int curx = q.front().first;
        int cury = q.front().second;
        int wall = board[cury][curx];

        q.pop();


        int flag = 1;

        for (int i = 0; i < 4; i++) {

            int nx = curx + dx[i];
            int ny = cury + dy[i];

            // 범위를 벗어나면 continue 해준다.
            if(nx < 0 || ny < 0 || nx >= m || ny >= n) {
                flag = (flag << 1);
                continue;
            }


            if ((flag & wall) != 0) {
                flag = (flag << 1);
                continue;
            }

            if (!visited[ny][nx]) {
                cnt++;
                visited[ny][nx] = num;
                q.push({nx, ny});
            }
            flag = (flag << 1);

        }
    }


    big_room_size = max(big_room_size, cnt);
    room_cnt[num] = cnt;



}



void bfs2(int num){

    int cnt = 1;
    while (!q.empty()) {
        int curx = q.front().first;
        int cury = q.front().second;
        int wall = board[cury][curx];

        q.pop();


        int flag = 1;

        for (int i = 0; i < 4; i++) {

            int nx = curx + dx[i];
            int ny = cury + dy[i];

            // 범위를 벗어나면 continue 해준다.
            if(nx < 0 || ny < 0 || nx >= m || ny >= n) {
                flag = (flag << 1);
                continue;
            }

            // 벽이 있다면 continue 해준다.
            if ((flag & wall) != 0) {
                flag = (flag << 1);

                // 같은 방이 아닌 방이 벽건너에 있다면
                if (visited[ny][nx] != num) {
                    combined_room = max(combined_room, room_cnt[visited[ny][nx]] + room_cnt[num]);
                }
                continue;
            }

            if (!visited2[ny][nx] && board[ny][nx] == num) {
                cnt++;
                visited2[ny][nx] = 1;
                q.push({nx, ny});
            }

            flag = (flag << 1);

        }
    }



}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> m >> n;

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            cin >> board[y][x];
        }
    }

    int room = 0;
    int idx = 1;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {

            if (!visited[y][x]) {
                room++;
                visited[y][x] = idx;
                q.push({x, y});
                bfs(idx++);
            }

        }
    }


    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {

            if (!visited2[y][x]) {
                visited2[y][x] = 1;
                q.push({x, y});
                bfs2(visited[y][x]);
            }

        }
    }

    cout << room << "\n";
    cout << big_room_size << "\n";
    cout << combined_room;
    return 0;
}