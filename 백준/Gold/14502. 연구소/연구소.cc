#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int visited[10][10];
int lab[10][10];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int ans = -1;

void dfs(int x, int y){


    visited[y][x] = 1;

    for (int i = 0; i < 4; i++) {
        int nextx = x + dx[i];
        int nexty = y + dy[i];

        if (nextx < 0 || nextx >= m || nexty < 0 || nexty >= n) {
            continue;
        }

        if (lab[nexty][nextx] == 0 && !visited[nexty][nextx]) {
            dfs(nextx, nexty);
        }


    }

}

void bt(int cnt){

    if (cnt == 3) {

        int num = 0;


        // visited 배열이 0인 칸을 1로 만들면서 dfs 한다.
        for (int y = 0; y < n; y++) {

            for (int x = 0; x < m; x++) {

                if (lab[y][x] == 2) {
                    dfs(x, y);
                }
            }
        }

        //visited 배열이 0 인칸은 안전 영역이다.
        for (int y = 0; y < n; y++) {

            for (int x = 0; x < m; x++) {

                if (visited[y][x] == 0) {
                    num++;
                }
            }
        }

        ans = max(ans, num);

        // 다시 visited 0으로 초기화
        for (int y = 0; y < n; y++) {

            for (int x = 0; x < m; x++) {

                if (lab[y][x] == 0) {
                    visited[y][x] = 0;
                }
            }
        }


        return;


    }


    for (int y = 0; y < n; y++) {

        for (int x = 0; x < m; x++) {

            if (lab[y][x] == 0 && !visited[y][x]) {
                lab[y][x] = 1;
                visited[y][x] = 1;
                bt(cnt + 1);
                visited[y][x] = 0;
                lab[y][x] = 0;
            }


        }
    }



}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;


    for (int y = 0; y < n; y++) {

        for (int x = 0; x < m; x++) {

            cin >> lab[y][x];
            if (lab[y][x] == 1) {
                visited[y][x] = 1;
            }
        }
    }


    bt(0);

    cout << ans;

    return 0;
}