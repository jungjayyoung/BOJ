#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int map[101][101];
int visited[101][101];

int n;
string str;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    cin >> str;

    // (100,100) 크기의 맵에서 (50,50)에서 시작한다고 가정
    int curx = 50;
    int cury = 50;

    int dir = 0;
    visited[cury][curx] = 1;

    // 최대 최소 curx 와 cury 를 구해서 그 부분만 출력하면 된다.

    int minx = 50;
    int miny = 50;
    int maxx = 50;
    int maxy = 50;

    for (int i = 0; i < n; i++) {

        if (str[i] == 'R') {
            dir--;
            if (dir < 0) {
                dir = 3;
            }
        } else if (str[i] == 'L') {
            dir++;
            if (dir > 3) {
                dir = 0;
            }
        } else if (str[i] == 'F') {
            int nx = curx + dx[dir];
            int ny = cury + dy[dir];

            visited[ny][nx] = 1;
            curx = nx;
            cury = ny;
            minx = min(minx, curx);
            maxx = max(maxx, curx);
            miny = min(miny, cury);
            maxy = max(maxy, cury);
        }

    }


    for (int y = miny; y <= maxy; y++) {
        for (int x = minx; x <= maxx; x++) {
            if (visited[y][x] == 1) {
                cout << '.';
            }else
                cout << '#';
        }
        cout << "\n";
    }


    return 0;
}