#include <iostream>
#include <queue>

using namespace std;

int map[4][4];
int visited[4][4];

int dx[] = {1, 0};
int dy[] = {0, 1};
queue<pair<int, int>> q;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;

    cin >> n;

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            cin >> map[y][x];
        }
    }

    q.push({0, 0});
    visited[0][0] = 1;


    while (!q.empty()) {

        int curx = q.front().first;
        int cury = q.front().second;
        q.pop();

        if (curx == n - 1 && cury == n - 1) {
            cout << "HaruHaru";
            return 0;
        }


        for (int i = 0; i < 2; i++) {
            int num = map[cury][curx];
            int nx = curx + (dx[i] * num);
            int ny = cury + (dy[i] * num);

            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;

            if (!visited[ny][nx]) {
                visited[ny][nx] = 1;
                q.push({nx, ny});
            }
        }

    }

    cout << "Hing";

    return 0;
}