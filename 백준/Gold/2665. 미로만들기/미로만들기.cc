#include <iostream>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

// 너비 우선 탐색으로 풀어야 될 것 같은 느낌?
// 검은방을 만나면 이동은 하는 대신에 queue에서 cnt를 +1을 저장하면 되지 않을까?
int n;
char board[51][51];
int ans = 87654;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int visited[51][51];
int cache[51][51];


queue<pair<int,int>> q;

void bfs(){


    q.push({0, 0});
    cache[0][0] = 0;

    while (!q.empty()) {

        int cur_x = q.front().first;
        int cur_y = q.front().second;

        q.pop();



        if (cur_x == n - 1 && cur_y == n - 1) {

            ans = min(ans, cache[cur_y][cur_x]);

        }

        for (int i = 0; i < 4; i++) {
            int nextx = cur_x + dx[i];
            int nexty = cur_y + dy[i];

            if (nextx < 0 || nextx >= n || nexty < 0 || nexty >= n) {
                continue;
            }

            if(board[nexty][nextx] == '1'){
                if (cache[nexty][nextx] > cache[cur_y][cur_x]) {
                    cache[nexty][nextx] = cache[cur_y][cur_x];
                    q.push({nextx, nexty});
                }
            } else if (board[nexty][nextx] == '0') {
                if (cache[nexty][nextx] > cache[cur_y][cur_x] + 1) {
                    cache[nexty][nextx] = cache[cur_y][cur_x] + 1;
                    q.push({nextx, nexty});
                }

            }

        }

    }


}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < str.size(); j++) {
            board[i][j] = str[j];
        }
    }

    fill(&cache[0][0], &cache[51][0], 54321);


    bfs();

   
    cout << ans;







    return 0;
}