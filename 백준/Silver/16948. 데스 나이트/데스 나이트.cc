#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n;
int r1, c1, r2, c2;
int dx[] = {-2, -2, 0, 0, 2, 2};
int dy[] = {-1, 1, -2, 2, -1, 1};
int visited[201][201];
queue<pair<pair<int,int>,int>> q;
bool check = false;
void bfs(){


    while (!q.empty()) {

        int x = q.front().first.first;
        int y = q.front().first.second;
        int cnt = q.front().second;

        q.pop();

        if (x == r2 && y == c2) {
            cout <<cnt;
            check = true;
            return;
        }

        for (int i = 0; i < 6; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx <0 || ny < 0 || nx >= n || ny >= n) continue;

            if (!visited[ny][nx]) {
                visited[ny][nx] = 1;
                q.push({{nx, ny}, cnt + 1});
            }

        }

    }

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);


    cin >> n;
    cin >> r1 >> c1 >> r2 >> c2;

    visited[c1][r1] = 1;
    q.push({{r1, c1}, 0});

    bfs();


    if (!check) {
        cout << -1;
    }


    return 0;
}