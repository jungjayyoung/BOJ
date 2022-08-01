#include <iostream>
#include <queue>

using namespace std;

int board[201][201];
int visited[201][201]; // 처음 바이러스의 위치에는 1이 저장된다. 다음 방문하는 visited에는 2가 저장된다.
                        // 이렇게 저장하면 현재 바이러스가 퍼지는 시간(초)를 알 수 있게 된다.
int n, k;
int s, xx, yy;

queue<pair<pair<int,int>,int>> q;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs(){

    while (!q.empty()) {

        int cur_x = q.front().first.first;
        int cur_y = q.front().first.second;
        int cur_virus = q.front().second;
        q.pop();

        if(visited[cur_y][cur_x] - 1 >= s) {
            continue;
        }

        for (int i = 0; i < 4; i++) {
            int nextx = cur_x + dx[i];
            int nexty = cur_y + dy[i];

            if (nextx < 0 || nextx >= n || nexty < 0 || nexty >= n) {
                continue;
            }

            if (!visited[nexty][nextx] && board[nexty][nextx] == 0) {
                visited[nexty][nextx] = visited[cur_y][cur_x] + 1;
                board[nexty][nextx] = cur_virus;
                q.push({{nextx, nexty}, cur_virus});
            }

        }

    }

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);


    cin >> n >> k;

    for (int y = 0; y < n; y++) {

        for (int x = 0; x < n; x++) {
            cin >> board[y][x];
        }
    }
    cin >> s >> xx >> yy;

    // 큐에는 1부터 k까지의 바이러스가 차례대로 들어간다.
    for (int i = 1; i <= k; i++) {

        for (int y = 0; y < n; y++) {

            for (int x = 0; x < n; x++) {

                if (board[y][x] == i) {
                    q.push({{x, y}, i});
                    visited[y][x] = 1;
                }

            }
        }

    }


    bfs();

//    for (int y = 0; y < n; y++) {
//        for (int x = 0; x < n; x++) {
//            cout << board[y][x] << " ";
//        }
//        cout << "\n";
//    }

    cout << board[xx - 1][yy - 1];


    return 0;
}