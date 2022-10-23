#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;


int r,c;
char map[1501][1501];
int visited[1501][1501];
int x1, y1, x2, y2;
queue<pair<int, int>> swan_q, swan_nq, water_q, water_nq;

vector<pair<int,int>> v; // 두 오리의 좌표가 담긴다.

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
bool check;
int ans;


void bfs_swan(){


    while (!swan_q.empty()) {

        int curx = swan_q.front().first;
        int cury = swan_q.front().second;

        swan_q.pop();

        for (int i = 0; i < 4; i++) {

            int nx = curx + dx[i];
            int ny = cury + dy[i];

            if (nx < 0 || ny < 0 || nx >= c || ny >= r) {
                continue;
            }

            if (!visited[ny][nx]) {
                visited[ny][nx] = 1;
                if (map[ny][nx] == '.') {
                    swan_q.push({nx, ny});
                }else{
                    if (map[ny][nx] == 'L') {
                        check = true;
                    }
                    swan_nq.push({nx, ny});
                }
            }

        }

    }



}

void bfs_water(){


    while (!water_q.empty()) {

        int curx = water_q.front().first;
        int cury = water_q.front().second;

        water_q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = curx + dx[i];
            int ny = cury + dy[i];

            if (nx < 0 || ny < 0 || nx >= c || ny >= r) {
                continue;
            }

            if (map[ny][nx] == 'X') {
                map[ny][nx] = '.';
                water_nq.push({nx, ny});
            }

        }
    }

}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);



    cin >> r >> c;

    for (int y = 0; y < r; y++) {
        string str;
        cin >> str;
        for (int x = 0; x < c; x++) {
            map[y][x] = str[x];
            if (map[y][x] == 'L') {
                v.push_back({x, y});
            }

            if (map[y][x] == '.' || map[y][x] == 'L') {
                water_q.push({x, y});
            }
        }
    }


    x1 = v[0].first;
    y1 = v[0].second;

    x2 = v[1].first;
    y2 = v[1].second;

    swan_q.push({x1, y1});
    visited[y1][x1] = 1;

    while (true) {


        bfs_swan();

        if (check) {
            break;
        }
        bfs_water();

        swan_q = swan_nq;
        water_q = water_nq;

        while(!swan_nq.empty()) swan_nq.pop();
        while(!water_nq.empty()) water_nq.pop();

        // 날짜를 1 증가 시켜준다.
        ans++;


    }


    cout << ans;

    return 0;
}