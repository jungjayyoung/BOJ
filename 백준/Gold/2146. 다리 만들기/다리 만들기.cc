#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n;

int board[101][101];
int visited[101][101];
int same_island[101][101]; // dfs를 통해 같은 섬인지 파악해야 한다.
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

queue<pair<pair<int, int>, int>> q;
int ans = 987654;


void dfs(int x,int y){


    for (int i = 0; i < 4; i++) {

        int nextx = x + dx[i];
        int nexty = y + dy[i];

        if (nextx < 0 || nexty < 0 || nextx >= n || nexty >= n) {
            continue;
        }

        if (board[nexty][nextx] == 1 && !same_island[nexty][nextx]) {
            same_island[nexty][nextx] = 1;
            dfs(nextx, nexty);
        }


    }


}
void bfs(){


    while (!q.empty()) {

        int cur_x = q.front().first.first;
        int cur_y = q.front().first.second;
        int cnt = q.front().second;


        q.pop();


        if (board[cur_y][cur_x] == 1 && cnt != 0) {
            ans = min(ans, cnt);

            continue;
        }


        for (int i = 0; i < 4; i++) {
            int nextx = cur_x + dx[i];
            int nexty = cur_y + dy[i];

            if(nextx < 0 || nexty < 0 || nextx>= n || nexty >=n) {
                continue;
            }

            // 같은 섬이면 continue
            if (same_island[nexty][nextx]) {
                continue;
            }

            if(!visited[nexty][nextx]){
                if (board[nexty][nextx] == 1) {
                    visited[nexty][nextx] = 1;
                    q.push({{nextx, nexty}, cnt});
                }else{
                    visited[nexty][nextx] = 1;
                    q.push({{nextx, nexty}, cnt + 1});
                }
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
        }
    }


    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {

            fill(&visited[0][0], &visited[101][0], 0);
            fill(&same_island[0][0], &same_island[101][0], 0);

            if (board[y][x] == 1) {
                dfs(x, y); // 같은 섬부터 파악
                q.push({{x, y}, 0});
                visited[y][x] = 1;
                bfs();
            }
        }
    }


    cout << ans;

    return 0;
}