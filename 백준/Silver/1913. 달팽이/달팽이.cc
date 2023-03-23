#include <iostream>


using namespace std;


int n;
int goal;

int map[1000][1000];

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> goal;

    int curx = 1;
    int cury = 1;
    int dir = 0;

    for (int i = n * n; i >= 1; --i) {
        if (map[cury][curx] == 0) {
            map[cury][curx] = i;
        }

        int nx = curx + dx[dir];
        int ny = cury + dy[dir];

        if (map[ny][nx] != 0 || (nx > n || ny > n || ny < 1)) {
            dir++;
            if (dir > 3) {
                dir = 0;
            }
            nx = curx + dx[dir];
            ny = cury + dy[dir];
        }
        curx = nx;
        cury = ny;
    }

    int xx;
    int yy;
    for (int y = 1; y <= n; y++) {

        for (int x = 1; x <= n; x++) {
            if (map[y][x] == goal) {
                yy = y;
                xx = x;
            }
            cout << map[y][x] << " ";
        }
        cout << "\n";
    }


    cout << yy << " " << xx;
    return 0;
}