#include <iostream>
#include <algorithm>

using namespace std;

int n;

int board[501][501];
int cache[501][501]; // cache[y][x] x,y 에 도착했을 때 방문한 칸들의 최대 갯수가 저장된다.

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};



int dfs(int x,int y){

    if (cache[y][x] != -1) {
        return cache[y][x];
    }


    cache[y][x] = 1;
    for (int i = 0; i < 4; i++) {

        int nextx = x + dx[i];
        int nexty = y + dy[i];

        if (nextx < 0 || nextx >= n || nexty < 0 || nexty >= n) {
            continue;
        }

        if (board[y][x] < board[nexty][nextx]) {

            cache[y][x] = max(cache[y][x], 1 + dfs(nextx, nexty));
        }

    }

    return cache[y][x];
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

    fill(&cache[0][0], &cache[501][0], -1);

    int ans = 0;
    for (int y = 0; y < n; y++) {

        for (int x = 0; x < n; x++) {

            if (cache[y][x] == -1) {
                ans = max(ans, dfs(x, y));
            }

        }
    }

    cout << ans;

    return 0;
}