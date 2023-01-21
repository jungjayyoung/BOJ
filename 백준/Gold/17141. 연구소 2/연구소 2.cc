#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
int map[51][51];
int visited[51][51];
int visited2[11];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

vector<pair<int,int>> v;
vector<pair<int,int>> pos;
int ans = 0;
int ans2 = 98765432;
int v_cnt = 0;
int empty_cnt = 0;


void bfs(){
    queue<pair<int,int>> virus;
    for (int i = 0; i < v.size(); i++) {
        virus.push({v[i].first, v[i].second});
        visited[v[i].second][v[i].first] = 1;
    }


    int cntt = 0;

    while (!virus.empty()) {
        int S = virus.size();

        for (int j = 0; j < S; j++) {

            int curx = virus.front().first;
            int cury = virus.front().second;
            virus.pop();
            cntt++;

            for (int i = 0; i < 4; i++) {
                int nx = curx + dx[i];
                int ny = cury + dy[i];

                if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                if (map[ny][nx] == 1) continue;

                if (!visited[ny][nx]) {

                    visited[ny][nx] = 1;
                    virus.push({nx, ny});
                }
            }

        }

        if(virus.size() != 0) ans++;

    }

    if (cntt == empty_cnt) {
        ans2 = min(ans2, ans);
    }


}

void bt(int idx){

    if (v.size() >= m) {

        for (int y = 0; y < n; y++) {
            for (int x = 0; x < n; x++) {
                visited[y][x] = 0;
            }
        }

        ans = 0;
        bfs();
        return;
    }


    for (int i = idx; i < v_cnt; i++) {

        if (!visited2[i]) {
            visited2[i] = 1;
            v.push_back({pos[i].first, pos[i].second});
            bt(idx + 1);
            v.pop_back();
            visited2[i] = 0;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;


    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            cin >> map[y][x];
            if (map[y][x] == 1) {
                visited[y][x] = 1;
            }
            if (map[y][x] == 2) {
                pos.push_back({x, y});
                v_cnt++;
            }

            if (map[y][x] != 1) {
                empty_cnt++;
            }
        }
    }

    bt(0);

    if (ans2 == 98765432) {
        cout << -1;
    }else
        cout << ans2;


    return 0;
}