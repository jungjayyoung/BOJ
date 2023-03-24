#include <iostream>


using namespace std;


int c, r, k;

int map[1001][1001];
int visited[1001][1001];

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int dir = 0;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> c >> r >> k;

    if (r * c < k) {
        cout << 0;
        return 0;
    }

    int cnt = 1;


    int sx = 1;
    int sy = 1;
    visited[sy][sx] = 1;

    while (cnt != k) {
        int nx = sx + dx[dir];
        int ny = sy + dy[dir];

        if (nx > c || nx < 1 || ny > r || ny < 1 || visited[ny][nx]) {
            dir++;
            if(dir > 3) dir = 0;
            nx = sx + dx[dir];
            ny = sy + dy[dir];
        }

        visited[ny][nx] = 1;
        cnt++;
        sx = nx;
        sy = ny;

    }


    cout << sx << " " << sy;
    return 0;
}