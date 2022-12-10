#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int dx[2] = {1, 0};
int dy[2] = {0, 1};

int n;
char map[6][6];
int maxx = -12345678;
int minn = 9876543;

void dfs(int x,int y, int idx,int sum, char pre){

    if (x == n - 1 && y == n - 1) {

        maxx = max(maxx, sum);
        minn = min(minn, sum);

        return;
    }


    for (int i = 0; i < 2; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= n || ny >= n) continue;
        // 다음 위치가 숫자 일 때
        if (idx % 2 == 1) {
                if (pre == '+') {
                    dfs(nx, ny, idx + 1, sum + (map[ny][nx] - '0'), map[ny][nx]);
                } else if (pre == '-') {
                    dfs(nx, ny, idx + 1, sum - (map[ny][nx] - '0'), map[ny][nx]);
                } else if (pre == '*') {
                    dfs(nx, ny, idx + 1, sum * (map[ny][nx] - '0'), map[ny][nx]);
                }
            // 다음 위치가 연산자일 때
        }else{
            dfs(nx, ny, idx + 1, sum, map[ny][nx]);
        }

    }


}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            cin >> map[y][x];
        }
    }

    dfs(0, 0, 0, map[0][0] - '0', map[0][0]);

    cout << maxx << " " << minn;

}