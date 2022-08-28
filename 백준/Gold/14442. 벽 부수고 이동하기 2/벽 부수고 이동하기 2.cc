#include <iostream>
#include <queue>
#include <string>
using namespace std;


int n, m, k;

int board[1001][1001];
bool visited[1001][1001][11];
queue<pair<pair<int,int>,pair<int,int>>> q;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
bool check = false;
int ans = 1;


void bfs(){

    q.push({{0, 0},{1,0}});

    for (int i = 0; i <= k; i++) {
        visited[0][0][i] = true;
    }

    while (!q.empty()) {

        int x = q.front().first.first;
        int y = q.front().first.second;
        int cnt = q.front().second.first;
        int crash = q.front().second.second;

        q.pop();

        if (x == m - 1 && y == n - 1) {
            ans = cnt;
            check = true;
            break;
        }
        for (int i = 0; i < 4; i++) {
            int nextx = x + dx[i];
            int nexty = y + dy[i];

            if(nextx < 0 || nexty < 0 || nextx >= m || nexty >= n) continue;

            if(board[nexty][nextx] == 0 && !visited[nexty][nextx][crash]){
                visited[nexty][nextx][crash] = true;
                q.push({{nextx,   nexty},{cnt + 1, crash}});
            }

            if(crash < k){
                if (board[nexty][nextx] == 1 && !visited[nexty][nextx][crash+1]) {
                    visited[nexty][nextx][crash+1] = true;
                    q.push({{nextx,   nexty},{cnt + 1, crash + 1}});
                }
            }

        }


    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    cin >> n >> m >> k;


    for (int y = 0; y < n; y++) {

        string a;
        cin >> a;
        for (int x = 0; x< a.size(); x++) {
            board[y][x] = a[x] - '0';
        }
    }


    bfs();

    if (check) {
        cout << ans;
    }else{
        cout << -1;
    }

    return 0;
}