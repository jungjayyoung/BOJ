#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int n,m;
char map[21][21];
int visited[21][21];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
vector<pair<int,int>> v;
int ans = 10;


bool check = false;


void bt(int cnt,int x1,int y1, int x2, int y2){


    if(x1 == x2 && y1 == y2) return;


    if (cnt > 10) {
        return;
    }

    if(x1 <0 || y1 < 0 || x1 >= m || y1 >= n) {
        ans = min(ans, cnt);
        check = true;
        return;
    }

    if(x2 <0 || y2 < 0 || x2 >= m || y2 >= n) {
        ans = min(ans, cnt);
        check = true;
        return;
    }




    for (int i = 0; i < 4; i++) {
        int nx1 = x1 + dx[i];
        int ny1 = y1 + dy[i];
        int nx2 = x2 + dx[i];
        int ny2 = y2 + dy[i];

        // 둘 다 떨어지면 안된다.
        if ((nx1 < 0 || ny1 < 0 || nx1 >= m || ny1 >= n) && (nx2 < 0 || ny2 < 0 || nx2 >= m || ny2 >= n)) {
            continue;
        }

        // 둘 다 벽이면 안된다.
        if(((nx1 >= 0 && ny1 >= 0 && nx1 < m && ny1 < n) && map[ny1][nx1] == '#') && ((nx2 >= 0 && ny2 >= 0 && nx2 < m
        && ny2 < n) && map[ny2][nx2] == '#')) continue;

        //하나만 벽이면 하나만 움직인다.
        if (((nx1 >= 0 && ny1 >= 0 && nx1 < m && ny1 < n) && map[ny1][nx1] == '#') || ((nx2 >= 0 && ny2 >= 0 && nx2 < m
                                                                                     && ny2 < n) &&
                                                                                    map[ny2][nx2] == '#')) {
            if ((nx1 >= 0 && ny1 >= 0 && nx1 < m && ny1 < n) && map[ny1][nx1] == '#') {
                bt(cnt + 1, x1, y1, nx2, ny2);
                continue;
            }else if((nx2 >= 0 && ny2 >= 0 && nx2 < m && ny2 < n) && map[ny2][nx2] == '#'){
                bt(cnt + 1, nx1, ny1, x2, y2);
                continue;
            }
        }

        bt(cnt + 1, nx1, ny1, nx2, ny2);

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
            if (map[y][x] == 'o') {
                v.push_back({x, y});
            }
        }
    }


    bt(0, v[0].first, v[0].second, v[1].first, v[1].second);

    if (check) {
        cout << ans;
    }else
        cout << -1;


    return 0;
}