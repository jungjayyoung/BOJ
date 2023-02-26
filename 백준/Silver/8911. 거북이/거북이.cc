#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;


    while (t--) {
        string str;
        cin >> str;

        int dir = 0;
        int sx = 500;
        int sy = 500;
        int maxx = 500;
        int maxy = 500;
        int minx = 500;
        int miny = 500;


        for (int i = 0; i < str.size(); i++) {
            int nx, ny;

            if (str[i] == 'F') {
                nx = sx + dx[dir];
                ny = sy + dy[dir];

                sx = nx;
                sy = ny;
                maxx = max(maxx, sx);
                minx = min(minx, sx);
                maxy = max(maxy, sy);
                miny = min(miny, sy);

            } else if (str[i] == 'B') {
                nx = sx - dx[dir];
                ny = sy - dy[dir];
                sx = nx;
                sy = ny;
                maxx = max(maxx, sx);
                minx = min(minx, sx);
                maxy = max(maxy, sy);
                miny = min(miny, sy);

            } else if (str[i] == 'L') {
                dir--;
                if (dir < 0) {
                    dir = 3;
                }

            } else if (str[i] == 'R') {
                dir++;
                if (dir > 3) {
                    dir = 0;
                }
            }

        }

        cout << (maxx - minx) * (maxy - miny) << "\n";

    }

    return 0;
}