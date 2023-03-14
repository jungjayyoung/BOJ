#include <iostream>
#include <string>

using namespace std;


int n, m;

char map[52][52];
int visited[52][52];
int dx1[] = {-1, 0, 0, 1, 1, 1};
int dy1[] = {0, -1, 1, -1, 0, 1};
int dx2[] = {-1, -1, -1, 0, 0, 1};
int dy2[] = {-1, 0, 1, -1, 1, 0};
int ans = 0;

void dfs(int x, int y){

    visited[y][x] = 1;

    for (int i = 0; i < 6; i++) {

        int nx;
        int ny;
        if (y % 2 == 1) {
            nx = x + dx1[i];
            ny = y + dy1[i];
        } else {
            nx = x + dx2[i];
            ny = y + dy2[i];
        }

        if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;

        if(visited[ny][nx]) continue;

        if (visited[ny][nx] == 0 && map[ny][nx] == '.') {
            dfs(nx, ny);
        } else if (visited[ny][nx] == 0 && map[ny][nx] == '#') {

            ans++;
        }


    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;


    for (int y = 0; y < n; y++) {

        string str;
        cin >> str;
        for (int x = 0; x < m; x++) {
            map[y][x] = str[x];
        }
    }

    for (int y = 0; y < n; y++) {

        for (int x = 0; x < m; x++) {
            if (map[y][x] == '.' && visited[y][x] == 0) {
                dfs(x, y);
            }
        }

    }


    cout << ans;

    return 0;
}